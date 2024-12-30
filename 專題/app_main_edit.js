'use strict';
const qrcode = require('qrcode');
const config = require('./public/js/config.js');
const mysql = require('mysql')
const express = require('express')
var os = require('os');
var router = express.Router();
var app = express();
var http = require('http')
var https= require('https')
var fs = require('fs')
const jwt = require('jsonwebtoken');
const formidable = require('formidable');
var path=require('path')
var socketIO = require('socket.io');
const cookieParser = require('cookie-parser')
const session = require('express-session')
const bodyParser = require('body-parser')
const db = require('./models/connection_db');
const util = require('util')
const encryption = require('./models/encryption.js');
var nodemailer = require('nodemailer');
var transporter = nodemailer.createTransport({
    service: 'Gmail',
    host: 'smtp.gmail.com',
    port: 465,
    secure: true,
    auth: {
        user: 'from140.138.144.152@gmail.com',
        pass: 'blawmoxjdzxcgwxr'
    }
});
const promisifiedQuery = util.promisify(db.query).bind(db);
app.use(express.static('public'));
app.use(bodyParser.json());
var urlencodedPsrser = bodyParser.urlencoded({ extended: false });
var sleep = require('system-sleep');
const screenshot = require('desktop-screenshot');
var path = require('path');
var root = path.dirname(require.main.filename);
app.use(session({
  secret: 'mySecret',
  name: 'user', 
  saveUninitialized: false,
  resave: true, 
}));
const multer  = require('multer');
const XLSX = require('xlsx');;
const upload = multer({ dest: 'uploads/' });

function auth_student(req, res, next) {
  if (req.session.student) {
    next()
  } 
  else {
    req.session.destroy()
    return res.redirect('/index')
  }
}

function auth_professor(req, res, next) {
  if (req.session.professor) {
    next()
  } 
  else {
    req.session.destroy()
    return res.redirect('/index')
  }
}
function auth_target_class(req, res, next) {
  if (req.session.target_class) {
    next()
  } 
  else {
    return res.redirect('/user/professor')
  }
}
function auth_target_exam(req, res, next) {
  if (req.session.target_exam) {
    next()
  } 
  else {
    return res.redirect('/user/professor')
  }
}
function auth_sysadmin(req, res, next) {
  if (req.session.sysadmin) {
    next()
  } 
  else {
    req.session.destroy();
    return res.redirect('/index')
  }
}

const sslServer = https.createServer( 
   {
      key: fs.readFileSync(path.join(__dirname,'cert','key.pem')),
      cert:fs.readFileSync(path.join(__dirname,'cert','cert.pem'))

   },app
)
sslServer.listen(process.env.PORT || 1447);
var io  = socketIO(sslServer);
//-------------------test-------------------
app.set('view engine', 'ejs');

app.post("/leave_exam",urlencodedPsrser ,function(req,res) {
  console.log(req.body);
});

app.post("/leave_exam",urlencodedPsrser ,function(req,res) {
  console.log(req.body);
});
//-----------------logout----------------------

app.post("/logout",urlencodedPsrser ,async function(req,res,next) {
  if (req.session.student) {
    try {
      const student = await promisifiedQuery('SELECT account FROM user_account_info WHERE account = ?', [req.session.student]); 
      if (req.session.qrcode && req.session.answer) {
        await promisifiedQuery('UPDATE ' + req.session.class_no + "_" + req.session.exam_file + ' SET exam_finish = 1 WHERE sID = "'+student[0].account+ '"');
        console.log(req.session.student + " hand in exam");
      } else if (req.session.qrcode) {
        res.redirect('/' + req.session.class_no + "___" + req.session.qrcode+"/index");
      } else {
      	res.redirect('/index');
        console.log("byebye");
      }    
        
    } catch (error) {
      console.log(error);
    } finally {
      req.session.destroy();
    }
  }
  else{
    req.session.destroy();
    res.redirect('/index');
  }
});


//-----------------login_page----------------------

app.get("/index", function(req, res){
  if(req.session.exam_file) { 
    req.session.destroy();
    res.render("./user_action/index.ejs", {log_fail:'',fgt_success:'',fgt_fail:''});
  }
  else if(req.session.loginErrContext) {
    res.render("./user_action/index.ejs", {log_fail:req.session.loginErrContext,fgt_success:'',fgt_fail:''});
  } else {
    res.render("./user_action/index.ejs", {log_fail:'',fgt_success:'',fgt_fail:''});
  }
});

app.get("/:course/index", async function(req, res){
  if(req.session.loginErrContext){
    res.render("./user_action/index.ejs", {log_fail:req.session.loginErrContext,fgt_success:'',fgt_fail:''});
  } else if (req.params.course != null && req.params.course) {
    var token = req.params.course.split("___");
    try {
      const rows = await promisifiedQuery('SELECT class_no, exam_file FROM professor_exam_info where account = ? AND qrcode = ? ', [token[0], token[1]]);
      if (rows.length == 0) {
        res.render("./user_action/index.ejs", {log_fail:'',fgt_success:'',fgt_fail:'網址錯誤。'});
      } else {
        req.session.class_no = rows[0].class_no;
        req.session.exam_file = rows[0].exam_file;
        req.session.qrcode = token[1];
        res.render("./user_action/index_student.ejs", {log_fail:'',fgt_success:'',fgt_fail:''});
      } 
    } catch (err) {
      console.log(err);
    }
  } else {
    res.render("./user_action/index.ejs", {log_fail:'',fgt_success:'',fgt_fail:'網址錯誤。'});
  }
});

app.post("/login",urlencodedPsrser ,async function(req,res,next) {
  const userData = {
    account: req.body.login_account,
    password: req.body.login_password//encryption(req.body.txtUserPwd)
  };
  try{
    const rows = await promisifiedQuery('SELECT account,password,authority FROM user_account_info WHERE account = ? AND password = ?', [userData.account, userData.password]);
    if(rows[0]==null){
      req.session.loginErrContext = '請輸入正確的帳號和密碼。';
      res.redirect("/index");
    } else {
      if(rows[0].authority==0){
        req.session.student =  req.body.login_account;
        const rows1 = await promisifiedQuery('SELECT * FROM student_class_info');
        var result_class_no=[];
        for(var i=0;i<rows1.length;i++){
          if(Object.values(rows1[i]).includes(req.session.student)) {
            result_class_no.push(rows1[i].class_no);
          }
        }
        res.redirect("/user/student/grade");
      } else if(rows[0].authority==1) {
        req.session.professor =  req.body.login_account;
        res.redirect('/user/professor');
      } else { 
        req.session.sysadmin =  req.body.login_account;
        res.redirect('/user/sysadmin');
      }
    }
  } catch(err) {
    console.log(err);
  }
});

app.post("/loginStudent",urlencodedPsrser ,function(req,res,next) {
  const userData = {
    account: req.body.login_account,
    password: req.body.login_password//encryption(req.body.txtUserPwd)
  }
  db.query('SELECT account,password,authority FROM user_account_info WHERE account = ? AND password = ?', [userData.account, userData.password], function(err,rows){
    if(err||rows[0]==null){
      req.session.loginErrContext = "請輸入正確的帳號和密碼。";
	    res.redirect(req.session.class_no+"___"+req.session.qrcode+"/index");
    }
    else{
      if(rows[0].authority==0) { // 0 student, 2 professor, 1 sysadmin
          req.session.student =  req.body.login_account;
          res.redirect('/user/student');
      }
      else if(rows[0].authority==1){
        req.session.professor =  req.body.login_account;
        res.redirect('/user/professor');
      }
      else{
        req.session.sysadmin =  req.body.login_account;
        res.redirect('/user/sysadmin'); 
      }
    }
  });
});

