<?php
if (file_exists("list.csv") && isset($_GET["id"]))
{
	$file = file("list.csv", FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
	$list = '';
	$max = 0;
	$flag = 0;
	foreach ($file as $line)
	{
		$temp = explode(";", $line);
		if ($temp[0] == $_GET['id'])
		{
			$flag = 1;
			continue;
		}
		$list .= $temp[0] - $flag . ";" . $temp[1] . PHP_EOL;
	}
	file_put_contents("list.csv", $list);
}