class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int res = students.size();
        int squ = 0, cir = 0;
        for (int i = 0; i < students.size(); i++) {
            if (students[i] == 0) {
                cir++;
            } else {
                squ++;
            }
        }
        for (int i = 0; i < sandwiches.size(); i++) {
            if (sandwiches[i] == 0) {
                if (cir > 0) {
                    res--;
                    cir--;
                } else {
                    return res;
                }
            } else {

                if (squ > 0) {
                    res--;
                    squ--;
                } else {
                    return res;
                }
            }
        }
        return res;
    }
};