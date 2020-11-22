//GRAPHS-Second Class

/*
Count All Possible Paths Between Two Vertices/Nodes


Vertex: A , E

A-E
A-B-E
A-C-E
A-B-D-C-E

O/P: 4

Vertex: A, C 

A-C
A-B-D-C 

O/P: 2

Solution:

//Recursion

(1) Node-Destination and Source, Global cnt=0
(2) If current node==Destination, cnt++
(3) Else, Recur for all Adjacent Nodes 
(Why Adjacent-- Bcz these ONLY are accssible from Source, Island Eg.)
(4) Print Cnt 

*/

/*

#include<bits/stdc++.h>
using namespace std;

// User-Defined Graph

class Graph
{
int V;
list<int> *adj; 

public:

Graph(int V);
void addedge(int u, int v, int w);
void countallpathsutil(int , int , int&);
int countallpaths(int s, int d);
};

// OOPS: Encapsulation + Abstarction

Graph::Graph(int V)
{
    this->V=V;
    adj=new list<int>[V];
}

void Graph::addedge(int u, int v, int w)
{
    // Directed Graph
//adj[u].push_back(v);

//Weighted Graph
adj[u].push_back({v,w});
}





*/




#include<bits/stdc++.h>
using namespace std;

//Unweighted and Undirected Graph
void addedge(vector<pair<int, int>> adj[], int u, int v, int w)
{
adj[u].push_back(make_pair(v,w));
// adj[v].push_back(make_pair(u,w));
}

void countallpathsutil(vector<pair<int, int>> adj[], int s, int d, int& ans);


