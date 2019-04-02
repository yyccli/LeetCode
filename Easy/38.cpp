class Solution {
public:
    string countAndSay(int n) {
        string s = "";
        string pre = "1";

        //use loop??? why recursion???
        for (int i = 1; i < n; i++) {
            char c = pre[0];
            int index = 0, _count = 0;

            while (index < pre.size()) {
                while (index < pre.size() && pre[index] == c) {
                    index++;
                    _count++;
                }

                s += (_count+'0');
                s += c;
                _count = 0;
                if(index < pre.size())
                    c = pre[index];
            }

            pre = s;
            s = "";
        }

        return pre;
    }

//     string GenerateSeq(string pre, int i, int n){
//         if (i <= n) {
//             string s = "";
//             char c = pre[0];
//             int index = 0, _count = 0;

//             while (index < pre.size()) {
//                 while (index < pre.size() && pre[index] == c) {
//                     index++;
//                     _count++;
//                 }

//                 s += (_count+'0') + c;
//                 _count = 0;
//                 if(index < pre.size())
//                     c = pre[index];
//             }

//             GenerateSeq(s, i+1, n);
//         } else {
//             return pre;
//         }
//     }
};
