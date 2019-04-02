class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //a classic dp?
        int ans = INT_MIN, dp = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(dp > 0) {
                dp += nums[i];
            } else {
                dp = nums[i];
            }

            if(dp > ans) {
                ans = dp;
            }
        }

        return ans;
    }
};
