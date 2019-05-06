<?php
function check_user($user)
{
	if (file_exists("../database/passwd"))
	{
		$array = unserialize(file_get_contents("../database/passwd"));
		foreach ($array as $user)
		{
			if ($user["login"] === $_POST["login"])
			{
				echo "ERROR\n";
				exit();
			}
		}
	}
	return (false);
}

if ($_POST["login"] == NULL
	|| $_POST["passwd"] == NULL
	|| $_POST["submit"] != "OK"
	|| check_user($user))
{
	echo "ERROR\n";
	exit();
}

$database = unserialize(file_get_contents("../database/passwd"));
$info["login"]  = $_POST["login"];
$info["passwd"] = hash("whirlpool", $_POST["passwd"]);
$database[]     = $info;

file_put_contents("../database/passwd", serialize($database));
header("Location: index.html");
echo "OK\n";
?>
