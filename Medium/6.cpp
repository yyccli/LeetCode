class Solution {
public:
    string convert(string s, int numRows) {

        if(1 == numRows)
            return s;

        int currRow = 0;
        int length = s.length();
        bool goingDown = false;
        vector<string> rows(min(numRows, length));

        for(char c : s)
        {
            rows[currRow] += c;
            if(0 == currRow || min(numRows, length)-1 == currRow)
                goingDown = !goingDown;
            currRow += goingDown ? 1 : -1;
        }

        string ans;
        for(string row : rows)
        {
            ans += row;
        }

        return ans;

    }
};
