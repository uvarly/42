#!/usr/bin/php
<?php
    if ($argc > 1)
    {
        $array = array();
        for ($i = 1; $i < $argc; $i++)
            $array = array_merge($array, preg_split('[ ]', $argv[$i], -1, PREG_SPLIT_NO_EMPTY));
        $count = count($array);
        $array[$count - 1] = $array[0];
        if ($count > 1)
            unset($array[0]);
        $line = implode(' ', $array);
        echo "$line\n";
    }
?>
