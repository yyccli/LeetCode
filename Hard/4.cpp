class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        vector<int> s;

        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] < nums2[j])
            {
                s.push_back(nums1[i]);
                i++;
            }
            else
            {
                s.push_back(nums2[j]);
                j++;
            }

        }

        if(i == nums1.size())
        {
            while(j < nums2.size())
            {
                s.push_back(nums2[j]);
                j++;
            }
        }
        else
        {
            while(i < nums1.size())
            {
                s.push_back(nums1[i]);
                i++;
            }
        }

        if(0 == s.size() % 2)
        {
            return (s[s.size()/2-1] + s[s.size()/2]) / 2.0;
        }
        else
        {
            return s[s.size()/2.0];
        }
    }
};
