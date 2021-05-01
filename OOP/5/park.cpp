#include "park.h"

Bench::Bench()
{
	freeSits = 3;
}

Dog::Dog()
{
	size = 1;
}

Human::Human()
{
	dog = NULL;
	bench = NULL;
}

size_t Bench::get_sits()
{
	return freeSits;
}

void Bench::add_sit()
{
	freeSits++;
}

void Bench::del_sit()
{
	freeSits--;
}

bool Bench::have_sit()
{
	return freeSits > 0;
}

void Human::add_dog(Dog* d)
{
	dog = d;
}

void Human::sitdown(Bench* b)
{
	bench = b;
}

bool Human::have_dog()
{
	return dog != NULL;
}

bool Human::have_sit()
{
	return bench != NULL;
}

void Human::up()
{
	if (bench != NULL)
	{
		(*bench).add_sit();
		bench = NULL;
	}
}

size_t Park::count_dogs()
{
	list<Human>::iterator i_h;
	size_t count = 0;

	for (i_h = h.begin(); i_h != h.end(); i_h++)
		if ((*i_h).have_dog())
			count++;
	return count;
}

size_t Park::count_sit()
{
	list<Human>::iterator i_h;
	size_t count = 0;

	for (i_h = h.begin(); i_h != h.end(); i_h++)
		if ((*i_h).have_sit())
			count++;
	return count;
}

void Park::add_human()
{
	Human n;
	h.push_back(n);
}

void Park::add_dog(int num)
{
	Dog n;
	list<Human>::iterator i_h;

	num--;
	for (i_h = h.begin(); i_h != h.end() && num > 0; i_h++)
		num--;

	if (num == 0)
		(*i_h).add_dog(&n);

	d.push_back(n);
}

void Park::sitdown(int n_b, int n_h)
{
	list<Bench>::iterator i_b;
	list<Human>::iterator i_h;

	n_b--;
	n_h--;
	for (i_h = h.begin(); i_h != h.end() && n_h > 0; i_h++)
		n_h--;

	for (i_b = b.begin(); i_b != b.end() && n_b > 0; i_b++)
		n_b--;

	if (&(*i_h) != NULL && &(*i_b) != NULL && (*i_b).have_sit())
	{
		(*i_h).sitdown(&(*i_b));
		(*i_b).del_sit();
	}
}

void Park::add_bench()
{
	Bench n;
	b.push_back(n);
}

void Park::up(int n_h)
{
	list<Human>::iterator i_h;

	n_h--;
	for (i_h = h.begin(); i_h != h.end() && n_h > 0; i_h++)
		n_h--;
	
	(*i_h).up();
}

void Park::print_inf()
{
	list<Human>::iterator i_h;
	list<Dog>::iterator i_d;
	list<Bench>::iterator i_b;
	int count = 0;

	for (i_h = h.begin(); i_h != h.end(); i_h++)
		count++;
	cout << count << " peoples\n";

	cout << count_sit() << " sitting peoples\n";
	cout << count_dogs() << " peoples with dogs\n";

	count = 0;
	for (i_d = d.begin(); i_d != d.end(); i_d++)
		count++;
	cout << count << " dogs\n";

	count = 0;
	int i = 0;
	for (i_b = b.begin(); i_b != b.end(); i_b++)
	{
		count += (*i_b).get_sits();
		i++;
	}
	cout << i << " benches\n";
	cout << count << " sits\n";
}

void Park::run()
{
	string c;
	size_t n;
	size_t b;

	while (c != "q")
	{
		cin >> c;
		if (c == "h")
			add_human();
		if (c == "d")
		{
			cout << "Enter human: ";
			cin >> n;
			add_dog(n);
		}
		if (c == "b")
			add_bench();
		if (c == "s")
		{
			cout << "Enter human: ";
			cin >> n;
			cout << "Enter bench: ";
			cin >> b;
			sitdown(b, n);	
		}
		if (c == "p")
			print_inf();
		if (c == "u")
		{
			cout << "Enter human: ";
			cin >> n;
			up(n);
		}
	}
}
