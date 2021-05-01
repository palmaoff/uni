#ifndef LEC_H
#define LEC_H

#include <iostream>
using namespace std;

class lec {
    int x;
public:
    lec():
        x(0) {}
    ~lec() {}
    inline void print();
    static void hello() {
        cout << "hi, im here" << endl;
    }
    static int id;
};

void lec::print() {
    cout << x << endl;
}

#endif
