<?php
if (file_exists("list.csv") && isset($_GET["todo"]))
{
    $file = file("list.csv", FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
    $max = 0;
    foreach ($file as $line)
    {
        $temp = explode(";", $line);
        if ($temp[0] >= $max)
            $max = $temp[0] + 1;
    }
  file_put_contents("list.csv", $max . ";" . $_GET["todo"] . PHP_EOL, FILE_APPEND);
}