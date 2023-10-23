<!DOCTYPE HTML>

<html lang="zh-tw">

<?php
include 'ChromePhp.php';
ChromePhp::log('Hello console!');
function console_log($data)
{
    echo '<script>';
    echo 'console.log(' . json_encode($data) . ')';
    echo '</script>';
}
// Import PHPMailer classes into the global namespace
// These must be at the top of your script, not inside a function
use PHPMailer\PHPMailer\PHPMailer;
use PHPMailer\PHPMailer\Exception;

require './PHPMailer/src/Exception.php';
require './PHPMailer/src/PHPMailer.php';
require './PHPMailer/src/SMTP.php';

// Instantiation and passing `true` enables exceptions
?>

<?php
$age = $_GET["age"];
$user = $_GET["user"];
$uf = $_GET["uf"];
$word = $_GET["words"];
if ($word == "") {
    $word = "Hello 有興趣認識一下嗎!";
}
$flag = $_GET["flag"];
if ($flag == null) {
    $flag = 0;
}
// ChromePhp::log($flag);
$like = $_GET["like"];
$userId = substr($user, 1);
$yzuMail = "s" . $like . "@mail.yzu.edu.tw";
$from = "yzumeetu@gmail.com";
// $to = "s1091419@mail.yzu.edu.tw";
// $to = "seanlin12345@gmail.com";
$to = $yzuMail;
$mail = new PHPMailer(true);
$html = <<<EOF

<h2>$word</h2><br>
<h2>我在YZU MeetU上滑到你 我是 $uf 的同學 如果想認識的話可以回信到 $user@mail.yzu.edu.tw 喔</h2><br>
<h2>此外這是我的照片</h2><br>
<img src="https://portalx.yzu.edu.tw/PortalSocialVB/Include/ShowImage.aspx?ShowType=UserPic&UserAccount=$user&UserPictureName=" height="320" width="221" alt="若圖片沒出現使用連結觀看">
<a href="https://portalx.yzu.edu.tw/PortalSocialVB/Include/ShowImage.aspx?ShowType=UserPic&UserAccount=$user&UserPictureName=">連結(不會中毒啦)</a>

EOF;
$d = $html . "\n" . $from . " to " . $to . "\n" . $userId . " & " . $like;
if ($flag == "1") {
    try {
        //Server settings
        // $mail->SMTPDebug = SMTP::DEBUG_SERVER;                      // Enable verbose debug output
        $mail->isSMTP();                                            // Send using SMTP
        $mail->Host       = 'smtp.gmail.com';                    // Set the SMTP server to send through
        $mail->SMTPAuth   = true;                                   // Enable SMTP authentication
        $mail->Username   = 'yzumeetu@gmail.com';                     // SMTP username
        $mail->Password   = 'yzu12345';                               // SMTP password
        $mail->SMTPSecure = PHPMailer::ENCRYPTION_STARTTLS;         // Enable TLS encryption; `PHPMailer::ENCRYPTION_SMTPS` encouraged
        $mail->Port       = 587;                                    // TCP port to connect to, use 465 for `PHPMailer::ENCRYPTION_SMTPS` above

        //Recipients
        $mail->setFrom($from, $userId);
        $mail->addAddress($to, $like);     // Add a recipient

        // Content
        $mail->Charset = 'UTF-8';
        $mail->isHTML(true);                                  // Set email format to HTML
        $mail->Subject = '你有一則來自YZU MeetU上的訊息!';
        $mail->Body    = $html;
        $mail->AltBody = 'This is the body in plain text for non-HTML mail clients';

        $mail->send();
        ChromePhp::log('Message has been sent');
    } catch (Exception $e) {
        ChromePhp::warn("Message could not be sent. Mailer Error: {$mail->ErrorInfo}");
    }
}
?>

<head>
    <title>YZU MeetU</title>
    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no" />
    <link rel="stylesheet" href="./assets/css/main.css" />
    <noscript>
        <link rel="stylesheet" href="./assets/css/noscript.css" />
    </noscript>
</head>

