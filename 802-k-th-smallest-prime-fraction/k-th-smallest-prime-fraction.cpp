class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>>pq;
        int l=arr.size();
        for(int i=0;i<l;i++){
            for(int j=i+1;j<l;j++){
                double temp= ((double)arr[i]/(double)arr[j]);
                pq.push({temp,{arr[i],arr[j]}});

                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        auto m=pq.top();

        int x=m.second.first,y=m.second.second;

        return {x,y};
    }
};