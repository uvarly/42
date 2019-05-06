<?php
session_start();
function check_user($user)
{
	if (file_exists("database/passwd"))
	{
		$array = unserialize(file_get_contents("database/passwd"));
		for ($i = 0; $i < count($array); $i++)
		{
			if ($array[$i]["login"] === $user)
				return (true);
		}
	}
	return (false);
}
if ($_SESSION["logged_user"] != NULL)
{
	header("Location: index.php");
	exit();
}
if ($_POST["login"] == NULL
	|| $_POST["passwd"] == NULL
	|| $_POST["submit"] != "OK"
	|| check_user($_POST["login"]) == true)
{
	header("Location: signup.html");
    exit();
}

$database = unserialize(file_get_contents("database/passwd"));
$info["login"]  = $_POST["login"];
$info["passwd"] = hash("whirlpool", $_POST["passwd"]);
$database[]     = $info;

file_put_contents("database/passwd", serialize($database));
header("Location: index.php");
?>
