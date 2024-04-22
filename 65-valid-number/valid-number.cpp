class Solution {
public:
    bool isValid(string str, bool canHaveDot) {
        if (!str.empty() && (str[0] == '+' || str[0] == '-'))
            str.erase(0, 1);

        if (str.empty() || str == ".")
            return false;

        for (char c : str) {
            if (c == '.') {
                if (!canHaveDot)
                    return false;
                canHaveDot = false;
            } else if (c < '0' || c > '9')
                return false;
        }
        return true;
    }
    bool isNumber(string s) {
        int len = s.size();
        if (len <= 0)
            return false;

        int epos = -1;
        for (int i = 0; i < len; ++i) {
            if (s[i] == 'e' || s[i] == 'E') {
                if (epos != -1)
                    return false;
                epos = i;
            }
        }

        if (epos == -1)
            return isValid(s, true);

        return isValid(s.substr(0, epos), true) &&
               isValid(s.substr(epos + 1), false);
    }
};