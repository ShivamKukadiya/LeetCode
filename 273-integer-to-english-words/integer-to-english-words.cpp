class Solution {
public:
    string numberToWordsUnder1000(int num) {
        vector<string> belowTwenty = {
            "",        "One",     "Two",       "Three",    "Four",
            "Five",    "Six",     "Seven",     "Eight",    "Nine",
            "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
            "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"",      "",      "Twenty",  "Thirty", "Forty",
                               "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string result;
        if (num >= 100) {
            result += belowTwenty[num / 100] + " Hundred ";
            num %= 100;
        }
        if (num >= 20) {
            result += tens[num / 10] + " ";
            num %= 10;
        }
        if (num > 0) {
            result += belowTwenty[num] + " ";
        }
        return result;
    }
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        vector<string> thousands = {"", "Thousand", "Million", "Billion"};

        string result;
        int index = 0;
        while (num > 0) {
            if (num % 1000 != 0) {
                result = numberToWordsUnder1000(num % 1000) + thousands[index] +
                         " " + result;
            }
            num /= 1000;
            index++;
        }

        // Trim trailing spaces
        while (result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};
