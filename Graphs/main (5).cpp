#include<bits/stdc++.h>
using namespace std;

//Count of all possible paths between 2 vertices of a graph
//10

class Graph
{
    int v;
    list<int> *adj;
    
    public:
    
    Graph(int v);
    void addedge(int u,int v);
    void countallpathutil(int s, int d, int &count);
    int countallpath(int s, int d);
};

Graph::Graph(int v)
{
    this->v=v;
    adj=new list<int>[v];
}

void Graph::addedge(int u,int v)
{
    //Directed graph
    adj[u].push_back(v);
}

int Graph::countallpath(int s,int d)
{
    int ans=0;
    countallpathutil(s,d,ans);
    return ans;
}

void Graph::countallpathutil(int s,int d,int& ans)
{
    if(s==d)
        ans++;
        
    //if curr vertex!=destinatiom
    else
    {
        list<int>::iterator i;
        
        for(i=adj[s].begin();i!=adj[s].end();i++)
        {
            countallpathutil(*i,d,ans);
        }
    }
}
int main()
{
    Graph g(5);
    
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(0,3);
    g.addedge(1,3);
    g.addedge(1,4);
    g.addedge(2,3);
    g.addedge(4,2);
    
    int s=0,d=3;
    cout<<"Number of paths from "<<s<<" to "<<d<<" are "<<endl;
    cout<<g.countallpath(s,d);
    
    return 0;
     
}