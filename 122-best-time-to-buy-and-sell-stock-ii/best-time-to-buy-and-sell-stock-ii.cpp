class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int res = 0;
        // int maxi = *max_element(prices);
        int sell = 0;
        int hold = INT_MIN;
        for(const int pr : prices){
            sell = max(sell,hold + pr);
            hold = max(hold,sell -pr);
        }
        return sell;
    }
};