#include <iostream>
#include <fstream>
#include <cstring>

struct player
{
    char nickname[21];
    unsigned score;
};

const int MAX = 100;
player playersList[MAX];

void loadFromFile(player *playersList)
{
    std::ifstream readPlayers("players.dat", std::ios::binary);

    if (!readPlayers.is_open())
    {
        std::cout << "Error";
        return;
    }

    int i = 0;

    unsigned scoreCurrent;

    char null[2] = "0";

    while (!readPlayers.eof())
    {
        readPlayers >> playersList[i].nickname;
        readPlayers >> scoreCurrent;
        if (scoreCurrent > 5000)
        {
            std::cout << "Ivalid score, player will be ingonerd \n";
            strcpy_s(playersList[i].nickname, null);
            playersList[i].score = 0;
        }
        else
        {
            playersList[i].score = scoreCurrent;
        }

        i += 1;
    }

    readPlayers.close();
}

void checkName(player* playersList, char* nick)
{
    int swapScores;

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < strlen(playersList[i].nickname); j++)
        {
            if (playersList[i].score != 0)
            {
                if (playersList[i].nickname[j] < nick[j])
                {
                    std::cout << playersList[i].nickname;
                    std::cout << " ";
                    std::cout << playersList[i].score;
                    std::cout << " ";
                    break;
                }
            }
        }
    }
}

void sortByScore(player* playersList, char *nick)
{
    unsigned swapScores;
    char swapNames[21];

    for (int i = 0; i < MAX; i++)
    {
        for (int j = i + 1; j < MAX - 1; j++)
        {
            
            if (playersList[i].score < playersList[j].score)
            {
                if (playersList[i].score != 0)
                {
                    //swap name
                    strcpy_s(swapNames, playersList[i].nickname);
                    strcpy_s(playersList[i].nickname, playersList[j].nickname);
                    strcpy_s(playersList[j].nickname, swapNames);

                    //swap score
                    swapScores = playersList[i].score;
                    playersList[i].score = playersList[j].score;
                    playersList[j].score = swapScores;
                }

            }
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        if (playersList[i].score != 0)
        {
            std::cout << playersList[i].nickname;
            std::cout << " ";
            std::cout << playersList[i].score;
            std::cout << " ";
        }

    }
    std::cout << "\n";
    std::cout << "Sorted by the word you entered: \n";
    checkName(playersList, nick);
}

int main()
{
    loadFromFile(playersList);

    std::cout << "Enter a nickname\n";
    char nick[21];
    std::cin.getline(nick, 21);

    for (int i = 0; i < MAX; i++)
    {
        if (playersList[i].score != 0)
        {
            std::cout << playersList[i].nickname;
            std::cout << " ";
            std::cout << playersList[i].score;
            std::cout << " ";
        }

    }
    std::cout << "\n";
    
    std::cout << "Sorted by score: \n";
    sortByScore(playersList, nick);
}
