class Solution {
public:
    int hIndex(vector<int>& citation) {
        int n = citation.size();

        vector<int> bucket(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (citation[i] >= n)
                bucket[n]++;
            else
                bucket[citation[i]]++;
        }

        int count = 0;

        for (int i = n; i >= 0; i--) {
            count += bucket[i];

            if (count >= i)
                return i;
        }

        return 0;
    }
};