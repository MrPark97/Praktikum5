//
// Created by MrPark on 08.02.2019.
//

#ifndef PRAKTIKUM5_TEST_H
#define PRAKTIKUM5_TEST_H
#include "ConsoleInterface.h"
#include <random>
using namespace std;

// this exceptions throws when two solutions of one task are not equals
class WrongSolutionException: public exception
{
    const char* what() const noexcept override {
        return "Solutions are not the same";
    }
};


// this test class randomly generates complete graph using key_number:
// key_number is a number of vertices, number of vectors in database, vector size.
// measures task solution time using two different approaches and compares them.
// random numbers taken in range [1, 1000]
class Test {
public:
    explicit Test(unsigned long long key_number): dijkstraCI(DIJKSTRA_MODE), floyd_warshallCI(FLOYD_WARSHALL_MODE), dijkstraTime(0.0), floyd_warshallTime(0.0)
    {
        k = m = n = key_number;
        l = key_number * (key_number-1) / 2;
        vector<int> t(k+1, INF);
        edges.assign(k+1, t);


        random_device rd;     // only used once to initialise (seed) engine
        mt19937 mt(rd());    // random-number engine used (Mersenne-Twister in this case)
        uniform_int_distribution<int> dist(1, 1000), v_dist(1, (int) k); // guaranteed unbiased

        for(auto i=1; i<k; i++) {
            for(auto j=i+1; j<=k; j++) {
                edges[j][i] = edges[i][j] = dist(mt);
            }
        }

        for(auto i=1; i<=k; i++)
        {
            edges[i][i] = 0;
        }

        g.setGraph(k, l, edges);

        vector<int> temp(m, 0);
        db.assign(n, temp);
        for(auto i=0; i < n; i++)
            for(int j=0; j<m; j++)
                db[i][j] = v_dist(mt);

        query.assign(m,0);
        for(auto i=0; i<m; i++)
        {
            query[i] = v_dist(mt);
        }
        dijkstraCI.setData(k, l, m, n, edges, db, query);
        floyd_warshallCI.setData(k, l, m, n, edges, db, query);
    }
    void test();
private:
    long double dijkstraTime, floyd_warshallTime;
    unsigned long long k, l, m, n;
    vector<vector<int> > edges;
    Graph g;
    vector<vector<int> > db;
    ConsoleInterface dijkstraCI, floyd_warshallCI;
    vector<int> query;
};


#endif //PRAKTIKUM5_TEST_H
