//------------------------------------------------------------------
// Array-Based Stack Implementation
// Author: Mohamed Aboutabl
// Edited/Modified by: Rocio Ramirez-Jimenez & Bradly Rutten 
//------------------------------------------------------------------
#include <iostream>
#include "arrayStack.h"

using namespace std;

int main()
{
    ArrayStack<int> s1 ;
    cout << "s1 after constructed: ";
    s1.print() ;
    try
    {
        cout << "top of s1 is: " << s1.top() ;
    }
    catch ( StackExcp & err )
    {
        cout << "operation 'top' failed: " << err.what() ;
    }
    cout << endl ;
    //---------------------
    
    try
    {
        s1.push(7) ;
        s1.push(13) ;
        s1.push(8) ;
        s1.print() ;
    }
    catch ( StackExcp & err )
    {
        cout << "operation 'push' failed: " << err.what() << endl ;
    }
    cout << endl ;
    //---------------------
    
    try
    {
        cout << "top of s1 is: " << s1.top() ;
    }
    catch ( StackExcp & err )
    {
        cout << "operation 'top' failed: " << err.what() << endl ;
    }
    cout << endl ;
    //---------------------
   
    try
    {
        s1.pop() ;
        s1.print() ;
        s1.pop() ;
        s1.pop() ;
        s1.print() ;
        s1.pop() ;
    }
    catch ( StackExcp & err )
    {
        cout << "operation 'pop' failed: " << err.what() << endl ;
    }
    cout << endl ;
    //---------------------
    
    //test empty()
    if(s1.empty())
        cout << "s1 is empty" << endl;
    else
        cout << "s1 is not empty" << endl;
    
    s1.push(5);
    if(s1.empty())
        cout << "s1 is empty" << endl;
    else
        cout << "s1 is not empty" << endl;
    
    //test copy constructor
    s1.push(7);
    s1.push(-3);
    s1.push(53);
    
    cout << endl;
    ArrayStack<int> s2(s1);
    s2.print();
    
    //test operator=
    ArrayStack<int> s3;
    s3 = s1;
    s3.print();
    
    //test pop on a copy stack
    try
    {
       s3.pop();
       s3.pop();
       s3.pop();
       s3.pop();
       s3.print();
       s3.pop();
    }
    catch ( StackExcp & err )
    {
        cout << "operation 'pop' failed: " << err.what() << endl ;
    }
    cout << endl;
    
    //test push on a copy stack
    try
    {
        cout << "top of s3 is: " << s1.top() ;
    }
    catch ( StackExcp & err )
    {
        cout << "operation 'top' failed: " << err.what() << endl ;
    }
    
    try
    {
        s3.push(10) ;
        s3.push(2) ;
        s3.push(17) ;
        s3.push(-1);
        s3.print() ;
    }
    catch ( StackExcp & err )
    {
        cout << "operation 'push' failed: " << err.what() << endl ;
    }
    cout << endl;
    
    //test new stack with different type (string/double)
    ArrayStack<string> s4;
    s4.push("Hello");
    s4.push("World");
    s4.print();
    s4.pop();
    s4.print();
    
    cout << endl;
    
    ArrayStack<double> s5;
    s5.push(34.2);
    s5.push(-81.9452);
    s5.print();
    s5.pop();
    s5.print();
    
    for(int i = 0; i < 10; i++)
    {
		cout << endl;
	}
}
