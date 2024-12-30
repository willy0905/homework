'use strict';
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
//middlewares
app.use(express.static('public'));
app.use(bodyParser.json());
var urlencodedPsrser = bodyParser.urlencoded({ extended: false });

app.use(session({
  secret: 'mySecret',
  name: 'user', // optional
  saveUninitialized: false,
  resave: true, 
}));

const sslServer = https.createServer( 
   {
      key: fs.readFileSync(path.join(__dirname,'cert','key.pem')),
      cert:fs.readFileSync(path.join(__dirname,'cert','cert.pem'))

   },app
)
sslServer.listen(process.env.PORT || 1436);

//-------------------register----------------
app.get("/reg", function(req, res){
  res.render("./user_action/register.ejs", {reg_success:'',reg_fail:'',reg_user:'student'});
});
app.get("/reg/proreg", function(req, res){
  res.render("./user_action/register.ejs", {reg_success:'',reg_fail:'',reg_user:'professor'});
});

app.post("/reg",urlencodedPsrser ,function(req,res) {
  console.log(req.body);
  if(req.body.reg_password!=req.body.reg_confirm_password){
    console.log(req.body.reg_account+" 註冊失敗, 輸入的兩個密碼並不相符。")
    res.render("./user_action/register.ejs", {reg_success:'',reg_fail:'輸入的兩個密碼並不相符，請再試一次',reg_user:"student"});
  }
  else{
    const userData = {
      account: req.body.reg_account,      
      password: req.body.reg_password,//encryption(req.body.txtUserPwd),
      email: req.body.reg_email,
      fgt_time: null,
      authority : 0,
    }
    db.query('INSERT INTO user_account_info SET ?', [userData], function (err,rows){
      if(err){
        console.log(err);
        // console.log(req.body.reg_account+" 註冊失敗, 已經有重複帳號或Eamil。")
        res.render("./user_action/register.ejs", {reg_success:'',reg_fail:'已經有重複帳號或Eamil',reg_user:"student"});
      }
      else{
        console.log(req.body.reg_account+" 註冊成功。")
        res.render("./user_action/register.ejs", {reg_success:'歡迎 '+ req.body.reg_account ,reg_fail:'',reg_user:"student"});
      }
    });
  }
});
app.post("/reg/proreg",urlencodedPsrser ,function(req,res) {
  //console.log("professor");
  if(req.body.reg_password!=req.body.reg_confirm_password){
    console.log(req.body.reg_account+" 註冊失敗, 輸入的兩個密碼並不相符。")
    res.render("./user_action/register.ejs", {reg_success:'',reg_fail:'輸入的兩個密碼並不相符，請再試一次',reg_user:'professor'});
  }
  else{
    const userData = {
      account: req.body.reg_account,
      email: req.body.reg_email,
      password: req.body.reg_password,//encryption(req.body.txtUserPwd),
      authority : 1,
      fgt_time: null,
    }
    db.query('INSERT INTO user_account_info SET ?', [userData], function (err,rows){
      if(err){
         console.log(req.body.reg_account+" 註冊失敗, 已經有重複帳號或Eamil。")
         res.render("./user_action/register.ejs", {reg_success:'',reg_fail:'已經有重複帳號或Eamil',reg_user:'professor'});
      }
      else{
        console.log(req.body.reg_account+" 註冊成功。")
        res.render("./user_action/register.ejs", {reg_success:'歡迎 '+ req.body.reg_account ,reg_fail:'',reg_user:'professor'});
      }
    });
  }
});
