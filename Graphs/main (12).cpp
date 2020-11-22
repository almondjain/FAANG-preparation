#include<bits/stdc++.h>
using namespace std;

//BFS without stl
//graph

void addedge(vector<int> adj[],int u,int v)
{
    //directed
    adj[u].push_back(v);
}

void BFS(vector<int> adj[],int v,int s)
{
    vector<bool> b(v,false);
    queue<int> q;
    //will put starting pt. value of graph
    q.push(s);
    b[s]=true;
    
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        
        cout<<x<<"-> ";
        
        for(auto it=adj[x].begin(); it!=adj[x].end();it++)
        {
            //here it is pointing address value of starting of given node(x) list(adjacent elements)
            if(!b[*it])
            {
                q.push(*it);
                b[*it]=true;
            }
            
        }
    }
}

int main()
{
    int v=4;
    
    vector<int> adj[v];
    
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,0,3);
    addedge(adj,2,3);
    addedge(adj,1,3);
    
    
    //from where traversal needs to be started
    int s=3;
    BFS(adj,v,s);
    
    
}