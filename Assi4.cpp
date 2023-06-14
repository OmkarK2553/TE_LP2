#include <bits/stdc++.h>
using namespace std;

class NQueens
{
    vector<vector<char>> v;
    int n;

public:
    NQueens(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            vector<char> temp(n, '.');
            this->v.push_back(temp);
        }
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void clear()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                v[i][j] = '.';
            }
        }
    }

    bool isSafe(int x, int y, int n)
    {
        for (int row = 0; row < x; row++)
        {
            if (v[row][y] == 'Q')
            {
                return false;
            }
        }

        int row = x, col = y;
        while (row >= 0 && col >= 0)
        {
            if (v[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col--;
        }

        row = x, col = y;
        while (row >= 0 && col < n)
        {
            if (v[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col++;
        }

        return true;
    }

    bool nQueens(int x, int n)
    {
        if (x >= n)
        {
            return true;
        }

        for (int col = 0; col < n; col++)
        {
            if (isSafe(x, col, n))
            {
                v[x][col] = 'Q';

                if (nQueens(x + 1, n))
                {
                    return true;
                }

                v[x][col] = '.';
            }
        }
        return false;
    }

    bool isSafeBB(int row, int col, vector<bool> rows, vector<bool> left, vector<bool> right, int n)
    {
        if (rows[row] || left[row + col] || right[row - col + n - 1])
        {
            return false;
        }
        return true;
    }

    bool nQueensBB(int col, vector<bool> &rows, vector<bool> &left, vector<bool> &right, int n)
    {
        if (col >= n)
        {
            return true;
        }

        for (int i = 0; i < n; i++)
        {
            if (isSafeBB(i, col, rows, left, right, n))
            {
                v[i][col] = 'Q';
                rows[i] = true;
                left[i + col] = true;
                right[i - col + n - 1] = true;

                if (nQueensBB(col + 1, rows, left, right, n))
                {
                    return true;
                }

                v[i][col] = '.';
                rows[i] = false;
                left[i + col] = false;
                right[i - col + n - 1] = false;
            }
        }

        return false;
    }
};

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    NQueens q(n);

    cout << "Using Backtracking: \n";
    // q.display();
    if (q.nQueens(0, n))
    {
        q.display();
    }
    q.clear();

    cout << "\nUsing Branch and bound: \n";
    vector<bool> rows(n, false);
    vector<bool> left(2 * n - 1, false);
    vector<bool> right(2 * n - 1, false);
    if (q.nQueensBB(0, rows, left, right, n))
    {
        q.display();
    }
}