//------------------------------------------------------------------
// CircleList Implementation
// Author: Rocio Ramirez-Jimenez & Bradly Rutten 
//------------------------------------------------------------------
#include <iostream>
#include "CircleList.h"

using namespace std;

int main()
{
    CircleList x;
    x.add(1);
    x.add(2);
    x.add(3);
    x.add(4);
    x.add(5);
    x.printNodes();
    
    cout << "Testing Constructor" << endl;
    CircleList y(x);
    y.printNodes();
    
    cout << "Test Operator=" << endl;
    CircleList z;
    z = x;
    z.printNodes();
    
    CircleList::Iterator p;
    
    for(p=x.begin(); p!=x.end; p.advance(x))
    {
      cout << "Iterator: " << p;
    }
}

