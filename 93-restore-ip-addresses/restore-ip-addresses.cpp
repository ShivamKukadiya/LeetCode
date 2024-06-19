class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string res;
        int n = s.size();
        for (int a = 1; a <= 3; a++) {
            for (int b = 1; b <= 3; b++) {
                for (int c = 1; c <= 3; c++) {
                    for (int d = 1; d <= 3; d++) {
                        if (a + b + c + d == n) {
                            int s1 = stoi(s.substr(0, a));
                            int s2 = stoi(s.substr(a, b));
                            int s3 = stoi(s.substr(a + b, c));
                            int s4 = stoi(s.substr(a + b + c, d));
                            if (s1 <= 255 && s2 <= 255 && s3 <= 255 &&
                                s4 <= 255) {
                                if ((res = to_string(s1) + "." + to_string(s2) +
                                         "." + to_string(s3) + "." +
                                         to_string(s4))
                                        .length() >= n + 3)
                                    ans.push_back(res);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};