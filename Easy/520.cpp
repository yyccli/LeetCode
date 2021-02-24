class Solution {
public:
    bool detectCapitalUse(string word) {

        /*
        if(regex_match(word, regex("[A-Z]+"))) {
            return true;
        }

        if(regex_match(word, regex("[A-Z][a-z]+"))) {
            return true;
        }

        if(regex_match(word, regex("[a-z]+"))) {
            return true;
        }


        return false;
        */

        return regex_match(word, regex("[A-Z]*|.[a-z]*"));
    }
};
