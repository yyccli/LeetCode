class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.size();
        int lb = b.size();
        int i = la-1, j = lb-1;
        int carry = 0;
        string ans(max(la, lb)+1, '0');
        int k = ans.size()-1;

        while(i >= 0 && j >= 0) {
            ans[k] = (((a[i]-'0') + (b[j]-'0') + carry)%2)+'0';
            carry = ((a[i]-'0') + (b[j]-'0') + carry)/2;
            i--, j--, k--;
        }

        while(i >= 0) {
            ans[k] = (((a[i]-'0') + carry)%2)+'0';
            carry = ((a[i]-'0') + carry)/2;
            i--, k--;
        }

        while(j >= 0) {
            ans[k] = (((b[j]-'0') + carry)%2)+'0';
            carry = ((b[j]-'0') + carry)/2;
            j--, k--;
        }

        if(carry > 0) {
            ans[0] = '1';
            return ans;
        } else {
            ans.erase(0, 1);
            return ans;
        }
    }
};
