class Solution {
public:
    int countSeniors(vector<string>& details) {
        int c =0;
        for(const auto&i : details){
            if(stoi(i.substr(11,2)) > 60){
                c++;
            }
        }
        return c;
    }
};