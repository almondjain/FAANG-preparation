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
    void BFS(int s);
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

void Graph::BFS(int s)
{
    //Graph may have cycle, so to count every vertex only once
    bool *visited=new bool[v];
    
    for(int i=0;i<v;i++)
        visited[i]=false;
    
    list<int> queue;
    
    visited[s]=true;
    queue.push_back(s);
    
    list<int>::iterator i;
    
    while(!queue.empty())
    {
        s=queue.front();
        cout<<s<<" ";
        queue.pop_front();
        
        for(i=adj[s].begin();i!=adj[s].end();i++)
        {
            if(!visited[*i])
            {
                visited[*i]=true;
                queue.push_back(*i);
            }
        }
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
    
    int s=0;
    cout<<"BFS starting from "<<s<<" is: "<<endl;
    
    g.BFS(s);
    
    return 0;
}