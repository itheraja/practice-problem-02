#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void playGame(int secret, int players, int currentPlayer)
{
    int guess;

    cout << "Player " << currentPlayer << ", enter guess: ";
    cin >> guess;

    if (guess == secret)
    {
        cout << "Player " << currentPlayer << " wins!";
        return;
    }

    if (guess > secret)
        cout << "Too High!\n";
    else
        cout << "Too Low!\n";

    currentPlayer++;

    if (currentPlayer > players)
        currentPlayer = 1;

    playGame(secret, players, currentPlayer);
}

int main()
{
    srand(time(0));

    int players;
    cout << "Enter number of players: ";
    cin >> players;

    int secret = rand() % 100 + 1;

    playGame(secret, players, 1);

    return 0;
}
