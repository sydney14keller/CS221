#include <string>
#include <iostream> 
using std::cout; using std::endl;
using std::string;

#include "Character.h"

int main()
{
	Character lauraCroft;
	lauraCroft.setName("Laura Croft");
	lauraCroft.setAppearance("very toned, tall");
	//did all the others
	Character jakeFromStateFarm;
	jakeFromStateFarm.setHealth(19);
	lauraCroft.setHealth(28);
	lauraCroft.modifyHealth(jakeFromStateFarm, 18);

	if (jakeFromStateFarm.getHealth() == 1)
	{
		cout << "Jake's gonna die!" << endl;
	}

	// add a 'type' variable, ENEMY, ALLY, or NEUTRAL.
	// m_type;
	// modify the modifyHealth method to check type, and hurt/heal appropriately
	// make sure the integer passed in is positive. (aka take the absolute value)
}