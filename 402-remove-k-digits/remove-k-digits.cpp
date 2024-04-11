#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        int keep = n - k;
        string result = "";
        for (char digit : num) {
            while (k > 0 && !result.empty() && result.back() > digit) {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }
        result.resize(keep);
        int s = 0;
        while (s < result.length() && result[s] == '0') {
            s++;
        }
        result = result.substr(s);
        return result.empty() ? "0" : result;
    }
};
