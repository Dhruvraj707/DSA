class Solution {
public:
    char repeatedCharacter(string s) {
        set<char> st;

        for (char c : s) {
            if (st.count(c)) {
                return c;
            }

            st.insert(c);
        }

        return '\0';
    }
};