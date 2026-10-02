#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void playerTurn(int secret, int players, int current);

void nextTurn(int secret, int players, int current)
{
    current++;

    if (current > players)
        current = 1;

    playerTurn(secret, players, current);
}

void playerTurn(int secret, int players, int current)
{
    int guess;

    cout << "Player " << current << ", enter guess: ";
    cin >> guess;

    if (guess == secret)
    {
        cout << "Player " << current << " wins!";
        return;
    }

    if (guess > secret)
        cout << "Too High!\n";
    else
        cout << "Too Low!\n";

    nextTurn(secret, players, current);
}

int main()
{
    srand(time(0));

    int players;

    cout << "Enter number of players: ";
    cin >> players;

    int secret = rand() % 100 + 1;

    playerTurn(secret, players, 1);

    return 0;
}
