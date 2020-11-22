#include<bits/stdc++.h>
using namespace std;

//Implementation of graphs
//user defined graph
//Graphs-4

class Graph
{
    int v;
    list<int> *adj;
    
    public:
    
    Graph(int v);
    void addedge(int u,int v);
    void print();
}

Graph::Graph(int v)
{
    this->v=v;
    adj=new list<int>[v];
}

void Graph::addedge(int u,int v)
{
    //Directed Graph
    adj[u].push_back(v);
}

void Graph::print()
{
    for(auto it:adj.begin(); it!=end();it++)
    {
        cout<<adj[i];
    }
}

int main()
{
    Graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,0);
    g.addedge(2,3);
    g.addedge(3,3);
    
    g.print();
}