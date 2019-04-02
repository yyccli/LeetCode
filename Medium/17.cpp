class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string s[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int length = digits.size();
        vector<string> ans;

        if(0 == length){
            return ans;
        }

        int t = digits[0] - '0';
        for(int i = 0; i < s[t].size(); i++){
            ans.push_back(string(1, s[t][i]));
        }

        if(1 == length){
            return ans;
        }

        for(int i = 1; i < length; i++){
            vector<string> temp;
            for(int m = 0; m < ans.size(); m++){
                for(int n = 0; n < s[digits[i]-'0'].size(); n++){
                    string mul = ans[m] + s[digits[i]-'0'][n];
                    temp.push_back(mul);
                }
            }

            ans = temp;
        }

        return ans;
    }

};
