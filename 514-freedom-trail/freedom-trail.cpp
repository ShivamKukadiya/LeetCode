

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        queue<pair<int,int> > q;
        int n = ring.size(), m = key.size();
        int steps[n+1][m+1]; //number of steps required when ring's 12 o'clock is at i, and character to be matched in key is j
        memset(steps,-1,sizeof(steps));

        q.push({0,0});
        steps[0][0]=0;
        while(!q.empty())
        {
            auto state = q.front();
            q.pop();
            if(state.second==m)
            {
                return steps[state.first][state.second];
            }

            if(state.second<m && ring[state.first]!=key[state.second])
            {
                auto nextState1 = make_pair((state.first+1)%n,state.second);
                auto nextState2 = make_pair((state.first-1+n)%n,state.second);

                if(steps[nextState1.first][nextState1.second]==-1)
                {
                    steps[nextState1.first][nextState1.second]=steps[state.first][state.second]+1;
                     q.push(nextState1);
                }

                if(steps[nextState2.first][nextState2.second]==-1)
                {
                    steps[nextState2.first][nextState2.second]=steps[state.first][state.second]+1;
                    q.push(nextState2);
                }
            }
            else
            {
                auto nextState = make_pair(state.first,state.second+1);
                if(steps[nextState.first][nextState.second]==-1)
                {
                    steps[nextState.first][nextState.second]=steps[state.first][state.second]+1;
                    q.push(nextState);
                }
            }
        }  
        return 0;
    }
};