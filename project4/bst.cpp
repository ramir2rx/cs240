/***************************************************************************
 *  Author:    Rocio Ramirez-Jimenez & Brad Rutten                         *
 *             Based on code by Goodrich, Tamassia, Mount.                 *
 *  Project:   04- Binary Search Trees                                     *
 *  File:      bst.cpp                                                     *
 *                                                                         *
 ***************************************************************************/

#include "bst.h"
#include <assert.h>
#include <iostream>

/***************************************************************************
*     Postion Constructor                                                  *
****************************************************************************/
bst::Position::Position( Node * u)
{
    v = u;
}

/***************************************************************************
*     Overloaded dereferencing operator to access the node's data          *
****************************************************************************/
Data_t & bst::Position::operator*() const
{
    return v->data;
}

/***************************************************************************
*     Returns the node's left child                                        *
****************************************************************************/
bst::Position bst::Position::left()   const
{
    return Position(v->left);
}

/***************************************************************************
*     Returns the node's right child                                       *
****************************************************************************/
bst::Position bst::Position::right()  const
{
    return Position(v->right);
}

/***************************************************************************
*     Returns the node's parent                                            *
****************************************************************************/
bst::Position bst::Position::parent() const
{
    return Position(v->par);
}

/***************************************************************************
*     Check if current node is the root                                    *
****************************************************************************/
bool bst::Position::isRoot()     const
{
    return v->par == NULL;
}

/***************************************************************************
*     Check if current node is external                                    *
****************************************************************************/
bool bst::Position::isExternal() const
{
    return (v->left == NULL && v->right == NULL) ;
}

/***************************************************************************
*     Check if current node has valid data                                 *
****************************************************************************/
bool bst::Position::isValid()    const
{
    return (v != NULL);
}
/***************************************************************************
*     Return tree's node count                                             *
****************************************************************************/
int  bst::nodeCount()          const
{
    return n;
}

/***************************************************************************
*     Return tree's external node count                                    *
****************************************************************************/
int  bst::externalCount()      const
{
    if(_root != NULL)
    {
        return rec_extCount(_root);
    }
    else
    {
         return 0;    
    }
}

/****************************************************************************
 *     Return the tree's height                                             *
 ****************************************************************************/
int  bst::height()             const
{
    if(_root != NULL)
    {
        return rec_height(_root);
    }
    else
    {
        return 0;    
    }
}

/****************************************************************************
 *     Return the tree's depth                                              *
 ****************************************************************************/
int  bst::depth( Position p )  const
{
     if(!p.isRoot())
    {
        return 1 + depth(p.parent());
    }
    else
    {
         return 0;    
    }
}

/****************************************************************************
 *     Check if tree is Empty                                               *
 ****************************************************************************/
bool bst::isEmpty()            const 
{
    return n == 0;
}

/****************************************************************************
 *     Return tree's external node count                                    *
 ****************************************************************************/
bst::Position bst::root() const
{
    return Position(_root);
}

/****************************************************************************
 *     Add positions to PositionList in order of the mode specified         *
 ****************************************************************************/
void bst::positions( int mode , PositionList & pl) const // internal nodes ONLY
{
    if(_root != NULL)
    {
        rec_positions(_root, mode, pl);
    }
}

/****************************************************************************
 *     Print nodes according to the mode given                              *
 ****************************************************************************/
void bst::printTree( int mode , Position p ) const
{
    if(p.isValid())
        rec_print(p.v, mode);
    else
        cout << "Starting Position is not Valid..." << endl;
}

/****************************************************************************
 *     Add Root                                                             *
 ****************************************************************************/
bst::Position bst::addRoot( Data_t val )
{
    Position p;
    assert(_root == NULL && n == 0);
    _root = new Node;
    n = 1;
    p = Position(_root);
    expandExternal(p);
    _root->data = val;
    return p;
}

/****************************************************************************
 *     Add dummy node's to the position given                               *
 ****************************************************************************/
void     bst::expandExternal( Position p )
{
    Node* v = p.v;
    v->left = new Node;
    v->left->par = v;
    v->right = new Node;
    v->right->par = v;
    n += 2;
}

/****************************************************************************
 *     Remove above external node position                                  *
 ****************************************************************************/
bst::Position bst::removeAboveExternal( Position p )
{
    Node* w = p.v;
    Node* v = w->par;
    Node* sib = (w == v->left ? v->right : v->left);
    if (v == _root)
    {
        _root = sib;
        sib->par = NULL;
    }
    else
    {
        Node* gpar = v-> par;
        if(v == gpar->left) gpar->left = sib;
        else gpar->right = sib;
        sib->par = gpar;
    }
    delete w; delete v;
    n -= 2;
    return Position(sib);
}

/****************************************************************************
 *     Insert a new node                                                    *
 ****************************************************************************/
bst::Position bst::insert( Data_t k )
{
    Position p = search(k);
   if (!p.isValid())
   {
       p = addRoot(k);
       return p;
   }
   else if(p.isExternal())
   {
       expandExternal(p);
       *p = k;
       return p;
   }
   else
   {
       return p;
   }
}

/****************************************************************************
 *     Erase value from tree                                                *
 ****************************************************************************/
