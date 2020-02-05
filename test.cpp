#include <iostream>
#include <vector>
#include <fstream>
#include <iosfwd>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int r, int c, vector<vector<char>> &board)
    {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != 'O')
        {
            return;
        }
        board[r][c] = '#';
        dfs(r + 1, c, board);
        dfs(r - 1, c, board);
        dfs(r, c + 1, board);
        dfs(r, c - 1, board);
    }

    void display(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << "----------" << endl;
    }

    void solve(vector<vector<char>> &board)
    {
        vector<bool> vis(board.size(), false);
        for (int i = 0; i < board[0].size(); i++)
        {
            if (board[0][i] == 'O')
            {
                dfs(0, i, board);
            }
            if (board[board.size() - 1][i] == 'O')
            {
                dfs(board.size() - 1, i, board);
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][0] == 'O')
                dfs(i, 0, board);
            if (board[i][board[0].size() - 1] == 'O')
                dfs(i, board[0].size() - 1, board);
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};

int main(int args, char **argv)
{
    // Solution twoSum_;
    // vector<vector<char>> board =
    // {{'X', 'X', 'X', 'X'},
    // {'X', 'O', 'O', 'X'},
    // {'X', 'X', 'O', 'X'},
    // {'X', 'O', 'X', 'X'}};
    // cout << "to solve" << endl;
    // twoSum_.solve(board);

    // int *p;
    // if (true)
    // {
    //     int x = 5;
    //     p = &x;
    // }
    // int* x = new int[8]{1,2,3,4,15,6,6,4};
    // delete p;
    // cout << *p << endl; // ???
    // char x(65);
    // cout << x << endl;
}