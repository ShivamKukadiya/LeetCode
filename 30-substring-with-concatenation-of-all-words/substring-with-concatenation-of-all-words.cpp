class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len=words[0].size();
        int n=s.size();
        int size=words.size();
        unordered_map<string, int> un;
        vector<int> ans;
        for(auto &it: words){
            un[it]++;
        }

        for(int i=0;i<len;i++){
            unordered_map<string, int> temp;
            int prev=i;
            int t=0;
            for(int j=i;j<n-i;j+=len){
                string cpy="";
                for(int k=j;(k<(j+len) and (j+len-1)<n);k++){
                    cpy.push_back(s[k]);
                }
                if(cpy.size()!=0){
                temp[cpy]++;
                t++;
                }
                while(temp[cpy]>un[cpy] and (prev+len-1)<n){
                    string cpy_prev="";
                    for(int k=prev;(k<(prev+len) and (prev+len-1)<n);k++){
                        cpy_prev.push_back(s[k]);
                    }
                    temp[cpy_prev]--;
                    prev+=len;
                    t--;
                }

                if(t==size){
                    ans.push_back(prev);
                    string cpy_prev="";
                    for(int k=prev;(k<(prev+len) and (prev+len-1)<n);k++){
                        cpy_prev.push_back(s[k]);
                    }
                    temp[cpy_prev]--;
                    prev+=len;
                    t--;
                }
            }
        }
        return ans;
    }
};