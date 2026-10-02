#include <iostream>
#include <climits>
using namespace std;

const int N = 6;

char grid[N][N] =
{
    {'D','S','S','F','D','F'},
    {'S','S','S','F','S','D'},
    {'S','D','S','S','S','F'},
    {'F','S','F','S','S','F'},
    {'S','S','S','D','S','F'},
    {'S','F','S','S','S','H'}
};

bool visited[N][N] = {false};

int pathR[36], pathC[36];
int bestR[36], bestC[36];

int bestLength = 0;
int minimumWind = INT_MAX;

void findPath(int row, int col,
              int wind, int length)
{
    if (row < 0 || row >= N ||
        col < 0 || col >= N)
        return;

    if (grid[row][col] == 'F')
        return;

    if (visited[row][col])
        return;

    if (grid[row][col] == 'D')
        wind++;

    if (wind >= minimumWind)
        return;

    visited[row][col] = true;

    pathR[length] = row;
    pathC[length] = col;
    length++;

    if (grid[row][col] == 'H')
    {
        minimumWind = wind;
        bestLength = length;

        for (int i = 0; i < length; i++)
        {
            bestR[i] = pathR[i];
            bestC[i] = pathC[i];
        }

        visited[row][col] = false;
        return;
    }

    findPath(row + 1, col, wind, length);
    findPath(row, col + 1, wind, length);
    findPath(row - 1, col, wind, length);
    findPath(row, col - 1, wind, length);

    visited[row][col] = false;
}

int main()
{
    findPath(0, 0, 0, 0);

    if (minimumWind == INT_MAX)
    {
        cout << "No path found.";
        return 0;
    }

    cout << "Best Path:\n";

    for (int i = 0; i < bestLength; i++)
    {
        cout << "(" << bestR[i]
             << "," << bestC[i] << ")";

        if (i < bestLength - 1)
            cout << " -> ";
    }

    cout << "\n\nHigh Wind Cells = "
         << minimumWind;

    cout << "\n\nBlocked Cells:\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 'F')
                cout << "(" << i
                     << "," << j << ") ";
        }
    }

    return 0;
}
