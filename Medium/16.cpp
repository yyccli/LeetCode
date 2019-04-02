class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size()-2; i++){
            if(i == 0 || (i > 0) && nums[i] != nums[i-1]){
                int l = i + 1;
                int r = nums.size() - 1;

                while(l < r){

                    int curr = nums[l] + nums[r] + nums[i];

                    if(curr == target){
                        return target;
                    }

                    ans = abs(ans - target) < abs(curr - target) ? ans : curr;

                    if(curr < target){
                        l++;
                    }else{
                        r--;
                    }
                }

            }
        }

        return ans;
    }
};
