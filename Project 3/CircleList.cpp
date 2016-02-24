#include "CircleList.h"
#include <iostream>
#include <string>

using namespace std;

CircleList::CircleList()
    :cursor(NULL) {}

CircleList::CircleList(const CircleList & other)
{
    cursor = NULL;
    if (other.empty())
    {
        cursor = NULL;
    }
    else
    {
        CNode* p = other.cursor->next;
        do
        { 
            add(p->elem);
            p = p->next;
            advance() ; // cursor = cursor->next;
        }       
        while(p != other.cursor->next);
    }
}

CircleList::~CircleList()
{
    while(!empty()) 
        remove();
}

const CircleList& CircleList::operator=(const CircleList & other)
{
    delete cursor;
    cursor = NULL;
    
    if (other.empty())
    {
        cursor = NULL;
    }
    else
    {
        CNode* p = other.cursor->next;
        do
        {
            add(p->elem);
            p = p->next;
            advance() ; // cursor = cursor->next;
        }
        while(p != other.cursor->next);
    }
}

bool CircleList::empty() const
{
    return cursor == NULL;
}

const int& CircleList::front() const
{
    return cursor->next->elem;
}

const int& CircleList::back() const
{
    return cursor->elem;
}

void CircleList::advance()
{
    cursor = cursor->next;
}         

void CircleList::add(const int& e)
{
    CNode* v = new CNode;
    v->elem = e;
    if (cursor == NULL)
    {
        v->next = v;
        cursor = v;
    }
    else
    {
        v->next = cursor->next;
        cursor->next = v;
    }
}

void CircleList::remove()
{
    CNode* old = cursor->next;
    if (old == cursor)
        cursor = NULL;
    else
        cursor->next = old->next;
    delete old;
}

void CircleList::printNodes()
{
    CNode* p = cursor->next;
    do
    {
        cout << p->elem << " ";
        p = p->next;
    }
    while(p != cursor->next);
    cout << endl;
}

CircleList::Iterator::Iterator(CNode* u)
{ 
    v = u; 
}

int& CircleList::Iterator::operator*()
{
    return v->elem;
}

bool CircleList::Iterator::operator==(const Iterator& p) const
{
    return v == p.v;
}

bool CircleList::Iterator::operator!=(const Iterator& p) const
{
    return v != p.v;
}

CircleList::Iterator& CircleList::Iterator::advance(const CircleList& a)
{
    if( v == a.cursor )
    {
        v = NULL;
    }
    else
    {
        v = v->next;
    }
    return *this;
}

CircleList::Iterator CircleList::begin() const
{
    return Iterator(cursor->next);
}
CircleList::Iterator CircleList::end() const
{
    return Iterator(cursor);
}