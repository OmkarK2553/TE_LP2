#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<string, vector<string>> adj;
    int v, e;

public:
    Graph(int v, int e)
    {
        this->v = v;
        this->e = e;
    }

    void createGraph()
    {
        cout << "Vertex: " << v << "\n";
        cout << "Edges: " << e << "\n";

        string src, dest;
        for (int i = 0; i < e; i++)
        {
            cout << "Enter source: ";
            cin >> src;
            cout << "Enter destination: ";
            cin >> dest;

            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
    }

    void dfsUtil(string node, map<string, vector<string>> &adj, map<string, bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                dfsUtil(neighbour, adj, visited);
            }
        }
    }

    void dfs(string start)
    {
        map<string, bool> visited;

        dfsUtil(start, adj, visited);
    }

    void bfsUtil(string node, map<string, vector<string>> &adj, map<string, bool> &visited, queue<string> &q)
    {
        visited[node] = true;
        cout << node << " ";

        q.pop();

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }

        if (q.empty())
        {
            return;
        }

        bfsUtil(q.front(), adj, visited, q);
    }

    void bfs(string start)
    {
        map<string, bool> visited;
        queue<string> q;

        q.push(start);
        bfsUtil(start, adj, visited, q);
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
    g.createGraph();

    string start;
    cout << "Enter starting node: ";
    cin >> start;

    cout << "\nDFS: ";
    g.dfs(start);
    cout << "\nBFS: ";
    g.bfs(start);
}