app.post("/fgt",urlencodedPsrser ,function(req,res,next) {
  db.query('SELECT account, email, password, fgt_time FROM user_account_info WHERE account = ? AND email = ?', [req.body.fgt_account, req.body.fgt_email], function(err,rows){
    if(err||rows[0]==null){
      res.render("./user_action/index.ejs", {log_fail:'',fgt_success:'',fgt_fail:'請輸入正確的帳號和Eamil。'});
    }
    else{
      var temp=  new Date();
      var condition = 0;
      if(rows[0].fgt_time!=null){
        rows[0].fgt_time.setMinutes(rows[0].fgt_time.getMinutes()+10);
        if (rows[0].fgt_time>temp){
          condition=1;
        }
      }
      if(condition===0){
        db.query('UPDATE user_account_info SET fgt_time = ? WHERE account = ?', [temp, req.body.fgt_account], function (err1,rows1){
          if(!err1){
            var options = {
              from: 'from140.138.144.152@gmail.com',//寄件者    
              to: rows[0].email, //收件者
              subject: '這是題庫系統發送的信件', // Subject line//主旨
              text: 'your password is: '+rows[0].password, //純文字
            };
            transporter.sendMail(options, function(error, info){
              if(error)
                console.log(error);
              else
                console.log('訊息已經發送,'+rows[0].account +' 請至email查看。'); 
            });
            res.render("./user_action/index.ejs", {log_fail:'',fgt_success:'請至email查看!!! ' ,fgt_fail:''});
          }    
        });
      }
      else{
        res.render("./user_action/index.ejs", {log_fail:'',fgt_success:'',fgt_fail:'操作太頻繁，請稍後再試。'});
      } 
    }
  });
});

//-----------------sysadmin_page----------------------
//-----------------sysadmin_admin----------------------//finish
app.get("/user/sysadmin", auth_sysadmin, function(req, res){
  db.query('SELECT * FROM user_account_info order by authority ASC, account ASC', function(err,rows){
    res.render("./sysadmin/index.ejs", {page: "Admin", sysadmin:req.session.sysadmin, user_info:rows});
  });
});
app.post("/user/sysadmin/admin/delete",urlencodedPsrser, function(req, res,next){
  console.log(req.body);
  db.query('DELETE FROM user_account_info WHERE account = ?', [req.body.account], function (err1,rows1){
    if(err1) console.log(err1);
  });
});
  

//-----------------sysadmin_class----------------------
app.get("/user/sysadmin/class", auth_sysadmin, function(req, res){
  db.query('SELECT * FROM professor_exam_info', function(err,rows,fields){
    db.query('SELECT * FROM professor_exam_file', function(err1,rows1,fields1){
      res.render("./sysadmin/class.ejs", {page:"Class",sysadmin:req.session.sysadmin,datalist:rows,class_info:rows1});
    });
  });
});
//-----------------sysadmin_profile----------------------//finish
app.get("/user/sysadmin/profile", auth_sysadmin, function(req, res){
  db.query('SELECT * FROM user_account_info WHERE account = ?', [req.session.sysadmin], function(err,rows){
    res.render("./sysadmin/profile.ejs", {page: "Profile", sysadmin:req.session.sysadmin, datalist:rows});
  });
});

//-----------------sysadmin__change_password----------------------
app.get("/user/sysadmin/change_password", auth_sysadmin, function(req, res){
  db.query('SELECT * FROM user_account_info WHERE account = ?', [req.session.sysadmin], function(err,rows){
    res.render("./sysadmin/change_password.ejs", {page: "Change password", sysadmin:req.session.sysadmin, datalist:rows});
  });
});

app.post("/user/sysadmin/change_password/change",urlencodedPsrser ,function(req,res,next) {
  db.query('UPDATE user_account_info set password = ? WHERE account = ?', [req.body.Newpwd, req.body.account], function(err,rows){
    if(err) console.log(err);
  });
});


//----------------------professor_page----------------------

//----------------------professor_exam----------------------// finish
  
app.get("/user/professor", auth_professor, function(req, res){
  db.query('SELECT class_no, exam_file FROM professor_exam_file WHERE account = ? ', [req.session.professor], function(err,rows){
    db.query('SELECT class_no, class_name,  exam_info FROM professor_exam_info WHERE account = ? ', [req.session.professor], function(err1,rows1){
      var class_list=[];
      for(var i =0;i<rows1.length;i++){
        class_list.push(rows1[i].class_no+" "+ rows1[i].class_name);
      }
      res.render("./professor/index.ejs", {page:"Exam", datalist:rows, class_list:class_list, professor:req.session.professor,class_no:"",exam_file:"",mes:-1});
    });
  });
});

app.get("/p", function(req, res){
  db.query('SELECT class_no, exam_file FROM professor_exam_file WHERE account = ? ', ['CS233A'], function(err,rows){
    db.query('SELECT class_no, exam_file, class_name,  exam_info FROM professor_exam_info WHERE account = ? ', ['CS233A'], function(err1,rows1){
      res.render("./professor/index_new.ejs", {page: "Exam", datalist: rows, class_list: rows1, professor: req.session.professor, classExamInfo: "", mes: -1});
    });
  });
});

app.get("/:course/p", async function(req, res){
  var token = req.params.course.split("___");
  var mes = token[0];
  var classExamInfo = token.length > 1 ? token[1] + " " : "";
  const rows = await promisifiedQuery('SELECT class_no, exam_file FROM professor_exam_file WHERE account = ? ', ['CS233A']);
  const rows1 = await promisifiedQuery('SELECT class_no, exam_file, class_name,  exam_info FROM professor_exam_info WHERE account = ? ', ['CS233A']);
  if (classExamInfo != "") {
    var class_name = await promisifiedQuery('SELECT class_name FROM professor_exam_info WHERE account = ? AND class_no = ?', ['CS233A', token[1]]);
    classExamInfo += class_name[0].class_name;
  }
  res.render("./professor/index_new.ejs", {page: "Exam", datalist: rows, class_list: rows1, professor: req.session.professor, classExamInfo: classExamInfo, mes: mes});
});

//debug OK 
app.post("/user/professor/index/exam",urlencodedPsrser, function(req, res,next){
  console.log(req.body);
  if(req.body.id=="0")
    req.body.exam_file = null;
  var class_no = req.body.class_no.split(" ");
  db.query('UPDATE professor_exam_info SET exam_info = ?, exam_file = ? WHERE class_no = ?', [parseInt(req.body.id), req.body.exam_file, class_no[0]], function (err,rows){
    if(err) console.log(err);
    else {
      if(req.body.id=="1") console.log('start success, test is begin');
      else{
        console.log('end success, test is end');
        res.redirect("/0/p");
      }
    }
  });
  if(req.body.id=="1"){
    var class_no = req.body.class_no.split(" ");
    db.query('UPDATE professor_exam_info SET exam_file = ? where class_no = ?',[req.body.exam_file, class_no[0]],function(err1,rows1){
      if(err1)  console.log(err1);
      res.redirect("/1___" + class_no[0] + "___" + req.body.exam_file + "/p");
    });
  }
});

