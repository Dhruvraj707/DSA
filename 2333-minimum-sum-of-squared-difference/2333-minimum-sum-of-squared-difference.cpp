
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<int> diff(nums1.size());
        int mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
        }

        long long total = 0;
        for (int d : diff) total += d;

        if (k >= total) return 0;

        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid) need += d - mid;
            }

            if (need <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int level = low;
        long long ans = 0;
        long long used = 0;

        for (int d : diff) {
            int remaining = min(d, level);
            ans += 1LL * remaining * remaining;
            used += d - remaining;
        }

        long long extra = k - used;

        // Reduce 'extra' differences from 'level' to 'level - 1'
        for (int d : diff) {
            if (extra == 0) break;
            if (d >= level && level > 0) {
                ans -= 2LL * level - 1;
                extra--;
            }
        }

        return ans;
    }
};
