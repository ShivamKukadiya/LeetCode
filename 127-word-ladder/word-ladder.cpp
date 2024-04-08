// #define int  long long
class Solution {
    bool isAdj(string& a, string& b) {
        int diff = 0;

        for (int i = 0; i < a.length(); ++i) {
            if (a[i] != b[i]) {
                diff++;
            }
        }

        return diff == 1;
    }

public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        wordList.insert(wordList.begin(), beginWord);

        int n = wordList.size();

        vector<vector<int>> adjList(n, vector<int>(0, 0));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isAdj(wordList[i], wordList[j])) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);

        queue<int> queue;
        queue.push(0);

        int pathLen = 0;

        while (!queue.empty()) {

            int size = queue.size();

            pathLen++;

            for (int k = 0; k < size; k++) {

                int node = queue.front();
                queue.pop();

                if (visited[node])
                    continue;

                visited[node] = true;

                if (wordList[node] == endWord)
                    return pathLen;

                for (auto e : adjList[node]) {
                    if (visited[e])
                        continue;

                    queue.push(e);
                }
            }
        }

        return 0;
    }
};