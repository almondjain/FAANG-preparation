#include<bits/stdc++.h>
using namespace std;

//traversing in graph-bfs
//user defined graph
//Graphs-4

class Graph
{
    int v;
    list<int> *adj;
    
    public:
    
    Graph(int v);
    void addedge(int u,int v);
    void DFS(int s);
    void DFSUtil(int v,bool visited[]);
};

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

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v]=true;
    cout<<v<<" ";

    list<int>::iterator i;

    for (i=adj[v].begin(); i!=adj[v].end(); ++i)
    {
        if (!visited[*i])
            DFSUtil(*i, visited);
    }
}

void Graph::DFS(int s)
{

    bool * visited=new bool[v];
    
    for (int i=0; i<v; i++)
        visited[i]= false;
    
    DFSUtil(s, visited);
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
    
    int s=0;
    cout<<"DFS starting from "<<s<<" is: "<<endl;
    
    g.DFS(s);
    
    return 0;
}