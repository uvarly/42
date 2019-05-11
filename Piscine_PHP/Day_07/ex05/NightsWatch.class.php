<?php
class NightsWatch implements IFighter
{
	private $fighters;

	public function recruit($f)
	{
		$this->fighters[] = $f;
	}

	public function fight()
	{
		foreach ($this->fighters as $f)
			if (method_exists(get_class($f), "fight"))
				$f->fight();
	}
}
?>
