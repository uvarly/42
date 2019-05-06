<?php
function check_user($user)
{
    if (file_exists("../private/passwd"))
    {
        $array = unserialize(file_get_contents("../private/passwd"));
        for ($i = 0; $i < count($array); $i++)
        {
            if ($array[$i]["login"] === $_POST["login"])
            {
                echo "ERROR\n";
                exit();
            }
        }
    }
    return (false);
}

if (!file_exists("../private"))
    mkdir("../private", 0755, 1);

if ($_POST["login"] == NULL
	|| $_POST["passwd"] == NULL
	|| $_POST["submit"] != "OK"
	|| check_user($_POST["login"]))
{
    echo "ERROR\n";
    exit();
}

if (file_exists("../private/passwd"))
    $database = unserialize(file_get_contents("../private/passwd"));
$info["login"]  = $_POST["login"];
$info["passwd"] = hash("whirlpool", $_POST["passwd"]);
$database[]     = $info;

file_put_contents("../private/passwd", serialize($database));
echo "OK\n";
?>
