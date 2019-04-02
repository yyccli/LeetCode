class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        if(nums.empty() || nums.size() < 3){
            return ans;
        }

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if(i == 0 || (i > 0) && nums[i] != nums[i-1]){
                int l = i+1;
                int r = nums.size()-1;
                int sum = -nums[i];

                while(l < r){
                    if(nums[l]+nums[r] == sum){
                        vector<int> temp{nums[i], nums[l], nums[r]};
                        ans.push_back(temp);

                        while(l < r && nums[l] == nums[l+1]){
                            l++;
                        }

                        while(l < r && nums[r] == nums[r-1]){
                            r--;
                        }

                        l++;
                        r--;

                    }else if(nums[l]+nums[r] < sum){
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
