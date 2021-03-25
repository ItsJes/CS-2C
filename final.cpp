//
//  main.cpp
//  Final exam Q9.3
//
//  Created by Sara Akhtar on 6/19/17.
//  Copyright © 2017 Sara Akhtar. All rights reserved.

#include<iostream>
#include <list>
#include <stack>
#include <gtest/gtest.h>

using namespace std;

// Class to represent a graph
class Graph
{
    int V;
    
    list<int> *adj;
    
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);
    
    void addEdge(int v, int w);
    
    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[],
                                stack<int> &Stack)
{
    visited[v] = true;
    
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
    
    Stack.push(v);
}

void Graph::topologicalSort()
{
    stack<int> Stack;
    
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
    
    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

TEST(test1, test)
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    
    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();
}

TEST(test2, test)
{
    Graph g(5);
    g.addEdge(3, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 3);
    g.addEdge(5, 1);
    g.addEdge(2, 3);
    
    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();
}

int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*
 [==========] Running 4 tests from 3 test cases.
 [----------] Global test environment set-up.
 [----------] 2 tests from Counter
 [ RUN      ] Counter.InitialState
 [       OK ] Counter.InitialState (0 ms)
 [ RUN      ] Counter.Increment
 [       OK ] Counter.Increment (0 ms)
 [----------] 2 tests from Counter (0 ms total)
 
 [----------] 1 test from test1
 [ RUN      ] test1.test
 Following is a Topological Sort of the given graph
 5 4 2 3 1 0 [       OK ] test1.test (0 ms)
 [----------] 1 test from test1 (0 ms total)
 
 [----------] 1 test from test2
 [ RUN      ] test2.test
 Following is a Topological Sort of the given graph
 2 3 4 1 0 [       OK ] test2.test (0 ms)
 [----------] 1 test from test2 (0 ms total)
 
 [----------] Global test environment tear-down
 [==========] 4 tests from 3 test cases ran. (0 ms total)
 [  PASSED  ] 4 tests.
 Program ended with exit code: 0
 */


