#!/usr/bin/php
<?php
if ($argc != 2 || (strcmp($argv[1], "average") && strcmp($argv[1], "average_user") && strcmp($argv[1], "moulinette_variance")))
    exit();
fgets(STDIN);
$array = array();
$user = array();
while (!feof(STDIN))
{
    $line = fgets(STDIN);
    if (!in_array(substr($line, 0, strpos($line, ";")), $user))
        array_push($user, substr($line, 0, strpos($line, ";")));
    array_push($array, $line);
}
$final_grade = array();
for ($i = 0; $i < count($user); $i++)
{
    $name = substr($array[$i], 0, strpos($array[$i], ";"));
    $grade = 0;
    $moulinette = 0;
    $count = 0;
    for ($j = 0; $j < count($array); $j++)
    {
        $data = preg_split('[;]', $array[$j], -1, PREG_SPLIT_NO_EMPTY);
        if (count($data) < 4)
            continue;
        if ($name == $data[0])
        {
            if ($argv[1] == "moulinette_variance" && $data[2] == "moulinette")
            {
                $moulinette = (int)$data[1];
                continue;
            }
            if ($data[2] != "moulinette")
            {
                $grade += (int)$data[1];
                $count++;
            }
        }
    }
    $grade /= $count;
    // $grade -= !strcmp($argv[1], "moulinette_variance") ? $moulinette : 0;
    array_push($final_grade, implode(":", array($name, $grade)));
}
for ($i = 0; $i < count($final_grade); $i++)
    echo "$final_grade[$i]\n";
?>
