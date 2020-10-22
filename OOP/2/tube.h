#include <iostream>
#include <string.h>
using namespace std;

struct t_vec
{
    double x;
    double y;
    double z;
};

class Tube
{
    double d;
    double U;
    t_vec B;
    t_vec V;
    void speed()
    {
    }
    t_vec vec_init()
    {
        t_vec v;

        v.x = 0;
        v.y = 0;
        v.z = 0;
        return v;
    }

public:
    Tube();
};