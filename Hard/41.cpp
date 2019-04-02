class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        if(nums.empty())
            return 1;

        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int ans = 1, i;

        for(i = 0; i < nums.size(); i++) {
            if(nums[i] > 0)
                break;
        }

        if(i > nums.size()-1)
            return 1;

        if(nums[i] > ans)
            return ans;

        while(i < nums.size()-1) {
            if(ans+1 < nums[i+1])
                return ans+1;

            i++;
            ans++;
        }

        return nums[nums.size()-1]+1;
    }
};
