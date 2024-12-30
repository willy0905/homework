'use strict';
let socket = io.connect();

var student = document.getElementById('studentItems').innerHTML;
var class_no = document.getElementById('classItems').innerHTML;
var exam = document.getElementById('examItems').innerHTML;
alert(student);

document.onvisibilitychange = function() {
  if(document.visibilityState === "visible"){
    console.log("cheat");
    socket.emit('student-cheat',{
      student: student,
      class_no: class_no,
      exam_file:exam
    });
  }
};
