//------------------------------------------------------------------
// BST Implementation
// Author: Rocio Ramirez-Jimenez & Bradly Rutten 
//------------------------------------------------------------------
#include "bst.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    bst tree;
    bst::Position ptree;
    
    //Testing is Empty
    cout << "isEmpty (expecting 1): " << tree.isEmpty() << endl;
   
    //Add root
    ptree = tree.addRoot("Root");
    //Test addRoot
    cout << "_root = " << *ptree << endl;
    
    //Test nodeCount
    cout << "Node Count (expecting 3): " << tree.nodeCount() << endl;
    
    //External Count
    cout << "External Count (expecting 2): " << tree.externalCount() << endl;
    
    //Test Height
    cout << "Height (expecting 1): " << tree.height() << endl;
    
    //Test Depth
    cout << "Depth (expecting 0): " << tree.depth(ptree) << endl;
    
    //Test isRoot
    cout << "isRoot (expecting 1): " << ptree.isRoot() << endl;
    
    //Test isExternal
    cout << "isExternal (expecting 0): " << ptree.isExternal() << endl;
    
    //Test isEmpty
    cout << "isEmpty (expecting 0): " << tree.isEmpty() << endl;
    
    //**************Test addRoot ************
    //cout << "addRoot (expecting program termination)" << tree.addRoot("New Root") << endl;
    
    cout << endl;
    
    bst::Position left = ptree.left();
    bst::Position leftChild = left.left();
    //Test left external
    cout << "isValid left (expecting 1): " << left.isValid() << endl;
    cout << "isValud leftChild (expecting 0): " << leftChild.isValid() << endl;
    cout << "isExternal left (expecting 1): " << left.isValid() << endl;
    cout << "isRoot left (expecting 0): " << left.isRoot() << endl;
    cout << "left child depth (expecting 1): " << tree.depth(left) << endl;
    
    cout << endl;
    
    bst::Position right = ptree.right();
    bst::Position rightChild = right.right();
    
    //Test right external
    cout << "isValid right (expecting 1): " << right.isValid() << endl;
    cout << "isValud rightChild (expecting 0): " << rightChild.isValid() << endl;
    cout << "isExternal right (expecting 1): " << right.isValid() << endl;
    cout << "isRoot right (expecting 0): " << right.isRoot() << endl;
    cout << "right child depth (expecting 1): " << tree.depth(right) << endl;
    
    //Test removeAboveExternal
    tree.removeAboveExternal(left);
    cout << "removeAboveExternal (expecting 1): " << right.isRoot() << endl;

    //Test max
    cout << endl;
    cout << "The max number is: " << max(10, 5) << endl;
    cout << "The max number is: " << max(5, 10) << endl;
    cout << "The max number is: " << max(10, 10) << endl;
    cout << endl;

    bst tree2;
    bst::Position p;
    bst::Position q;
    p = tree2.addRoot("Root");
    cout << "ROOT: " << *p << endl;
    q = tree2.insert("Hello");
    cout << "Test Insert: " << *p << endl;
    cout << "Height: " << tree2.height() << endl;
    cout << "Depth of q: " << tree2.depth(q) << endl;
    cout << "Is the parent of the current position valid? (The Root) (Expecting 1) ";
    cout << (p.parent()).isValid() << endl;
    cout << endl;

    //Test insert
    tree2.insert("Test");
    tree2.insert("Apple");
    tree2.insert("Brad");
    tree2.insert("Rocio");

    //Test print
    cout << "Test printing tree: " << endl;
    cout << "Preorder:" << endl;
    tree2.printTree(1, p);
    cout << endl;
    cout << "Inorder:" << endl;
    tree2.printTree(2, p);
    cout << endl;
    cout << "Postorder:" << endl;
    tree2.printTree(3, p);
    cout << endl;
    cout << endl;
    cout << "Tree 2 node count " << tree2.nodeCount() << endl;

    //Test Positions
    bst::PositionList pl1;
    tree2.positions(1, pl1);
    
    bst::PositionList pl2;
    tree2.positions(2, pl2);
    
    bst::PositionList pl3;
    tree2.positions(3, pl3);
    
    //Test copyConstructor
    cout << endl;
    bst tree3(tree2);
    cout << "Test Copy Constucor (using nodeCount())" << endl;
    cout << "Tree2 " << tree2.nodeCount() << endl;
    cout << "Tree3 " << tree3.nodeCount() << endl;
    cout << "print three3: " << endl;
    cout << endl;

    //Test destroy
    tree3.destroy();
    cout << "Test destory: " << endl;
    cout << "Node Count for tree3: " << tree3.nodeCount() << endl;
    cout << endl;

    //Test operator=
    tree3 = tree2;
    cout << "Test operator= " << endl;
    cout << "Tree2 nodeCount: " << tree2.nodeCount() << endl;
    cout << "Tree3 nodeCount: " << tree3.nodeCount() << endl;
    bst::Position m;
    m = tree3.root();

    //Test erase
    cout << "Print tree2: " << endl;
    tree2.printTree(1, p);
    cout << endl;
    cout << "Print tree3 after operator=" << endl;
    tree3.printTree(1, m);
    cout << endl;
    tree2.erase("Hello");
    tree2.erase("Root");
    tree2.printTree(1, p);
    cout << endl;
    
    bst tree4;
    tree4.erase("NOT VALID");

    //test root() parent() left() and right() 
    bst tree5;
    bst::Position p2;
    tree5.insert("M");
    tree5.insert("A");
    tree5.insert("Z");
    p2 = tree5.root();
    cout << "Root Position Value(expecting M): " << *p2 << endl;
    p2 = p2.left();
    cout << "Left Position of Root Vale (expecting A): " << *p2 << endl;
    p2 = p2.right();
    cout << "Right Position of Root Vale (expecting Z): " << *p2 << endl;
    p2 = p2.parent();
    cout << "Parent Position of Right Vale (expecting M): " << *p2 << endl;

    //test Search
    p2 = tree5.search("A");
    cout << "Searched for A found: " << *p2 << endl;
    p2 = tree5.search("hello");
    cout << "Searched for hello (expecting null): " << *p2 << endl;   
}
