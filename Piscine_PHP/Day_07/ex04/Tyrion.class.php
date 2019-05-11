<?php
class Tyrion
{
    public function sleepWith($counterpart)
    {
        if ($counterpart instanceof Jaime)
            print("Not even if I'm drunk !" . PHP_EOL);
        if ($counterpart instanceof Sansa)
            print("Let's do this." . PHP_EOL);
        if ($counterpart instanceof Cersei)
            print("Not even if I'm drunk !" . PHP_EOL);
    }
}
?>
