#pragma once
#pragma once
#include <string>

#include "Item.h"
using std::string;

class Character
{
private:
	string m_name;
	int m_health;
	Item m_stuff[10];
	int m_numItems;
	int m_charisma;
	int m_constitution;
	int m_dexterity;
	//more stats here
	string m_appearance;		//in the real world, this would be it's own class.
								//	this class could have Shirt, Pants, Shoes, Helmet, Gloves, etc

public:
	Character();				//default constructor

	void setName(string name);					string getName();
	void setAppearance(string appearance);		string getAppearance();
	void setHealth(int health);		int getHealth();
	bool addItem(const Item& i);
	void setCha(int cha);			int getCha();
	void setCon(int con);			int getCon();
	void setDex(int dex);			int getDex();

	void modifyThisHealth(int healthChanged);
	void modifyHealth(Character& c, int healthChanged);

};