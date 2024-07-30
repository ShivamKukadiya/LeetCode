class Solution {
public:
    int minimumDeletions(string s) {
        int ans =0 ; 
        int cnt  = 0;
        for(int i = 0;i < s.size(); i++){
            if(s[i] == 'a'){
                ans = min(ans + 1 , cnt);
            }else{
                cnt++;
            }
        }
        return ans;
    }
};