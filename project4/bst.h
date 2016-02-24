/***************************************************************************
 *  Author:    Mohamed Aboutabl                                            *
 *             Based on code by Goodrich, Tamassia, Mount.                 *
 *  Project:   04- Binary Search Trees                                     *
 *  File:      bst.h                                                       *
 *                                                                         *
 ***************************************************************************/

#ifndef BST_H
#define BST_H

#include <list>
#include <string>

using namespace std;

// Traversal Modes
#define PREORDER    1
#define INORDER     2
#define POSTORDER   3

//---------------------------------------------------------------------------
// Binary Search Tree Class Definition

typedef std::string Data_t ;

class bst   
{
  protected:
    //------------------------------------------------------------------------
    struct Node     // Layout of a typical node in the tree
    {
        Data_t  data;
        Node   *par , *left , *right ;    // Parent, Left & Right subtrees
        Node() : data()                     // Def. Constructor
        {  par = left = right = NULL ; }
    } ;
    //------------------------------------------------------------------------

  public:
    //------------------------------------------------------------------------
    class Position          // Position abstraction of a Node
    {
      private:
        Node * v;
      public:
        Position( Node * u = NULL ) ;   // Constructor
        Data_t & operator*() const ;    // Access node's data
        Position left()   const ;       // get node's left child
        Position right()  const ;       // get node's right child
        Position parent() const ;       // get node's parent
        bool isRoot()     const ;       // Is this the root?
        bool isExternal() const ;       // Is this an external node?
        bool isValid()    const ;       // Is this a position of a real node?

        friend class bst ;
    } ;
    //------------------------------------------------------------------------

    typedef std::list<Position> PositionList ;

    // Reporting Tree Properties
    int  nodeCount()          const ;
    int  externalCount()      const ;
    int  height()             const ;
    int  depth( Position p )  const ;
    bool isEmpty()            const ;

    // Node Access Functions
    Position root() const ;
    void positions( int mode , PositionList & pl) const; // internal nodes ONLY
    void printTree( int mode , Position p ) const ;

    // Update Functions 
    Position addRoot( Data_t val ) ;
    void     expandExternal( Position p );
    Position removeAboveExternal( Position p );
    Position insert( Data_t k ) ;
    void     erase( Data_t k );
    void     destroy() ;

    // Search Function
    Position search( Data_t k ) const ;  

    // Housekeeping Functions
    bst() ;                       // Constructor
    bst( const bst & other ) ;    // Copy Constructor
    ~bst() ;                      // Destructor
    const bst & operator=( const bst & other ) ;  // Assignment Operator
    
  private:    
    Node * _root ;          // pointer to the root node
    int    n ;              // count of nodes currenty in the tree

    // Some utility functions. You can add more of your own
    void     rec_destroy  ( Node * u ) ;    // by operator= and ~bst()
    void     rec_copyNodes( Node * u ) ;    // by operator= and copyConstructor
    void     rec_positions( Node * u , int mode , PositionList & pl ) const ;
    void     rec_print    ( Node * u , int mode ) const ;  // by printTree()
    int      rec_height   ( Node * u ) const ;  // used by height()
    int      rec_extCount ( Node * u ) const ;  // used by externalCount()
    Position rec_search   ( Node * u , Data_t k ) const ; // by search()
    
    int max(int a, int b) const;
};

#endif

