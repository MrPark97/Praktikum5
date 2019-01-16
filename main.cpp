#include <bits/stdc++.h>
#include <exception>
using namespace std;

#define USER_KEY_CANCEL 'c'

const int INF = 1e9;

class DisconnectedGraphException: public exception
{
    const char* what() const noexcept override {
        return "Graph is disconnected";
    }
};


class Graph {
public:
    Graph(int k, int l): k(k), l(l)
    {
        vector<int> t(INF, k+1);
        g.assign(k+1, t);
        for(int i=0; i<l; i++)
        {
            int a,b,w;
            cin >> a >> b >> w;
            g[a][b] = g[a][b] = w;
        }
        for(int i=1; i<=k; i++)
        {
            g[i][i] = 0;
        }
    }
    char isConnected();
private:
    int k, l;
    vector<vector<int> > g;
};

char Graph::isConnected() {

}

class ConsoleInterface {
public:
    ConsoleInterface()
    {}
    int run();
    int step();
    int init();
private:
    Graph *g;
    vector<vector<int> > db;
};

int ConsoleInterface::init() {
    int k, l, m, n;
    cout << "Input number of vertices K:";
    cin >> k;
    cout << "Input number of edges T:";
    cin >> l;
    cout << "Input edges:";
    Graph my_g(k, l);
    g = &my_g;



    cout << "Input number of vectors N:";
    cin >> n;
    cout << "Input size of vector M";
    cin >> m;
    vector<int> temp(m, 0);
    db.resize(n, temp);
    cout << "Input vectors";
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> db[i][j];
        }
    }
}

int ConsoleInterface::run()
{
    char userKey=0;
    while(step() && userKey!=USER_KEY_CANCEL)
    {
        // отобразить состояние задачи
        if(mode==MODE_STEP)
        {
            cout<<"Press a key to continue";
            cin>>userKey;
        }
    }
}

int main() {
    ConsoleInterface ci;

    try {
        ci.init();
    } catch(exception& e)
    {
        cout << e.what() << endl;
    }

    ci.run();

    return 0;
}