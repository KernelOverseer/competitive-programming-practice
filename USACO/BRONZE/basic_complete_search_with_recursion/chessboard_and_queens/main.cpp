#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned char uchar;

// #define DEBUG
#define MOD 1000000007

char    board[8][8];

void    copy_board(char my_board[8][8], char temp_board[8][8])
{
    for (uint i = 0; i < 8; i++)
    {
        for (uint j = 0; j < 8; j++)
        {
            temp_board[i][j] = my_board[i][j];
        }
    }
}

void    debug_print_board(char temp_board[8][8])
{
    for(int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << temp_board[i][j];
        }
        cout << endl;
    }
}

void    remove_positions(char temp_board[8][8], int y, int i)
{
    for (int j = 0; j < 8; j++)
    {
        temp_board[y][j] = '*';
        temp_board[j][i] = '*';
    }
    for (int j = -min(y, i); y+j < 8 && i+j < 8; j++)
    {
        temp_board[y+j][i+j] = '*';
    }
    int j = 0;
    while (i + j < 8 && y - j >= 0)
    {
        temp_board[y-j][i+j] = '*';
        j++;
    }
    j = 0;
    while (i - j >= 0 && y + j < 8)
    {
        temp_board[y+j][i-j] = '*';
        j++;
    }
}

int solve(char my_board[8][8], int y)
{
    char temp_board[8][8];

    if (y == 8)
        return (1);
    int result = 0;

    for (uint i = 0; i < 8; i++)
    {
        if (my_board[y][i] == '.')
        {
            copy_board(my_board, temp_board);
            remove_positions(temp_board, y, i);
            result += solve(temp_board, y+1);
        }
    }
    return result;
}

int main(void)
{
    // freopen("gymnastics.in", "r", stdin);
    // freopen("gymnastics.out", "w", stdout);

    for(uint i = 0; i < 8; i++)
    {
        for (uint j = 0; j < 8; j++)
            cin >> board[i][j];
    }
    cout << solve(board, 0) << endl;
    return (0);
}