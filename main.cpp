#include <bits/stdc++.h>
#include <exception>
#include "ConsoleInterface.h"
#include "Test.h"
using namespace std;

int main()
{
    /*ConsoleInterface ci(DIJKSTRA_MODE);

    try
    {
        ci.init();
        ci.run();
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }*/
    int key_numbers[5] = {50, 100, 200, 500, 1000};

    for(auto i=0; i<5; i++)
    {
        cout << "******TEST # " << i+1 << "******" << endl;
        Test t(key_numbers[i]);
        try
        {
            t.test();
        }
        catch (exception& e)
        {
            cerr << e.what() << endl;
        }
        cout << endl;
    }

    return 0;
}