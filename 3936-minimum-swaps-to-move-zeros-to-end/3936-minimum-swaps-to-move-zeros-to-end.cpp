class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int c = 0;
        while (i <= j) {
            if (nums[j] == 0) {
                j--;
            } else if (nums[i] == 0) {
                c++;
                i++;
                j--;
            } else {
                i++;
            }
        }
        return c;
    }
};