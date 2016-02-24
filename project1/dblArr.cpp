/***************************************************************************
*  Author:    Rocio Ramirez-Jimenez, Brad Rutten                           *
*  Project:   1- Dynamic Arrays                                            *
*  File:      dblArr.cpp                                                   *
****************************************************************************/

#include <iostream>
#include <string>
#include "dblArr.h"
#include <cassert>
#include <cstdlib>

using namespace std;

/***************************************************************************
 *     constructor to allocate memmory for 'sz' entries                    *
 *     and initialize all entries to 'val'                                 *
****************************************************************************/
dblArr::dblArr ( int sz, double val )
{
    n = 0; //set n to 0
    //if invalid size, set size to default size (10)
    if(sz < 0)
    {
        size = DEFAULTSIZE; 
    }
    else
    {
        size = sz;
    }

    //Check if there is sufficient memory.
    try
    {
        element = new double[size]; //Allocate new memory
        for(int i = 0; i < size; i++)
        {
            element[i] = val; //set default values
        }
    }
    catch(bad_alloc & err)
    {
        //Report error and terminate program
        cout << "Insufficient memory: " << err.what(); 
        cout << "\n";
        exit(EXIT_FAILURE); //terminate program if insufficient memory
    }
}

/***************************************************************************
 *     Copy constructor                                                    *
****************************************************************************/
dblArr::dblArr ( const dblArr & other )
{
        //set attributes from other dblArr
        size = other.size;
        n = other.n;

        //Check if there is sufficient memory.
        try
        {
            element = new double[size];
            for(int i = 0; i < size; i++)
            {
                element[i] = other.element[i];
            }
        }
        catch(bad_alloc & err)
        {
            //Report error and terminate program
            cout << "Insufficient memory: " << err.what(); 
            cout << "\n";
            exit(EXIT_FAILURE); //terminate program if insufficient memory
        }
}

/***************************************************************************
 *     Destructor                                                          *
****************************************************************************/
dblArr::~dblArr()
{
    delete [] element; //deallocate the memory
}

/***************************************************************************
 *     Assign 'other' to this object                                       *
****************************************************************************/
const dblArr & dblArr::operator= ( const dblArr & other )
{
    if( this != & other)
    {
        delete [] element; //deallocate the memory

        //set the attributes from other dblArr
        size = other.size;
        n = other.n;

        //Check if there is sufficient memory.
        try
        {
            element = new double[size]; //allocate new memory
            
            //deep copy
            for(int i = 0; i < size; i++)
            {
                element[i] = other.element[i]; 
            }
        }
        catch(bad_alloc & err)
        {
            //Report error and terminate program
            cout << "Insufficient memory: " << err.what(); 
            cout << "\n";
            exit(EXIT_FAILURE); //terminate program if insufficient memory
        }
    }
}

/***************************************************************************
 *     Overload the subscript operator                                     *
****************************************************************************/
double & dblArr::operator[] ( int index )
{
    assert(index >= 0 && index<size); //check if valid index. 
                                      //if invalid, terminate program.
    return element[index];
}

/***************************************************************************
 *     Overload the subscript operator                                     *
****************************************************************************/
const double & dblArr::operator[] ( int index ) const
{
    assert(index >= 0 && index<size); //check if valid index.
                                      //if invalid, terminate program
    return element[index];
}

/***************************************************************************
 *       insert 'val' at rear of array                                     *
 *       terminate program in no room in array                             *
****************************************************************************/
void dblArr::addRear( double val ) 
{    
    element[count()] = val; //add value to element
    n++; //increment count
}

/***************************************************************************
 *       remove last element in array                                      *
****************************************************************************/
void dblArr::removeRear()
{
    element[count()-1] = DEFAULTINIT; //remove value and set to deafult.
    n--; //decrement count
}

/***************************************************************************
 *  Function to output the actually used entries in the array              *
****************************************************************************/
void dblArr::print() const
{
    cout << "{ ";

    //Go through each element in the dblArr
    for(int i = 0; i < count(); i++)
    {
        if (count() == 1 || i == count()-1) //check for first/last value
        {
            cout << element[i] << " ";
        }
        else
        {
            cout << element[i] << ", ";
        }
    }
    cout << "}" << endl;
}
