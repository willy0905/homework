const config = require('../public/js/config.js');
const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'root',
  password: '10914361447',
  database:'itemBank_db'
});

connection.getConnection(function(err) {
  if (err)
    console.log("Connect mysql Error");
  else
    console.log("Connect mysql Success");
});
module.exports = connection;