//----------------------professor_draw_up----------------------// finish

app.get("/user/professor/draw_up", auth_professor, function(req, res){  // OK 
  db.query('SELECT * FROM professor_exam_file WHERE account = ?', [req.session.professor], function(err,rows){
    db.query('SELECT * FROM student_class_info', function(err1,rows1){
      db.query('SELECT class_no, class_name FROM professor_exam_info WHERE account = ? ', [req.session.professor], function(err2,rows2){
        var class_list=[];
        for(var i =0;i<rows2.length;i++){
          class_list.push(rows2[i].class_no+" "+ rows2[i].class_name);
        }
        res.render("./professor/draw_up.ejs", {page: "Draw up", professor:req.session.professor,datalist:rows, student: rows1, class_list:class_list});
      });
    });
  });
});

app.post("/user/professor/draw_up/create",urlencodedPsrser ,function(req,res,next) {
	if(req.body.folder_name!=""){
  	db.query('SELECT * FROM professor_exam_file WHERE account = ?', [req.session.professor], function (err,rows){
      if(err){
      	console.log(err);
      }
      else{
        var repeat_non = 0;
        for(var i=0;i<rows.length;i++){
          if(rows[i].class_no == req.body.class_no && rows[i].exam_file == req.body.folder_name){
            repeat_non = 1;
          }
        }
        if(repeat_non == 0){
          db.query('INSERT INTO professor_exam_file SET ?', [{"account":req.session.professor,"class_no":req.body.class_no, "exam_file":req.body.folder_name,post_info:0}], function (err,rows){
            if(err) console.log(err);
          });
        }
      }
    });
    var table_name = req.body.class_no+"_"+req.body.folder_name;
    var answer_table_name = req.body.class_no+"_"+req.body.folder_name+"_答案";
    (async ()=> {
			try {
				if(req.body.folder_name=="測試"){
					await promisifiedQuery('DROP TABLE '+table_name);
					await promisifiedQuery("DROP TABLE "+answer_table_name);
				}
				var rows;
				rows = await promisifiedQuery("select * from student_class_info where class_no = ?",[req.session.professor]);
				var question_num = req.body.question_num;
				var student_no =[];
				var student_num = rows[0]["student_num"];
				for(var i=1;i<=student_num;i++){
						student_no.push(rows[0]["student"+i]);
				}
				await promisifiedQuery("CREATE TABLE "+answer_table_name+" (class_no VARCHAR(50), exam_file VARCHAR (100),sID VARCHAR(15) unique, form_finish VARCHAR(15),question_number INT )");
				await promisifiedQuery("CREATE TABLE "+table_name+" (class_no VARCHAR(50), exam_file VARCHAR (100),sID VARCHAR(15) unique, cheat_times INT, point INT,form_finish VARCHAR(15),exam_finish INT, question_number INT, get_form INT)");
				for(var i=0;i<student_no.length;i++){
					await promisifiedQuery("INSERT INTO "+table_name+" SET ?",[{"class_no":req.session.professor,"exam_file":req.body.folder_name,"sID":student_no[i],"question_number":question_num,"form_finish":"no", "cheat_times":0, "exam_finish":0 }]);
					await promisifiedQuery("INSERT INTO "+answer_table_name+" SET ?",[{"class_no":req.session.professor,"exam_file":req.body.folder_name,"sID":student_no[i],"question_number":question_num,"form_finish":"no"}]);
					console.log("add:"+student_no[i]);
				}
				for(var i=1;i<=question_num;i++){
					await promisifiedQuery('ALTER TABLE '+ table_name +' ADD question_'+ i +' VARCHAR(1000)');
					await promisifiedQuery('ALTER TABLE '+ answer_table_name +' ADD question_'+ i +' VARCHAR(1000)');
			 	}
			}
			catch (err) {
				console.log(err); 
			}
		})()
    	/*db.query("DROP TABLE "+table_name,function(err,reslut){});
    	db.query("DROP TABLE "+answer_table_name,function(err,reslut){});*/
    //sleep(500);
    
    /*db.query(" select * from student_class_info where class_no = ?",[req.session.professor], function(err,rows){
    	var student_num = rows[0]["student_num"];
    	for(var i=1;i<=student_num;i++){
    		student_no.push(rows[0]["student"+i]);
    	}
    });*/
	}
			/*db.query('ALTER TABLE '+ table_name +' ADD question_'+ i +' VARCHAR(1000)',function(err,result){
			if(err) console.log(err);
		  });
		  db.query('ALTER TABLE '+ answer_table_name +' ADD question_'+ i +' VARCHAR(1000)',function(err,result){
			if(err) console.log(err);
		  });*/
    //sleep(100);
  /*
    newed
  var str = "";    
  for (var i = 0; i < req.body.question_num; i++) {
    if (i != 0)
      str += ', ';
    str += 'question' + i + ' VARCHAR(1000)';
  }
  db.query("CREATE TABLE " + table_name + " (class_no VARCHAR(50), exam_file VARCHAR (100), sID VARCHAR(15) unique, question_number INT, question_all VARCHAR(1000), "+str+",cheat_times INT not null, point INT)", function (err, result) {
    if (err) console.log(err);
  });
   
  */
});
app.post("/user/professor/draw_up/delete",urlencodedPsrser ,function(req,res,next) {
  console.log(req.body);
  db.query('DROP table '+req.body.class_no+'_'+req.body.exam_file, function (err,rows){
    if(err)
      console.log(err);
    else{
      //console.log('action: delete the class '+req.body.class_no+' --> Success');
    }
  });
  db.query('DROP table '+req.body.class_no+'_'+req.body.exam_file+'_答案', function (err,rows){
    if(err)
      console.log(err);
    else{
      //console.log('action: delete the class '+req.body.class_no+' --> Success');
    }
  });
  db.query('DELETE FROM professor_exam_file where class_no = ? AND exam_file = ?',[req.body.class_no, req.body.exam_file], function(err,rows){
    if(err) console.log(err);
    else console.log("success delete "+req.body.class_no+" "+req.body.exam_file);
  });
});

//----------------------professor_qrcode---------------------
app.get("/user/professor/qrcode", auth_professor, function(req, res){
  db.query('SELECT * FROM professor_exam_info WHERE account = ?', [req.session.professor], function(err,rows){
    res.render("./professor/qrcode.ejs", {page: "Qrcode", professor:req.session.professor,class_list:rows});
  });
});

app.get("/show", function(req, res){

  db.query('select qrcode from professor_exam_info WHERE account = ? AND class_no = ?', ["CS233A", "CS233A"], function(err,rows){
    if(rows!=null){
      const url = "https://140.138.144.121:1447/CS233A___"+rows[0].qrcode+"/index";
      qrcode.toDataURL(url, (err, qrCodeData) => {
        if (err) console.error(err);
        else {
          res.render("qrcode.ejs", {url: url, qrCodeData: qrCodeData});  
        }
      });  
    }
  });
});

//----------------------professor_grade----------------------
app.get("/user/professor/grade", auth_professor, function(req, res){
  db.query('SELECT * FROM professor_exam_info WHERE account = ?', [req.session.professor], function(err,rows){
    res.render("./professor/grade_new.ejs", {page: "Grade", professor:req.session.professor,class_dict:rows, grade_info: []});
  });
});



