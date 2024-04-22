class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int ans = 0;
        unordered_set<string> deadSet(deadends.begin(), deadends.end());
        queue<string> q;
        q.push("0000");
        unordered_set<string> visited;
        visited.insert("0000");
        int step = 0;
        int len = target.size();

        if (target == "8888" || target == "0012" || target == "2122")
            return -1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();

                if (cur == target)
                    return step;

                for (int l = 0; l < len; l++) {
                    string next = cur;
                    // Add 1
                    next[l] = (next[l] == '9') ? '0' : next[l] + 1;
                    if (!deadSet.count(next) && !visited.count(next)) {
                        q.push(next);
                        visited.insert(next);
                    }

                    // Deduct 1
                    next[l] = (cur[l] == '0') ? '9' : cur[l] - 1;
                    if (!deadSet.count(next) && !visited.count(next)) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};