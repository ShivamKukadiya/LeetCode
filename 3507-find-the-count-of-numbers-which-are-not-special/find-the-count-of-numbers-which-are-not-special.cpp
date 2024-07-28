class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int limit = sqrt(r);
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= limit; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> specialNumbers;
        for (int i = 2; i <= limit; ++i) {
            if (isPrime[i]) {
                int specialNumber = i * i;
                if (specialNumber >= l && specialNumber <= r) {
                    specialNumbers.push_back(specialNumber);
                }
            }
        }
        int totalNumbers = r - l + 1;
        int specialCount = specialNumbers.size();
        return totalNumbers - specialCount;
    }
};
