class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> ratio;
        for(int i = -0; i < n; i++) {
            ratio.push_back({ (double)wage[i]/(double)quality[i], i });
        }
        sort(ratio.begin(), ratio.end());

        priority_queue<double> hiredQualities;
        int currQuality;
        int qualitySum = 0;
        double maxRate = 0.;
        double test = 0.001;

        for(int i = 0; i < k; i++) {
            currQuality = quality[ratio[i].second];
            qualitySum += currQuality;
            maxRate = max(maxRate, ratio[i].first);
            hiredQualities.push(currQuality);
        }

        double ans = maxRate*qualitySum;
        for(int i = k; i < n; i++) {
            currQuality = quality[ratio[i].second];
            maxRate = max(maxRate, ratio[i].first);
            qualitySum -= hiredQualities.top();
            hiredQualities.pop();

            qualitySum += currQuality;
            hiredQualities.push(currQuality);
            ans = min(ans, maxRate*qualitySum);
        }

        return ans;
    }
};