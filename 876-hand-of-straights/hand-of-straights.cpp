class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mpp;
        for (int cap : hand) {
            mpp[cap]++;
        }
        sort(hand.begin(),hand.end());
        for (int i = 0; i < hand.size(); i++) {
            if (mpp[hand[i]] == 0) {
                continue;
            }
            for (int j = 0; j < groupSize; j++) {
                // if(mpp[]] == 0)
                int curd = hand[i] + j;
                if (mpp[curd] == 0) {
                    return false;
                }
                mpp[curd]--;
            }
        }
        return true;
    }
};