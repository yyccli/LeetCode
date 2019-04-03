class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) {
            return 0;
        }

        int ans = 0;
        int j;

        for(j = s.size()-1; j >= 0; j--) {
            if(s[j] != ' ') {
                break;
            }
        }

        for(int i = j; i>= 0; i--) {
            if(s[i] != ' ') {
                ans++;
            } else {
                break;
            }
        }

        return ans;
    }
};
