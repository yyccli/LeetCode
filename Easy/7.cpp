class Solution {
public:
    int reverse(int x) {
        long long int lx = x;
        long long int ans = 0;

        while(0 != lx)
        {
            ans = ans * 10 + lx % 10;
            lx /= 10;
        }

        if(ans > INT_MAX || ans < INT_MIN)
        {
            return 0;
        }

        return (int)ans;
    }
};
