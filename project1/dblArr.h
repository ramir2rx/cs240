/***************************************************************************
*  Author:    Rocio Ramirez-Jimenez, Brad Rutten                           *
*  Project:   1- Dynamic Arrays                                            *
*  File:      dblArr.h                                                     *
****************************************************************************/

#ifndef DBLARR_H
#define DBLARR_H

using namespace std;

#define DEFAULTSIZE 10
#define DEFAULTINIT 0.0

class dblArr
{
    double *element;  // dynamically allocated array of doouble-precision
    int size ,        // max capacity of array
        n ;           // actually used entries of array
public:
    dblArr ( int sz = DEFAULTSIZE, double val = DEFAULTINIT ) ;
        // constructor to allocate memmory for 'sz' entries
        // and initialize all entries to 'val'

    dblArr ( const dblArr & other ) ;
        // Copy constructor

    ~dblArr() ;
        // Destructor

    const dblArr & operator= ( const dblArr & other ) ;
        // assign 'other' to this object

        double & operator[] ( int index ) ;
    const double & operator[] ( int index ) const ;
        // overload the subscript operator

    int capacity () const {return size; } ;
        // report the maximum capacity of array

    int count() const { return n; };
        // report number of actually used entries in array

    void addRear( double val ) ;
        // insert 'val' at rear of array
        // terminate program in no room in array

    void removeRear() ;
        // remove last element in array

    void print() const ;
        //Function to output the actually used entries in the array
};
 #endif
