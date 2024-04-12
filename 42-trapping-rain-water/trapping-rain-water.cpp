class Solution {
public:
    int trap(vector<int>& arr) {
  int n=arr.size();
  vector<int>ml(n),mr(n),water(n);
  ml[0]=arr[0];
  for(int i=1; i<n; i++){
    // cout<<arr[i]<<" ";
        ml[i]=max(ml[i-1],arr[i]);
  }
//   print(ml,n);
  mr[n-1]=arr[n-1];
  for(int i=n-2; i>=0; i--){
    mr[i]=max(arr[i],mr[i+1]);
  }
//   cout<<endl;
//   print(mr,a);
  for(int i=0; i<n; i++){
    water[i]=((min(ml[i],mr[i]))-arr[i]);
  }
  int sum=0;
  for (int i = 0; i < n; ++i)
  {
      /* code */
    sum+=water[i];
  }
  return sum;
    }
};