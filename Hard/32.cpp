class Solution {
public:
    int longestValidParentheses(string s) {
        //DP
        if(s.empty()) {
            return 0;
        }

        int n = s.size();
        int ans = 0;
        int* dp = new int[n];

        for(int i = 0; i < n; i++)
            dp[i] = 0;

        for(int i = 1; i < n; i++) {
            if(s[i] == ')') {
                if(s[i-1] == '(') {
                    dp[i] = (i-2 >= 0) ? dp[i-2] + 2 : 2;
                } else {
                    if((i-dp[i-1]-1) >= 0 && s[i-dp[i-1]-1] == '(') {
                        dp[i] = (i-dp[i-1]-2) >= 0 ? dp[i-1] + dp[i-dp[i-1]-2] + 2 : dp[i-1] + 2;
                    }
                }

                ans = max(ans, dp[i]);
            }

        }

        return ans;
    }

};
