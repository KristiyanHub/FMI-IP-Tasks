#include <iostream>
#include <fstream>

struct player
{
    char nickname[21];
    unsigned score;
};

player *playersList;

void loadFromFile(player* playersList)
{
    std::ofstream readPlayers("players.dat", std::ios::binary);

    if (!readPlayers.is_open())
    {
        std::cout << "Error";
        return;
    }

    int i = 0;

    while (!readPlayers.eof())
    {
        readPlayers << playersList[i].nickname;
        readPlayers << playersList[i].score;

        i += 1;
    }
}

int main()
{
    loadFromFile(playersList);

    std::cout << "Enter a nickname\n";
    char nick[21];
    std::cin.getline(nick, 21);

    for (int i = 0; i < 10; i++)
    {
        std::cout << playersList[i].nickname;
        std::cout << playersList[i].score;
    }
}
