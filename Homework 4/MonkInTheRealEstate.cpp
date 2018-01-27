#include <iostream>
const int MAX_NODE = 10001;
bool nodes[MAX_NODE];
int main()
{
    int T; // Test cases
    std::cin >> T;
    for(int i = 0; i < T; i++)
    {
        int townCount = 0;
        int E; //Number of edges
        std::cin >> E;
        for(int p = 0; p < MAX_NODE; p++)
            nodes[p] = false;
        for(int k = 0; k < E; k++)
        {
            int v,w;
            std::cin >> v >> w;
            //If we haven't already bought that town we add it to the count and buy it
            if(!nodes[v])
            {
                townCount++;
                nodes[v] = true;   
            }
            if(!nodes[w])
            {
                townCount++;
                nodes[w] = true;
            }
        }
        std::cout << townCount << '\n';
    }
    return 0;
}
