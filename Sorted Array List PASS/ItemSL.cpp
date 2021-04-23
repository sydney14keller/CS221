
#include "ItemSL.h"

ItemSL::ItemSL()
{
    m_name = "N/A";
    m_weight = 0.0;
}
ItemSL::ItemSL(string name, double weight)
{
    m_name = name;
    m_weight = weight;
}

double ItemSL::getWeight()
{
    return m_weight;
}

string ItemSL::getName()
{
    return m_name;
}

void ItemSL::display(ostream& out)
{
    out << getName() << " --> " << getWeight() << endl;
}

Item ItemSL::operator+ (const Item& rhs)
{
    float newWeight = m_weight + rhs.m_weight;
    string newName = m_name + rhs.m_name;
    return Item(newName, newWeight);
}

int ItemSL::compareTo(ItemSL& other)
{
    //we want to compare the m_weight's of the class
    //return -1 if THIS is less than other
    //return 0 if they are the same
    //return 1 if THIS is greater than other. 
    if (other.getWeight() > this->m_weight)
    {
        return -1; // because THIS would be less than OTHER
    }
    else if (other.getWeight() < this->m_weight)
    {
        return 1;
    }
    else
    {
        if (other.getName() > this->getName())
        {
            return -1;
        }
        else if (other.getName() < this->getName())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

bool ItemSL::operator<(ItemSL& rhs)
{
    if (compareTo(rhs) < 0)
    {
        return true;
    }
    else {
        return false;
    }
}

bool ItemSL::operator>(ItemSL& rhs)
{
    if (compareTo(rhs) > 0)
    {
        return true;
    }
    else {
        return false;
    }
}