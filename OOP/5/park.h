#ifndef PARK
#define PARK

#include <iostream>
#include <list>

using namespace std;

class Dog
{
	size_t size;
public:
	Dog();
};

class Bench
{
	size_t freeSits;
public:
	Bench();
	size_t get_sits();
	void add_sit();
	void del_sit();
	bool have_sit();
};

class Human
{
	bool sex;
	Dog* dog;
	Bench* bench;
public:
	Human();
	void add_dog(Dog* d);
	void sitdown(Bench* b);
	bool have_dog();
	bool have_sit();
	void up();
};

class Park
{
	list <Human> h;
	list <Dog> d;
	list <Bench> b;
public:
	void add_dog(int h);
	void sitdown(int b, int h);
	void up(int h);
	void add_human();
	void add_bench();
	size_t count_sit();
	size_t count_dogs();
	void print_inf();
	void run();
};

#endif
