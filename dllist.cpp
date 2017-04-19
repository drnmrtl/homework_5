#include <cstdlib>
struct Node
{
    void * data;
    Node * prev;
    Node * next;
};

class DllList
{
    Node * begin;
    Node * end;
public:
    Node * ptrbegin() const
    {
        return begin;
    }

    Node * ptrend() const
    {
        return end;
    }

    Node * findNode(void * data) const
    {
        Node * _begin = begin;
        Node * _end = end;
        while ( (_begin != nullptr) && (_begin->data!= data) && (_end->data != data ) )
        {
            _begin = _begin->next;
            _end = _end->prev;
        }
        if ( (_begin->data == data) || (_begin == nullptr))
        {
            return _begin;
        }
        if ( _end->data == data)
        {
            return _end;
        }
        else return nullptr;
    }

    void insert(void* data, Node * Before)
    {
        Node * newNode = new Node ;
        newNode->data = data;
        if(Before == nullptr)
        {
            begin = newNode;
            end = newNode;
            return;
        }
        newNode->prev = Before;
        newNode->next = Before->next;
        if (Before->next != nullptr)
        {
           Before->next->prev = newNode;
        }
        Before->next = newNode;
    }

    void remove(Node * rNode)
    {
        if (rNode == nullptr)
        {
            return;
        }
        if (rNode == begin)
        {
            removeFront();
            return;
        }
        if (rNode == end)
        {
            removeBack();
            return;
        }
        rNode->prev->next = rNode->next;
        rNode->next->prev = rNode->prev;
        delete rNode;
        return;
    }
    void removeFront()
    {
        if (begin == nullptr)
        {
            return;
        }
        Node * d = begin;
        begin = begin->next;
        delete d;
        if (begin != nullptr)
        {
           begin->prev = nullptr;
        }
        else
        {
            end = nullptr;
        }
    }

    void removeBack()
    {
        if (end == nullptr)
        {
            return;
        }
        Node * d = end;
        end = end->prev;
        delete d;
        if (end != nullptr)
        {
            end->next = nullptr;
        }
        else
        {
            begin = nullptr;
        }
    }
    size_t size()
    {
        size_t i = 0;
        Node * n = begin;
        while(n != nullptr)
        {
            n = n->next;
            ++i;
        }
        return i;
    }

    DllList(): begin(nullptr), end(nullptr) {}

};
