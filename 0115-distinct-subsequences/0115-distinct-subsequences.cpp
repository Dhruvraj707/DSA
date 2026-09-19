class Solution {
public:
    typedef unsigned long long ull;
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        vector<ull>curr(n+1, 0);
        vector<ull>prev(n+1, 0);

        curr[0] = 1;
        prev[0] = 1;


        for(int i=1; i<=m; i++) {
            for(int j =1; j<= n; j++) {
                if(s[i-1] == t[j-1]) {
                    curr[j] = prev[j-1] + prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;

        }
        return prev[n];
    }
};