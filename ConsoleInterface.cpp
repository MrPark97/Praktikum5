//
// Created by MrPark on 08.02.2019.
//

#include "ConsoleInterface.h"


int ConsoleInterface::init()
{
    cout << "Input number of vertices K:" << endl;
    cin >> k;
    cout << "Input number of edges T:" << endl;
    cin >> l;
    cout << "Input edges:" << endl;
    g.setParameters(k,l);

    if(!g.isConnected())
    {
        throw DisconnectedGraphException();
    }

    cout << "Input number of vectors N:" << endl;
    cin >> n;
    cout << "Input size of vector M:" << endl;
    cin >> m;
    vector<int> temp(m, 0);
    db.assign(n, temp);
    cout << "Input vectors:" << endl;

    for(auto i=0; i < n; i++)
        for(int j=0; j<m; j++)
            cin >> db[i][j];

    query.assign(m, 0);
}

int ConsoleInterface::dijkstraStep()
{
    int result = 0;

    for(auto i=0; i<m; i++)
    {
        g.dijkstra(query[i]);
        result += g.shortest_distance[db[vector_index][i]];
    }

    return result;
}

int ConsoleInterface::floydWarshallStep()
{
    if(!vector_index)
        g.floydWarshall();

    int result = 0;

    for(auto i=0; i<m; i++)
        result += g.shortest_distances[query[i]][db[vector_index][i]];

    return result;
}

int ConsoleInterface::step()
{
    int current_result = INF;
    if(mode==DIJKSTRA_MODE)
    {
        current_result = dijkstraStep();

    }
    else if(mode==FLOYD_WARSHALL_MODE)
    {
        current_result = floydWarshallStep();
    }

    if(current_result < best_result)
    {
        best_result = current_result;
        best_index = vector_index;
    }

    if(++vector_index == n)
    {
        return 0;
    }

    return vector_index;
}

int ConsoleInterface::run()
{
    cout << "Input query vector:" << endl;
    for(auto i=0; i<m; i++)
    {
        cin >> query[i];
    }

    char userKey=0;
    while(step() && userKey!=USER_KEY_CANCEL)
    {
        cout << best_result << endl;
        // отобразить состояние задачи
        switch(mode)
        {
            case DIJKSTRA_MODE:
                cout << "DIJKSTRA MODE" << endl;
                break;
            case FLOYD_WARSHALL_MODE:
                cout << "FLOYD-WARSHALL MODE" << endl;
                break;
            default:
                break;
        };

        cout << "Checked vector is: ";
        for(auto i=0; i<m; i++)
        {
            cout << db[vector_index-1][i] << ' ';
        }
        cout << endl;
        cout << "Best vector is: ";
        for(auto i=0; i<m; i++)
        {
            cout << db[best_index][i] << ' ';
        }
        cout << endl;

        cout<<"Press any key to continue (to cancel press 'c'):" << endl;
        userKey = static_cast<char>(getchar());
    }

    cout << "The nearest vector from database:" << endl;
    for(auto i=0; i<m; i++)
    {
        cout << db[best_index][i] << ' ';
    }
    cout << endl;
}