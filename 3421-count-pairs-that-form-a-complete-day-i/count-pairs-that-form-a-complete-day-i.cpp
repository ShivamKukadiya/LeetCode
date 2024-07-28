#include <vector>
using namespace std;

class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int ans = 0;
        int sum;
        int n = hours.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {  // Corrected here: 'j++' instead of 'i++'
                sum = hours[i] + hours[j];
                if(sum % 24 == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
