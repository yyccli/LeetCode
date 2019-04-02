class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }

        string snum = to_string(x);
        string rsnum(snum.rbegin(), snum.rend());

        if(snum.compare(rsnum) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
};
