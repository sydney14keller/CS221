#include "Item.h"
Item::Item(){	m_name = "N/A";	m_weight = 0.0;}Item::Item(string name, double weight){	m_name = name;	m_weight = weight;}double Item::getWeight(){	return m_weight;}string Item::getName(){	return m_name;}void Item::print(ostream& out){	out << getName() << " --> " << getWeight() << endl;}



