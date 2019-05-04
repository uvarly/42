#!/usr/bin/php
<?php
	echo "Enter a number: ";
	$line = trim(fgets(STDIN));
	if (!feof(STDIN))
	{
		if (is_numeric($line))
		{
			if ($line % 2 == 0)
				echo "The number $line is even";
			else
				echo "The number $line is odd";
		}
		else
			echo "'$line' is not a number";
	}
	echo "\n";
?>
