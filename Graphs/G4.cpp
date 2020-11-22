#include<bits/stdc++.h>
using namespace std;

//weighted , undirected graph
//Graphs-4
//will use pairs

void addedge(vector<pair<int,int>> adj[],int u,int v,int w)
{
    //u vertex v vertex se associate h vd w weight.
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

void printgraph(vector<pair<int,int>> adj[],int V)
{
    for(int i=0;i<V;i++)
    {
        cout<<"Vertex "<<i<<" makes an edge with "<<endl;
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {
            int p=it->first;
            int q=it->second;
            cout<<"Vertex: "<<p<<" with weight "<<q<<endl;
        }
        cout<<endl;
    }
}

int main()
{
    int V=4;
    vector<pair<int,int>> adj[V];
    
    //edges are marked from source to destination
    addedge(adj,0,1,10);
    addedge(adj,0,3,2);
    addedge(adj,0,2,3);
    addedge(adj,2,3,6);
    addedge(adj,1,3,7);
    
    printgraph(adj,V);
}