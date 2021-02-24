class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int i, j;
        int flag = 0;
        int res = 0;

        for(i = 0; i < 8; ++i){
            for(j = 0; j < 8; ++j){
                if('R' == board[i][j]){
                    flag = 1;
                    break;
                }
            }
            if(flag){
                break;
            }
        }

        for(int k = i; k >= 0; --k){
            if('B' == board[k][j]){
                break;
            }

            if('p' == board[k][j]){
                res++;
                break;
            }
        }

        for(int k = i; k < 8; ++k){
            if('B' == board[k][j]){
                break;
            }

            if('p' == board[k][j]){
                res++;
                break;
            }
        }

        for(int k = j; k >= 0; --k){
            if('B' == board[i][k]){
                break;
            }

            if('p' == board[i][k]){
                res++;
                break;
            }
        }

        for(int k = j; k < 8; ++k){
            if('B' == board[i][k]){
                break;
            }

            if('p' == board[i][k]){
                res++;
                break;
            }
        }


        return res;

    }
};
