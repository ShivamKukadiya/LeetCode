#include <bits/stdc++.h>

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        if (score.size() == 0) {
            return {};
        }
        vector<string> result(score.size());
        vector<pair<int, int>> vp;

        for (int i = 0; i < score.size(); i++) {
            vp.push_back({score[i], i});
        }
        for (int i = 0; i < score.size(); i++) {
            for (int j = 0; j < score.size() - 1;
                 j++) { // Adjusted loop condition
                if (vp[j].first < vp[j + 1].first) {
                    swap(vp[j], vp[j + 1]);
                }
            }
        }

        vector<string> prizes = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        for (int i = 0; i < vp.size(); ++i) {
            int rank = i;
            if (rank < 3) {
                result[vp[i].second] = prizes[rank];
            } else {
                result[vp[i].second] = to_string(rank + 1);
            }
        }
        return result;
    }
};