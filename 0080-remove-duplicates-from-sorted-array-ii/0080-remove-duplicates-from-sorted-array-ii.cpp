class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int n = nums.size();

        while (r < n) {
            int count = 1;

            while (r + 1 < n && nums[r] == nums[r + 1]) {
                r++;
                count++;
            }

            int cnum = min(2, count);

            for (int i = 0; i < cnum; i++) {
                nums[l] = nums[r];
                l++;
            }

            r++;
        }

        return l;
    }
};