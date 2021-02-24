class Solution {
public:
    string multiply(string num1, string num2) {
        if("0" == num1 || "0" == num2) {
            return "0";
        }

        int a = num1.size();
        int b = num2.size();

        string res(a+b, '0');

        for(int i = a-1; i >= 0; i--) {
            int c = 0;
            for(int j = b-1; j >= 0; j--) {
                int temp = (res[i+j+1]-'0') + (num1[i]-'0') * (num2[j]-'0') + c;
                res[i+j+1] = (temp % 10) + '0';
                c = temp / 10;
            }
            res[i] += c;
        }

        for(int i = 0; i < res.size(); i++) {
            if(res[i] != '0') {
                return res.substr(i);
            }
        }

        return "0";
    }

};
