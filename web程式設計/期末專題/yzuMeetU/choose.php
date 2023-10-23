<!DOCTYPE html>
<html lang="zh-tw">

<?php
    $user = $_POST["login"]
?>

    <head>
        <link rel="stylesheet" href="./assets/css/choose.css" />
    </head>

    <body>
        <div class="boxes">
            <h2 style="text-align: center; color: whitesmoke">今晚你想來點?</h2>
            <form name="ageForm" action="./yzuMeetU.php" method="GET">
                <input type="hidden" name="user" value="<?php echo ($user); ?>" />
                <input type="radio" name="age" id="box-1" value="109" checked/>
                <label for="box-1">109級清純小孩</label>

                <input type="radio" name="age" id="box-2" value="108" />
                <label for="box-2">108級熟男熟女</label>

                <input type="radio" name="age" id="box-3" value="107" />
                <label for="box-3">107級老練大三</label>

                <input type="radio" name="age" id="box-4" value="106" />
                <label for="box-4">106級考研戰士</label>

                <div class="buttons">
                    <div class="container">
                        <a href="javascript:document.ageForm.submit();" class="btn effect01">
                            <span>送出</span>
                        </a>
                    </div>
                </div>
            </form>
        </div>
    </body>
</html>
