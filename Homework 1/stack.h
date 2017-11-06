#ifndef STACK_H
#define STACK_H
#include <iostream>
template <typename T>
struct node
{
    T data;
    node* next;
};
template <typename T>
class LStack
{
    node<T>* topNode;
    void copy(node<T>* toCopy);
    void eraseStack();
    void copyStack (LStack const& ls);
public:
    LStack();
    LStack(LStack const&);
    LStack& operator=(LStack const& ls);
    ~LStack();
    bool empty() const;
    void push(T const& x);
    T pop();
    T top() const;
    T findMaximal() const;

};

template <typename T>
void LStack<T>::copy(node<T>* toCopy)
{
    if (toCopy == NULL)
        return;
    copy(toCopy->next);
    push(toCopy->data);
}
template <typename T>
void LStack<T>::copyStack (LStack const& ls)
{
    topNode = NULL;
    copy(ls.topNode);
}
template <typename T>
void LStack<T>::eraseStack()
{
    while(!empty())
        pop();
}
template <typename T>
bool LStack<T>::empty() const
{
    return topNode == NULL;
}
template <typename T>
LStack<T>::LStack()
{
    topNode = NULL;
}
template <typename T>
LStack<T>::LStack(LStack const& ls)
{
    copyStack(ls);
}
template <typename T>
LStack<T>::~LStack()
{
    eraseStack();
}
template <typename T>
void LStack<T>::push(T const& x)
{
   node<T>* newNode = new node<T>;
   newNode->data = x;
   newNode->next = topNode;
   topNode = newNode;
}
template <typename T>
T LStack<T>::pop()
{
    if(empty())
    {
        std::cout << "empty stack\n";
        return 0;
    }
    node<T>* p = topNode;
    topNode = topNode->next;
    T x = p->data;
    delete p;
    return x;
}
template <typename T>
T LStack<T>::top() const
{
    if(empty())
        return 0;
    return topNode->data;
}
template <typename T>
T LStack<T>::findMaximal() const
{
    T maximal = topNode->data;
    node<T>* p = topNode;
    while(p->next != NULL)
        {
            p = p->next;
            if(p->data > maximal)
                maximal = p->data;
        }

    return maximal;
}
#endif
