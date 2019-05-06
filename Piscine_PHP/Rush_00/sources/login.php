<?php
include("auth.php");
session_start();
$login = $_POST["login"];
$passwd = hash("whirlpool", $_POST["passwd"]);
if ($_POST["login"] != NULL
		&& $_POST["passwd"] != NULL
		&& auth($login, $passwd))
{
	if ($_SESSION["logged_user"] == NULL)
		$_SESSION["logged_user"] = $login;
}
else
{
	$_SESSION["logged_user"] == NULL;
	header("Location: index.php");
	echo "ERROR\n";
}
?>
