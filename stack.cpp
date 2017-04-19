#include "dllist.cpp"

class ListStack
{
    DllList list;
public:
    void push(void * el);
    void pop();
    void *last();
};

void ListStack::push(void *el)
{
    list.insert(el,list.ptrend());
}

void ListStack::pop()
{
    if(list.ptrbegin() != nullptr)
    {
       list.removeBack();
    }
    else return;
}

void * ListStack::last()
{
    if(list.ptrend() != nullptr)
    {
        return list.ptrend()->data;
    }
    else return nullptr;
}

