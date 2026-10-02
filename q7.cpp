#include <iostream>
using namespace std;

const int N = 5;

char forest[N][N] =
{
    {'S','A','A','T','A'},
    {'A','T','A','A','G'},
    {'T','A','T','A','F'},
    {'A','A','A','T','G'},
    {'A','T','G','T','G'}
};

void searchForest(int row, int col,
                  char item, int goal,
                  int &count,
                  bool visited[N][N],
                  int output[N][N])
{
    if (row < 0 || row >= N ||
        col < 0 || col >= N)
        return;

    if (forest[row][col] == 'T')
        return;

    if (visited[row][col])
        return;

    if (count >= goal)
        return;

    visited[row][col] = true;

    output[row][col] = 1;

    if (forest[row][col] == item)
        count++;

    searchForest(row + 1, col,
                 item, goal, count,
                 visited, output);

    searchForest(row, col + 1,
                 item, goal, count,
                 visited, output);

    searchForest(row - 1, col,
                 item, goal, count,
                 visited, output);

    searchForest(row, col - 1,
                 item, goal, count,
                 visited, output);
}

void display(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";

        cout << endl;
    }
}

int main()
{
    bool squirrelVisited[N][N] = {false};
    bool foxVisited[N][N] = {false};

    int squirrelPath[N][N] = {0};
    int foxPath[N][N] = {0};

    int acorns = 0;
    int gems = 0;

    searchForest(
        0, 0,
        'A', 7,
        acorns,
        squirrelVisited,
        squirrelPath
    );

    searchForest(
        2, 4,
        'G', 6,
        gems,
        foxVisited,
        foxPath
    );

    cout << "Squirrel collected "
         << acorns << " acorns\n";

    cout << "\nSquirrel Path:\n";
    display(squirrelPath);

    cout << "\nFox collected "
         << gems << " gems\n";

    cout << "\nFox Path:\n";
    display(foxPath);

    if (gems < 6)
        cout << "\n6 gems cannot be collected.";

    return 0;
}
