class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        int c = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == target[i]){
                c++;
            }
        }
        if(c == arr.size()){
            return true;
        }else{
            return false;
        }
    }
};