#!/usr/bin/env php
<?php
	if ($argc == 2)
	{
		$file = file_get_contents($argv[1]);
		$file = preg_replace_callback('/<a.*?title="(.*?)">/si', function ($matches) {return (str_replace($matches[1], strtoupper($matches[1]), $matches[0]));}, $file);
		$file = preg_replace_callback('/<a .*?>(.*?)</si', function ($matches) {return (str_replace($matches[1], strtoupper($matches[1]), $matches[0]));}, $file);
		echo $file;
	}
?>
