<!DOCTYPE html>

<html lang="zh-tw">
    <head>
        <link rel="stylesheet" href="./assets/css/login.css" />
    </head>

    <body>
        <div class="wrapper fadeInDown">
            <div id="formContent">
                <!-- Tabs Titles -->
                <h2>歡迎使用YZU MeetU</h2>
                <!-- Icon -->

                <!-- Login Form -->
                <form action="./choose.php" method="POST">
                    <input type="text" id="login" class="fadeIn second" name="login" placeholder=" 請輸入portal帳號" pattern="s\d{7}"/>
                    <input type="submit" class="fadeIn fourth" value="Log In" />
                </form>
            </div>
        </div>
    </body>
</html>
