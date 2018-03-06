//#define IWANNAGET10POINTS

#include "BidiLinkedList.h"
#include <iostream>

typedef BidiLinkedList<int> IntBidiList;
typedef IntBidiList::Node IntBidiListNode;


/** \brief Helper function clears memory for given chain of nodes */
void clearNodes(IntBidiListNode* beg, IntBidiListNode* end)
{
    while (beg)
    {
        IntBidiListNode* nxt = beg->getNext();
        delete beg;
        beg = nxt;
    }
}


int main() {
    /*
    std::cout << "Hello, World!" << std::endl;
    IntBidiList lst;
    bool f;
    f = lst.getHeadNode() == nullptr;
    std::cout << f << std::endl;
    f = lst.getLastNode() == nullptr;
    std::cout << f << std::endl;
    f = lst.getSize() == 0;
    std::cout << f << std::endl;
    IntBidiListNode* nd1 = lst.appendEl(10);
    f = lst.getSize() == 1;
    std::cout << f << std::endl;

    f = lst.getHeadNode() == nullptr;
    std::cout << f << std::endl;
    f = lst.getLastNode() == nullptr;
    std::cout << f << std::endl;

    f = lst.getLastNode() == lst.getHeadNode();
    std::cout << f << std::endl;

    IntBidiListNode* nd2 = lst.appendEl(20);
    f = lst.getSize() == 2;
    std::cout << f << std::endl;

    f = lst.getLastNode() != lst.getHeadNode();
    std::cout << f << std::endl;

    f = lst.getHeadNode() == nd1;
    std::cout << f << std::endl;
    f = lst.getLastNode() == nd2;
    std::cout << f << std::endl;
    f = nd1->getNext() == nd2;
    std::cout << f << std::endl;
    f = nd2->getPrev() == nd1;
    std::cout << f << std::endl;

    IntBidiListNode* nd3 = new IntBidiListNode(15);
    lst.insertNodeAfter(nd1, nd3);

    f = nd1->getNext() == nd3;
    std::cout << f << std::endl;

    f = nd3->getNext() == nd2;
    std::cout << f << std::endl;

    f = nd2->getPrev() == nd3;
    std::cout << f << std::endl;

    f = nd3->getPrev() == nd1;
    std::cout << f << std::endl;

    IntBidiListNode* nd4 = new IntBidiListNode(18);
    lst.insertNodeAfter(nd3, nd4);

    f = nd3->getNext() == nd4;
    std::cout << f << std::endl;

    f = nd4->getNext() == nd2;
    std::cout << f << std::endl;

    f = nd4->getPrev() == nd3;
    std::cout << f << std::endl;

    f = nd2->getPrev() == nd4;
    std::cout << f << std::endl;
    */

    ///////////////////////////////////////////////////////
    /*
    IntBidiList lst;
    bool f;

    size_t sz = lst.getSize();
    f = 0 == sz;
    std::cout << f << std::endl;



    IntBidiListNode* nd1 = lst.insertNodeAfter(nullptr, new IntBidiListNode(10));
    sz = lst.getSize();
    f = 1 == sz;
    std::cout << f << std::endl;
    f = nd1 == lst.getHeadNode();
    std::cout << f << std::endl;
    f = nd1 == lst.getLastNode();
    std::cout << f << std::endl;

    IntBidiListNode* nd2 = lst.insertNodeAfter(nullptr, new IntBidiListNode(20));
    sz = lst.getSize();
    f = 2 == sz;
    std::cout << f << std::endl;
    f = nd1 == lst.getHeadNode();
    std::cout << f << std::endl;
    f = nd2 == lst.getLastNode();
    std::cout << f << std::endl;
    f = nd1->getNext() == nd2;
    std::cout << f << std::endl;

    IntBidiListNode* nd3 = lst.insertNodeAfter(nullptr, new IntBidiListNode(30));
    sz = lst.getSize();
    f = 3 == sz;
    std::cout << f << std::endl;
    f = nd1 == lst.getHeadNode();
    std::cout << f << std::endl;
    f = nd3 == lst.getLastNode();
    std::cout << f << std::endl;
    f = nd1->getNext() == nd2;
    std::cout << f << std::endl;
    f = nd2->getNext() == nd3;
    std::cout << f << std::endl;
    f = nd3->getPrev() == nd2;
    std::cout << f << std::endl;
    f = nd2->getPrev() == nd1;
    std::cout << f << std::endl;
     */
    //////////////////////////////////////////////////////


    /////////////////////////////////////////////////////
    /*
    IntBidiList lst;
    bool f;

    size_t sz = lst.getSize();
    f = 0 == sz;
    std::cout << f << std::endl;

    IntBidiListNode* nd1 = lst.appendEl(10);
    IntBidiListNode* nd2 = lst.appendEl(20);
    IntBidiListNode* nd3 = lst.appendEl(10);
    sz = lst.getSize();
    f = 3 == sz;
    std::cout << f << std::endl;

    IntBidiListNode* cutNd = lst.cutNode(nd2);
    sz = lst.getSize();
    f = 2 == sz;
    std::cout << f << std::endl;
    f = cutNd == nd2;
    std::cout << f << std::endl;

    f = nd1->getNext() == nd3;
    std::cout << f << std::endl;
    f = nd3->getPrev() == nd1;
    std::cout << f << std::endl;

    delete cutNd;
     */
    /////////////////////////////////////////////////////


    ////////////////////////////////////////////////////
    /*
    IntBidiList lst;
    bool f;

    size_t sz = lst.getSize();
    f = 0 == sz;
    std::cout << f << std::endl;

    IntBidiListNode* ndBeg = lst.appendEl(10);
    IntBidiListNode* nd1 = lst.appendEl(20);
    IntBidiListNode* nd2 = lst.appendEl(21);
    IntBidiListNode* nd3 = lst.appendEl(22);
    IntBidiListNode* ndEnd = lst.appendEl(30);

    sz = lst.getSize();
    f = 5 == sz;
    std::cout << f << std::endl;

    lst.cutNodes(nd1, nd3);
    sz = lst.getSize();
    f = 2 == sz;
    std::cout << f << std::endl;

    lst.insertNodesAfter(nullptr, nd1, nd3);
    sz = lst.getSize();
    f = 5 == sz;
    std::cout << f << std::endl;

    f = ndBeg->getNext() == ndEnd;
    std::cout << f << std::endl;
    f = ndEnd->getPrev() == ndBeg;
    std::cout << f << std::endl;

    f = ndEnd->getNext() == nd1;
    std::cout << f << std::endl;
    f = nd1->getPrev() == ndEnd;
    std::cout << f << std::endl;

    f = nd3->getNext() == nullptr;
    std::cout << f << std::endl;
    f = nd3->getPrev() == nd2;
    std::cout << f << std::endl;

    // put it back
    lst.cutNodes(nd1, nd3);
    sz = lst.getSize();
    f = 2 == sz;
    std::cout << f << std::endl;

    lst.insertNodesAfter(ndBeg, nd1, nd3);
    sz = lst.getSize();
    f = 5 == sz;
    std::cout << f << std::endl;

    f = ndBeg->getNext() == nd1;
    std::cout << f << std::endl;
    f = nd1->getPrev() == ndBeg;
    std::cout << f << std::endl;

    f = ndEnd->getPrev() == nd3;
    std::cout << f << std::endl;
    f = nd3->getNext() == ndEnd;
    std::cout << f << std::endl;
     */
    ////////////////////////////////////////////////////

    ///////////////////////////////////////////////////
    /*
    IntBidiList lst;
    bool  f;

    size_t sz = lst.getSize();
    f = 0 == sz;
    std::cout << f << std::endl;

    IntBidiListNode* nd1 = lst.appendEl(10);
    IntBidiListNode* nd2 = lst.appendEl(20);
    IntBidiListNode* nd3 = lst.appendEl(10);
    IntBidiListNode* nd4 = lst.appendEl(22);
    IntBidiListNode* nd5 = lst.appendEl(10);

    sz = lst.getSize();
    f = 5 == sz;
    std::cout << f << std::endl;

    // search empty
    IntBidiListNode* fnd = lst.findFirst(nullptr, 10);
    f = nullptr == fnd;
    std::cout << f << std::endl;

    // search first
    fnd = lst.findFirst(10);
    f = nd1 == fnd;
    std::cout << f << std::endl;

    // search second from the same node
    fnd = lst.findFirst(fnd, 10);
    f = nd1 == fnd;
    std::cout << f << std::endl;

    // search second from the next node
    fnd = lst.findFirst(fnd->getNext(), 10);
    f = nd3 == fnd;
    std::cout << f << std::endl;

    // search third from the next node
    fnd = lst.findFirst(fnd->getNext(), 10);
    f = nd5 == fnd;
    std::cout << f << std::endl;

    // search non-existing fourth
    fnd = lst.findFirst(fnd->getNext(), 10);
    f = nullptr == fnd;
    std::cout << f << std::endl;
     */
    ///////////////////////////////////////////////////

    ///////////////////////////////////////////////////
    /*
    IntBidiList lst;
    bool f;

    size_t sz = lst.getSize();
    f = 0 == sz;
    std::cout << f << std::endl;

    IntBidiListNode* nd1 = lst.appendEl(10);
    IntBidiListNode* nd2 = lst.appendEl(20);
    IntBidiListNode* nd3 = lst.appendEl(10);
    IntBidiListNode* nd4 = lst.appendEl(22);
    IntBidiListNode* nd5 = lst.appendEl(10);

    sz = lst.getSize();
    f = 5 == sz;
    std::cout << f << std::endl;

    // search empty
    int fndSize = 0;
    IntBidiListNode** fnd = lst.findAll(nullptr, 10, fndSize);
    f = nullptr == fnd;
    std::cout << f << std::endl;

    // search first
    fnd = lst.findAll(10, fndSize);
    f = nullptr != fnd;
    std::cout << f << std::endl;
    f = 3 == fndSize;
    std::cout << f << std::endl;
    f = nd1 == fnd[0];
    std::cout << f << std::endl;
    f = nd3 == fnd[1];
    std::cout << f << std::endl;
    f = nd5 == fnd[2];
    std::cout << f << std::endl;

    delete[] fnd;

    // search from second element
    fnd = lst.findAll(nd2, 10, fndSize);
    f = nullptr != fnd;
    std::cout << f << std::endl;
    f = 2 == fndSize;
    std::cout << f << std::endl;
    f = nd3 == fnd[0];
    std::cout << f << std::endl;
    f = nd5 == fnd[1];
    std::cout << f << std::endl;

    delete[] fnd;
     */
    ///////////////////////////////////////////////////


    ////////////////////////////////////////////////
    /*
    IntBidiList lst;
    bool f;

    size_t sz = lst.getSize();
    f = 0 == sz;
    std::cout << f << std::endl;

    IntBidiListNode* nd1 = lst.appendEl(10);
    IntBidiListNode* nd2 = lst.appendEl(20);
    IntBidiListNode* nd3 = lst.appendEl(10);
    IntBidiListNode* nd4 = lst.appendEl(22);
    IntBidiListNode* nd5 = lst.appendEl(10);

    sz = lst.getSize();
    f = 5 == sz;
    std::cout << f << std::endl;

    IntBidiListNode* cutNd = lst.cutFirst(10);
    sz = lst.getSize();
    f = 4 == sz;
    std::cout << f << std::endl;
    f = cutNd == nd1;
    std::cout << f << std::endl;
    delete cutNd;


    cutNd = lst.cutFirst(nd4, 10);
    sz = lst.getSize();
    f = 3 == sz;
    std::cout << f << std::endl;
    f = cutNd == nd5;
    std::cout << f << std::endl;
    delete cutNd;
     */
    //////////////////////////////////////////////


    /////////////////////////////////////////
    /*
    IntBidiList lst;
    bool f;

    size_t sz = lst.getSize();
    f = 0 == sz;
    std::cout << f << std::endl;


    IntBidiListNode* ndBeg = lst.appendEl(10);
    IntBidiListNode* nd1 = lst.appendEl(20);
    lst.appendEl(21);
    IntBidiListNode* nd2 = lst.appendEl(22);
    IntBidiListNode* ndEnd = lst.appendEl(30);

    sz = lst.getSize();
    f = 5 == sz;
    std::cout << f << std::endl;


    lst.cutNodes(nd1, nd2);
    sz = lst.getSize();
    f = 2 == sz;
    std::cout << f << std::endl;


    // clear memory
    clearNodes(nd1, nd2);
     */
    /////////////////////////////////////////


    ///////////////////////////////////////
    /*
    IntBidiList lst;
    bool f;

    size_t sz = lst.getSize();
    f = 0 == sz;
    std::cout << f << std::endl;

    IntBidiListNode* ndBeg = lst.appendEl(10);
    IntBidiListNode* nd1 = lst.appendEl(20);
    IntBidiListNode* nd2 = lst.appendEl(21);
    IntBidiListNode* nd3 = lst.appendEl(22);
    IntBidiListNode* ndEnd = lst.appendEl(30);

    sz = lst.getSize();
    f = 5 == sz;
    std::cout << f << std::endl;

    lst.cutNodes(ndBeg, nd3);
    sz = lst.getSize();
    f = 1 == sz;
    std::cout << f << std::endl;

    f = ndEnd == lst.getHeadNode();
    std::cout << f << std::endl;
    f = nullptr == ndEnd->getPrev();
    std::cout << f << std::endl;
    f = nullptr == ndEnd->getNext();
    std::cout << f << std::endl;
    // clear memory
    clearNodes(ndBeg, nd3);
     */
    ///////////////////////////////////////

    /////////////////////////////////////
    /*
    IntBidiList lst;
    bool f;

    size_t sz = lst.getSize();
    f = 0 == sz;
    std::cout << f << std::endl;

    IntBidiListNode* ndBeg = lst.appendEl(10);
    IntBidiListNode* nd1 = lst.appendEl(20);
    IntBidiListNode* nd2 = lst.appendEl(21);
    IntBidiListNode* nd3 = lst.appendEl(22);
    IntBidiListNode* ndEnd = lst.appendEl(30);

    sz = lst.getSize();
    f = 5 == sz;
    std::cout << f << std::endl;

    lst.cutNodes(nd1, ndEnd);
    sz = lst.getSize();
    f = 1 == sz;
    std::cout << f << std::endl;

    f = ndBeg == lst.getHeadNode();
    std::cout << f << std::endl;
    f = nullptr == ndBeg->getPrev();
    std::cout << f << std::endl;
    f = nullptr == ndBeg->getNext();
    std::cout << f << std::endl;

    // clear memory
    clearNodes(nd1, ndEnd);
     */
    /////////////////////////////////////

    /////////////////////////////////////
    /*
    IntBidiList lst;
    bool f;

    size_t sz = lst.getSize();
    f = 0 == sz;
    std::cout << f << std::endl;

    IntBidiListNode* ndBeg = lst.appendEl(10);
    IntBidiListNode* nd1 = lst.appendEl(20);
    IntBidiListNode* nd2 = lst.appendEl(21);
    IntBidiListNode* nd3 = lst.appendEl(22);
    IntBidiListNode* ndEnd = lst.appendEl(30);

    sz = lst.getSize();
    f = 5 == sz;
    std::cout << f << std::endl;

    lst.cutNodes(ndBeg, ndEnd);
    sz = lst.getSize();
    f = 0 == sz;
    std::cout << f << std::endl;

    f = nullptr == lst.getHeadNode();
    std::cout << f << std::endl;

    // clear memory
    clearNodes(ndBeg, ndEnd);
     */
    /////////////////////////////////////

    ////////////////////////////////////
    /*
    IntBidiList lst;
    bool f;

    size_t sz = lst.getSize();
    f = 0 == sz;
    std::cout << f << std::endl;

    IntBidiListNode* ndBeg = lst.appendEl(10);
    IntBidiListNode* nd1 = lst.appendEl(20);
    IntBidiListNode* nd2 = lst.appendEl(21);
    IntBidiListNode* nd3 = lst.appendEl(22);
    IntBidiListNode* ndEnd = lst.appendEl(30);

    sz = lst.getSize();
    f = 5 == sz;
    std::cout << f << std::endl;

    lst.cutNodes(nd1, nd3);
    sz = lst.getSize();
    f = 2 == sz;
    std::cout << f << std::endl;

    lst.insertNodesBefore(nullptr, nd1, nd3);
    sz = lst.getSize();
    f = 5 == sz;
    std::cout << f << std::endl;

    f = ndBeg->getNext() == ndEnd;
    std::cout << f << std::endl;
    f = ndEnd->getPrev() == ndBeg;
    std::cout << f << std::endl;

    f = nd3->getNext() == ndBeg;
    std::cout << f << std::endl;
    f = ndBeg->getPrev() == nd3;
    std::cout << f << std::endl;

    f = ndEnd->getNext() == nullptr;
    std::cout << f << std::endl;
    f = ndEnd->getPrev() == ndBeg;
    std::cout << f << std::endl;


    // put it back
    lst.cutNodes(nd1, nd3);
    sz = lst.getSize();
    f = 2 == sz;
    std::cout << f << std::endl;

    lst.insertNodesBefore(ndEnd, nd1, nd3);
    sz = lst.getSize();
    f = 5 == sz;
    std::cout << f << std::endl;

    f = ndBeg->getNext() == nd1;
    std::cout << f << std::endl;
    f = nd1->getPrev() == ndBeg;
    std::cout << f << std::endl;

    f = ndEnd->getPrev() == nd3;
    std::cout << f << std::endl;
    f = nd3->getNext() == ndEnd;
    std::cout << f << std::endl;
     */
    ////////////////////////////////////

    ////////////////////////////////
    /*
    IntBidiList lst;
    bool f;

    size_t sz = lst.getSize();
    f = 0 == sz;
    std::cout << f << std::endl;


    IntBidiListNode* nd1 = lst.insertNodeBefore(nullptr, new IntBidiListNode(30));
    sz = lst.getSize();
    f = 1 == sz;
    std::cout << f << std::endl;
    f = nd1 == lst.getHeadNode();
    std::cout << f << std::endl;
    f = nd1 == lst.getLastNode();
    std::cout << f << std::endl;

    IntBidiListNode* nd2 = lst.insertNodeBefore(nullptr, new IntBidiListNode(20));
    sz = lst.getSize();
    f = 2 == sz;
    std::cout << f << std::endl;
    f = nd2 == lst.getHeadNode();
    std::cout << f << std::endl;
    f = nd1 == lst.getLastNode();
    std::cout << f << std::endl;
    f = nd2->getNext() == nd1;
    std::cout << f << std::endl;

    IntBidiListNode* nd3 = lst.insertNodeBefore(nullptr, new IntBidiListNode(10));
    sz = lst.getSize();
    f = 3 == sz;
    std::cout << f << std::endl;
    f = nd3 == lst.getHeadNode();
    std::cout << f << std::endl;
    f = nd1 == lst.getLastNode();
    std::cout << f << std::endl;
    f = nd3->getNext() == nd2;
    std::cout << f << std::endl;
    f = nd2->getNext() == nd1;
    std::cout << f << std::endl;
    f = nd1->getPrev() == nd2;
    std::cout << f << std::endl;
    f = nd2->getPrev() == nd3;
    std::cout << f << std::endl;
     */
    ////////////////////////////////

    //////////////////////////////
    /*
    IntBidiList lst;
    bool f;

    size_t sz = lst.getSize();
    f = 0 == sz;
    std::cout << f << std::endl;

    IntBidiListNode* nd1 = lst.appendEl(10);
    IntBidiListNode* nd2 = lst.appendEl(20);
    IntBidiListNode* nd3 = lst.appendEl(10);
    IntBidiListNode* nd4 = lst.appendEl(22);
    IntBidiListNode* nd5 = lst.appendEl(10);

    sz = lst.getSize();
    f = 5 == sz;
    std::cout << f << std::endl;

    // search empty
    int fndSize = 0;
    IntBidiListNode** fnd = lst.cutAll(nullptr, 10, fndSize);
    f = nullptr == fnd;
    std::cout << f << std::endl;

    // search first
    fnd = lst.cutAll(10, fndSize);

    sz = lst.getSize();
    f = 2 == sz;       // only two more elements should be left
    std::cout << f << std::endl;


    f = nullptr != fnd;
    std::cout << f << std::endl;
    f = 3 == fndSize;
    std::cout << f << std::endl;
    f = nd1 == fnd[0];
    std::cout << f << std::endl;
    f = nd3 == fnd[1];
    std::cout << f << std::endl;
    f = nd5 == fnd[2];
    std::cout << f << std::endl;

    delete[] fnd;
    */
    //////////////////////////////
    return 0;
}