#!/usr/bin/php
<?php
date_default_timezone_set('Europe/Moscow');
$file = fopen("/var/run/utmpx", "rb");
while (!feof($file))
{
    $info = fread($file, 628);
    if (strlen($info) == 628)
    {
        $info = unpack("a256_USER_/a4_ID_/a32_LINE_/i_PID_/i_TYPE_/i_TIME_", $info);
        if ($info["_TYPE_"] == 7)
        {
            echo trim($info["_USER_"])."   ";
            echo trim($info['_LINE_'])."  ";
            $date = date("M d H:i", $info['_TIME_']);
            echo "$date \n";
        }
    }
}
?>
