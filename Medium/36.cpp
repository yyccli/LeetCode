class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //BF? It may be a TLE qwq

        int h_r[9] = {0};
        int h_c[9] = {0};

        //Why i am so stupid?
        //Yes
        int h_sub[9] = {0};

        //Row and Column?
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(h_r[board[i][j]-'0'-1] == 1){
                        return false;
                    }else{
                        h_r[board[i][j]-'0'-1] = 1;
                    }
                }

                if(board[j][i] != '.'){
                    if(h_c[board[j][i]-'0'-1] == 1){
                        return false;
                    }else{
                        h_c[board[j][i]-'0'-1] = 1;
                    }
                }

            }

            //h_r = {0}, h_c = {0};
            memset(h_r, 0, sizeof(h_r));
            memset(h_c, 0, sizeof(h_c));
        }

        //Sub-box
        for(int i = 0; i < 9; i++){
            for(int m = 0; m < 3; m++){
                for(int n = 0; n < 3; n++){
                    if(board[(i/3)*3+m][(i%3)*3+n] != '.'){
                        if(h_sub[board[(i/3)*3+m][(i%3)*3+n]-'0'-1] == 1){
                            return false;
                        }else{
                            h_sub[board[(i/3)*3+m][(i%3)*3+n]-'0'-1] = 1;
                        }
                    }
                }
            }

            //h_sub = {0};
            memset(h_sub, 0, sizeof(h_sub));
        }

        return true;

    }
};
