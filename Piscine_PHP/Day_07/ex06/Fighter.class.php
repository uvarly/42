<?php
abstract class Fighter
{
	private $name;

	abstract function fight($target);

	public function __construct($name)
	{
		$this->name = $name;
	}

	public function getName()
	{
		return ($this->name);
	}
}
?>
