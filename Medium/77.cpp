class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> r(k, 0);

        int i = 0;

        while(i >= 0) {
            r[i]++;

            if(r[i] > n) {
                i--;
            } else if(i == k-1) {
                res.push_back(r);
            } else {
                i++;
                r[i] = r[i-1];
            }
        }

        return res;

    }
};
