class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower[26] = {0};
        int upper[26] = {0};
        for(auto &i : word){
            if(i >= 'a' && i  <= 'z'){
                lower[ i - 'a']++;
            }else{
                upper[i - 'A']++;
            }
        }
        int ans = 0;
        for(int i = 0; i < 26; i++){
            if(lower[i]!=0 && upper[i]!=0){
                ans++;
            }
        }
        return ans;
    }
};