<?php
require_once('TCPDF/tcpdf_import.php');
$pdf = new TCPDF(PDF_PAGE_ORIENTATION, PDF_UNIT, PDF_PAGE_FORMAT, true, 'UTF-8', false);
$pdf->setPrintHeader(false);
$pdf->setPrintFooter(false);
$pdf->SetFont('cid0jp','', 18); 
$pdf->AddPage();

/*---------------- Your Code Start -----------------*/
$style = array(
    'position' => '',
    'align' => 'C',
    'stretch' => false,
    'fitwidth' => true,
    'cellfitalign' => '',
    'border' => true,
    'hpadding' => 'auto',
    'vpadding' => 'auto',
    'fgcolor' => array(0,0,0),
    'bgcolor' => false, 
    'text' => true,
    'font' => 'helvetica',
    'fontsize' => 8,
    'stretchtext' => 4,
);
$input1 = $_POST['order'];
$input2 = $_POST['name'];
$input3 = $_POST['tel'];
$input4 = $_POST['email'];
$input5 = $_POST['address'];
$n1 = $_POST['n1'];
$n2 = $_POST['n2'];
$n3 = $_POST['n3'];
$n4 = $_POST['n4'];
$num =[0,$n1,$n2,$n3,$n4];
$dollar =[0,399,299,409,499];
$name=["","8塊雞感恩桶餐","椒香麻辣脆雞雙人分享餐","派對B餐6塊雞桶","開燻雙拼餐"];
$total= 0;
$n=0;
$sel=0;
$str =0;
if(isset($input1))
{
    $n = count($input1)-1;
    for($i=0; $i < $n; $i++)
    {
		$sel = $input1[$i]
		$total = $total+$num[$sel]*$dollar[$sel]
		$str = $str."<tr> <td> <img src= menu".$sel.".jpg>".$name[$sel]."</td><td>".$num[$sel]."</td><td>".$dollar[$sel]."</td><td>".$num[$sel]*$dollar[$sel]."</td></tr>";
    }
}
else
{
	$order="請確認餐點";
}

$pdf->Text(160, 20, '訂單號碼');
$pdf->Ln();
$pdf->write1DBarcode('1234567', 'S25', '150', '', '', 18, 0.4, $style, 'N');
$pdf->Ln();

$html = <<<EOF
		<table border="1">
			<tr>
				<td>訂購人:</td>
				<td>$input2</td>
				<td>電話:</td>
				<td>$input3</td>
			</tr>
			<tr>
				<td>Email:</td>
				<td colspan="2">$input4</td>
			</tr>   
			<tr>
				<td>地址:</td>
				<td colspan="2" >$input5</td>
			</tr>
			<tr>
				<td colspan="3" style="color=red;text-align=center">訂購餐點</td>
			</tr>
			<tr>
				<td>餐點名稱</td>
				<td>數量</td>
				<td>單價</td>
				<td>總計</td>
			</tr>
				$str
			<tr>
				<td>總金額:</td>
				<td colspan="3" style="text-align:center;color:red">$total 元</td>

			</td>
		</table>
EOF;
/*---------------- Your Code End -------------------*/

$pdf->writeHTML($html);
$pdf->lastPage();
$pdf->Output('order.pdf', 'I');
