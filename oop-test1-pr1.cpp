#include <iostream>
#include <fstream>

const int MAX = 100;

struct square
{
    unsigned side;
    unsigned lowerLeftX;
    unsigned lowerLeftY;
};

square squares[MAX];

void readSquaresFromFile(square squares[MAX])
{
    std::ifstream readSquares("squares.dat", std::ios::binary);

    unsigned sideCurrent;
    unsigned leftX;
    unsigned leftY;

    int i = 0;

    while (!readSquares.eof())
    {
        readSquares >> sideCurrent;
        squares[i].side = sideCurrent;
        readSquares >> leftX;
        squares[i].lowerLeftX = leftX;
        readSquares >> leftY;
        squares[i].lowerLeftY = leftY;

        i += 1;
    }

    readSquares.close();
}

void saveByArea(square *squares, unsigned number)
{
    std::ofstream saveSquares("squares-output.txt");

    int squareArea;

    for (int i = 0; i < MAX; i++)
    {
        squareArea = (squares[i].side * squares[i].side);

        if (squareArea > number)
        {
            std::cout << squares[i].side << " ";
            std::cout << squares[i].lowerLeftX << " ";
            std::cout << squares[i].lowerLeftX << " ";
            std::cout << squareArea << "\n";

            saveSquares << "\n" << "These are for square: " << i + 1 << "\n";
            //Lower left
            saveSquares << squares[i].lowerLeftX;
            saveSquares << " ";
            saveSquares << squares[i].lowerLeftY;
            saveSquares << " ";
            //UpperRight
            saveSquares << (squares[i].lowerLeftX + squares[i].side);
            saveSquares << " ";
            saveSquares << (squares[i].lowerLeftY + squares[i].side);
            saveSquares << " ";
        }
    }

    saveSquares.close();
}

void sortSquares(square *squares, int number)
{
    std::cout << "Sorting has started here: \n";
    int keepForSwapSide;
    int keepForSwapX;
    int keepForSwapY;

    //Sort by side
    for (int i = 0; i < MAX; i++)
    {
        for (int j = i + 1; j < MAX; j++)
        {
            if (squares[i].side < squares[j].side)
            {
                //swap sides
                keepForSwapSide = squares[i].side;
                squares[i].side = squares[j].side;
                squares[j].side = keepForSwapSide;
            
                //swap x
                keepForSwapX = squares[i].lowerLeftX;
                squares[i].lowerLeftX = squares[j].lowerLeftX;
                squares[j].lowerLeftX = keepForSwapX;

                //swap y
                keepForSwapY = squares[i].lowerLeftY;
                squares[i].lowerLeftY = squares[j].lowerLeftY;
                squares[j].lowerLeftY = keepForSwapY;
            }
            else if (squares[i].side == squares[j].side)
            {
                if (squares[i].lowerLeftX < squares[j].lowerLeftX)
                {
                    //swap sides
                    keepForSwapSide = squares[i].side;
                    squares[i].side = squares[j].side;
                    squares[j].side = keepForSwapSide;

                    //swap x
                    keepForSwapX = squares[i].lowerLeftX;
                    squares[i].lowerLeftX = squares[j].lowerLeftX;
                    squares[j].lowerLeftX = keepForSwapX;

                    //swap y
                    keepForSwapY = squares[i].lowerLeftY;
                    squares[i].lowerLeftY = squares[j].lowerLeftY;
                    squares[j].lowerLeftY = keepForSwapY;
                }
                else if (squares[i].lowerLeftY < squares[j].lowerLeftY)
                {
                    //swap sides
                    keepForSwapSide = squares[i].side;
                    squares[i].side = squares[j].side;
                    squares[j].side = keepForSwapSide;

                    //swap x
                    keepForSwapX = squares[i].lowerLeftX;
                    squares[i].lowerLeftX = squares[j].lowerLeftX;
                    squares[j].lowerLeftX = keepForSwapX;

                    //swap y
                    keepForSwapY = squares[i].lowerLeftY;
                    squares[i].lowerLeftY = squares[j].lowerLeftY;
                    squares[j].lowerLeftY = keepForSwapY;
                }
            }
        }
    }

    saveByArea(squares, number);
}

int main()
{
    readSquaresFromFile(squares);

    std::cout << "Enter a number \n";
    unsigned number;
    std::cin >> number;

    std::cout << "Our squares: \n";
    for (int i = 0; i < MAX; i++)
    {
        if (squares[i].side != 0)
        {
            std::cout << squares[i].side << " ";
            std::cout << squares[i].lowerLeftX << " ";
            std::cout << squares[i].lowerLeftY << " ";
            std::cout << "\n";
        }
    }

    sortSquares(squares, number);
}
