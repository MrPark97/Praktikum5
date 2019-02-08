//
// Created by MrPark on 08.02.2019.
//

#ifndef PRAKTIKUM5_GRAPH_H
#define PRAKTIKUM5_GRAPH_H

#include <vector>
#include <iostream>
using namespace std;

const int INF = 1e9;

// this exceptions throws when Graph is Disconnected
class DisconnectedGraphException: public exception
{
    const char* what() const noexcept override {
        return "Graph is disconnected";
    }
};


// this class implements graph as an adjacency table ans some of its useful methods
class Graph {
public:
    Graph(): k(0), l(0)
    {}
    Graph(unsigned long long k, unsigned long long l): k(k), l(l)
    {
        vector<int> t(k+1, INF);
        g.assign(k+1, t);
        readEdges();
        for(auto i=1; i <= k; i++)
        {
            g[i][i] = 0;
        }
    }
    ~Graph()
    {
        g.clear();
    }
    // this method reads edges from console
    void readEdges()
    {
        for(auto i=0; i < l; i++)
        {
            int a,b,w;
            cin >> a >> b >> w;
            g[a][b] = g[b][a] = w;
        }
    }
    // this method sets number of vertices ans number of
    void setParameters(unsigned long long k, unsigned long long l)
    {
        this->k = k;
        this->l = l;
        vector<int> t(k+1, INF);
        g.assign(k+1, t);
        readEdges();
        for(auto i=1; i <= k; i++)
        {
            g[i][i] = 0;
        }
    }
    char isConnected();
    void dfs(int v);
    void dijkstra(int s);
    void floydWarshall();
    vector<int> shortest_distance;
    vector<vector<int> > shortest_distances;
private:
    unsigned long long k, l;
    vector<vector<int> > g;
    vector<char> used;
};

#endif //PRAKTIKUM5_GRAPH_H
