#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#include <list>
using namespace std;

class Graph
{
private:
    int vertexCount; //number of vertices
    list<int> *adj; // adjacency list where adj[v] = list of all adjacent vertices of v
    void DFSUtil(int v, bool visited[],list<int> &traversal);
    bool isCyclicUtil(int v, bool visited[], bool recStack[]);
public:
    Graph(int n);
    void addEdge(const int &v,const int &w);
    void DFS(int v,list<int> &traversal);
    bool isCyclic();
    ~Graph();
};

Graph::Graph(int n)
{
    vertexCount = n+1;
    adj = new list<int>[vertexCount];
}
Graph::~Graph()
{
    delete[] adj;
}

void Graph::addEdge(const int &v,const int &w)
{
    adj[v].push_back(w);
}
void Graph::DFSUtil(int v, bool visited[],list<int> &traversal)
{
    visited[v] = true;
    traversal.push_back(v);
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++)
        if(!visited[*i])
            DFSUtil(*i,visited,traversal);
}
void Graph::DFS(int v,list<int> &traversal)
{
    bool *visited = new bool[vertexCount];

    for(int k = 0; k < vertexCount; k++)
        visited[k] = false;

    DFSUtil(v,visited,traversal);
}
bool Graph::isCyclicUtil(int v, bool visited[], bool recStack[])
{
    if(visited[v] == false)
    {
        visited[v] = true; // Mark the current node as visited
        recStack[v] = true; // and as part of the recursion stack

        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if(!visited[*i] && isCyclicUtil(*i,visited,recStack))
                return true;
            else if(recStack[*i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}
bool Graph::isCyclic()
{
    bool *visited = new bool[vertexCount];
    bool *recStack = new bool[vertexCount];

    for(int i = 0; i < vertexCount; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for(int i = 0; i < vertexCount; i++)
    {
        if(isCyclicUtil(i,visited,recStack))
            return true;
    }
    return false;
}

#endif // GRAPH_H_INCLUDED
