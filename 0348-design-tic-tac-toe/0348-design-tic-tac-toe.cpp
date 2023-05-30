class TicTacToe {
private:
    vector<vector<int>> rowCount;
    vector<vector<int>> colCount;
    vector<vector<int>> diagCount;
    int n;
    
public:
    TicTacToe(int n) {
        this->n = n;
        rowCount.resize(3, vector<int> (n));
        colCount.resize(3, vector<int> (n));
        diagCount.resize(3, vector<int> (2));
    }
    
    int move(int row, int col, int player) {
        rowCount[player][row]++;
        colCount[player][col]++;
        
        if(row == col)
            diagCount[player][0]++;
        
        if(row + col == n - 1)
            diagCount[player][1]++;
        
        if(rowCount[player][row] == n or colCount[player][col] == n or 
           diagCount[player][0] == n or diagCount[player][1] == n)
            return player;
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */