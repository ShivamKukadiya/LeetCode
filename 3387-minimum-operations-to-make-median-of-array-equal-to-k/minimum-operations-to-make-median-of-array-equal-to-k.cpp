class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long cnt =0 ;
        long long n= nums.size();
        long long les = n/2;
         for(long long i = les; i >=0; i--){
            if(nums[i] < k )
                break;
            cnt +=(abs(nums[i]-k));
        }
        for(long long i = les; i<nums.size(); i++){
            if(nums[i] > k)
                break;
            cnt +=(abs(nums[i]-k));
        }
       
        return cnt;
    }
};