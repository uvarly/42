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
function check_category($category)      // функция проверяет, есть ли $category в БД
{
    if ($category == NULL)
        return (false);
    $fd = fopen("database/categories.csv", "r");
    while (!feof($fd))
    {
        $array = fgetcsv($fd);
        if ($array[0] == $category)
        {
            fclose($fd);
            return (true);
        }
    }
    fclose($fd);
    return (false);
}
if ($_SESSION["logged_user"] == NULL		// проверяется, разрешено ли заолгиненному юзеру находиться в этом файле
		|| $_SESSION["logged_user"] != "root"
		|| !is_moderator($_SESSION["login"]))
{
	header("Location: index.php");
	exit();
}
if (($_POST["category_add"] == NULL && $_POST["category_remove"] == NULL)   // проверяется валидность имени категории и ее наличие в БД
		|| $_POST["submit"] != "OK")
{
    header("Location: development.php");
	exit();
}
if (check_category($_POST["category_add"]) == false && $_POST["category_add"] && $_POST["category_remove"] == NULL)            // если дана команда "category_add" (и нет "category_remove"), сделать вставку в БД
{
    $fd = fopen("database/categories.csv", "a");
    fputcsv($fd, array($_POST["category_add"]));
    fclose($fd);
    header("Location: development.php");
    exit();
}
if (check_category($_POST["category_remove"]) == true && $_POST["category_add"] == NULL && $_POST["category_remove"])            // если дана команда "category_remove" (и нет "category_add"), удалить категорию
{
    var_dump($_POST["category_remove"]);
    $file = explode("\n", file_get_contents("database/categories.csv"));
    for ($i = 0; $i < count($file); $i++)
    {
        $line = explode(",", $file[$i]);
        var_dump($line);
        if ($line[0] == $_POST["category_remove"])
            unset($file[$i]);
    }
    file_put_contents("database/categories.csv", implode("\n", $file));
    // header("Location: development.php");
    exit();
}
?>
