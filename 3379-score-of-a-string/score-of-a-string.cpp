class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 1; i < s.size(); i++) {
            ans += abs(int(s[i]) - int(s[i - 1]));
        }
        // p1(ans);
        return ans;
    }
};