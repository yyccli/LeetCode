class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) {
            return 0;
        }

        size_t index = haystack.find(needle);

        if(index == string::npos) {
            return -1;
        }

        return index;
    }
};
