#!/usr/bin/php
<?php
    function ft_split($string)
    {
        $words = preg_split('[ ]', $string, -1, PREG_SPLIT_NO_EMPTY);
        sort($words, SORT_STRING);
        return ($words);
    }
?>
