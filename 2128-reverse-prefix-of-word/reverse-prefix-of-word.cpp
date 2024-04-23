class Solution {
public:
    string reversePrefix(string word, char ch) {

        string ans = "";
        bool flag = false;

        for(auto i:word){
            if(i!=ch){
                ans += i;
            }
            if(i==ch){
                if(flag==false){
                    ans += i;
                    reverse(ans.begin(), ans.end());
                    flag = true;
                }
                else{
                    ans += i;
                }
            }
        }
        return ans;
    }
};