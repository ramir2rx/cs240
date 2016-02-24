/***************************************************************************
*  Author:    Rocio Ramirez-Jimenez, Brad Rutten                           *
*  Project:   1- Dynamic Arrays                                            *
*  File:      testDblArr.cpp                                               *
****************************************************************************/
#include <iostream>
#include <string>
#include "dblArr.h"

using namespace std;

int main()
{
    cout << "Test Array x:" << endl;
    //Test default constructor
    dblArr x;
    //Test capcity()
    cout << "Expected Capacity: 10 Actual Capacity: ";
    cout << x.capacity(); 
    cout << endl;
    //Test count()
    cout << "Expected Count: 0 Actual Count: ";
    cout << x.count(); 
    cout << endl;
    //Test print() with no values
    cout << "Expected print: { } Actual print: ";
    x.print(); 
    cout << endl;
    //Test addRear() and count()
    x.addRear(25);
    cout << "Expected print: { 25 } Actual print: ";
    x.print(); 
    cout << endl;
    x.addRear(50.87);
    x.addRear(-46.92);
    cout << "Expected print: { 25, 50.87, -46.92 } Actual print: ";
    x.print(); 
    cout << endl;
    //Test operator[] with valid index
    cout << "Expected print x[0]: 25 Actual print: " << x[0] << endl;
    //Test removeRear()
    x.removeRear();
    cout << "Expected print: { 25, 50.87 } Actual print: ";
    x.print(); 
    cout << endl;

    cout << "Test Array y:" << endl;
    //Test explicit constructor
    dblArr y(5, 3);
    //Test capcity()
    cout << "Expected Capacity: 5 Actual Capacity: ";
    cout << y.capacity(); 
    cout << endl;
    //Test count()
    cout << "Expected Count: 0 Actual Count: ";
    cout << y.count(); 
    cout << endl;
    //Test operator=
    y = x;
    cout << "Expected y=x print: { 25, 50.87 } Actual print: ";
    y.print(); 
    cout << endl;

    //Test Copy Constructor
    dblArr z(x);
    cout << "Expected print: { 25, 50.87 } Actual print: ";
    z.print(); 
    cout << endl;

    
    //Invalid Test Cases

    //Test invalid default size
    dblArr u(-5, 25);
    cout << "Expected Capacity: 10 Actual Capacity: ";
    cout << u.capacity(); 
    cout << endl;

    
    //Test operator[] with invalid index
    //cout << "Expected print x[50]: program terminated Actual print: " << x[50] << endl;

    
    
}
