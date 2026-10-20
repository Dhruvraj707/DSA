class Solution {
public:
    bool check(vector<int>& nums, int k) {
        int n = nums.size();
        int prevEnd = -1;

        for (int start = 0; start < n; start += k) {
            int drops = 0;
            int dropPos = -1;

            for (int i = 0; i < k; i++) {
                int curr = nums[start + i];
                int next = nums[start + (i + 1) % k];

                if (curr > next) {
                    drops++;
                    dropPos = i;

                    if (drops > 1)
                        return false;
                }
            }

            int first, last;

            if (drops == 0) {
                first = nums[start];
                last = nums[start + k - 1];
            } else {
                first = nums[start + (dropPos + 1) % k];
                last = nums[start + dropPos];
            }

            if (prevEnd != -1 && prevEnd > first)
                return false;

            prevEnd = last;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k == 0 && check(nums, k)) {
                ans += k;
            }
        }

        return ans;
    }
};

