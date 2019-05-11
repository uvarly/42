<?php
class Jaime
{
    public function sleepWith($counterpart)
    {
        if ($counterpart instanceof Tyrion)
            print("Not even if I'm drunk !" . PHP_EOL);
        if ($counterpart instanceof Sansa)
            print("Let's do this." . PHP_EOL);
        if ($counterpart instanceof Cersei)
            print("With pleasure, but only in a tower in Winterfell, then." . PHP_EOL);
    }
}
?>
