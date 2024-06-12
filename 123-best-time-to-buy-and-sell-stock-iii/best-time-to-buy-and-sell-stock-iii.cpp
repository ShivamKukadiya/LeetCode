class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int n = prices.size();
        vector<int> leftProfits(n, 0);  // we sell on or before day i
        vector<int> rightProfits(n, 0); //  we buy on or after day i

        // Calculate leftProfits
        int minPrice = prices[0];
        for (int i = 1; i < n; ++i) {
            leftProfits[i] = max(leftProfits[i - 1], prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        // Calculate rightProfits
        int maxPrice = prices[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightProfits[i] = max(rightProfits[i + 1], maxPrice - prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }

        // Combine the results to get the maximum profit by two transactions
        int maxProfit = 0;
        for (int i = 0; i < n; ++i) {
            maxProfit = max(maxProfit, leftProfits[i] + rightProfits[i]);
        }

        return maxProfit;
    }
};
