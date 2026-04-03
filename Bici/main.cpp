
#include <iostream>
#include <cstring>
#include "Bici.h"

int main()
{
    int x;
    Bici b1(40,"blue"), b2(36,"verde");

    b2.dipingiti("rosso");
    b2.pedala();
    b2.pedala();
    b2.pedala();
    b1.presentati();   
    b2.presentati();

    return 0;
}