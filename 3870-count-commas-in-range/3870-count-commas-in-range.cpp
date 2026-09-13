#define ll long long
class Solution {
public:
    int countCommas(int n) {
        ll result = 0;
        ll start = 1000;
        while(start <= n) {
            result += (n - start + 1);
            start *= 1000;
        }
        return result;
        
        
    }
};