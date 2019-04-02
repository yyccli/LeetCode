class Solution {
public:
    string longestPalindrome(string s) {
        string rs(s.rbegin(), s.rend());

        int n = s.length();
        pair<int, int> ans(0, 0);
        int dp[n+1][n+1];

        for(int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for(int j = 0; j <= n; j++)
            dp[0][j] = 0;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s[i-1] == rs[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    //judge if dp[i][j] is palindromic
                    if(dp[i][j] > ans.second)
                    {
                        if(isPalindromic(i, dp[i][j], s))
                        {
                            ans = make_pair(i, dp[i][j]);
                        }
                    }
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        return s.substr(ans.first - ans.second, ans.second);
    }

    bool isPalindromic(int i, int length, string s)
    {
        int ii = i - length;
        int jj = i - 1;

        while(ii < jj)
        {
            if(s[ii] == s[jj])
            {
                ii++;
                jj--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
