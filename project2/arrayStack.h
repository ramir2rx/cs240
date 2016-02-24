//------------------------------------------------------------------
// Array-Based Stack Implementation
// Author: Goodrich, Tamassia, Mount
// Edited/Modified by (v1): Mohamed Aboutabl
// Edited/Modified by (v2): Rocio Ramirez-Jimenez & Bradly Rutten 
//------------------------------------------------------------------

#ifndef ARRAYSTACK
#define ARRAYSTACK

#include <string>
#include <iostream>

using namespace std;

#define MAX_CAPACITY 100

class StackExcp
{
    public:
        StackExcp ( const string & err ) { errMsg=err; } ;
        string what() { return errMsg; } ;
    private:
        string errMsg ;
};

template <typename E>
class ArrayStack
{
  public:
    ArrayStack(int cap = MAX_CAPACITY);          // constructor from capacity
    int size() const;                           // number of items in the stack
    bool empty() const;                         // is the stack empty?
    const E& top() const    throw(StackExcp);  // get the top element
    void push(const E& e)   throw(StackExcp);  // push element e onto stack
    void pop()               throw(StackExcp);  // pop the stack

    //...housekeeping functions omitted
    // copy constructor, destructor & assignment operator.
    ArrayStack(const ArrayStack & other);
    ~ArrayStack();
    const ArrayStack<E> & operator=(const ArrayStack<E> & other);
    

    void print() const;                        // print all elements for
                                                // debugging purposes only
                                                
  private:
    E* S ;                // array of stack elements
    int capacity ;       // stack capacity                                        
    int t ;              // index of the top of the stack
}; 


//------------------------------------------------------------------
// constructor from capacity
//------------------------------------------------------------------
template <typename E>
ArrayStack<E>::ArrayStack(int cap)
    // : S(new E[cap]), capacity(cap), t(-1) { }
{
    S = new E[cap] ;
    capacity = cap ;
    t = -1 ;
}

//------------------------------------------------------------------
// number of items in the stack
//------------------------------------------------------------------
template <typename E>
int ArrayStack<E>::size() const
{
    return ( t + 1 ) ;
}

//------------------------------------------------------------------
// is the stack empty?
//------------------------------------------------------------------
template <typename E>
bool ArrayStack<E>::empty() const
{
    return ( t < 0 ) ;
}

//------------------------------------------------------------------
// return top of stack
//------------------------------------------------------------------
template <typename E>
const E& ArrayStack<E>::top() const
          throw(StackExcp)
{
    if ( empty() )
        throw StackExcp("Top of empty stack") ;
    return S[t] ;
}

//------------------------------------------------------------------
// push element onto the stack
//------------------------------------------------------------------
template<typename E>
void ArrayStack<E>::push(const E& e)
    throw(StackExcp)
{
    if (size() == capacity)
        throw StackExcp("Push to full stack") ;
    S[++t] = e;
}

//------------------------------------------------------------------
// pop the stack
//------------------------------------------------------------------
template<typename E>
void ArrayStack<E>::pop()
    throw(StackExcp) 
{
    if ( empty() )
        throw StackExcp("Pop from empty stack");
    --t;
}

//------------------------------------------------------------------
// Print Stack content for debugging purpose: bottom to top
//------------------------------------------------------------------
template<typename E>
void ArrayStack<E>::print() const
{
    cout << "[" ;
    if ( ! empty() )
    {
        cout << " " << S[0];
        for (int i = 1 ; i <= t ; i++)
            cout << " , " << S[i] ;
    }
    cout << " ] with size= " << size() << " t=" << t << endl ;
}

//------------------------------------------------------------------
// copy constructor
//------------------------------------------------------------------
template <typename E>
ArrayStack<E>::ArrayStack(const ArrayStack & other)
{
        //set attributes from other ArrayStack
        capacity = other.capacity;
        t = other.t;
       
        //copy data from other stack
        S = new E[capacity];
        for (int i = 0; i < capacity; i++)
        {
            S[i] = other.S[i];
        }
}

//------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------
template <typename E>
ArrayStack<E>::~ArrayStack()
{
    delete [] S; //deallocate the memory
}

//------------------------------------------------------------------
// Assignment Operator
//------------------------------------------------------------------
template <typename E>
const ArrayStack<E> & ArrayStack<E>::operator= (const ArrayStack<E> & other)
{
    if( this != & other)
    {
        delete [] S; //deallocate the memory
 
        //set attributes from other ArrayStack
        capacity = other.capacity;
        t = other.t;
        
        S = new E[other.size()]; //allocate new memory
             
        //deep copy
        for(int i = 0; i < other.size(); i++)
        {
            S[i] = other.S[i];
        }
        
    }
    
    return *this;
}
#endif

