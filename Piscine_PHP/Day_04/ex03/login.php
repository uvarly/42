<?php
include("auth.php");
session_start();
$login = $_GET["login"];
$passwd = hash("whirlpool", $_GET["passwd"]);
if (auth($login, $passwd))
{
    $_SESSION["loggued_on_user"] = $login;
    echo "OK\n";
}
else
    echo "ERROR\n";
?>
