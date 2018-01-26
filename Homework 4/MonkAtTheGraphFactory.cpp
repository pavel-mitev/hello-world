#include <iostream>
#include <fstream>
#include "Graph.h"
using namespace std;

void printList(list<int> &l)
{
    list<int>::iterator i;
    for(i = l.begin(); i != l.end(); i++)
        cout << *i << ' ';
}
int main()
{
    list<int> input;
    ifstream in;
    in.open("inputEdges.txt");
    int max_vertex = 0;
    while(!in.eof())
    {
        int a,b;
        in >> a >> b;
        input.push_back(a);
        input.push_back(b);
        if(max_vertex < a)
            max_vertex = a;
        if(max_vertex < b)
            max_vertex = b;
    }
    in.close();
    input.sort();
    input.unique();
    Graph g(max_vertex);
    in.open("inputEdges.txt");
    while(!in.eof())
    {
        int a,b;
        in >> a >> b;
        g.addEdge(a,b);
    }
    in.close();
    bool connected = false;
    bool cyclic = g.isCyclic();
    for(list<int>::iterator i = input.begin(); i != input.end(); i++)
    {
        list<int> traversal;
        g.DFS(*i,traversal);
        if(input == traversal)
            connected = true;
    }
   if(connected && !cyclic)
    cout << "Yes" << endl;
   else
    cout << "No" << endl;

    return 0;
}
