#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int n = s.size();
        string ans = "";
        int res = 2 * (numRows - 1);
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < n; j += res) {
                ans += s[j];
                int l = j + res - 2 * i;
                if (i != 0 && i != numRows - 1 && l < n) {
                    ans += s[l];
                }
            }
        }
        return ans;
    }
};
