class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int result = 0;
        int oddfreq = 0;

        for(char &ch : s) {
            mp[ch]++;
            if(mp[ch] % 2 != 0) {
                oddfreq++;
            } else {
                oddfreq --;
            }
        }
        if(oddfreq > 0) {
            return n-oddfreq +1;
        }
        return n;


        
    }
};