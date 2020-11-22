/*

// Shortest Path in GRAHS

(1) Single Source Shortest Path
(2) All Pairs Shortest Path  


Shortest Path:
- Weights (City, Cost, .....) (Modified BFS)
- Edges  (BFS)

Graph: E, V


// Single Point Shortest Path
DIJKSTRA'S ALGO

- Example- DONE
- ALGO(Underlying Algo)- GREEDY 
- Constarints- NEGATIVE EDGES WONT WORK


Theory/Algo:

Given: s, 
Find Shortest distance to all Vertex from s 

v: attribute d(v)= shortest path from s to v

d(v): Initilaise with INF 
min(a,INF) = a 

s, 
d(s)= 0

d(s): s ka s se distance
d(v): s ka v se distance (v is for all vertices)


Print: d(s,v)
(s,v): temp:
// (For All u in V-U)
d(u,v)= MIN(w(u,v) + d(u))



// Greedy Algo 
R 10 1000
20 20 .
. . .
. . .



// Code:

#include <bits/stdc++.h>
using namespace std;


// STL- Weighted Graph

vector<int> dijkstra(int n, int source, vector<pair<int, int>> G[])
{

int INF= (int)1e9;
// 1000000000

vector<int> D(n, INF);
D[source]=0;

set<pair<int,int>> Q;
Q.insert({0,source});

while (!Q.empty())
{

auto top= Q.begin();
int u= top->second;
Q.erase(top);

for (auto next: G[u])
{

int v=next.first, weight=next.second;
if (D[u] + weight< D[v])
{

if (Q.find({D[v], v})!= Q.end())
Q.erase(Q.find({D[v], v}));

D[v]= D[u] + weight;

Q.insert({D[v], v});
}

}
}

return D;

}

int main() 
{
int n, e, s, u, v, w;
cin>>n>>e>>s;

int i;
vector<pair<int, int>> *G=new vector<pair<int, int>>[n];
vector<int> ans;

for (i=0; i<e; i++)
{
cin>>u>>v>>w;

G[u].push_back(make_pair(v,w));
}

ans= dijkstra(n,s,G);

for (i=0; i<n; i++)
cout<<"Shortest Distance from "<<s<<" to "<<i<<" is "<<ans[i]<<endl;

cout<<endl;
}

// T: O(E*V)
//Can Optimised to O(E*log V): BST, Heap, PQ


/*

// BELLMAN FORD:
- optimised DIJKSTRA

Constarints: Negative Edges will WORK 


// Code:

#include <bits/stdc++.h>
using namespace std;


// STL- Weighted Graph

vector<int> bellmanford(int n, int source, vector<pair<int, int>> G[])
{

int INF= (int)1e9;
// 1000000000

vector<int> D(n, INF);
D[source]=0;

int i, u;

for (i=0; i<n-1; i++)
{
    for (int u=0; u<n; u++)
    {
        for (auto edge:G[u])
        {
            int v=edge.first;
            int w=edge.second;

            if (D[u]!=INF)
            D[v]= min(D[v], D[u] + w);
        }
    }
}


// Negative Case

for (u=0; u<n ; u++)
{
for (auto edge: G[u])
{
    int v=edge.first;
    int w=edge.second;

    // Negative Exist
    if (D[u]!= INF && D[v]>D[u] + w)
    assert(0);
}

}


return D;
}

int main() 
{
int n, e, s, u, v, w;
cin>>n>>e>>s;

int i;
vector<pair<int, int>> *G=new vector<pair<int, int>>[n];
vector<int> ans;

for (i=0; i<e; i++)
{
cin>>u>>v>>w;

G[u].push_back(make_pair(v,w));
}

ans= bellmanford(n,s,G);

for (i=0; i<n; i++)
cout<<"Shortest Distance from "<<s<<" to "<<i<<" is "<<ans[i]<<endl;

cout<<endl;
}


// T: O(V^3) + O(E*V) 


All Pairs Shortest Path Algo:

- Floyd Warshall 

d(u,v): Shortest Path between u and v 
For ALL u, v 

d(u,v)= w (u,v) 
        = INF , if NO PATH 

Intermediate Steps:
d(u,v)= min (d(u,v) + d(u,k)+ d(k,v))

*/

#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000

int main()
{
int n,e,s,u,v,w;
cin>>n>>e>>s;

int G[n][n];
int i=0, j=0;

for (i=0; i<n; i++)
{
for (j=0; j<n; j++)
{
if (i==j)
G[i][j]=0;

else
G[i][j]=INF;
}
}

for (i=0; i<e; i++)
{
    cin>>u>>v>>w;
    G[u][v]=w;
}


// Floyd Warshall

int k=0;
for (k=0; k<n; k++)
{

for (i=0; i<n; i++)
{
    for (j=0; j<n; j++)
    G[i][j]=min(G[i][j], G[i][k] + G[k][j]);
}

}

for (i=0; i<n; i++)
{
    for (j=0; j<n; j++)
cout<<G[i][j]<<" ";
cout<<endl;
}


return 0;

}


// Spanning Trees and MST

SPANNING TREE

- Tree is Undirected Graph 

Given an Undirected and Connected Graph, Spanning Tree of a Graph G is a Tree that spans G.
(Includes Every Vertex of G) and is a subgraph of G.


MST

- Spanning Tree With Minimum Cost

(More than 1 MST in a Graph= POSSIBLE)


// Applications of MST:

- Travelling Salesman
- Network Design (Cover Each Router, Minimum Wire Cost)
- Cluster Analysis
- Image Segmentation 
- Handwriting Recognition

// Algorithms Used to Solve MST Problems

- Prim's Algo
- Kruskal's Algo 