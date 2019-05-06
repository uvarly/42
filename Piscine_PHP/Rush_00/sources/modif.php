<?php
function attempt_change()
{
	$array = unserialize(file_get_contents("/database/passwd"));
	$old_passwd = hash("whirlpool", $_POST["oldpw"]);
	for ($i = 0; $i < count($array); $i++)
	{
		if ($array[$i]["login"] == $_POST["login"] && $array[$i]["passwd"] == $old_passwd)
		{
			$array[$i]["passwd"] = hash("whirlpool", $_POST["newpw"]);
			file_put_contents("/database/passwd", serialize($array));
			header("Location: index.html");
			echo "OK\n";
			exit();
		}
	}
	echo "ERROR\n";
}

if ($_POST["login"] == NULL
		|| $_POST["oldpw"] == NULL
		|| $_POST["newpw"] == NULL
		|| $_POST["submit"] != "OK")
{
	echo "ERROR\n";
	exit();
}
attempt_change();
?>
