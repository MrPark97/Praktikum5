//
// Created by MrPark on 08.02.2019.
//

#include "Test.h"
#include <ctime>



void Test::test()
{
    clock_t begin = clock();
    clock_t end = clock();
    if(k > 200)
    {
        cout << "KEY NUMBER IS TOO LARGE FOR DIJKSTRA MODE" << endl;
    }
    else
    {
        cout << "NUMBER OF VERTICES: " << k << endl;
        begin = clock();
        dijkstraCI.solve();
        clock_t end = clock();
        dijkstraTime = ((long double) (end - begin)) / CLOCKS_PER_SEC;
        cout << "DIJKSTRA MODE BEST RESULT IS: " << dijkstraCI.getBestResult() << endl;
        cout << "SOLUTION TIME IS: " << dijkstraTime << endl;
    }

    if(k > 1000)
    {
        cout << "KEY NUMBER IS TOO LARGE FOR DIJKSTRA MODE" << endl;
    }
    else
    {
        begin = clock();
        floyd_warshallCI.solve();
        end = clock();
        floyd_warshallTime = ((long double) (end - begin)) / CLOCKS_PER_SEC;
        cout << "FLOYD-WARSHALL MODE BEST RESULT IS: " << floyd_warshallCI.getBestResult() << endl;
        cout << "SOLUTION TIME IS: " << floyd_warshallTime << endl;
    }



    if(dijkstraCI.getBestResult() != floyd_warshallCI.getBestResult())
    {
        throw WrongSolutionException();
    }
}