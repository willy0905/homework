<?php
require_once('/home/s1091436/public_html/HW2/TCPDF/tcpdf_import.php');
$mail = $_POST['mail'];
$name = $_POST['usename'];
#gender =$_POST['gender'];
$phone = $_POST['phone'];
$snumber = $_POST['snumber'];
$yourid = $_POST['yourid'];
$shoe1 = $_POST['rating1'];
$shoe2 = $_POST['rating2'];
$shoe3 = $_POST['rating3'];
$shoe4 = $_POST['rating4'];
$shoe5 = $_POST['rating5'];
$shoe6 = $_POST['rating6'];
$shoe7 = $_POST['rating7'];
$shoe8 = $_POST['rating8'];
$shoe9 = $_POST['rating9'];
$shoe10= $_POST['rating10'];
$shoe11= $_POST['rating11'];
$shoe12= $_POST['rating12'];
$sum= 0;
  $sum=($shoe1*599)+($shoe2*699)+($shoe3*580)+($shoe4*599)+($shoe5*580)+($shoe6*580)+($shoe7*750)+($shoe8*580)+($shoe9*580)+($shoe10*580)+($shoe11*580)+($shoe12*618);
  
  
include "phpqrcode.php";
QRcode::png('http://140.138.152.215/~s1091436/HW2/PDF/'.$name.'pdf','QRCODE/QRCODE.png'); 
$QR = "QRCODE.phg";
imagepng($QR);

/*---------------- Sent Mail Start -----------------*/
mb_internal_encoding("utf-8");
$to="$mail";
$subject=mb_encode_mimeheader("shopping list","utf-8");
$message="
電子郵件 : $mail
姓名 : $name
身分證 : $yourid
電話 : $phone
s學號 : $snumber
總金額 : $sum
";
$headers="MIME-Version: 1.0\r\n";
$headers.=" Content-type: text/html; charsert =utf-8\r\n";
#headers.="From:".mb_encode_mimeheader("Shopping List",utf-8)."<s1091436@mail.yzu.edu.tw>\r\n";
mail($to,$subject,$message,$headers);
/*---------------- Sent Mail End -------------------*/
/*---------------- Print PDF Start -----------------*/
$pdf = new TCPDF(PDF_PAGE_ORIENTATION, PDF_UNIT, PDF_PAGE_FORMAT, true, 'UTF-8', false);
$pdf->setPrintHeader(false);
$pdf->setPrintFooter(false);
$pdf->SetFont('cid0jp','', 18); 
$pdf->AddPage();

$html = <<<EOF
<table border ="1">
<tr>
	<td>姓名:$name</td>
	<td>Email:$mail</td>
</tr>
<tr>
  <td>電話:$phone</td>
  <td>s學號:$snumber</td>
</tr>
<tr>
  <td style="color:red">總金額:$sum</td>
</tr>
<br/>
<img src="QRCODE/QRCODE.png">
</table>

EOF;
/*---------------- Print PDF End -------------------*/

$pdf->writeHTML($html);
$pdf->lastPage();
$pdf->Output('/home/s1091436/public_html/HW2/PDF/'.$name.'.pdf','FI');
?>
