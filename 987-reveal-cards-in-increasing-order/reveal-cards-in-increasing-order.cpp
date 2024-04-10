class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int res = 0;
        int n = deck.size();
        vector<int>v(n);
        deque<int>qq;
        for(int i = 0; i < n; i++){
            qq.push_back(i);
        }
        for(int card : deck){
            int index = qq.front();
            qq.pop_front();

            v[index] = card;
            if(!qq.empty()){
                qq.push_back(qq.front());
                qq.pop_front();
            }
        }
        return v;
    }
};