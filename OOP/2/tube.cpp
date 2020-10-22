#include "tube.h"

t_vec	Tube::vec_init()
{
	t_vec v;

	v.x = 0;
	v.y = 0;
	v.z = 0;
	return v;
}

Tube::Tube()
{
	d = 0;
	U = 0;
	B = vec_init();
	V = vec_init();
}
