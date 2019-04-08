#include <iostream>
#include <pthread.h>
#include <cassert>
#include "matrix.hpp"


int main()
{
        data a;
        data b;
        data c;
        data d;
        data e;
        data f;
        data g;
        
        a.initialize();
        b.initialize();
        c.initialize();
        d.initialize();
        
        a.print("a");
        b.print("b");
        c.print("c");
        d.print("d");
        
        adder ab(&a, &b, &e);
        adder cd(&c, &d, &f);
        multiplier ef(&e, &f, &g);

        ab.create_thread();
        cd.create_thread();
        ef.create_thread();
        ab.join_thread();
        cd.join_thread();
        ef.join_thread();

        e.print("e");
        f.print("f");
        g.print("g");

	return 0;
}
