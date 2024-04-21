class Solution {
public:
    int numberOfSpecialChars(string word) {
        int l[26]={0},u[26]={0};
        int n=word.size()-1;
        for(int x=n;x>=0;x--){
            char i=word[x];
            if(i>='a'&&i<='z'){
                l[i-'a']++;
                if(u[i-'a']==0)u[i-'a']=-1;
            // cout<<i<<" "<<l[i-'a']<<" "<<u[i-'a']<<endl;    
            }
            if(i>='A'&&i<='Z'){
                u[i-'A']++;
                if(l[i-'A']!=0)u[i-'A']=-1;
            // cout<<i<<" "<<l[i-'A']<<" "<<u[i-'A']<<endl;    
            }
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            if(l[i]!=0&&u[i]!=0&&u[i]!=-1)cnt++;
        }
        return cnt; 
    }
};