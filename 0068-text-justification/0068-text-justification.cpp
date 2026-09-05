class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int wordsLength = 0;

            
            while (j < n &&
                   wordsLength + words[j].length() + (j - i) <= maxWidth) {
                wordsLength += words[j].length();
                j++;
            }

            int numberOfWords = j - i;
            int spaces = maxWidth - wordsLength;
            string line;

            
            if (j == n || numberOfWords == 1) {
                for (int k = i; k < j; k++) {
                    if (k > i)
                        line += " ";

                    line += words[k];
                }

                
                line += string(maxWidth - line.length(), ' ');
            }
            else {
                int gaps = numberOfWords - 1;

                
                int spacesPerGap = spaces / gaps;

                
                int extraSpaces = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        int currentSpaces = spacesPerGap;

                        if (k - i < extraSpaces)
                            currentSpaces++;

                        line += string(currentSpaces, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};