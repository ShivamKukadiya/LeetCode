class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (s[0] == '0' || n == 0)
            return 0;
        else if (n == 1)
            return 1;
        int c1 = 1, c2 = 1;
        for (int i = 1; i < n; i++) {
            int d = s[i] - '0';
            int d2 = (s[i - 1] - '0') * 10 + d;
            int c = 0;
            if (d > 0)
                c += c2;
            if (d2 >= 10 && d2 <= 26)
                c += c1;
            c1 = c2;
            c2 = c;
        }
        return c2;
    }
};