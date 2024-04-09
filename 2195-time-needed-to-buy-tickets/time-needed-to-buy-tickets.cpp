class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0;
        int i = 0;
        while (tickets[k] != 0) {
            if (tickets[i] != 0) {
                tickets[i] = tickets[i] - 1;
                res++;
            }
            if (i == tickets.size() - 1) {
                i = 0;
                continue;
            }
            i++;
        }
        return res;
    }
};