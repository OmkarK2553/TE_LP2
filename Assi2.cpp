#include <bits/stdc++.h>
using namespace std;
#define N 3

class Node
{
    Node *par;
    int mat[N][N];
    int x, y;
    int level;
    int cost;

    friend class Solution;
};

class Solution
{
public:
    bool isSafe(int x, int y)
    {
        if (x >= 0 && x < N && y >= 0 && y < N)
        {
            return true;
        }
        return false;
    }

    void printMatrix(int mat[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void printPath(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        printPath(root->par);
        cout << "g(n) = " << root->level << "\n";
        cout << "h(n) = " << root->cost << "\n";
        printMatrix(root->mat);
        cout << "\n";
    }

    int calculateCost(int initial[N][N], int final[N][N])
    {
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (initial[i][j] && initial[i][j] != final[i][j])
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    class Comp
    {
    public:
        bool operator()(Node *lhs, Node *rhs)
        {
            return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
        }
    };

    Node *newNode(int mat[N][N], int x, int y, int newX, int newY, int level, Node *par)
    {
        Node *node = new Node;
        node->par = par;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                node->mat[i][j] = mat[i][j];
            }
        }

        swap(node->mat[x][y], node->mat[newX][newY]);

        node->cost = INT_MAX;
        node->level = level;

        node->x = newX;
        node->y = newY;

        return node;
    }

    void solve(int initial[N][N], int x, int y, int final[N][N])
    {
        int rows[] = {-1, 0, 1, 0};
        int cols[] = {0, -1, 0, 1};
        priority_queue<Node *, vector<Node *>, Comp> pq;

        Node *root = newNode(initial, x, y, x, y, 0, nullptr);
        root->cost = calculateCost(initial, final);

        pq.push(root);

        while (!pq.empty())
        {
            Node *min = pq.top();
            pq.pop();

            if (min->cost == 0)
            {
                printPath(min);
                return;
            }

            for (int i = 0; i < 4; i++)
            {
                if (isSafe(min->x + rows[i], min->y + cols[i]))
                {
                    Node *child = newNode(min->mat, min->x, min->y, min->x + rows[i], min->y + cols[i], min->level + 1, min);
                    child->cost = calculateCost(child->mat, final);
                    pq.push(child);
                }
            }
        }
    }
};

int main()
{
    int initial[N][N], final[N][N];
    int xc, yc;

    cout << "Enter initial state: \n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << "Enter number: ";
            cin >> initial[i][j];

            if (initial[i][j] == 0)
            {
                xc = i;
                yc = j;
            }
        }
    }

    cout << "\nEnter final state: \n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << "Enter number: ";
            cin >> final[i][j];
        }
    }

    Solution s;
    s.solve(initial, xc, yc, final);
}