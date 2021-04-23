#pragma once
#pragma once
#include "Character.h"
class Player : public Character
{
	//weapon currently in use
	//energy
	//a class that holds all of the stats
	// array instead
	// struct maybe
	string m_activeWeapon;
	float m_maxEnergyLevel;
	float m_currentEnergyLevel;
	double m_maxSpeed;

public:
	//Map m_minimap;
	//"friend" method
	Player(); //default
	Player(float maxEnergy, double maxSpeed);

	void attack(Character& c);

};