app.post("/user/professor/grade/post",urlencodedPsrser ,function(req,res,next) {
  console.log(req.body);
  
  
  db.query('update professor_exam_file set post_info=2 WHERE account = ? and class_no =? and exam_file=?', [req.session.professor,req.body.postClass, req.body.postExam], function(err,rows){
    if(err) console.log(err);
    else res.redirect('/user/professor/grade');
  });
  
  
});

//----------------------professor_class----------------------//finish//debug OK
app.get("/user/professor/class", auth_professor, function(req, res){  
  db.query('SELECT * FROM professor_exam_info where account = ?', [req.session.professor],function(err,rows,fields){
    res.render("./professor/class.ejs", {page:"Class", professor:req.session.professor,datalist:rows});
  });
});

//debug OK
app.post("/user/professor/class/edit",urlencodedPsrser ,function(req,res,next) {
  db.query('UPDATE professor_exam_info set class_name = ?  WHERE class_no = ?', [req.body.class_name,req.body.class_no], function (err,rows){
    if(err||rows[0==null])
      console.log(err);
    else{
      console.log('action: edit the class '+req.body.class_no+' --> Success');
    }
  });
});

app.post("/testAjax",urlencodedPsrser ,async function(req,res,next) {
  var studentId = req.body.studentId.split('+');
  const tempData = {
    account:req.body.account,
    class_no:req.body.class_no,
    class_name:req.body.class_name,
    exam_info:0,
  }
  try {
    let existingAccountsRow = await promisifiedQuery('SELECT account FROM user_account_info WHERE account IN (?)', [studentId]);
    const existingAccounts = existingAccountsRow.map((result) => result.account);
    const missingAccounts = studentId.filter((number) => !existingAccounts.includes(number));
    console.log('存在於資料庫的學號:', existingAccounts);
    console.log('不存在於資料庫的學號:', missingAccounts);
    const dataToInsert = missingAccounts.map((number) => {
      const account = number;
      const password = encryption(number).substring(0, 10);
      const email = 's'+number+'@mail.yzu.edu.tw';
      const fgt_time = null;
      const authority = 0;
      
      // have to test
      var options = {
        from: 'from140.138.144.152@gmail.com',//寄件者    
        to: email, //收件者
        subject: '這是題庫系統發送的信件', // Subject line//主旨
        text: 'your password is: '+ password, //純文字
      };
      transporter.sendMail(options, function(error, info){
        if(error) console.log(error);
        else console.log('訊息已經發送,'+ email + ' 請至email查看。'); 
      });
      //
      
      return [account, password, email, fgt_time, authority];
    });
    if (missingAccounts.length != 0)
      await promisifiedQuery('INSERT INTO user_account_info (account, password, email, fgt_time, authority) VALUES ?', [dataToInsert]);
    await promisifiedQuery('INSERT INTO professor_exam_info SET ?', [tempData]);
    const classInfoResult = await promisifiedQuery('SELECT class_no, student_num FROM student_class_info order by student_num DESC');
    var add_length = "";
    var student_list = "";
 
    if(classInfoResult.length == 0 || classInfoResult[0].student_num < studentId.length){
      //console.log("student_class_info add column", classInfoResult[0].student_num, studentId.length);
      const low = classInfoResult[0].student_num;
      const high = studentId.length;
      for (var i = 0; i < high; i++){
        if(i >= low){
          add_length+='ADD student'+ (i + 1) +' VARCHAR(255)';
          if(i != high-1)
            add_length+=', ';
        }
        if(i != 0)
          student_list+=", ";
        student_list+='student'+ (i + 1)+' = "'+ studentId[i]+'" ';
      }  
    }
    else {
      const high = studentId.length;
      for (var i = 0; i < high; i++){
        add_length+='ADD student'+ (i + 1) +' VARCHAR(255)';
        if(i != high-1)
          add_length+=', ';
        if(i != 0)
          student_list+=", ";
        student_list+='student'+ (i + 1)+' = "'+ studentId[i]+'" ';
      }
    }
    await promisifiedQuery('ALTER TABLE student_class_info '+add_length);
    await promisifiedQuery('INSERT INTO student_class_info SET class_no = "'+req.body.class_no+'", student_num = '+studentId.length+', '+student_list);
  } catch (err) {
    console.log(err);
  }
});

//debug OK
app.post("/user/professor/class/delete",urlencodedPsrser , async function(req,res,next) {

  const classExamInfo = await promisifiedQuery('SELECT * FROM professor_exam_file where class_no = ?', [req.body.class_no]);
  console.log(classExamInfo);
  const classExamInfoSql = classExamInfo.map((result) => req.body.class_no+"_"+result.exam_file).join(', ');
  console.log(classExamInfoSql);
  if (classExamInfoSql) {
    try {
      await promisifiedQuery('DROP table ' + classExamInfoSql);
      console.log("delete all of the table about the exam of this class success");
    } catch(err) {
      console.log("delete all of the table about the exam of this class failed" + err);
    }
  }
  let max_student_num = await promisifiedQuery('SELECT MAX(student_num) as max FROM student_class_info WHERE class_no != "'+req.body.class_no+'" AND student_num >= (SELECT student_num FROM student_class_info WHERE class_no = "'+req.body.class_no+'") UNION ALL SELECT student_num FROM student_class_info WHERE class_no = "'+req.body.class_no+'"');
  try {
    await promisifiedQuery('DELETE FROM student_class_info WHERE class_no = ?', [req.body.class_no]);
    console.log("delete the table about students in this class success");
  } catch(err) {
    console.log("delete the table about students in this class failed: " + err);
  }
  
  if(!max_student_num[0]['max']){
    try {
      let new_max_student_num = await promisifiedQuery('SELECT MAX(student_num) as max FROM student_class_info');
      new_max_student_num = new_max_student_num[0]['max'] + 1;
      var sciDropSql = "ALTER TABLE student_class_info ";
      for(new_max_student_num; new_max_student_num <= max_student_num[1]['max']; new_max_student_num++) {
        sciDropSql += 'DROP student' + new_max_student_num;
        if(new_max_student_num != max_student_num[1]['max']) 
          sciDropSql += ', ';
      }
      await promisifiedQuery(sciDropSql);
      await promisifiedQuery('DELETE FROM professor_exam_file WHERE class_no = ?', [req.body.class_no]);
      await promisifiedQuery('DELETE FROM professor_exam_info WHERE class_no = ?', [req.body.class_no]);
       
      console.log("delete the table about students in this class success");
    } catch(err) {
      console.log("delete the table about students in this class failed: " + err);
    }
  } 
/*
  
  db.query('DELETE FROM professor_exam_file WHERE class_no = ?', [req.body.class_no], function (err,rows){
    if(err||rows[0==null])
      console.log(err);
    else{
      console.log('action: delete the class '+req.body.class_no+' --> Success');
    }
  });
  db.query('DELETE FROM professor_exam_info WHERE class_no = ?', [req.body.class_no], function (err,rows){
    if(err||rows[0==null])
      console.log(err);
    else{
      console.log('action: delete the class '+req.body.class_no+' --> Success');
    }
  });
  */
});

app.get("/user/professor/student", auth_professor,  function(req, res){
   db.query('SELECT class_no, class_name FROM professor_exam_info WHERE account = ? ', [req.session.professor], function(err,rows){
     res.render("./professor/student.ejs", {page: "Student", professor:req.session.professor, class_list:rows});
   });
});

