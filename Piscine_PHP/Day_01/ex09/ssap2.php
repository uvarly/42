#!/usr/bin/php
<?php
function are_words_sorted($word_a, $word_b)
{
    $table  = array(
        'a',
        'b',
        'c',
        'd',
        'e',
        'f',
        'g',
        'h',
        'i',
        'j',
        'k',
        'l',
        'm',
        'n',
        'o',
        'p',
        'q',
        'r',
        's',
        't',
        'u',
        'v',
        'w',
        'x',
        'y',
        'z',
        '0',
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9'
    );
    $word_a = strtolower($word_a);
    $word_b = strtolower($word_b);
    $len    = min(strlen($word_a), strlen($word_b));
    for ($i = 0; $i < $len; $i++)
    {
        $letter_a        = substr($word_a, $i, 1);
        $letter_b        = substr($word_b, $i, 1);
        $letter_a_weight = array_search($letter_a, $table);
        $letter_b_weight = array_search($letter_b, $table);
        $letter_a_weight = $letter_a_weight === false ? ord($letter_a) + 127 : $letter_a_weight;
        $letter_b_weight = $letter_b_weight === false ? ord($letter_b) + 127 : $letter_b_weight;
        if ($letter_a_weight > $letter_b_weight)
            return (false);
        if ($letter_a_weight < $letter_b_weight)
            return (true);
    }
    return strlen($word_a) <= strlen($word_b) ? true : false;
}
if ($argc > 1)
{
    $array = array();
    for ($i = 1; $i < $argc; $i++)
    {
        $temp  = preg_split('[ ]', $argv[$i], -1, PREG_SPLIT_NO_EMPTY);
        $array = array_merge($array, $temp);
    }
    $count = count($array);
    for ($i = 0; $i < $count - 1; $i++)
    {
        if (!are_words_sorted($array[$i], $array[$i + 1]))
        {
            $temp          = $array[$i];
            $array[$i]     = $array[$i + 1];
            $array[$i + 1] = $temp;
            $i             = -1;
        }
    }
    for ($i = 0; $i < $count; $i++)
        echo "$array[$i]\n";
}
?>
