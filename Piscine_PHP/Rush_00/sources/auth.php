<?php
function auth($login, $passwd)
{
	if (file_exists("database/passwd"))
	{
		$array = unserialize(file_get_contents("database/passwd"));
		for ($i = 0; $i < count($array); $i++)
		{
			if ($array[$i]["login"] == $login)
				if ($array[$i]["passwd"] == hash("whirlpool", $passwd))
					return (true);	
			else
				return (false);
		}
	}	
	return (false);
}
?>
