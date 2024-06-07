class Solution {
public:
    string replaceWords(vector<string>& dict, string sent) {
        unordered_set<string> st;
        for(auto &it:dict)
            st.insert(it);
        
        string ans = "";
        stringstream strStream(sent);
        string word = "";
        while(getline(strStream, word, ' ')){
            if(word.size() == 0) break;
            string temp = "";
            bool isFound = false;
            for(int i = 0; i < word.size(); i++){
                temp += word[i];
                if(st.find(temp) != st.end()){
                    ans += temp + " ";
                    isFound = true;
                    break;
                }
            }
            if(!isFound)
                ans += temp + " ";
        }
        ans.pop_back();
        return ans;
    }
};