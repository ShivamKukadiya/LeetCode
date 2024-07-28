#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> countMap;
        long long ans = 0;

        for(int hour : hours) {
            int mod = hour % 24;
            int complement = (24 - mod) % 24;
            if(countMap.find(complement) != countMap.end()) {
                ans += countMap[complement];
            }
            countMap[mod]++;
        }

        return ans;
    }
};
