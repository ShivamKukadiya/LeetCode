class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1);
        if(rowIndex == 0){
            ans[0] = 1;
            return ans;
        }
        vector<int> tmp;
        for(int i=1;i<=rowIndex;i++){
            ans[0] = 1;
            int j=1;
            while(j<tmp.size() && tmp[j]!=0){
                ans[j] = tmp[j] + tmp[j-1];
                j++;
            }
            ans[j] = 1;
            tmp = ans;
        }

        return ans;
    }
};