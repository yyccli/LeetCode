class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()){
            return 0;
        }

        int index = 0;
        int pos = true;

        while(' ' == str[index]){
            index++;
        }

        if(index == str.length()){
            return 0;
        }

        if('-' == str[index]){
            if(isdigit(str[index+1])){
                pos = false;
                index++;
            }else{
                return 0;
            }

        }

        if('+' == str[index]){
            if(isdigit(str[index+1])){
                index++;
            }else{
                return 0;
            }
        }

        if(isalpha(str[index])){
            return 0;
        }

        int start = index;
        while(isdigit(str[index])){
            index++;
        }

        string ans = "";
        if(!pos){
            ans += "-";
            ans += str.substr(start, index-start+1);
        }else{
            ans += str.substr(start, index-start+1);
        }

        stringstream ss;
        long long int llans;
        ss << ans;
        ss >> llans;

        if(llans > INT_MAX){
            return INT_MAX;
        }

        if(llans < INT_MIN){
            return INT_MIN;
        }

        return (int)llans;
    }
};
