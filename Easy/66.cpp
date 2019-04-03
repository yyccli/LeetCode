class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = (digits[digits.size()-1] + 1) / 10;
        int i;

        if(0 == carry) {
            digits[digits.size()-1]++;
            return digits;
        } else {
            digits[digits.size()-1] = 0;
            for(i = digits.size()-2; i >= 0; i--) {
                if(digits[i] + carry > 9) {
                    digits[i] = 0;
                    carry = 1;
                } else {
                    digits[i]++;
                    break;
                }
            }

            if(i < 0) {
                digits.insert(digits.begin(), 1);
            }

            return digits;
        }
    }
};
