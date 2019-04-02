class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        int mid;

        while(l < r) {
            mid = (l+r)/2;

            if(nums[mid] > nums[l])
                l = mid;

            if(nums[mid] < nums[r])
                r = mid;

            if(l == r-1)
                break;
        }

        int rl, rr;
        if(l == r-1)
            rl = l+1, rr = r-1+n;
        else
            rl = 0, rr = n-1;

        while(rl <= rr) {
            mid = (rl+rr)/2;

            if(nums[mid%n] == target)
                return mid%n;

            if(nums[mid%n] > target)
                rr = mid-1;
            else
                rl = mid+1;
        }

        return -1;
    }
};
