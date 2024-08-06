class Solution {
public:
   int minimumPushes(string word)
{
    map<char, int> mp;
    for (auto i : word)
        mp[i]++;

    int cnt = 0;
    int ans = 0;
    int mul = 1;
    int occurance = 0;
    vector<int> v;
    for (auto i : mp)
        v.push_back(i.second);

    sort(v.begin(), v.end(), greater<int>());
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        occurance++;
        cnt += v[i];
        if (occurance == 8)
        {
            ans = ans + (mul * cnt);
            cnt = 0;
            occurance = 0;
            mul++;
        }
    }
    ans = ans + (mul * cnt);
    return ans;
}
};