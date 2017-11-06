#include <iostream>
#include "stack.h"

int maximalElements[100000]; // where we save all the maximum elements returned from type 3 querry so we can print them later
int main()
{
    LStack<int> s;
    int n;
    int querryType;
    int elementsCounter = 0; // counts how many times we enetered type 3 querry
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> querryType;
        switch(querryType)
        {
        case 1:
            int x;
            std:: cin >> x;
            s.push(x);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            maximalElements[elementsCounter++] = s.findMaximal();
            break;
        }
    }
    for (int i = 0; i < elementsCounter; i++)
    {
        std::cout << maximalElements[i] << std::endl;
    }
    return 0;
}
