///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief Contains pseudo-implementation part of bidirectional list structure 
/// template declared in the file's h-counterpart
///
/// © Sergey Shershakov 2015–2016
///
/// No part of this code can be used without an explicit permission of the author. 
/// The exception is done for educational goals of the course "Algorithms and Data 
/// Structures" provided by the School of Software Engineering of the Faculty 
/// of Computer Science at the Higher School of Economics.
///
/// When altering code, a copyright line must be preserved.
///////////////////////////////////////////////////////////////////////////////





#include <stdexcept>
#include "vector"


//==============================================================================
// class BidiList<T>::Node
//==============================================================================


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::Node::insertAfterInternal(Node* insNode)
{
    Node* afterNode = this->_next;      // an element, which was after node

    _next = insNode;

    if (afterNode)
        afterNode->_prev = insNode;

    insNode->_next = afterNode;
    insNode->_prev = this;


    return insNode;
}

//==============================================================================
// class BidiList<T>
//==============================================================================


template <typename T>
BidiLinkedList<T>::~BidiLinkedList()
{
    clear();
}


template <typename T>
void BidiLinkedList<T>::clear()
{
    Node* current = _head;

    while (current)
    {
        Node* temp = current;
        current = current->_next;
        delete temp;
    }

    _head = nullptr;

}

template <typename T>
size_t BidiLinkedList<T>::getSize()
{
    if (_size == NO_SIZE)
        calculateSize();

    return _size;
}


template <typename T>
void BidiLinkedList<T>::calculateSize()
{
    size_t count = 0;
    Node* current = _head;

    while (current)
    {
        count++;
        current = current->_next;
    }

    _size = count;
}



template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::getLastNode() const
{
    Node* current = _head;
    if (!current)
        return current;

    while (current->_next)
        current = current->_next;

    return current;
}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::appendEl(const T& val)
{
    Node* newNode = new Node(val);
    // !...
    // Здесь вырезана часть кода. Ее необходимо реализовать
    // !...

    // inserts after last node, size if going to e invalidated there
    return insertNodeAfter(getLastNode(), newNode);
}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::insertNodeAfter(Node* node, Node* insNode)
{
    if (!insNode)
        throw std::invalid_argument("`insNode` is nullptr");

    if (!node)
        node = getLastNode();

    // if last node is nullptr itself, it means that no elements in the list at all
    if (!node)
        _head = insNode;
    else
        node->insertAfterInternal(insNode);


    invalidateSize();

    return insNode;
}

template <typename T>
void BidiLinkedList<T>::insertNodesAfter(Node *node, Node *beg, Node *end)
{
    if (!beg || !end)
        throw std::invalid_argument("Beginning or end is nullptr!");

    if (!node)
        node = getLastNode();

    if (!node)
    {
        _head = beg;
        invalidateSize();
        return;
    }

    Node* afterNode = node->_next;

    node->_next = beg;
    beg->_prev = node;
    end->_next = afterNode;
    if (afterNode)
        afterNode->_prev = end;

    invalidateSize();
}




// Следующий фрагмент кода перестанет быть "блеклым" и станет "ярким", как только вы определите
// макрос IWANNAGET10POINTS, взяв тем самым на себя повышенные обязательства
#ifdef IWANNAGET10POINTS


template <typename T>
typename BidiLinkedList<T>::Node*
    BidiLinkedList<T>::insertNodeBefore(Node* node, Node* insNode)
{
    if (!insNode)
        throw std::invalid_argument("Inserting node is nullptr!");

    if (!node)
    {
        if (!_head)
        {
            _head = insNode;
            invalidateSize();
            return insNode;
        }

        insNode->_next = _head;
        _head->_prev = insNode;

        _head = insNode;
        _head->_prev = nullptr;
    }
    else
    {
        Node* beforeNode = node->_prev;

        beforeNode->_next = insNode;
        insNode->_prev = beforeNode;

        insNode->_next = node;
        node->_prev = insNode;
    }

    invalidateSize();

    return insNode;
}


template <typename T>
void BidiLinkedList<T>::insertNodesBefore(Node* node, Node* beg, Node* end)
{
    if (!beg || !end)
        throw std::invalid_argument("Either `beg` or `end` is nullptr!");

    if (!node)
    {
        beg->_prev = nullptr;

        if (!_head)
        {
            _head = beg;
            end->_next = nullptr;
            invalidateSize();
            return;
        }

        end->_next = _head;
        _head->_prev = end;
        _head = beg;
    }
    else
    {
        Node* beforeNode = node->_prev;

        beforeNode->_next = beg;
        beg->_prev = beforeNode;

        end->_next = node;
        node->_prev = end;
    }

    invalidateSize();
}



#endif // IWANNAGET10POINTS


template <typename T>
void BidiLinkedList<T>::cutNodes(Node* beg, Node* end)
{
    if (!beg || !end)
        throw std::invalid_argument("Either `beg` or `end` is nullptr");

    if (beg->_prev)
        beg->_prev->_next = end->_next;
    else
        _head = end->_next;

    if (end->_next)
        end->_next->_prev = beg->_prev;

    beg->_prev = nullptr;
    end->_next = nullptr;

    invalidateSize();
}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::cutNode(Node* node)
{
    if (!node)
        throw std::invalid_argument("Parameter `node` is nullptr!");

    if (node->_prev)
        node->_prev->_next = node->_next;
    else
        _head = node->_next;

    if (node->_next)
        node->_next->_prev = node->_prev;

    node->_next = nullptr;
    node->_prev = nullptr;

    invalidateSize();

    return node;
}


template <typename T>
typename BidiLinkedList<T>::Node* 
    BidiLinkedList<T>::findFirst(Node* startFrom, const T& val)
{
    while (startFrom)
    {
        if (startFrom->_val == val)
            return startFrom;
        startFrom = startFrom->_next;
    }

    return nullptr;     // not found
}



template <typename T>
typename BidiLinkedList<T>::Node** 
    BidiLinkedList<T>::findAll(Node* startFrom, const T& val, int& size)
{
    if (!startFrom)
        return nullptr;

    Node** res = nullptr;
    size = 0;

    invalidateSize();
    calculateSize();

    while (startFrom)
    {
        if (startFrom->_val == val)
        {
            if (!res)
                res = new Node*[_size];
            res[size] = startFrom;
            size++;
        }

        startFrom = startFrom->_next;
    }

    if (res)
    {
        Node** temp = new Node*[size];

        for (int i = 0; i < size; ++i)
            temp[i] = res[i];

        delete[] res;
        res = new Node*[size];

        for (int i = 0; i < size; ++i)
            res[i] = temp[i];

        delete[] temp;
    }

    return res;
}

// Следующий фрагмент кода перестанет быть "блеклым" и станет "ярким", как только вы определите
// макрос IWANNAGET10POINTS, взяв тем самым на себя повышенные обязательства
#ifdef IWANNAGET10POINTS

template <typename T>
typename BidiLinkedList<T>::Node**  
BidiLinkedList<T>::cutAll(Node* startFrom, const T& val, int& size)
{
    Node** arr = findAll(startFrom, val, size);

    for (int i = 0; i < size; ++i)
        arr[i] = cutFirst(val);

    invalidateSize();

    return arr;
}

#endif // IWANNAGET10POINTS