//----------------------professor_admin----------------------//finish//debug OK
app.get("/user/professor/admin", auth_professor, function(req, res){
  db.query('SELECT * FROM professor_exam_file WHERE account = ?', [req.session.professor], function(err,rows){
    db.query('SELECT * FROM student_class_info', function(err1,rows1){
      db.query('SELECT * FROM user_account_info', function(err2,rows2){
        db.query('SELECT class_no FROM professor_exam_info WHERE account = ? ', [req.session.professor], function(err3,rows3){
          var class_list=[];
          for(var i =0;i<rows3.length;i++){
            class_list.push(rows3[i].class_no);
          }
          res.render("./professor/admin.ejs", {page: "Admin", professor:req.session.professor, datalist:rows, user_info:rows2, user:rows1,class_list:class_list });
        });
      });
    });
  });
});

//debug OK
app.post("/user/professor/admin/create",urlencodedPsrser ,function(req,res,next) {
  console.log(req.body);
  const userData = {
    account: req.body.accountSend,
    password: req.body.passwordSend,
    email: req.body.addressSend,//encryption(req.body.txtUserPwd),
    fgt_time:null,
    authority : req.body.authoritySend,
  }
  db.query('INSERT INTO user_account_info SET ?', [userData], function (err,rows){
    if(!err)
      console.log(userData.account+" newed success");
    else
      console.log(err);
  });
});

//debug OK
app.post("/user/professor/admin/edit",urlencodedPsrser ,function(req,res,next) {
  console.log(req.body);
  const userData = {
    account: req.body.accountSend,
    password: req.body.passwordSend,
    email: req.body.addressSend,//encryption(req.body.txtUserPwd),
    fgt_time:null,
    authority : req.body.authoritySend,
  }
  db.query('UPDATE user_account_info set ? WHERE account = ?', [userData,req.body.accountSend], function (err,rows){
    if(err||rows[0==null])
      console.log(err);
    else{
      console.log('edit '+req.body.accountSend+' information success');
    }
  });
});

//----------------------professor_profile----------------------//finish
app.get("/user/professor/profile", auth_professor, function(req, res){
  db.query('SELECT * FROM user_account_info WHERE account = ?', [req.session.professor], function(err,rows){
    res.render("./professor/profile.ejs", {page: "Profile", professor:req.session.professor, datalist:rows});
  });
});

//----------------------professor_change_password----------------------//finish
app.get("/user/professor/change_password", auth_professor, function(req, res){
  db.query('SELECT * FROM user_account_info WHERE account = ?', [req.session.professor], function(err,rows){
    res.render("./professor/change_password.ejs", {page: "Change password", professor:req.session.professor, datalist:rows});
  });
});

//debug OK
app.post("/user/professor/change_password/change",urlencodedPsrser ,function(req,res,next) {
  //console.log(req.body);
  db.query('UPDATE user_account_info set password =? WHERE account = ?', [req.body.Newpwd,req.session.professor], function(err,rows){
  });
});

//----------------------professor_exam_invigilation----------------------
app.get("/user/professor/invigilation", auth_professor, function(req, res){
  db.query('SELECT * FROM professor_exam_info WHERE account = ? ', [req.session.professor], function(err,rows){
    //res.render("./professor/invigilation_major.ejs", {page: "Exam invigilation", professor:req.session.professor, datalist:rows});
    res.render("./professor/invigilation.ejs", {page: "Exam invigilation", professor:req.session.professor, datalist:rows});
  });
});

app.get("/testFinish", function(req, res){
  db.query('SELECT * FROM professor_exam_info WHERE account = ? ', ["CS233A"], function(err,rows){
    
    res.render("./professor/invigilation_testFInish.ejs", {page: "Exam invigilation", professor:req.session.professor, datalist:rows});
  });
});


app.post("/user/professor/invigilation/condition",urlencodedPsrser ,function(req,res,next) {
  console.log(req.body);
  //1111111111111
  req.session.target_class =  req.body.target_class_no;
  req.session.target_exam =  req.body.target_exam_file;
  res.redirect("/user/professor/invigilation/"+req.session.target_class+"_"+req.session.target_exam);
});

app.get("/user/professor/invigilation/*_*", auth_professor, auth_target_class, auth_target_exam, function(req, res){
  console.log("HEHE");
  db.query('SELECT * FROM professor_exam_info WHERE account = ? ', [req.session.professor], function(err,rows){
    db.query('SELECT * FROM '+req.session.target_class+'_'+req.session.target_exam, function(err1,rows1){
      res.render("./professor/invigilation_minor.ejs", {page: "Exam invigilation", professor: req.session.professor, datalist: rows, student_info: rows1, class_no: req.session.target_class, exam_file: req.session.target_exam});
    });
  });
})

//-------------------google_form-------------------

app.post('/get_url_from_google',urlencodedPsrser ,function(req,res,next){
	var sID = req.body.sID;
	var folder_name = req.body.folder_name;
	var url = req.body.url;
	var question_num;
	console.log(sID);
	console.log(folder_name);
	console.log(url);
	(async ()=> {
		try {
			const rows = await promisifiedQuery('SELECT question_number FROM '+folder_name+' where sID =?',[sID]);
			question_num =rows[0]["question_number"];
			url = url.split(";");
			await promisifiedQuery('UPDATE '+folder_name+' SET form_finish =? where sID =?',["yes",sID]);
			console.log("form_finish success set");
			for(var i=0;i<question_num;i++){
				await promisifiedQuery('UPDATE '+folder_name+' SET question_'+(i+1)+' =? where sID =?',[url[i],sID]);
				console.log("question"+(i+1)+" success set");
			} 
			io.emit('finish_create',{sID:sID,folder_name:folder_name});
			res.send("finish");
		}
		/*db.query('UPDATE '+folder_name+' SET question_'+(i+1)+' =? where sID =?',[url[i],sID],function(err,rows){
		});
		sleep(500)*/
		catch (err) {
			console.log(err);
		}
	})()
	/*db.query('SELECT question_number FROM '+folder_name+' where sID =?',[sID],function(err,rows){
		question_num =rows[0]["question_number"];
	});
	sleep(100)
	console.log(question_num)
	url = url.split(";")
	db.query('UPDATE '+folder_name+' SET form_finish =? where sID =?',["yes",sID],function(err,rows){
			console.log("form_finish success set")
	});
	for(var i=0;i<question_num;i++){
		async function update_folder_name() {
			try {
				const rows = await promisifiedQuery('UPDATE '+folder_name+' SET question_'+(i+1)+' =? where sID =?',[url[i],sID]);
			} 
			catch (err) {
				console.log(err);
			}
		}
		update_folder_name();
		/*db.query('UPDATE '+folder_name+' SET question_'+(i+1)+' =? where sID =?',[url[i],sID],function(err,rows){
		});
		sleep(500)
		console.log("question"+(i+1)+" success set");
	}
	io.emit('finish_create',{sID:sID,folder_name:folder_name});
	res.send("finish");*/
});
app.post('/send_id_to_google',urlencodedPsrser ,function(req,res,next) { 
 db.query('SELECT account FROM student_exam',function(err,rows,fields){
  res.send(rows);
  console.log('success send id');
 });
});
app.post('/get_id_from_google',urlencodedPsrser ,function(req,res,next){ //no use
	console.log('ID:'+req.body.sID+"----------");
 console.log('folder_name:'+req.body.folder_name+"----------");
 res.send("success send id to html!");
	var student_id = req.body.sID;
 var question_type_size=req.body.send_question.split(";");
 var question_url = req.body.url.split(';');
 var table_name = req.body.folder_name;
 console.log(question_type_size);
 console.log(question_url);
 (async ()=> {
		try {
			await promisifiedQuery('INSERT INTO '+ table_name +' SET ?', [{"sID":student_id, "question_number":question_type_size.length, "cheat_times":0}]);
		} 
		catch (err) {
			console.log(err);
		}
	})()
 /*db.query('INSERT INTO '+ table_name +' SET ?', [{"sID":student_id, "question_number":question_type_size.length, "cheat_times":0}], function (err,result){
      if(err) console.log(err);
		});s
	sleep(100);*/
 for(var i=1;i<question_url.length;i++){
 	if(i==1){
	   db.query('UPDATE '+table_name+' SET question'+i+ '=? WHERE sID = ?', [question_type_size[i-1]+";"+question_url[i], student_id], function (err1,rows1){
	       if(err1)
	       	   console.log(err1);
	    });
    }
   }
});
app.post('/get_grade_from_google',urlencodedPsrser ,function(req,res,next) { 
 console.log('ID:'+req.body.sID);
 console.log('grade:'+req.body.grade);
 console.log('folder_name:'+req.body.folder_name);
 res.send("success sned grade to html!");
 const userData ={
 account: req.body.sID,
 exam_grade : req.body.grade
 }
 db.query('UPDATE '+req.body.folder_name +' SET point =? WHERE sID = ?', [req.body.grade, req.body.sID], function (err,rows){
 if(err)
    console.log('update '+ req.body.sID+' grade error');
 else
    console.log('update '+ req.body.sID+' grade success');
 });
});

