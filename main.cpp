#include <bits/stdc++.h>
#include <exception>
#include "ConsoleInterface.h"
#include "Test.h"
using namespace std;

int main()
{
    ConsoleInterface ci(DIJKSTRA_MODE);

    try
    {
        ci.init();
        ci.run();
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }



    return 0;
}