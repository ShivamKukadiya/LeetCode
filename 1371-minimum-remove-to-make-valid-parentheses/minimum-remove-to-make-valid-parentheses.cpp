
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int res = 0;
        vector<char> arr(s.begin(), s.end());

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == '(')
                res++;
            else if (arr[i] == ')') {
                if (res == 0)
                    arr[i] = '*';
                else
                    res--;
            }
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            if (res > 0 && arr[i] == '(') {
                arr[i] = '*';
                res--;
            }
        }

        string result = "";
        for (char c : arr) {
            if (c != '*')
                result += c;
        }

        return result;
    }
};