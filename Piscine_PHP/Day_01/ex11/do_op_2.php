#!/usr/bin/php
<?php
if ($argc == 2) {
    $expression = str_replace(" ", "", $argv[1]);
    $arg1       = intval($argv[1]);
    $arg2       = substr(substr($expression, strlen((string) $arg1)), 1);
    $op         = substr(substr($expression, strlen((string) $arg1)), 0, 1);
    if (is_numeric($arg1) && is_numeric($arg2)) {
        if ($op == "+")
            echo $arg1 + $arg2 . "\n";
        else if ($op == "-")
            echo $arg1 - $arg2 . "\n";
        else if ($op == "*")
            echo $arg1 * $arg2 . "\n";
        else if ($op == "/")
            echo $arg1 / $arg2 . "\n";
        else if ($op == "%")
            echo $arg1 % $arg2 . "\n";
        else
            echo "Syntax Error\n";
    } else
        echo "Syntax Error\n";
} else
    echo "Syntax Error\n";
?>
