<?php


abstract class Weapon
{
	// use WeaponType;

	private $_charges;
	private $_coordinates;
	private $_orientation;
	private $_short_range;
	private $_middle_range;
	private $_long_range;
	private $_effect_zone;

	public abstract function isInRange(Ship $ship);

	/**
	 * @return mixed
	 */
	public function getCharges()
	{
		return $this->_charges;
	}

	/**
	 * @param mixed $base_charges
	 */
	public function setCharges($charges)
	{
		$this->_charges = $charges;
	}

	/**
	 * @return mixed
	 */
	public function getOrientation()
	{
		return $this->_orientation;
	}

	/**
	 * @param mixed $orientation
	 */
	public function setOrientation($orientation)
	{
		$this->_orientation = $orientation;
	}

    /**
     * @return mixed
     */
    public function getCoordinates()
    {
        return $this->_coordinates;
    }

    /**
     * @param mixed $coordinates
     */
    public function setCoordinates($coordinates)
    {
        $this->_coordinates = $coordinates;
    }

    /**
     * @return mixed
     */
    public function getShortRange()
    {
        return $this->_short_range;
    }

    /**
     * @param mixed $short_range
     */
    public function setShortRange($short_range)
    {
        $this->_short_range = $short_range;
    }

    /**
     * @return mixed
     */
    public function getMiddleRange()
    {
        return $this->_middle_range;
    }

    /**
     * @param mixed $middle_range
     */
    public function setMiddleRange($middle_range)
    {
        $this->_middle_range = $middle_range;
    }

    /**
     * @return mixed
     */
    public function getLongRange()
    {
        return $this->_long_range;
    }

    /**
     * @param mixed $long_range
     */
    public function setLongRange($long_range)
    {
        $this->_long_range = $long_range;
    }

    /**
     * @return mixed
     */
    public function getEffectZone()
    {
        return $this->_effect_zone;
    }

    /**
     * @param mixed $effect_zone
     */
    public function setEffectZone($effect_zone)
    {
        $this->_effect_zone = $effect_zone;
    }

}