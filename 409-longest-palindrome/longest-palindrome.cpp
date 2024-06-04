class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mpp;
        int ans = 0;
        int temp = 0;
        for (char i : s) {
            mpp[i]++;
        }
        bool flag = true;
        for (auto i : mpp) {
            if (i.second & 1) {
                if (flag) {
                    ans += i.second;
                    flag = false;
                } else {
                    ans += i.second - 1;
                }
            } else {
                ans += i.second;
            }
        }
        return ans ;
    }
};