//-----------------student_page----------------------
//-----------------student_exam----------------------
app.get("/user/student", auth_student, function(req, res){
	(async ()=> {
		try {
			const exam_info = await promisifiedQuery('SELECT exam_file, class_name FROM professor_exam_info WHERE class_no = ?',[req.session.class_no]);
			if(exam_info){
				res.render("./student/index.ejs", {page: "Exam", student:req.session.student, class_no: req.session.class_no, class_name: exam_info[0].class_name, exam_file: exam_info[0]["exam_file"], mes:-1});
		  }
		  else{
		    res.render("./user_action/index_student.ejs", {log_fail:'登入網址錯誤。',fgt_success:'',fgt_fail:''});
		  }
		} 
		catch (err) {
			console.log(err);
			res.render("./user_action/index_student.ejs", {log_fail:'登入網址錯誤。',fgt_success:'',fgt_fail:''});
		}
	})()
});

app.post('/user/student/exam/get_papper',urlencodedPsrser ,function(req,res,next) { 
  console.log(req.body);
  db.query('SELECT exam_file FROM professor_exam_info where class_no = ? and exam_info = ?', [req.body.class_no, 1], function(err,rows){
    if(rows.length==0){
      db.query('SELECT * FROM student_class_info',  function(err1,rows1){
        var result_class_no=[];
        for(var i=0;i<rows1.length;i++){
          if(Object.values(rows1[i]).includes(req.session.student)){
            result_class_no.push(rows1[i].class_no);
          }
        }
        res.render("./student/index.ejs", {page: "Exam", student:req.session.student, datalist:result_class_no, mes:0});
      });
    }
    else{
      var table_name = req.body.class_no+"_"+rows[0].exam_file;
      db.query('SELECT * FROM '+table_name+' where sID = ?', [req.session.student],  function(err1,information){
      var url=[];
      var type=[];
      var size=[];
      for(var i=0;i<=information[0]['question_number'];i++){
      	var str = information[0]["question"+i];
      	if(i==0){
      	  url.push(information[0]['question_all']);
      	}
      	else{
      	url.push(str);
      	}
      }
      res.render("./student/test_form.ejs", {page: "form", student:req.session.student, class_no:req.body.class_no, exam_file:rows[0].exam_file, form_url: url , mes:1});
      });  
    }
  });
});

//-----------------student_grade----------------------
app.get("/user/student/grade", auth_student, function(req, res){
	(async ()=> {
		try {
			const rows = await promisifiedQuery('SELECT * FROM student_class_info');
			const rows1 = await promisifiedQuery('SELECT * FROM professor_exam_info');
			var result_class_no=[];
      for(var i=0;i<rows.length;i++){
        if(Object.values(rows[i]).includes(req.session.student)){
          const index = rows1.findIndex(item => item.class_no = rows[i].class_no);
          result_class_no.push(rows[i].class_no+" "+rows1[index].class_name);
        }
      }
      res.render("./student/grade.ejs", {page: "Grade", student:req.session.student, datalist:result_class_no, grade_info:[]});
		}
		catch(err){
			console.log(err);
		}
	})()
  /*db.query('SELECT * FROM student_class_info',  function(err,rows){
    db.query('SELECT * FROM professor_exam_info',  function(err1,rows1){
      var result_class_no=[];
      for(var i=0;i<rows.length;i++){
        if(Object.values(rows[i]).includes(req.session.student)){
          const index = rows1.findIndex(item => item.class_no = rows[i].class_no);
          result_class_no.push(rows[i].class_no+" "+rows1[index].class_name);
        }
      }
      res.render("./student/grade.ejs", {page: "Grade", student:req.session.student, datalist:result_class_no, grade_info:[]});
    });
  });*/
});


