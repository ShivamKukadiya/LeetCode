#include<bits/stdc++.h>
class Solution {
public:
    bool checkValidString(string s) {
        stack<int>lalu,ceo;
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='('){
                lalu.push(i);
            }
            else if(s[i]=='*'){
                ceo.push(i);
            }else{
                if(!lalu.empty()){
                    lalu.pop();
                }else if(!ceo.empty()){
                    ceo.pop();
                }else{
                    return false;
                }
            }
        }
        while(!lalu.empty() && !ceo.empty() && ceo.top() > lalu.top()){
            lalu.pop();
            ceo.pop();
        }
        return lalu.empty();
    }
};