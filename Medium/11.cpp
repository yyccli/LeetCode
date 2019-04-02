class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int ans = (j-i) * min(height[i], height[j]);

        while(i < j){
            if(height[i] <= height[j]){
                i++;
            }else{
                j--;
            }

            ans = max(ans, (j-i)*min(height[i], height[j]));
        }

        return ans;

    }
};
