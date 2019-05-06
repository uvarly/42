<?php
session_start();
function is_moderator($user)		// функция проверяет, является ли $user модератором
{
	$array = unserialize(file_get_contents("database/moderators"));
	for ($i = 0; $i < count($array); $i++)
	{
		if ($array[$i]["login"] === $user)
			return (true);
	}
}
function check_user($user)		// проверка, существует ли такой $user в базе данных passwd
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
if ($_SESSION["logged_user"] == NULL		// проверяется, разрешено ли заолгиненному юзеру находиться в этом файле
		|| $_SESSION["logged_user"] != "root"
		|| !is_moderator($_SESSION["login"]))
{
	header("Location: index.php");
	exit();
}
if ($_POST["login"] == NULL				// проверяется валидность имени удаляемого юзера и его наличие в БД
		|| $_POST["login"] == "root"	// если хочешь удалить рута, убери это условие (!!!)
		|| $_POST["submit"] != "OK"
		|| check_user($_POST["login"]) != true)
{
	header("Location: development.php");
	exit();
}

$database = unserialize(file_get_contents("database/passwd"));
for ($i = 0; $i < count($database); $i++)
{
	if ($database[$i]["login"] === $_POST["login"])
	{
		unset($database[$i]);
		file_put_contents("database/passwd", serialize($database));
		header("Location: development.php");
		exit();
	}			
}
?>
