#ifndef SINGLETONE_H
#define SINGLETONE_H


using namespace std;

class Singleton
{
	static Singleton* ptr;
	Singleton();
	Singleton(const Singleton& obj);
	Singleton& operator = (const Singleton& obj);
public:
	static Singleton* get_instance();
};


#endif 