<body class="is-preload">
    <!-- Header -->
    <header id="header">
        <div class="content">
            <h1 id="faculty">YZU MeetU</h1>
            <p>將隨機產生專屬於你的學伴<br>使用入學頭貼絕無修圖欺騙!!!</p>
            <ul class="actions">
                <li><a href="#" class="button primary icon solid" onclick="formSubmit1();">想認識!!!</a></li>
                <li><a href="./yzuMeetU.php?<?php echo ("user=" . $user . "&age=" . $age); ?>" class="button icon solid scrolly">下面一位</a></li>
                </li>
            </ul>
            <form name="send" id="send" action="#" method="GET">
                <input type="hidden" name="user" value="<?php echo ($user); ?>">
                <input type="hidden" name="age" value="<?php echo ($age); ?>">
                <input type="hidden" id="uf" name="uf" value="<?php echo ($uf); ?>">
                <input type="hidden" id="words" name="words" value="<?php echo ($word); ?>">
                <input type="hidden" id="flag" name="flag" value="1">
                <input type="hidden" id="like" name="like" value="">
            </form>
        </div>
        <div class="image phone">
            <div id="screen" class="inner"></div>
        </div>
    </header>
    <!-- Footer -->
    <footer id="footer">
        <h3>掃描下面並贊助資金即有機會開發限定男女功能</h3>
        <ul class="icons">
            <img src="images/linepay.jpg" alt="">
        </ul>
    </footer>

    <!-- Scripts -->

    <script src="./assets/js/jquery.min.js"></script>
    <script src="./assets/js/jquery.scrolly.min.js"></script>
    <script src="./assets/js/browser.min.js"></script>
    <script src="./assets/js/breakpoints.min.js"></script>
    <script src="./assets/js/util.js"></script>
    <script src="./assets/js/main.js"></script>
    <script src="https://unpkg.com/sweetalert/dist/sweetalert.min.js"></script>

    <script>
        console.log("flag=<?php echo ($flag); ?>")
        if (<?php echo ($flag . " == '1'"); ?>) {
            swal({
                position: 'top-end',
                icon: 'success',
                button: false,
                title: '信件已送出',
                timer: 1500
            });
        }
        // document.getElementById('flag').setAttribute('value', 0);
        function getRandom(min, max) {
            return Math.floor(Math.random() * (max - min + 1)) + min;
        };

        var facultyId = {
            id: ['03', '04', '05', '06', '07', '08', '09', '10', '11', '12', '13', '14', '15', '33', '16', '17', '18', '20', '22', '23', '24', '25', '26', '99', '27', '28', '29', '30', '31', '32'],
            name: ['通訊A', '通訊B', '電機A', '電機B', '光電A', '機械A', '機械B', '化材A', '化材B', '工管A', '工管B', '資工A', '資工B', '資工C', '資管A', '資管B', '資傳A(設計組)', '資傳B(科技組)', '管院A(企管)', '管院B(企管)', '管院C(財金)', '管院D(財金)', '管院E(國企)', '管院I(國企)', '管院G(英專)', '管院F(會計)', '應外A', '中語A', '社政A', '藝設A']
        };
        var r = getRandom(0, 29);
        var fac = facultyId.id[r]
        var n = getRandom(1, 55);
        var sNum = ''
        if (n < 10) {
            sNum += '0';
            sNum += n.toString();
        } else {
            sNum += n.toString();
        }
        var cata = facultyId.name[r];
        var userId = '<?php echo ($user); ?>';
        var userCata = facultyId.name[facultyId.id.indexOf(userId.substr(4, 2))];
        console.log("user " + userId + " from " + userCata);
        var sid = <?php echo ($age); ?> + fac + sNum;
        document.getElementById('faculty').innerHTML = cata;
        document.getElementById('screen').innerHTML = '<img src="https://portalx.yzu.edu.tw/PortalSocialVB/Include/ShowImage.aspx?ShowType=UserPic&UserAccount=s' + sid + '&UserPictureName=\" height=\"320\" width=\"221\">';

        function formSubmit1() {
            // document.getElementById('flag').setAttribute('value', '1')
            // console.log(sid, "zzz1", document.getElementById('flag'));
            document.getElementById('uf').setAttribute('value', userCata);
            document.getElementById('like').setAttribute('value', sid);
            swal("寫下想對他說的一句話", {
                    content: "input",
                    inputPlaceholder: "沒輸入的話預設就是->Hello 有興趣認識一下嗎!"
                })
                .then((value) => {
                    document.getElementById('words').setAttribute('value', value);
                    swal({
                        title: "確認寄出邀請?",
                        text: "他的YZU Email信箱將收到你的來信",
                        icon: "info",
                        buttons: true,
                        dangerMode: false
                    }).then((button) => {
                        if (button) {
                            document.getElementById('send').submit();
                        }
                    });
                });
        }
        // function formSubmit2() {
        // 	document.getElementById('flag').setAttribute('value', '0')
        // 	console.log(sid, "zzz2", document.getElementById('flag'));
        // 	document.getElementById('next').submit();
        // }
    </script>

</body>

</html>