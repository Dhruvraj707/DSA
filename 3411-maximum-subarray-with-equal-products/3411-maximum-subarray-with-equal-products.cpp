class Solution {
public:
    int maxLength(vector<int>& nums) {
        //            0  1  2  3  4  5  6  7  8  9  10
        int mask[11] = {0, 0, 1, 2, 1, 4, 3, 8, 1, 2, 5};   // bit0=2, bit1=3, bit2=5, bit3=7

        int n = nums.size();
        int used = 0, l = 0;
        int ans = 2;   // any subarray of length 1 or 2 is always valid

        for (int r = 0; r < n; r++) {
            while (used & mask[nums[r]]) {
                used ^= mask[nums[l]];
                l++;
            }
            used |= mask[nums[r]];
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};