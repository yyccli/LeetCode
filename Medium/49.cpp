class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<string, vector<string>> m;
        vector<vector<string>> res;
        for(int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());

            m[s].push_back(strs[i]);

        }

        map<string, vector<string>>::iterator iter;
        for(iter = m.begin(); iter != m.end(); iter++) {
            res.push_back(iter->second);
        }

        return res;

    }
};
