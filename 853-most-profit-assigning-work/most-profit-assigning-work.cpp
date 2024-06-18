#include <bits/stdc++.h>
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
//         int n = worker.size();
//         int m = profit.size();

//         priority_queue<pair<int, int>> pq;
//         for (int i = 0; i < difficulty.size(); i++) {
//             int l = difficulty[i];
//             int k = profit[i];

//             pq.push({l, k});
//         }
//         // sort(worker.begin(), worker.end(), greater<int>());
// reverse(worker.rbegin(),worker.rend());
//         int i = 0;
//         int res = 0;
//         while (i < n && !pq.empty()) {
//             if (pq.top().second > worker[i]) {
//                 pq.pop();
//             } else {
//                 res += pq.top().first;
//                 i++;
//             }
//         }

//         return res;
    int n = difficulty.size();
        int m = worker.size();

        priority_queue<pair<int, int>> pq; //max heap of pairs

        for(int i = 0; i < n; i++) {
            int diff = difficulty[i];
            int prof = profit[i];

            pq.push({prof, diff});
        }

        sort(begin(worker), end(worker), greater<int>()); //descending order

        int i = 0;
        int totalProfit = 0;
        while(i < m && !pq.empty()) {
            if(pq.top().second > worker[i]) {
                pq.pop();
            } else {
                totalProfit += pq.top().first;
                i++;
            }
        }

        return totalProfit;
    
    }
};