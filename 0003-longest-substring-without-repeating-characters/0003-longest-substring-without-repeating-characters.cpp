class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> seen;
        int left = 0, maxlen = 0;
        for(int right = 0; right<n; right++){
            while(seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;

       
        

        
    }
};