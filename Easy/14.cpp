class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }

        sort(strs.begin(), strs.end());

        int i = 0;
        int flag = true;
        while(i < strs[0].size()){
            for(int j = 1; j < strs.size(); j++){
                if(strs[0][i] != strs[j][i]){
                    flag = false;
                }
            }

            if(flag){
                i++;
            }else{
                break;
            }
        }

        if(0 == i){
            return "";
        }

        return strs[0].substr(0, i);
    }
};
