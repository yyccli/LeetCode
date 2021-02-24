class Solution {
public:
    static bool comp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2){
        return (p1.first.second < p2.first.second);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        vector<pair<pair<int, int>, int>> all;
        pair<int, int> tp(0 ,0);
        pair<pair<int, int>, int> tpp(tp, 0);
        all.push_back(tpp);

        for(int i = 0; i < endTime.size(); ++i){
            tp = make_pair(startTime[i], endTime[i]);
            tpp = make_pair(tp, profit[i]);

            all.push_back(tpp);
        }

        sort(all.begin()+1, all.end(), comp);

        vector<int> p;
        p.push_back(0);
        int j;
        for(int i = 1; i < all.size(); ++i){
            j = i - 1;
            while(j >= 0 && all[i].first.first < all[j].first.second){
                j--;
            }

            p.push_back(j >= 0 ? j : 0);
        }

        int* dp = new int[all.size()];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i < all.size(); ++i){
            dp[i] = max(dp[i-1], dp[p[i]]+all[i].second);
        }

        return dp[all.size()-1];
    }

};
