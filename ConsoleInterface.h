//
// Created by MrPark on 08.02.2019.
//

#ifndef PRAKTIKUM5_CONSOLEINTERFACE_H
#define PRAKTIKUM5_CONSOLEINTERFACE_H
#define USER_KEY_CANCEL 'c'
#define DIJKSTRA_MODE 'p'
#define FLOYD_WARSHALL_MODE 'f'
#include <vector>
#include "Graph.h"
using namespace std;

class ConsoleInterface {
public:
    ConsoleInterface(char mode): k(0), l(0), m(0), n(0), mode(mode), vector_index(0), best_index(0), best_result(INF)
    {}
    int run();
    int step();
    int init();
    int dijkstraStep();
    int floydWarshallStep();
private:
    unsigned long long k,l,m,n;
    char mode;
    Graph g;
    vector<vector<int> > db;
    vector<int> query;
    int vector_index;
    int best_index, best_result;
};

#endif //PRAKTIKUM5_CONSOLEINTERFACE_H
