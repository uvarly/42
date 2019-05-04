#!/usr/bin/php
<?php
if ($argc > 2)
{
	$array = array();
	$flag = 0;
	for ($i = 1; $i < $argc; $i++)
		array_push($array, $argv[$i]);
	for ($i = 1; $i < $argc - 1; $i++)
	{
		if (strcmp($array[0], substr($array[$i], 0, strlen($array[0]))) == 0)
		{
			$flag = 1;
			$ret = substr($array[$i], strpos($array[$i], ":") + 1);
		}
	}
	if ($flag == 1)
		echo $ret."\n";
}
?>
