<?php
include("auth.php");
session_start();
$login = $_POST["login"];
$passwd = hash("whirlpool", $_POST["passwd"]);
if ($_POST["login"] != NULL
		&& $_POST["passwd"] != NULL
		&& auth($login, $passwd))
{
	if ($_SESSION["loggued_on_user"] == NULL)
		$_SESSION["loggued_on_user"] = $login;
}
else
{
	$_SESSION["loggued_on_user"] == NULL;
	header("Location: index.html");
	echo "ERROR\n";
}
?>
<html>
	<head>
		<meta charset="UTF-8">
		<title>42Chat</title>
	</head>
	<body>
		<iframe name="chat" src="chat.php" width="100%" height="550px"></iframe>
		<iframe name="speak" src="speak.php" width="100%" height="50px"></iframe>
	</body>
</html>
