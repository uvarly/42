<?php
session_start();
function check_moderator($user)		// проверка, существует ли такой $moderator в базе данных moderators
{
	if (file_exists("database/moderators"))
	{
		$array = unserialize(file_get_contents("database/moderators"));
		for ($i = 0; $i < count($array); $i++)
		{
			if ($array[$i]["moderator"] === $user)
				return (true);
		}
	}
	return (false);
}
if ($_SESSION["logged_user"] == NULL		// проверяется, разрешено ли заолгиненному юзеру находиться в этом файле
		|| $_SESSION["logged_user"] != "root")
{
	header("Location: index.php");
	exit();
} 
if (($_POST["add_moderator"] == NULL && $_POST["remove_moderator"] == NULL)		// проверяется валидность имени и пароля создаваемого модератора и его наличие в БД
		|| ($_POST["passwd"] == NULL && $_POST["add_moderator"])
		|| $_POST["submit"] != "OK")
{
	header("Location: development.php");
	exit();
}
if (check_moderator($_POST["add_moderator"]) == false && $_POST["add_moderator"] && $_POST["remove_moderator"] == NULL)
{
	$database = unserialize(file_get_contents("database/moderators"));
	$info["moderator"]  = $_POST["add_moderator"];
	$info["passwd"] = hash("whirlpool", $_POST["passwd"]);
	$database[]     = $info;
	file_put_contents("database/moderators", serialize($database));
	header("Location: development.php");
	exit();
}
if (check_moderator($_POST["remove_moderator"]) == true && $_POST["remove_moderator"] && $_POST["add_moderator"] == NULL)
{
	$database = unserialize(file_get_contents("database/moderators"));
	for ($i = 0; $i < count($database); $i++)
	{
		if ($database[$i]["moderator"] === $_POST["remove_moderator"])
		{
			unset($database[$i]);
			file_put_contents("database/moderators", serialize($database));
			header("Location: development.php");
			exit();
		}			
	}
}
?>