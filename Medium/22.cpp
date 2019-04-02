class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        if(0 == n){
            ans.push_back("");
            return ans;
        }

        Generate("", 0, 0, n, ans);

        return ans;
    }

    void Generate(string str, int left, int right, int n, vector<string>& ans) {
        if(str.size() == 2 * n){
            ans.push_back(str);
            return;
        }

        if(left < n){
            Generate(str+'(', left+1, right, n, ans);
        }

        if(right < left){
            Generate(str+')', left, right+1, n, ans);
        }

    }
};
