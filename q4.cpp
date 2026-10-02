#include <iostream>
using namespace std;

const int N = 5;

int maze[N][N] =
{
    {1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1},
    {0, 1, 0, 1, 1},
    {1, 0, 0, 1, 1},
    {1, 1, 1, 0, 1}
};

int solution[N][N] = {0};

bool solveMaze(int row, int col)
{
    if (row < 0 || row >= N ||
        col < 0 || col >= N)
        return false;

    if (maze[row][col] == 0)
        return false;

    if (solution[row][col] == 1)
        return false;

    solution[row][col] = 1;

    if (row == 4 && col == 4)
        return true;

    if (solveMaze(row + 1, col))
        return true;

    if (solveMaze(row, col + 1))
        return true;

    if (solveMaze(row - 1, col))
        return true;

    if (solveMaze(row, col - 1))
        return true;

    solution[row][col] = 0;

    return false;
}

int main()
{
    if (solveMaze(0, 0))
    {
        cout << "Solution:\n";

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << solution[i][j] << " ";

            cout << endl;
        }
    }
    else
    {
        cout << "No path found.";
    }

    return 0;
}
