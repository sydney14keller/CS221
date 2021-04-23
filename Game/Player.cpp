#include "player.h"
Player::Player() //default
{
	m_activeWeapon = "N/A";
	m_maxEnergyLevel = 20.0;
	m_currentEnergyLevel = 20.0;
	m_maxSpeed = 0.0;
}
Player::Player(float maxEnergy, double maxSpeed)
{
	m_activeWeapon = "N/A";
	m_maxEnergyLevel = maxEnergy;
	m_currentEnergyLevel = maxEnergy;
	m_maxSpeed = maxSpeed;
}

//setter methods to change the activeWeapon

void Player::attack(Character& target)
{
	//we want to USE UP some energy. Lets say the same amount as the damage it deals.
	m_currentEnergyLevel -= m_activeWeapon.length();//lose 2 energy


    //deal a number of damage equal to the number of characters in the string.
	//we want to deal damage to character "target"
	target.modifyThisHealth(-m_activeWeapon.length());//LENGTH OF STRING

	
	//we want to reference the 'weapon' currently in use
	cout << "You are using " << m_activeWeapon << endl;


	


}

