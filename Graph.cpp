//
// Created by MrPark on 08.02.2019.
//

#include "Graph.h"

void Graph::dfs(int v)
{
    used[v] = 1;
    for(auto i=1; i <= k; i++)
    {
        if(g[v][i] < INF && !used[i])
        {
            dfs(i);
        }
    }
}

void Graph::dijkstra(int s)
{
    shortest_distance.assign(k+1, INF);
    shortest_distance[s] = 0;
    used.assign(k+1, 0);
    for(auto i=1; i<=k; i++)
    {
        int v = -1;
        for(auto j=1; j<=k; j++)
            if (!used[j] && (v == -1 || shortest_distance[j] < shortest_distance[v]))
                v = j;


        if(shortest_distance[v] == INF)
            break;

        used[v] = 1;

        for(auto j=1; j<=k; j++)
            if(shortest_distance[v] + g[v][j] < shortest_distance[j])
                shortest_distance[j] = shortest_distance[v] + g[v][j];
    }
}

void Graph::floydWarshall()
{
    shortest_distances.assign(g.begin(), g.end());

    for(auto t=1; t<=k; t++)
        for(auto i=1; i<=k; i++)
            for(auto j=1; j<=k; j++)
                shortest_distances[i][j] = min(shortest_distances[i][j], shortest_distances[i][t] + shortest_distances[t][j]);
}

char Graph::isConnected()
{
    used.assign(k+1, 0);
    for(auto i=1; i <= k; i++) {
        used[i] = 0;
    }
    dfs(1);
    for(auto i=1; i <= k; i++)
        if(!used[i])
            return 0;
    return 1;
}

void Graph::setGraph(unsigned long long k, unsigned long long l, vector<vector<int> > &edges)
{
    this->k = k;
    this->l = l;
    this->g.insert(this->g.begin(), edges.begin(), edges.end());
}