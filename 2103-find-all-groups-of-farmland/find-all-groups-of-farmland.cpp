

      
   class Solution {

public:

    vector<vector<int>> findFarmland(vector<vector<int>>& l) {

        vector<vector<int>> res;

        int n = l.size();

        int m = l[0].size();

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(i == 0 || j == 0) {

                    if(l[i][j] == 1) {

                        if((i != 0 && l[i-1][j] == 1) || (j != 0 && l[i][j-1] == 1)) continue;

                        int ii = i, jj = j;

                        while(jj < m && l[ii][jj] == 1) {

                            jj++;

                            if(jj >= m || l[ii][jj] != 1) {

                                jj--;

                                break;

                            }

                        }

                        while(ii < n && l[ii][jj] == 1) {

                            ii++;

                            if(ii >= n || l[ii][jj] != 1) {

                                ii--;

                                break;

                            }

                        }

                        res.push_back({i,j,ii,jj});

                    }

                }

                else {

                    if(l[i][j] == 1) {

                        if((l[i-1][j] == 1) || (l[i][j-1] == 1)) continue;

                        int ii = i, jj = j;

                        while(jj < m && l[ii][jj] == 1) {

                            jj++;

                            if(jj >= m || l[ii][jj] != 1) {

                                jj--;

                                break;

                            }

                        }

                        while(ii < n && l[ii][jj] == 1) {

                            ii++;

                            if(ii >= n || l[ii][jj] != 1) {

                                ii--;

                                break;

                            }

                        }

                        res.push_back({i,j,ii,jj});

                    }

                }

            }

        }

        return res;

    }

};
