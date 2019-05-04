#!/usr/bin/php
<?php
if ($argc == 4)
{
    $array = array();
    for ($i = 1; $i < $argc; $i++)
    {
        $temp  = preg_split('[ ]', $argv[$i], -1, PREG_SPLIT_NO_EMPTY);
        $array = array_merge($array, $temp);
    }
    $arg1 = (int)$array[0];
    $arg2 = (int)$array[2];
    $op = $array[1];
    if ($op == "+")
        echo $arg1 + $arg2;
    if ($op == "-")
        echo $arg1 - $arg2;
    if ($op == "*")
        echo $arg1 * $arg2;
    if ($op == "/")
        echo $arg1 / $arg2;
    if ($op == "%")
        echo $arg1 % $arg2;
    echo "\n";
}
else
    echo "Incorrect Parameters\n";
?>