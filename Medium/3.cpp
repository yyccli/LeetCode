class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0, i = 0, j = 0;
        set<char> set;

        while(i < n && j < n)
        {
            if(set.find(s[j]) == set.end())
            {
                set.insert(s[j++]);
                ans = ans > (j - i) ? ans : (j - i);
            }
            else
            {
                set.erase(s[i++]);
            }
        }

        return ans;
    }
};
