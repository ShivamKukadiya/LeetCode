class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v = {0,1};
        for(int i = 1 ; i < n; i++){
            auto tmp = v;
            reverse(tmp.begin(),tmp.end());
            for(auto &v : tmp){
                v += 1 << i;
            }
            v.insert(v.end(),tmp.begin(),tmp.end());
        }
        return v;
    }
};