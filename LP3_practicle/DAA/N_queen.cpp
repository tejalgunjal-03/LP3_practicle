
#include <iostream>
using namespace std;

int board[20][20];
int n;

// Check whether position is safe
bool isSafe(int row, int col)
{
    // Check same column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper-left diagonal
    int i = row - 1;
    int j = col - 1;

    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
            return false;

        i--;
        j--;
    }

    // Check upper-right diagonal
    i = row - 1;
    j = col + 1;

    while (i >= 0 && j < n)
    {
        if (board[i][j] == 1)
            return false;

        i--;
        j++;
    }

    return true;
}

// Backtracking function
bool solveNQueens(int row)
{
    // All queens successfully placed
    if (row == n)
        return true;

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            // Place queen
            board[row][col] = 1;

            if (solveNQueens(row + 1))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    cout << "Enter N: ";
    cin >> n;

    if (n <= 0 || n > 20)
    {
        cout << "Invalid N!";
        return 0;
    }

    // Initialize board
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    int col;

    cout << "Enter first queen column (1 to "
         << n << "): ";
    cin >> col;

    if (col < 1 || col > n)
    {
        cout << "Invalid position!";
        return 0;
    }

    // Place first queen in first row
    board[0][col - 1] = 1;

    if (solveNQueens(1))
    {
        cout << "\nN-Queens Solution:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }

            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists!";
    }

    return 0;
}
