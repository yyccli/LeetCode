class Solution {
public:
    int romanToInt(string s) {
        int length = s.size();
        int i = 0, ans = 0;
        char c;

        while(i < length){
            c = s[i];

            switch(c){
                case 'I':
                    if(s[i+1] == 'V'){
                        ans += 4;
                        i += 2;
                        break;
                    }

                    if(s[i+1] == 'X'){
                        ans += 9;
                        i += 2;
                        break;
                    }

                    ans++;
                    i++;
                    break;

                case 'V':
                    ans += 5;
                    i++;
                    break;

                case 'X':
                    if(s[i+1] == 'L'){
                        ans += 40;
                        i += 2;
                        break;
                    }

                    if(s[i+1] == 'C'){
                        ans += 90;
                        i += 2;
                        break;
                    }

                    ans += 10;
                    i++;
                    break;

                case 'L':
                    ans += 50;
                    i++;
                    break;

                case 'C':
                    if(s[i+1] == 'D'){
                        ans += 400;
                        i += 2;
                        break;
                    }

                    if(s[i+1] == 'M'){
                        ans += 900;
                        i += 2;
                        break;
                    }

                    ans += 100;
                    i++;
                    break;

                case 'D':
                    ans += 500;
                    i++;
                    break;

                case 'M':
                    ans += 1000;
                    i++;
                    break;

            }

        }

        return ans;
    }
};
