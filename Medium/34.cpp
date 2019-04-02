class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1, -1};

        if(nums.empty()) {
            return ans;
        }

        int l = 0, r = nums.size()-1, mid;
        int t = -1;

        while(l <= r) {
            mid = (l+r)/2;

            if(nums[mid] == target) {
                t = mid;
                break;
            }

            if(nums[mid] > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        if(-1 == t) {
            return ans;
        }

        l = t, r = t;

        while(nums[t] == nums[l]) {
            l--;

            if(l < 0)
                break;
        }

        while(nums[t] == nums[r]) {
            r++;

            if(r > nums.size()-1)
                break;
        }

        ans[0] = ++l;
        ans[1] = --r;

        return ans;
    }
};
