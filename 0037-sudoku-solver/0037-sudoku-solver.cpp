class Solution {
public:
    vector<int> getSubBox(int row, int col){
        if( row<=2 ){
            if(col<=2){
                return {0,0};
            }
            else if(col<=5){
                return {0,3};
            }
            else{
                return {0,6};
            }
        }
        else if( row<=5){
            if(col<=2){
                return {3,0};
            }
            else if(col<=5){
                return {3,3};
            }
            else{
                return {3,6};
            }
        }
        else{
            if(col<=2){
                return {6,0};
            }
            else if(col<=5){
                return {6,3};
            }
            else{
                return {6,6};
            }
        }
    }

    bool safe( int num, int row, int col, vector<vector<char>>& board){
        // row check:
        for( auto it : board[row] ){
            if( it == '.'){
                continue;
            }
            if( (it - '0') == num ){
                return false;
            }
        }

        // col check 
        for( int i = 0; i<9; i++ ){
            char it = board[i][col];
            if( it == '.'){
                continue;
            }
            if( (it - '0') == num ){
                return false;
            }
        }

        // subBox check
        vector<int> curr = getSubBox( row, col);
        int r = curr[0];
        int c = curr[1];

        for( int i = r; i<r+3; i++ ){
            for( int j = c; j<c+3; j++ ){

                char it = board[i][j];
                if( it == '.'){
                    continue;
                }
                if( (it - '0') == num ){
                    return false;
                }

            }
        }

        // all checks passed :
        return true;

    }

    vector<int> findNext(int row, int col, vector<vector<char>>& board){

        vector<int> ans(2,-1);
        if( row == 9 && col == 9 ){
            if( board[0][0] == '.' ){
                ans[0] = 0;
                ans[1] = 0;
                return ans;
            }
            else{
                row = 0;
                col = 0;
            }
        }
        for( int i = row; i<9; i++ ){
            int startCol;
            if(i == row){
                startCol = col + 1;
            }
            else{
                startCol = 0;
            }
            for( int j = startCol; j<9; j++ ){
                if( board[i][j] == '.' ){
                    ans[0] = i;
                    ans[1] = j;
                    return ans;
                }
            }
        }
        return ans;
    }

    bool solve( int row, int col, vector<vector<char>>& board ){
        
        for( int i = 1; i<=9; i++ ){
            bool check = safe( i, row, col, board);
            if( check == false ){
                continue;
            }

            board[row][col] = (char)(i + '0');

            vector<int> nextpos = findNext( row, col, board );

            if( nextpos[0]== -1  && nextpos[1] == -1 ){
                return true;
            }

            if(   solve( nextpos[0], nextpos[1], board )   ){
                return true;
            }

            board[row][col] = '.';

        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        bool ans;
        int r, c;
        if( board[0][0] == '.' ){
            r = 0;
            c = 0;
        }
        else{
            vector<int> startpos = findNext( 0, 0, board );
            r = startpos[0];
            c = startpos[1];
        }

        ans = solve( r, c, board );
    }
};