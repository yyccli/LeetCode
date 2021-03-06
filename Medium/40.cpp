class Solution {

private:
    vector<vector<int>> ans;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()) {
            return ans;
        }

        sort(candidates.begin(), candidates.end());
        vector<int> temp;

        for (int i = 0; i < candidates.size(); i++) {
            GenerateComb(i, candidates, target, temp);
        }

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }

    void GenerateComb(int i, vector<int>& candidates, int target, vector<int> temp) {
        temp.push_back(candidates[i]);
        int sum = accumulate(temp.begin(), temp.end(), 0);

        if (sum == target) {
            ans.push_back(temp);
            return;
        } else if (sum > target) {
            return;
        } else {
            for (int j = i+1; j < candidates.size(); j++) {
                GenerateComb(j, candidates, target, temp);
            }
        }
    }
};
