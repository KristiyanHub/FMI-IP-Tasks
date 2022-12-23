#include <iostream>

using namespace std;
const int SIZE = 225;

int givePositiveKey(int key)
{
    if(key < 0)
    {
        key = key * -1;
        return key;
    }
    else
    {
        return key;
    }
}

int numberOfElments(char message[SIZE])
{
    int counter = 0;
    
    while(message[counter] != '\0')
    {
        counter += 1;
    }
    
    return counter;
}

int getRows(char message[SIZE], int key)
{
    key = givePositiveKey(key);
    int counterForAllElements = 0;
    int counterForCurrentRow = 0;
    int numberOfRows = 1;
    
    while(message[counterForAllElements] != '\0')
    {
        counterForAllElements += 1;
        counterForCurrentRow += 1;
        if(counterForCurrentRow == key)
        {
           numberOfRows += 1;
           counterForCurrentRow = 0;
        }
    }
    
    return numberOfRows;
}

char turnArrayToMatrix(char message[SIZE],char matrix[SIZE][SIZE], int key)
{
    int lenght = numberOfElments(message);
    int counterForIndex = 0;
    int row;
    int col;
    
    col = givePositiveKey(key);
    row = getRows(message, key);
    
    matrix[row][col];
    
    //Entering elements in matrix
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            matrix[i][j] = message[counterForIndex];
            counterForIndex++;
            lenght -= 1;
            
            if(lenght < 0)
            {
                matrix[i][j] = 'X';
            }
        }
    }
    
    return matrix[SIZE][SIZE];
}

void encriptMatrix(char message[SIZE], char matrix[SIZE][SIZE], int key)
{
    int lenght = numberOfElments(message);
    int counterForIndex = 0;
    int row;
    int col;
    
    char newMatrix[SIZE][SIZE];
    
    col = givePositiveKey(key);
    row = getRows(message, key);
    
    char enciptedMessage[SIZE];
    
    if(key > 0)
    {
        int i;
        int startingRow = 0;
        int startingCol = 0;
        
        int count = 0;
        int total = row * col;
        while (startingRow < row && startingCol < col)
        {
            if (count == total)
            {
                break;
            }
            
            for (i = startingRow; i < row; i++)
            {
                enciptedMessage[count] = matrix[i][startingCol];
                count++;
            }
            
            startingCol++;
            
            if (count == total)
            {
                break;
            }

            for (i = startingCol; i < col; i++)
            {
                enciptedMessage[count] = matrix[row - 1][i];
                count++;
            }
            
            row--;

            if (count == total)
            {
                break;
            }

            if (startingRow < row)
            {
                for (i = row - 1; i >= startingRow; i--)
                {
                    enciptedMessage[count] = matrix[i][col - 1];
                    count++;
                }
                
                col--;
            }

            if (count == total)
            {
                break;
            }
            
            if (startingCol < col)
            {
                for (i = col - 1; i >= startingCol; i--)
                {
                    enciptedMessage[count] = matrix[startingRow][i];
                    count++;
                }
                
                startingRow++;
            }
        }
    }
    
    
    else
    {
        int i;
        int startingRow = row;
        int startingCol = col;
        
        row = 0;
        col = 0;
        
        int count = 0;
        int total = startingRow * startingCol;
        
        while (startingRow > row && startingCol > col)
        {
            if(count == total)
            {
                break;
            }
            
            for(i = startingRow - 1; i > row; i--)
            {
                enciptedMessage[count] =  matrix[i][startingCol - 1];
                count += 1;
            }
            startingCol -= 1;
            
            if(count == total)
            {
                break;
            }
            
            for(i = startingCol; i >= col; i--)
            {
                enciptedMessage[count] = matrix[row][i];
                count += 1;
            }
            row += 1;
            
            if(count == total)
            {
                break;
            }
            
            if(startingRow > row)
            {
                for(i = row; i < startingRow; i++)
                {
                    enciptedMessage[count] = matrix[i][col];
                    count += 1;
                }
                col += 1;
            }
            
            if(count == total)
            {
                break;
            }
            
            //here
            if(startingCol > col)
            {
                for(i = col; i < startingCol; i++)
                {
                    enciptedMessage[count] = matrix[startingRow - 1][i];
                    count += 1;
                }
                startingRow -= 1;
            }
        }
    }
    
    cout << enciptedMessage;
}

int main()
{
    cout<<"Enter key" << endl;
    int key;
    do
    {
        cin >> key;
    }
    while(key == 0);
    
    cout << "Enter message without spaces or other symbols" << endl;
    char message[SIZE];
    cin.ignore();
    cin.getline(message, SIZE);
    
    char matrix[SIZE][SIZE];
    
    turnArrayToMatrix(message, matrix, key);
    
    cout << endl;
    
    //Print matrix
    cout << "The text in a matrix is" << endl;
    for(int i = 0; i < getRows(message, givePositiveKey(key)); i++)
    {
        for(int j = 0; j < givePositiveKey(key); j++)
        {
            if (matrix[i][j] == '\0')
            {
                break;
            }
            cout << matrix[i][j] << " "; 
        }
        cout << endl;
    }
    
    cout << "The encripted message is: ";
    encriptMatrix(message, matrix, key);

    return 0;
}