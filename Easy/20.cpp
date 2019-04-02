class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;

        int n = s.size();
        int index = 0;
        bool flag = false;

        if(n%2 != 0) return false;

        stack<char> sta;
        while(index < n){
            char c = s[index];
            if(sta.empty()){
                sta.push(c);
                index++;
                continue;
            }

            switch(c){
                case '(':
                    sta.push(c);
                    break;

                case '{':
                    sta.push(c);
                    break;

                case '[':
                    sta.push(c);
                    break;

                case ')':
                    if(sta.top() == '(') sta.pop();
                    else flag = true;
                    break;

                case '}':
                    if(sta.top() == '{') sta.pop();
                    else flag = true;
                    break;

                case ']':
                    if(sta.top() == '[') sta.pop();
                    else flag = true;
                    break;
            }

            if(flag) return false;
            index++;
        }

        if(sta.empty()) return true;
        return false;
    }
};
