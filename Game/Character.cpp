#include "Character.h"

Character::Character()//default private
{
	m_name = "N/A";
	m_health = 0;
	m_numItems = 0;
	m_charisma = 0;
	m_constitution = 0;
	m_dexterity = 0;
	m_appearance = "N/A";
}

void Character::setName(string name)
{
	m_name = name;
}
string Character::getName()
{
	return m_name;
}
void Character::setAppearance(string appearance)
{
	m_appearance = appearance;
}
string Character::getAppearance()
{
	return m_appearance;
}
void Character::setHealth(int health)
{
	m_health = health;
}
int Character::getHealth()
{
	return m_health;
}
bool Character::addItem(const Item& i)
{
	return true;
}
void Character::setCha(int cha)
{
	m_charisma = cha;
}
int Character::getCha()
{
	return m_charisma;
}
void Character::setCon(int con)
{
	m_constitution = con;
}
int Character::getCon()
{
	return m_constitution;
}
void Character::setDex(int dex)
{
	m_dexterity = dex;
}
int Character::getDex()
{
	return m_dexterity;
}

void Character::modifyThisHealth(int healthChanged)//modify the character themself
{
	m_health += healthChanged;
}

void Character::modifyHealth(Character& c, int healthChanged)
{
	//c.setHealth(c.getHealth() + healthChanged);
	c.modifyThisHealth(healthChanged);
}

