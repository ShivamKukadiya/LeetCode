class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int res = 2;
        if(a == e || b == f) {
            if(a == e) {
                if(a == c){    
                    int x = b > f ? -1 : 1;
                    int t = b;
                    while(t != f) {
                        if(t == d) break;
                        t += x;
                    }
                    if(t == f) return 1;
                }
                else return 1;
            }
            else {
                if(b == d) {
                    int x = a > e ? -1 : 1;
                    int t = a;
                    while(t != e) {
                        if(t == c) break;
                        t += x;
                    }
                    if(t == e) return 1;
                    
                }
                else return 1;
            }
        }
        if((c + d)%2 == (e + f)%2) {
            if(abs(c - e) == abs(d - f)) {
                int x = e > c ? 1 : -1;
                int y = f > d ? 1 : -1;
                while(c != e && d != f) {
                    if(c == a && d == b) break;
                    c += x;
                    d += y;
                }
                if(c == e && d == f) return 1;
            }
        }
        return 2;
    }
};