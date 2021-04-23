#include <iostream>
#include<string>
class Base {
private:
	int x;

protected:
	int y;

public:
	int z;

	Base() : x{ 1 }, y{ 2 }, z{ 3 }
	{
	}

	void printStuff() {
		std::cout << "x = " << x << std::endl;
		std::cout << "y = " << y << std::endl;
		std::cout << "z = " << z << std::endl;
	}

	virtual std::string toString() {
		std::string s = std::to_string(x) + " "
			+ std::to_string(y) + " "
			+ std::to_string(z);
		return s;
	}

};

class Derived : public Base {
private:
	int a;

public:
	int b;

	Derived() : Base{}, a{ 20 }, b{ 88 }
	{
	}

	void printStuff() {
		Base::printStuff();
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
	}

	virtual std::string toString() override {
		std::string s = Base::toString() + " "
			+ std::to_string(a) + " "
			+ std::to_string(b);
		return s;
	}
};

int main() {

	Base* object = new Derived;

	object->printStuff();     // *** Point 1 ***

	std::cout << std::endl;
	std::cout << object->toString() << std::endl;     // *** Point 2 *** 

	delete object;

	return 0;
}