class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(0 == n){
            return 0;
        }
        int m = matrix[0].size();

        int** dp = new int*[n];
        for(int i = 0; i < n; ++i){
            dp[i] = new int[m];
        }

        int length = 0;

        for(int i = 0; i < m; ++i){
            dp[0][i] = matrix[0][i]-'0';
            if(1 == dp[0][i]){
                length = 1;
            }
        }

        for(int j = 0; j < n; ++j){
            dp[j][0] = matrix[j][0]-'0';
            if(1 == dp[j][0]){
                length = 1;
            }
        }

        for(int i = 1; i < n; ++i){
            for(int j = 1; j < m; ++j){
                if('1' == matrix[i][j] && '1' == matrix[i-1][j] && '1' == matrix[i][j-1] && '1' == matrix[i-1][j-1]){
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }else{
                    if('1' == matrix[i][j]){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = 0;
                    }
                }
                length = dp[i][j] > length ? dp[i][j] : length;
            }
        }

        return pow(length, 2);
    }
};