//-----------------student_get_form------------------
app.post('/user/student/go_to_form',urlencodedPsrser ,function(req,res,next) {
	var info;
	var check_get;
	var answer_info;
	var answer ="";
	(async ()=> {
		try {
			const rows = await promisifiedQuery('SELECT get_form FROM '+req.body.folder_name+' where sID = ?',[req.body.sID]);
			check_get = rows[0]["get_form"];
			console.log(check_get)
			if(!check_get){
				await promisifiedQuery('update '+ req.body.folder_name +' set get_form ="1" where sID = ?',[req.body.sID]);
				const rows = await promisifiedQuery('SELECT * FROM '+req.body.folder_name+' where sID = ?',[req.body.sID]);
				info = rows[0];
				const rows2 = await promisifiedQuery('SELECT * FROM '+req.body.folder_name+'_答案 '+' where sID = ?',[req.body.sID]);
				answer_info = rows2[0];
				var url ="";
				var num = info['question_number'];
				for(var i=1;i<=num;i++){
					url+=info['question_'+i];
					if(!answer_info['question_'+i]){
						answer+="null";
					}
					else{
						answer+=answer_info['question_'+i];
					}
					if(i!=num){
						url+=";";
						answer+="!!!";
					}
				}
				console.log(url);
				console.log(answer);
				req.session.exam_file = info['exam_file'];
				req.session.form_url = url;
				req.session.class_no = info['class_no'];
				req.session.answer = answer;
				res.send([1]);
			}
			else{
				res.send([0]);
			}
		} 
		catch (err) {
			console.log(err);
		}
	})()
	/*db.query('SELECT get_form FROM '+req.body.folder_name+' where sID = ?',[req.body.sID],function(err,rows){
		check_get = rows[0]["get_form"];
	});
	sleep(400);
	console.log(check_get)
	if(!check_get){
		async ()=> {
			try {
				await promisifiedQuery('update '+ req.body.folder_name +' set get_form ="1" where sID = ?',[req.body.sID]);
				const rows = await promisifiedQuery('SELECT * FROM '+req.body.folder_name+' where sID = ?',[req.body.sID]);
				info = rows[0];
				const rows2 = await promisifiedQuery('SELECT * FROM '+req.body.folder_name+'_答案 '+' where sID = ?',[req.body.sID]);
				answer_info = rows2[0];
				var url ="";
				var num = info['question_number'];
				for(var i=1;i<=num;i++){
					url+=info['question_'+i];
					if(!answer_info['question_'+i]){
						answer+="null";
					}
					else{
						answer+=answer_info['question_'+i];
					}
					if(i!=num){
						url+=";";
						answer+="!!!";
					}
				}
				console.log(url);
				console.log(answer);
				req.session.exam_file = info['exam_file'];
				req.session.form_url = url;
				req.session.class_no = info['class_no'];
				req.session.answer = answer;
				res.send([1]);
			} 
			catch (err) {
				console.log(err);
			}
		}
		db.query('update '+ req.body.folder_name +' set get_form ="1" where sID = ?',[req.body.sID],function(err,rows){
			if(err){
				console.log(err);
			}
		});
		db.query('SELECT * FROM '+req.body.folder_name+' where sID = ?',[req.body.sID],function(err,rows){
			info = rows[0];
		});
		db.query('SELECT * FROM '+req.body.folder_name+'_答案 '+' where sID = ?',[req.body.sID],function(err,rows){
			answer_info = rows[0];
		});
		sleep(800);
	}
	else{
		res.send([0]);
	}*/
});
app.post('/user/student/check_form',urlencodedPsrser ,function(req,res,next) {
	var info;
	var exam_file;
	(async ()=> {
		try {
			const rows = await promisifiedQuery('SELECT exam_file FROM professor_exam_info where class_no = ?',[req.body.class_no]);
			exam_file = rows[0]['exam_file'];
			const rows2 = await promisifiedQuery('SELECT * FROM '+req.body.class_no+'_'+exam_file+' where sID = ?',[req.body.sID]);
			info = rows2[0];
			console.log(rows2);
			if(info['form_finish']=='yes'){
				res.send([1,info['exam_file']]);
			}
			else{
				res.send([0]);
			}
		} 
		catch (err) {
			console.log(err);
		}
	})()
	/*db.query('SELECT exam_file FROM professor_exam_info where class_no = ?',[req.body.class_no],function(err,rows){
		exam_file = rows[0]['exam_file'];
	});
	sleep(100);
	console.log('SELECT * FROM '+req.body.class_no+'_'+exam_file+' where sID = '+req.body.sID);
	db.query('SELECT * FROM '+req.body.class_no+'_'+exam_file+' where sID = ?',[req.body.sID],function(err,rows){
		info = rows[0];
	});
	sleep(100);*/
});
app.post("/user/student/get_form", urlencodedPsrser, function(req, res ,next){//no use
	var file_name;
	var class_no = req.body.class_no;
	var sID = req.body.student_id;
	var url = "";
	var info;
	//need to fix don't check test time
	(async ()=> {
		try {
			const rows = await promisifiedQuery("select exam_file from professor_exam_info where class_no = ?",[class_no]);
			file_name = rows[0]["exam_file"];
			const rows2 = await promisifiedQuery("select * from "+class_no+"_"+file_name+" where sID = ?",[sID]);
			info = rows2[0];
		} 
		catch (err) {
			console.log(err);
		}
	})()
	db.query("select exam_file from professor_exam_info where class_no = ?",[class_no],function(err,rows){
	 	file_name = rows[0]["exam_file"];
  });
  sleep(100)
  do{
  	db.query("select * from "+class_no+"_"+file_name+" where sID = ?",[sID],function(err,rows){
	 		info = rows[0];
	 	});
	 	sleep(100)
	 	console.log("try to create!")
	}while(info["form_finish"]=="no")
	
	console.log("finish create")
	for(var i=0;i<info["question_number"];i++){
		url+= ";"+info["question_"+(i+1)];
	}
	req.session.exam_file = file_name;
	req.session.form_url = url;
	req.session.class_no = class_no;
  //res.render("./student/test_form.ejs", {page: "form", student:sID, exam_file:file_name, form_url:url}); 
  res.redirect("/user/student/test_form");
});
//-----------------save_answer-----------------------
app.post("/user/student/save_answer", urlencodedPsrser, function(req, res ,next){
	db.query("update "+req.session.class_no+"_"+req.session.exam_file+"_答案  set question_"+req.body.question_num+"=? where sID=?",[req.body.answer,req.session.student],function(err,rows){
		if(err){
			console.log(err)
		}
	});
	res.send("success");
});
//-----------------student_form----------------------
app.get("/user/student/test_form", auth_student, function(req, res){
  /*
  db.query('SELECT * FROM student_class_info',  function(err,rows){
    var result_class_no=[];
    for(var i=0;i<rows.length;i++){
      if(Object.values(rows[i]).includes(req.session.student)){
        console.log(rows[i].class_no);
        result_class_no.push(rows[i].class_no);
      }
    }
    
    res.render("./student/test_form.ejs", {page: "form", student:req.session.student, datalist:result_class_no});
  });
  */
	var answer_info;
	var answer ="";
	(async ()=> {
		try {
			const rows = await promisifiedQuery('SELECT * FROM '+req.session.class_no+"_"+req.session.exam_file+'_答案 '+' where sID = ?',[req.session.student]);
			answer_info = rows[0];
			var num = answer_info['question_number'];
			for(var i=1;i<=num;i++){
				if(!answer_info['question_'+i]){
					answer+="null";
				}
				else{
					answer+=answer_info['question_'+i];
				}
				answer+="!!!";
			}
			req.session.answer = answer;
			res.render("./student/test_form.ejs", {page: "form", student:req.session.student,class_no: req.session.class_no,exam_file:req.session.exam_file,	form_url:req.session.form_url,answer:req.session.answer});
		} 
		catch (err) {
			console.log(err);
		}
	})()
	/*db.query('SELECT * FROM '+req.session.class_no+"_"+req.session.exam_file+'_答案 '+' where sID = ?',[req.session.student],function(err,rows){
		answer_info = rows[0];
	});
	sleep(800);*/
	
  //"NOWNOW"
});
//-----------------student_class----------------------
app.get("/user/student/class", auth_student, function(req, res){
  db.query('SELECT * FROM student_class_info', function(err,rows){
    db.query('SELECT * FROM professor_exam_info', function(err1,rows1){
      var class_list=[];
      for(var i=0;i<rows.length;i++){
        if(Object.values(rows[i]).includes(req.session.student)){
          for(var j=0;j<rows1.length;j++){
            if(rows1[j].class_no==rows[i].class_no){
              var temp_data={
                class_no: rows1[j].class_no,
                class_name: rows1[j].class_name
              };
              class_list.push(temp_data);
            }
          }
        }
      }
      res.render("./student/class.ejs", {page: "Class", student:req.session.student, datalist:class_list});  
    });
  });
});

