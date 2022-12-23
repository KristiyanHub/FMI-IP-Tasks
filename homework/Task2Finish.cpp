#include <iostream>

using namespace std;

const int MAX = 100;

int numberOfElments(char actions[MAX])
{
    int counter = 0;
    
    while(actions[counter] != '\0')
    {
        counter += 1;
    }
    
    return counter;
}

char colNumberToSymbol(int col)
{
    char columChar;
    
    if(col == 1)
    {
        columChar = 'a';
    }
    else if(col == 2)
    {
        columChar = 'b';
    }
    else if(col == 3)
    {
        columChar = 'c';
    }
    else if(col == 4)
    {
        columChar = 'd';
    }
    else if(col == 5)
    {
        columChar = 'e';
    }
    else if(col == 6)
    {
        columChar = 'f';
    }
    else if(col == 7)
    {
        columChar = 'g';
    }
    else if(col = 8)
    {
        columChar = 'h';
    }
    
    return columChar;
}

int checkStartingCol(char startingCol)
{
    int col = 0;
    
    if(startingCol == 'a')
    {
        col = 1;
    }
    else if(startingCol == 'b')
    {
        col = 2;
    }
    else if(startingCol == 'c')
    {
        col = 3;
    }
    else if(startingCol == 'd')
    {
        col = 4;
    }
    else if(startingCol == 'e')
    {
        col = 5;
    }
    else if(startingCol == 'f')
    {
        col = 6;
    }
    else if(startingCol == 'g')
    {
        col = 7;
    }
    else if(startingCol == 'h')
    {
        col = 8;
    }
    
    return col;
}

int checkStartingRow(char startingRow)
{
    int row = 0;
    
    if(startingRow == '1')
    {
        row = 1;
    }
    else if(startingRow == '2')
    {
        row = 2;
    }
    else if(startingRow == '3')
    {
        row = 3;
    }
    else if(startingRow == '4')
    {
        row = 4;
    }
    else if(startingRow == '5')
    {
        row = 5;
    }
    else if(startingRow == '6')
    {
        row = 6;
    }
    else if(startingRow == '7')
    {
        row = 7;
    }
    else if(startingRow == '8')
    {
        row = 8;
    }
    
    return row;
}

void calculateMoves(char startingCol, char startingRow, char actions[MAX])
{
    char command1[3];
    char command2[3];
    int row;
    int col;
    
    int Prevrow;
    int Prevcol;
    
    int index = 0;
    int counter = 0;
    
    int numberOfActions;
    numberOfActions = numberOfElments(actions);
    
    row = checkStartingRow(startingRow);
    col = checkStartingCol(startingCol);
    
    while(actions[counter] != '\0')
    {
        command1[index] = actions[counter + counter];
        command2[index + 1] = actions[counter + counter + 1];
            
        if(command1[index] == 'u' & command2[index + 1] == 'l')
        {
            row += 2; 
            col -= 1;
        }
        
        else if(command1[index] == 'u' & command2[index + 1] == 'r')
        {
            row += 2; 
            col += 1;
        }
        
        
        else if(command1[index] == 'r' & command2[index + 1] == 'u')
        {
            row += 1; 
            col += 2;
        }
        
        
        else if(command1[index] == 'r' & command2[index + 1] == 'd')
        {
            row -= 1; 
            col += 2;
        }
        
            
        else if(command1[index] == 'd' & command2[index + 1] == 'r')
        {
            row -= 2; 
            col += 1;
        }
            
        else if(command1[index] == 'd' & command2[index + 1] == 'l')
        {
            row -= 2; 
            col -= 1;
        }
            
        else if(command1[index] == 'l' & command2[index + 1] == 'd')
        {
            row -= 1;
            col -= 2;
        }
            
        else if(command1[index] == 'l' & command2[index + 1] == 'u')
        {
            row += 1;
            col -= 2;
        }
        
        if(col >= 1 && col <= 8 && row >= 1 && row <= 8 )
        {
            Prevrow = row;
            Prevcol = col; 
        }
        else
        {
            break;
        }
        
        counter += 1;
    }   
    
    if(row > 8 || col > 8 || col < 1 || row < 1)
    {
        cout << "Not all moves valid. The knight cannot move to " << actions[counter + counter] << actions[counter + counter + 1] << " The knight's final posiotion is: " << colNumberToSymbol(Prevcol) << Prevrow;
    }
    else if((row >= 1 && row <= 8) && (col >= 1 && col <= 8))
    {
        cout << "All moves valid. The knight ends at postiion: " << colNumberToSymbol(Prevcol) << Prevrow;
    }
    
}

int main()
{
    cout << "Enter starting position" << endl;
    char startingCol;
    cin >> startingCol;
    
    char startingRow;
    cin >> startingRow;
    
    cin.ignore();
    
    cout << "Enter eight symbols" << endl;
    char actions[MAX];
    cin.getline(actions, MAX);
    
    char command[3];
    
    cout << "Starting position is: ";
    cout << checkStartingCol(startingCol);
    cout << checkStartingRow(startingRow) << endl;
    
    cout << "Commands are: ";
    cout << actions;
    
    cout << endl;
    
    calculateMoves(startingCol, startingRow, actions);

    return 0;
}