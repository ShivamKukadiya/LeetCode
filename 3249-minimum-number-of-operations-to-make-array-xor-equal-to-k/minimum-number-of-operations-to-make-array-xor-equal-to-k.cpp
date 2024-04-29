class Solution {
public:
    int minOperations(vector<int>& v, int k) {
        int res = std::accumulate(v.begin(), v.end(), 0, std::bit_xor<int>());
    int prev = res ^ k;

    int ct = 0;
    while (prev != 0) {
        ct += prev & 1;
        prev >>= 1;
    }

    return ct;
        //  int res = 0;
        // for (int q : v) {
        //     res ^= q;
        // }
        // int prev = res ^ k;
        // int ct = 0;
        // while (prev != 0) {
        //     ct += prev & 1;
        //     prev >>= 1;
        // }
        // return ct;
    }
};