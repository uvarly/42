<?php
function auth($login, $passwd)
{
    $array = unserialize(file_get_contents("../private/passwd"));
    for ($i = 0; $i < count($array); $i++)
    {
        if ($array[$i]["login"] == $login)
            if ($array[$i]["passwd"] == $passwd)
                return (true);
            else
                return (false);
    }
    return (false);
}
?>