void     bst::erase( Data_t k )
{
    if(_root != NULL)
    {
        Position v = search(k);
        Position w;
        if(v.left().isExternal())
        {
            w = v.left();
        }
        else if(v.right().isExternal())
        {
            w = v.right();
        }
        else
        {
            w = v.right();
            do
            {
                w = w.left();
            }
            while(!w.isExternal());
            Position u = w.parent();
            *v = *u;
        }
        
        removeAboveExternal(w);
    }   
}

/****************************************************************************
 *     Delete each node in the tree                                         *
 ****************************************************************************/
void     bst::destroy()
{
    if(_root != NULL)
    {
        rec_destroy(_root);
    }
    _root = NULL;
    n = 0;
}

/****************************************************************************
 *     Search tree for the given value                                      *
 ****************************************************************************/
bst::Position bst::search( Data_t k ) const 
{
    if(_root != NULL)
    {
        return rec_search(_root, k );
    }
    else
    {
        return Position(NULL);
    }

}

/****************************************************************************
 *     Binary Search Tree Constructor                                       *
 ****************************************************************************/
bst::bst()
{
    _root = NULL;
    n = 0;
}

/****************************************************************************
 *     Binary Search Tree Copy Constructor                                  *
 ****************************************************************************/
bst::bst( const bst & other )
{
    _root = NULL;
    n = 0;
    if(other._root != NULL)
    {
        rec_copyNodes(other._root);
    }
    else
    {
        return;
    }
    
}

/****************************************************************************
 *     Binary Search Tree Destructor                                        *
 ****************************************************************************/
bst::~bst()
{
    if(_root != NULL)
    {
        rec_destroy(_root);
    }
}

/****************************************************************************
 *     Assign 'other' to this object                                        *
 ****************************************************************************/
const bst & bst::operator=( const bst & other )
{
    if(_root != NULL)
    {
        destroy();
    }
    if(other._root != NULL)
    {
        rec_copyNodes(other._root);
    }
}

/****************************************************************************
 *     operator= and ~bst() utility function                               *
 ****************************************************************************/
void     bst::rec_destroy  ( Node * u )
{
    if(u!= NULL)
    {
        if(u->left != NULL)
            rec_destroy(u->left);
        if(u->right != NULL)
            rec_destroy(u->right);
        
        delete u;
    }
    return;
}

/****************************************************************************
 *     operator= and copyConstructor utility function                       *
 ****************************************************************************/
void     bst::rec_copyNodes( Node * u )
{
    if(u->left == NULL && u->right == NULL)
    {
        return;
    }
    insert(u->data);
    rec_copyNodes(u->left);
    rec_copyNodes(u->right);
}

/****************************************************************************
 *     operator= and copyConstructor utility function                       *
 ****************************************************************************/
void     bst::rec_positions( Node * u , int mode , PositionList & pl ) const 
{
    if(u->left == NULL && u->right == NULL)
    {
        return;
    }
    if(mode == PREORDER)
    {
        pl.push_back(Position(u));
    }
    rec_positions(u->left, mode, pl);
    if (mode == INORDER)
    {
        pl.push_back(Position(u));
    }
    rec_positions(u->right, mode, pl);
    if(mode == POSTORDER)
    {
        pl.push_back(Position(u));
    }
}

/****************************************************************************
 *     positions() utility function                                         *
 ****************************************************************************/
void     bst::rec_print    ( Node * u , int mode ) const 
{
    if(u->left == NULL && u->right == NULL)
    {
        cout << "_ ";
        return;
    }
    cout << "( ";
    if(mode == PREORDER)
    {
        cout << u->data;
    }
    rec_print(u->left, mode);
    if (mode == INORDER)
    {
        cout << u->data;
    }
    rec_print(u->right, mode);
    if(mode == POSTORDER)
    {
        cout << u->data;
    }
    cout << " )";
}

/****************************************************************************
 *     height() utility function                                            *
 ****************************************************************************/
int      bst::rec_height   ( Node * u ) const
{
    if(u->left == NULL && u->right == NULL)
    {
        return 0;
    }
    else
    {
        return(1 + max(rec_height(u->left), rec_height(u->right)));
    }
}

/****************************************************************************
 *     externalCount() utility function                                     *
 ****************************************************************************/
int      bst::rec_extCount ( Node * u ) const 
{
    if(u->left == NULL && u -> right == NULL)
    {
        return 1;
    }
    else
    {
        return (rec_extCount(u->left) + rec_extCount(u->right));
    }
}

/****************************************************************************
 *     search() utility function                                            *
 ****************************************************************************/
bst::Position bst::rec_search   ( Node * u , Data_t k ) const 
{
    if(u->left == NULL && u->right == NULL)
    {
        return Position(u);
    }
    else if(u->data == k)
    {
        return Position(u);
    }
    else if(k < u->data)
    {
        return rec_search(u->left, k);
    }
    else if(k > u->data)
    {
        return rec_search(u->right, k);
    }
}

/****************************************************************************
 *    height() utility function                                             *
 ****************************************************************************/
int bst::max(int a, int b) const
{
    return (a >= b ? a : b);

}
