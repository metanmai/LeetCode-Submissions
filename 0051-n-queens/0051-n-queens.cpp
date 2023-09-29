class Solution {
private:
    void queens(vector<vector<string>> &answer, vector<string> &board, set<int> col, set<int> diag1, set<int> diag2, int i, int n)
    {
        if(i == n)
        {
            answer.push_back(board);
            return;
        }

        for(int j = 0; j < n; j++)
        {
            if(col.count(j) or diag1.count(i - j) or diag2.count(i + j))
                continue;
            
            board[i][j] = 'Q';
            col.insert(j);
            diag1.insert(i - j);
            diag2.insert(i + j);
            queens(answer, board, col, diag1, diag2, i + 1, n);
            board[i][j] = '.';
            col.erase(j);
            diag1.erase(i - j);
            diag2.erase(i + j);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;

        vector<string> board(n, string(n, '.'));
        set<int> col, diag1, diag2;

        queens(answer, board, col, diag1, diag2, 0, n);
        return answer;
    }
};