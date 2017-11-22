
#include <iostream>
#include "stack.h"

template <typename T>
class QueueUsingStacks
{
    LStack<T> toPush;
    LStack<T> toPop;
public:
    void enqueue (T const &x);
    T dequeue();
    T top()
    {
        return toPush.top();
    }
};
template <typename T>
void QueueUsingStacks<T>::enqueue (T const &x)
{
    while(!toPush.empty())
    {
        toPop.push(toPush.pop());
    }
    toPush.push(x);
    while(!toPop.empty())
    {
        toPush.push(toPop.pop());
    }
}
template <typename T>
T QueueUsingStacks<T>::dequeue()
{
    if(toPush.empty())
    {
        std::cout << "Queue is empty\n";
        return T();
    }
    return toPush.pop();
}
int main()
{
    QueueUsingStacks<int> queue;
    int n;
    int printCounter = 0;
    std::cin >> n;
    int* topPrint = new int[n];
    for (int i = 0; i < n; i++)
    {
        int query;
        std::cin >> query;
        switch(query)
        {
        case 1:
            int x;
            std::cin >> x;
            queue.enqueue(x);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            topPrint[printCounter]=queue.top();
            printCounter++;
            break;
        }
    }
    for (int i = 0; i < printCounter; i++)
    {
        std::cout << topPrint[i] << std::endl;
    }
    return 0;
}
