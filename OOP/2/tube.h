#include <iostream>
#include <string.h>
using namespace std;

class Tube
{
    double d;
    double U;
    double B;
    double V;

    void	tube_input();
    void    speed();

public:

    // constructor
    Tube();
    Tube(double d, double U, double B);

    // distructor
    ~Tube();

    // get
    double  getD();
    double  getU();
    double  getB();
    double  getV();

    // set
    void    set();
    void    setD(double d);
    void    setU(double U);
    void    setB(double B);

    // toString
    string  toString();

    // print
    void    print();
};

void tube_loop();
