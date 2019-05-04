#!/usr/bin/php
<?php
    if ($argc > 1)
    {
        $array = array();
        for ($i = 1; $i < $argc; $i++)
        {
            $temp = preg_split('[ ]', $argv[$i], -1, PREG_SPLIT_NO_EMPTY);
            $array = array_merge($array, $temp);
        }
        sort($array, SORT_STRING);
        $count = count($array);
        for ($i = 0; $i < $count; $i++)
            echo "$array[$i]\n";
    }
?>
