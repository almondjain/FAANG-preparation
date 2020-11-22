#include<bits/stdc++.h>
using namespace std;

//Unweighted , Undirected graph
//Graphs-1

void addedge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printgraph(vector<int> adj[],int V)
{
    for(int i=0;i<V;i++)
    {
        cout<<"Adjacency List of vertex "<<i;
        for(auto x:adj[i])
        {
            cout<<" ->"<<x;
        }
        cout<<endl;
    }
}

int main()
{
    int V=5;
    vector<int> adj[5];
    
    //edges are marked from source to destination
    addedge(adj,0,1);
    addedge(adj,0,4);
    addedge(adj,1,4);
    addedge(adj,1,3);
    addedge(adj,1,2);
    addedge(adj,2,3);
    addedge(adj,3,4);
    
    printgraph(adj,V);
}