//-----------------student_profile----------------------//finish
app.get("/user/student/profile", auth_student, function(req, res){
  db.query('SELECT * FROM user_account_info WHERE account = ?', [req.session.student], function(err,rows){
    res.render("./student/profile.ejs", {page: "Profile", student:req.session.student, datalist:rows});
  });
});

//-----------------student__change_password----------------------
app.get("/user/student/change_password", auth_student, function(req, res){
  db.query('SELECT * FROM user_account_info WHERE account = ?', [req.session.student], function(err,rows){
    res.render("./student/change_password.ejs", {page: "Change password", student:req.session.student, datalist:rows});
  });
});

app.post("/user/student/change_password/change",urlencodedPsrser ,function(req,res,next) {
  console.log("student account change password");
  console.log(req.body);
  db.query('UPDATE user_account_info set password = ? WHERE account = ?', [req.body.Newpwd, req.body.account], function(err,rows){
    if(err) console.log(err);
  });
});

//socketIO
app.post('/test_socket',urlencodedPsrser,function(req,res,next){
	io.emit('finish_create',{sID:req.body.sID,folder_name: 'CS233A_測試'});
	res.send("");
});

const students = {};
io.sockets.on('connection', function(socket) {
  socket.on('student-cheat', function(data) {
    db.query('SELECT cheat_times FROM '+data.class_no+'_'+data.exam_file+' where sID = ?', [data.student], function(err,rows){
      db.query('UPDATE '+data.class_no+'_'+data.exam_file+' set cheat_times =? WHERE sID = ?', [rows[0]["cheat_times"]+1,data.student], function(err1,rows1){
        if(err1) console.log(err1);
        else{
          io.sockets.emit('detect-student-cheat',{ 
            class_no: data.class_no,
            exam_file: data.exam_file
          });
        }
      });
    });
  });
  socket.on('student_finish_test',function(data){
  	io.sockets.emit('change_status',{ 
			class_no: data.class_no,
			exam_file: data.exam_file,
			student:data.student,
    });
  });
  socket.on('on', function(data) {
  	console.log(data);
  });
  socket.on('off', function(data) {
  	console.log(data);
  });
  socket.on('double_off', function(data) {
  	console.log(data);
  });
  socket.on('generate-class-qrcode', function(data) { 
    const token =jwt.sign({data,exp: Math.floor(Date.now()/1000)+(60*15)},'my_scecret_key').substring(0,10);  
    const url = "https://140.138.144.121:1447/"+data.professor+"___"+token+"/index";
    qrcode.toDataURL(url, (err, qrCodeData) => {
      if (err) {
        console.error(err);
      } else {
        db.query('UPDATE professor_exam_info SET qrcode = ? WHERE account = ? AND class_no = ?', [token, data.professor, data.class_no], function(err1,rows1){});
        socket.emit('show-class-qrcode', {
          qrCodeData: qrCodeData,
          class_no: data.class_no,
          professor: data.professor,
        });
      }
    });
  });
  socket.on('professor-show-student', function(data) {   
    db.query('SELECT student_num FROM student_class_info where class_no = ?' , [data.class_no], function(err,rows){
      if (rows.length == 0 || rows[0].student_num < 1)
        socket.emit('professor-student-update', {
          rows: data.professor,
          class_no: data.class_no,
          student_account: [],
        });
    
      var str = "SELECT ans.account, ans.password, ans.email FROM( ";
      for (var i = 0; i < rows[0].student_num; i++) {
        if (i != 0)
          str += " UNION ALL ";
        str += "SELECT uai.account, uai.password, uai.email FROM student_class_info sci JOIN user_account_info uai ON sci.student" + (i+1).toString() + " = uai.account WHERE sci.class_no = '" + data.class_no + "'";
      }
      str += ") AS ans ORDER BY ans.account" ;
      db.query(str, function(err1,rows1){
        socket.emit('professor-student-update', {
          professor: data.professor,
          class_no: data.class_no,
          student_account: rows1,
        });
      });
    });
  });
  socket.on('show-cheat-status', function(data) { 
  	console.log("get change");
    var tableName = data.class_no+'_'+data.exam_file;
    db.query('SELECT sID, cheat_times, get_form, exam_finish FROM '+data.class_no+'_'+data.exam_file+' ORDER BY sID ASC', function(err,rows){
      if(err) console.log(err);
      else{
        io.sockets.emit('update-cheat-status', {
          rows: rows,
          class_no: data.class_no,
          exam_file: data.exam_file,
        });
      }
    });
  });
  socket.on('student-show-grade', function(data) {
    db.query('SELECT * FROM professor_exam_file WHERE class_no = ?', [data.class_no], function(err,rows){
      if (err) console.log(err);
      
      if (rows.length > 0){
        var temp_str="";     
        for( var i=0; i<rows.length; i++){
          var temp_table=rows[i].class_no+"_"+rows[i].exam_file;
          if(i!=0)
            temp_str+=" union ";
          temp_str+="select class_no, exam_file, point, cheat_times from "+temp_table+' where sID = "'+data.student+'"';
        }
        temp_str = "select table1.exam_file, table1.point, table1.cheat_times, professor_exam_file.post_info from ( "+temp_str+" ) as table1 JOIN professor_exam_file on table1.exam_file = professor_exam_file.exam_file and table1.class_no = professor_exam_file.class_no";
        
        db.query(temp_str, function(err1,rows1){
          if(err1) console.log(err1);
          else {
            socket.emit('student-grade-update', {
              student: data.student,
              grade_info: rows1,
            });
          }
        });
      }
      else{
        socket.emit('student-grade-update', {
          student: data.student,
          grade_info: [],
        });
      }
    });
  });
  socket.on('professor-show-grade', function(data) {
		(async ()=> {
			try {
				var rows = await promisifiedQuery('SELECT * FROM professor_exam_file WHERE class_no = ?', [data.class_no]);
				if(rows.length > 0){
        var examInfo = [];
        var temp1 = "SELECT t1.sID, ";
        var temp2 = " FROM ("      
        for (var i = 0; i < rows.length; i++){
          const tempData = {
            exam_file: rows[i].exam_file,
            post_Info: rows[i].post_info,
          };
          examInfo.push(tempData);
          if (i != 0) { 
            temp1 += ", ";
            temp2 += " union ";
          }
          
          
          temp1 += "MAX(CASE WHEN t1.exam_file = '" + tempData.exam_file + "' THEN t1.point ELSE NULL END) AS Grade" +tempData.exam_file;
          temp1 += ", MAX(CASE WHEN t1.exam_file = '" + tempData.exam_file + "' THEN t1.cheat_times ELSE NULL END) AS Cheat" +tempData.exam_file; 
          if (i == rows.length-1) temp1 += " ";
          temp2 += "select exam_file,sID, point, cheat_times from "+data.class_no+"_" + tempData.exam_file + "";
		    }
        temp2 += ") AS t1 GROUP BY t1.sID ORDER BY sID DESC;"
        var rows1 = await promisifiedQuery(temp1+temp2);
		    socket.emit('professor-grade-update', {
		          professor: data.professor,
		          examInfo: examInfo,
		          gradeInfo: rows1,            
		      });
		   }
		   else{
					socket.emit('professor-grade-update', {
		        professor: data.professor,
		        examInfo: [],
		        gradeInfo: [],            
		      });
		    }
			} 
			catch (err) {
				console.log(err);
			}
		})()  
  });
});

app.use((req, res) => {
  res.status(404).send("404-Not Found");
});
