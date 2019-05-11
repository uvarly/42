<?php
if (file_exists("list.csv"))
{
    $file = file("list.csv", FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
    foreach ($file as $line)
    {
        $temp = explode(";", $line);
        $array[] = $temp[1];
    }
    echo (json_encode($array));
}