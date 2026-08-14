class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int start = 0;
        int end = 0;
        map<char, int> charfrequency;
        int maxLength = 0;
        while(end < n) {
            charfrequency[s[end]]++;
            while(charfrequency[s[end]] > 2) {
                charfrequency[s[start]]--;
                start++;
            }
            maxLength = max(maxLength, end - start +1);
            end++;
        }
        return maxLength;
        
    }
};