class Solution {
public:
    int climbStairs(int n) {
       int t = 1;
       int t1 = 1;
       int result = 1;
       for(int i =  2 ; i <= n; i++){
        result = t  + t1;
        t = t1;
        t1 = result;
       }
       return result;
    }
};