/*
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


int countallpaths(vector<pair<int, int>> adj[], int s, int d)
{
int ans=0;
countallpathsutil(adj, s,d,ans);
cout<<endl;
return ans;
}


void countallpathsutil(vector<pair<int, int>> adj[], int s, int d, int& ans)
{
int sum=0;


if (s==d)
{
++ans;
for (auto i:adj[s])
sum+=i.second;
}

//If curr Vertex != Destination


else 
{
   // auto i;
    
    for (auto i:adj[s])
    {
    countallpathsutil(adj, i.first, d, ans);
   sum+=i.second;
    }
}


cout<<sum<<" ";
}


int main()
{

int V=5;
vector<pair<int,int>> adj[V];


// A-0 , B-2 ,C-1, D-4, E-3

addedge(adj, 0,1, 10);
addedge(adj,0,2, 20);
addedge(adj,0,3, 30);
addedge(adj,1,3, 40);
addedge(adj,2,3, 50);
addedge(adj,2,4, 60);
addedge(adj,4,1, 70);


int s=0, d=3;
cout<<"Number of Paths from "<<s<<" to "<<d<<" are:"<<endl;

cout<<endl;
cout<<countallpaths(adj, s, d);


return 0;

}



Count the Number of Nodes at Given Level in a Tree Using BFS 


Tree= Undirected Graph

I/P:

7
0 1
0 2
1 3
1 4
1 5
2 6

Level=2

            0                   // Level 0
 1                  2           // Level 1
3 4 5               6            //Level 2

O/P:4


Level=1
O/P: 2



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
void BFS(int s, int level);
//void DFS(int s);
//void DFSUtil(int v, bool visited[]);
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


void Graph::BFS(int s, int level)
{
// Graph May have cycle, So to Count Every Vertex Only Once
bool *visited= new bool[V];
int levelwise[V];

for (int i=0; i<V; i++)
{visited[i]=false;
levelwise[i]=0;}

list<int> queue;

visited[s]= true;
queue.push_back(s);
levelwise[s]=0;

list<int>::iterator i;

while (!queue.empty())
{

s=queue.front();
//cout<<s<<" ";
queue.pop_front();

for (i= adj[s].begin(); i!=adj[s].end(); i++)
{
if (!visited[*i])
{
levelwise[*i]=levelwise[s]+1;    
visited[*i]=true;
queue.push_back(*i);
}

}

}

int count=0;
for (int i=0; i<V; i++)
if (levelwise[i]==level)
++count;

cout<<count;
}




int main()
{

Graph g(7);

g.addedge(0,1);
g.addedge(0,2);
g.addedge(1,3);
g.addedge(1,4);
g.addedge(1,5);
g.addedge(2,6);

int s=0;
int level=100;

cout<<"BFS Starting from "<<s<<" is: "<<endl;

g.BFS(0, level);


return 0;
}




Given a Directed Graph, Detect Whether Graph Has Cycle?

At least once: true
Else: false

n=4
e=6

0-1
0-2
1-2
2-0
2-3
3-3

#include<bits/stdc++.h>
using namespace std;

// User-Defined Graph

class Graph
{
int V;
list<int> *adj; 
bool iscyclicutil(int v, bool visited[], bool *res);

public:

Graph(int V);
void addedge(int u, int v);
bool iscyclic();

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


bool Graph::iscyclicutil(int v, bool visited[], bool recstack[])
{

if (visited[v]==false)
{
    visited[v]=true;
    recstack[v]=true;

// Recur for All ADJACENT VERTICES
list<int>::iterator i;

for (i= adj[v].begin(); i!= adj[v].end(); ++i)
{
    if (!visited[*i] && iscyclicutil(*i, visited, recstack))
    return true;

    else if (recstack[*i])
    return true;
}
}

recstack[v]=false;
return false;
}


bool Graph::iscyclic()
{
// All Vertex Not Visited and Not part of Recursion Stack

bool visited[V];
bool recstack[V];

int i=0;

for (i=0; i<V; ++i)
{
    visited[i]=false;
    recstack[i]=false;
}


for (i=0; i<V; ++i)
if (iscyclicutil(i, visited, recstack))
return true;


return false;
}

int main()
{

Graph g(4);
g.addedge(0,1);
g.addedge(1,2);
g.addedge(2,0);
g.addedge(2,3);


if (g.iscyclic())
cout<<"YES";
else
cout<<"NO";

}


Series:

AP/GP/HP

Derived- Pascal Triangle, Dress Seqeunce

nth Term= Count of Odd Numbers in nth Row of PT


1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1
1 7 21 35 35 21 7 1
1 8 28 56 70 56 28 8 1
1 9 36 84 126 126 84 36 9 1


Odd: 1, 2, 2, 4, 2, 4, 4, 8, 2, 4
Even: 

GOULD SEQUENCE


// Toplogical Sorting- Khan's Algorithm

Directed Edge: u->v

Traverse: u->v 

MORE THAN ONE Toplogical Sort 

5-0
5-2
4-0
4-1
2-3
3-1


PROCESS, THREAD


P1, P2, P3, P4, P5

*/


#include<bits/stdc++.h>
using namespace std;

// User-Defined Graph

class Graph
{
int V;
list<int> *adj; 
void topologicalsortutil(int v, bool visited[], stack<int>&s);

public:

Graph(int V);
void addedge(int u, int v);
void topologicalsort();
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

void Graph::topologicalsortutil(int v, bool visited[], stack<int>& s)
{
visited[v]= true;

list<int>::iterator i;

for (i= adj[v].begin(); i!=adj[v].end(); i++)
if (!visited[*i])
topologicalsortutil(*i, visited, s);

s.push(v);
}

void Graph::topologicalsort()
{

stack<int> s;
bool visited[V];
int i=0;

for (i=0; i<V; ++i)
visited[i]=false;

for (i=0; i<V; i++)
if (!visited[i])
topologicalsortutil(i, visited, s);

while (!s.empty())
{
cout<<s.top()<<" ";
s.pop();
}

}

int main()
{

Graph g(6);
g.addedge(5,2);
g.addedge(5,0);
g.addedge(4,0);
g.addedge(4,1);
g.addedge(2,3);
g.addedge(3,1);

g.topologicalsort();

return 0;
}