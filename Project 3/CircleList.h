//------------------------------------------------------------------
// Circle List  Implementation
// Author: Goodrich, Tamassia, Mount
// Edited/Modified by (v1): Rocio Ramirez-Jimenez & Bradly Rutten 
//------------------------------------------------------------------
#ifndef CIRCLELIST
#define CIRCLELIST

class CircleList                    // a circularly linked list
{
private:
    struct CNode
    {                         // circularyly linked list node
        int elem;                         // linked list element value
        CNode* next;                      // next item in the list 
    };
public:
    class Iterator
    {
        public:
            int& operator*();
            bool operator==(const Iterator& p) const;
            bool operator!=(const Iterator& p) const;
            Iterator& advance(const CircleList& a);
            friend class CircleList;
        private:
            CNode* v;
            Iterator(CNode* u);
    };
public:
    CircleList();                   
        // constructor
        
    CircleList(const CircleList & other);  
        // copy constructor
        
    ~CircleList();
        // destructor
        
    Iterator begin() const;
        // beginning position
    
    Iterator end() const;
        // (just beyond) last position
    
    const CircleList & operator=(const CircleList & other);
        //assign other to this
        
    bool empty() const;            
        // is list empty?
        
    const int& front() const;     
        // element at cursor
        
    const int& back() const;      
        // element following cursor
        
    void advance();                 
        // advance cursor
        
    void add(const int& e);       
        // add after cursor
        
    void remove();                 
        // remove node after cursor
    void printNodes();
        // print the data fields of all nodes

    friend class Iterator;
private:
    CNode* cursor;                  // the cursor
};
#endif