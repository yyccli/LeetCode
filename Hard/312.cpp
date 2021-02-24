class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        if(!n){
            return 0;
        }

        int** dp = new int*[n+2];
        for(int i = 0; i < n+2; ++i){
            dp[i] = new int[n+2]();
            // memset(dp[i], 0, sizeof(dp[i]));
        }

        int t = 0;
        for(int i = n; i >= 1; --i){
            for(int j = 1; j <= n; ++j){
                for(int k = i; k <= j; ++k){
                    t = dp[i][k-1] + nums[i-1]*nums[k]*nums[j+1] + dp[k+1][j];
                    dp[i][j] = dp[i][j] > t ? dp[i][j] : t;
                }
            }
        }

        return dp[1][n];
    }
};
