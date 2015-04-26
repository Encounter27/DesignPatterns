#include "singleton.h"

#include<iostream>

using namespace std;


Singleton *Singleton::ptr = NULL;

Singleton::Singleton()
{
	cout << "Constructor\n";
}


Singleton::Singleton(const Singleton& ob)
{
	cout << "Copy Constructor\n";
}


Singleton& Singleton::operator = (const Singleton& ob)
{
	cout << "Assignment Operator\n";
}

Singleton* Singleton::get_instance()
{
	cout << "Inside get_instance\n";
	if( ptr == NULL)
		ptr = new Singleton();
	return ptr;
}
