class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;

        if(1 == n) {
            return;
        }

        for(i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                break;
            }
        }

        if(-1 == i) {
            sort(nums.begin(), nums.end());
            return;
        }

        int j = i+1;
        while(j < n) {
            if(nums[j] > nums[i]) {
                j++;
            }else{
                break;
            }
        }
        j--;

        swap(nums[i], nums[j]);
        sort(nums.begin()+i+1, nums.end());
    }

    void swap(int& a, int& b) {
        int t;
        t = a;
        a = b;
        b = t;
    }
};
