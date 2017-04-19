#include "dllist.cpp"

class ListQueue
{
    DllList list;
public:
    void push(void * el);
    void pop();
    void * top();

};
void ListQueue::push(void *el)
{
    list.insert(el, list.ptrend());
}

void ListQueue::pop()
{
    if(list.ptrbegin() != nullptr)
    {
       list.removeFront();
    }
    else return;
}

void * ListQueue::top()
{
    if(list.ptrbegin() != nullptr)
    {
        return list.ptrbegin()->data;
    }
    else return nullptr;
}
