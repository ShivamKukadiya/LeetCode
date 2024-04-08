class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& res) 
    {
        int les = 0;
        sort(res.begin(), res.end());
        vector<int> v = res[0];
        for(size_t i = 1; i < res.size(); i++){
            if(res[i][0] < v[1]){
                les++;
                v[1] = min(res[i][1], v[1]);
            } else {
                v = res[i];
            }
        }
        return les;
    }
};