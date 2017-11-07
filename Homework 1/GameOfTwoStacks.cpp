#include <iostream>
#include "stack.h"
int main()
{
    LStack<int> A,B;

    int games; // Number of games
    int n,m; // Sizes respectfully of A and B
    int x; // sum that can't be exceeded
    int maxScore; // number of elements removed before X is exceeded
    std::cin >> games;
    for (int i = 0; i < games; i++)
    {
        maxScore = 0;
        std::cin >> n >> m >> x;
        int* reversedA = new int[n]; // because first element enetered should be last pushed in the stack..
        int* reversedB = new int[m];
        for (int k = 0; k < n; k++)
        {
            std::cin >> reversedA[k];
        }
        for (int k = n - 1; k >= 0; k--)
        {
            A.push(reversedA[k]);
        }
        for (int k = 0; k < m; k++)
        {
            std::cin >> reversedB[k];
        }
        for (int k = m - 1; k >= 0; k--)
        {
            B.push(reversedB[k]);
        }
        while (x >= 0)
        {
            maxScore++;
            if (A.top() > B. top())
            {
                x -= A.top();
                A.pop();
            }
            else
            {
                x -= B.top();
                B.pop();
            }
        }
        std::cout << maxScore << std::endl;
        delete[] reversedA;
        delete[] reversedB;
    }
}
