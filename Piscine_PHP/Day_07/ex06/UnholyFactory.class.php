<?php
class UnholyFactory
{
	private $fighters;

	public function absorb($f)
	{
		if (get_parent_class($f) == "Fighter")
		{
			if (!isset($this->fighters[$f->getName()]))
			{
				print("(Factory absorbed a fighter of type " . get_class($f) . ")" . PHP_EOL);
				$this->fighters[$f->getName()] = $f;
			}
			else
				print("(Factory already absorbed a fighter of type " . get_class($f) . ")" . PHP_EOL);
		}
		else
			print("(Factory can't absorb this, it's not a fighter)" . PHP_EOL);
	}

	public function fabricate($f)
	{
		if (key_exists($f, $this->fighters))
		{
			print("(Factory fabricates a fighter of type " . $f . ")" . PHP_EOL);
            return (clone $this->fighters[$f]);
		}
		else
		{
			print("(Factory hasn't absorbed any fighter of type " . $f . ")" . PHP_EOL);
            return (NULL);
		}
	}
}
?>
