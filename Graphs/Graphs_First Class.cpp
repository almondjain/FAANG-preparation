/*

// GRAPHS

// Introduction, DFS, and BFS 


Linear : Array, LL, Queue, Stack, PQ, 
Non-Linear: Trees, BST, GRAPHS 

GRAPHS: Nodes and Edges

Nodes: Vertex
Edges: Lines/Arc that connect any two vertex 


"Graph consists of a finite set of vertex and set of Edges which connect a pair of Vertex"

Types:

Directed
Undirected
Weighted
Unweighted

// Applications:

(1) Network Problems- Routing, Path in City, Telephone Netwroks
(2) Social Media- Insta/Linkedin/FB/Snap

Linkedin: 
Person: Node/Vertex
Connections: Edges 

Node : Name, ID, Gender, Location
Graphs: Class/ Structure 

struct Node
{
    int data,
    Node *left, *right
}

(3) Google Maps- Shortest Path b/w Source and Destination


// Represenations


(u,v): Edge 

u, v: Vertex/Node

(u,v): w 

2 Ways:

(1) Adjacency Matrix
(2) Adjacency List 

- Incidence Matrix/ Incidence List 

// Adjacency Matrix

2D Array of size VxV
V: Number of Vertex 

// Unweighted Graphs
adj[i][j]= 1
There is Edge from vertex i to vertex j

// Weighted Graphs
adj[i][j]= w 
w is weight of Edge from vertex i to j


Undirected and Directed Graph ki Adjacency atrix mein diff?

if (adj[i][j]==1) //O(1) 

Pros:
- Easy to Understand
- Check for Queries like a to b path exist or not 

Cons:
- Adding a Vertex ix Costly

// Adjacency List
An Array of List is Used 
Size of Array: Number of Vertices

a[i]= List of Vertices ADJACENT to ith Vertex 

// Unweighted 
u-> v

//Weighted: MAKE PAIR
u-> (v,w)

Pros:
- Saves Space
- Adding a Vertex is Easier

Cons:
- Checking if a to b path exist or not- Takes More Time: O(V)



// Code: Adjacency List

// Graphs: Class, Structure, User-Defined, STL
// Questions/CP: STL

// Unweighted Graph

#include<bits/stdc++.h>
using namespace std;

//Unweighted and Undirected Graph
void addedge(vector<int> adj[], int u, int v)
{
adj[u].push_back(v);
adj[v].push_back(u);
}

// Print
void printgraph(vector<int> adj[], int V)
{
    int i=0;

    for (i=0; i<V; i++)
    {
        cout<<"Adjacency List of Vertex: "<<i;
        for (auto x: adj[i])
        cout<<" -> "<<x;
        cout<<endl;
    }


}


int main()
{
int V=5;
vector<int> adj[V];

addedge(adj, 0, 1);
addedge(adj, 0, 4);
addedge(adj, 1, 4);
addedge(adj, 1, 3);
addedge(adj, 1, 2);
addedge(adj, 2, 3);
addedge(adj, 3, 4);

printgraph(adj, V);

return 0;
}



// Weighted Graph

#include<bits/stdc++.h>
using namespace std;

//Unweighted and Undirected Graph
void addedge(vector<pair<int, int>> adj[], int u, int v, int w)
{
adj[u].push_back(make_pair(v,w));
// adj[v].push_back(make_pair(u,w));
}

// Print
void printgraph(vector<pair<int, int>> adj[], int V)
{
 int i, j, k;

 for (i=0; i<V; i++)
 {
cout<<"Vertex "<< i<< " makes an Edge with"<<endl;

for (auto it=adj[i].begin(); it!=adj[i].end(); it++)
{
    j=it->first;
    k=it->second;
    cout<<"Vertex: "<<j <<" with weight= "<<k<<endl;
}

cout<<endl;
 }   

}


int main()
{
int V=4;
vector<pair<int,int>> adj[V];


addedge(adj, 0, 1, 10);
addedge(adj, 0, 2, 3);
addedge(adj, 0, 3, 2);
addedge(adj, 1, 3, 7);
addedge(adj, 2, 3, 6);

printgraph(adj, V);

return 0;
}


// BFS- Breadth First Traversal


            2
    0                   3
1                       


            0
    1                   2
2                       3


BFS: 2 0 3 1 
DFS: 2 0 1 3
*/

#include<bits/stdc++.h>
using namespace std;

// User-Defined Graph

class Graph
{
int V;
list<int> *adj; 

public:

Graph(int V);
void addedge(int u, int v);
void BFS(int s);
void DFS(int s);
void DFSUtil(int v, bool visited[]);
};

// OOPS: Encapsulation + Abstarction

Graph::Graph(int V)
{
    this->V=V;
    adj=new list<int>[V];
}

void Graph::addedge(int u, int v)
{
    // Directed Graph
adj[u].push_back(v);
}

/*
void Graph::BFS(int s)
{
// Graph May have cycle, So to Count Every Vertex Only Once
bool *visited= new bool[V];

for (int i=0; i<V; i++)
visited[i]=false;

list<int> queue;

visited[s]= true;
queue.push_back(s);

list<int>::iterator i;

while (!queue.empty())
{

s=queue.front();
cout<<s<<" ";
queue.pop_front();

for (i= adj[s].begin(); i!=adj[s].end(); i++)
{
if (!visited[*i])
{
visited[*i]=true;
queue.push_back(*i);
}

}

}

}

*/

void Graph::DFSUtil(int v, bool visited[])
{
visited[v]=true;
cout<<v<<" ";

list<int>::iterator i;

for (i=adj[v].begin(); i!=adj[v].end(); ++i)
if (!visited[*i])
DFSUtil(*i, visited);
}

void Graph::DFS(int s)
{

bool * visited=new bool[V];

for (int i=0; i<V; i++)
visited[i]= false;

DFSUtil(s, visited);
}

// Recursion: RS + k space


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
cout<<"DFS Starting from "<<s<<" is: "<<endl;

g.DFS(s);

// 2 0 1 3

return 0;
}


// Applications of DFS and BFS


A B C D E F


H 
I 
J 
K