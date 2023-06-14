#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v, e;
    vector<vector<int>> adj;

public:
    Graph()
    {
        v = 0;
        e = 0;
    }

    Graph(int v, int e)
    {
        this->v = v;
        this->e = e;
        adj.resize(v, vector<int>(v, -1));
    }

    void createGraph()
    {
        int src, dest, wt;
        cout << "Enter the edges: \n\n";
        for (int i = 0; i < e; i++)
        {
            cout << "Enter source: ";
            cin >> src;
            cout << "Enter destination: ";
            cin >> dest;
            cout << "Enter weight: ";
            cin >> wt;

            adj[src][dest] = adj[dest][src] = wt;
        }
    }

    void display()
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void prims(int start)
    {
        vector<bool> taken(v, false);
        vector<vector<int>> mst;

        taken[start] = true;

        for (int cnt = 0; cnt < v - 1; cnt++)
        {
            int src, dest, wt, minn = 1e5, flag;
            for (int v1 = 0; v1 < v; v1++)
            {
                if (taken[v1])
                {
                    for (int v2 = 0; v2 < v; v2++)
                    {
                        if (adj[v1][v2] != -1 && taken[v2] == false && adj[v1][v2] <= minn)
                        {
                            src = v1;
                            dest = v2;
                            wt = adj[v1][v2];
                            minn = wt;
                            flag = 1;
                        }
                    }
                }
            }
            if (flag)
            {
                mst.push_back({src, dest, wt});
                taken[dest] = true;
            }
        }

        int total = 0;
        cout << "\nMST:-\n\n";
        cout << "Edge\tWeight\n";
        for (auto x : mst)
        {
            cout << x[0] << " - " << x[1] << "\t" << x[2] << "\n";
            total += x[2];
        }
        cout << "Total weight: " << total << "\n";
    }

    void selection()
    {
        int p;
        cout << "Enter the size: ";
        cin >> p;

        vector<string> v;
        for (int i = 0; i < p; i++)
        {
            string x;
            cin >> x;
            v.push_back(x);
        }

        for (int i = 0; i < p - 1; i++)
        {
            int minn = i;
            for (int j = i + 1; j < p; j++)
            {
                if (v[j] < v[minn])
                {
                    minn = j;
                }
            }

            if (minn != i)
            {
                swap(v[minn], v[i]);
            }
        }

        for (int i = 0; i < p; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    Graph g(v, e);
    // g.createGraph();
    // g.display();
    // int start;
    // cout << "enter the starting point: ";
    // cin >> start;
    // g.prims(start);

    g.selection();
}