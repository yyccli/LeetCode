class Solution {
public:
    int minDistance(string word1, string word2) {
        const int m = word1.size();
        const int n = word2.size();

        int f[501][501] = {0};
        int _max = 0;

        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(word1[i-1] == word2[j-1]){
                    f[i][j] = f[i-1][j-1] + 1;
                }else{
                    f[i][j] = max(f[i-1][j], f[i][j-1]);
                }

            }
        }

        return m+n-2*f[m][n];
    }
};
