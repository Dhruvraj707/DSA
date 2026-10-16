
class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct SegmentTree {
        int n;
        vector<long long> sum, sq, lazy;

        SegmentTree(int n) : n(n) {
            sum.assign(4 * n, 0);
            sq.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
        }

        void apply(int node, int l, int r, long long v) {
            long long len = r - l + 1;

            sq[node] = (sq[node]
                + 2LL * v % MOD * sum[node] % MOD
                + len % MOD * v % MOD * v % MOD) % MOD;

            sum[node] = (sum[node] + len * v) % MOD;
            lazy[node] = (lazy[node] + v) % MOD;
        }

        void push(int node, int l, int r) {
            if (lazy[node] == 0 || l == r) return;

            int mid = (l + r) / 2;

            apply(node * 2, l, mid, lazy[node]);
            apply(node * 2 + 1, mid + 1, r, lazy[node]);

            lazy[node] = 0;
        }

        void update(int node, int l, int r,
                    int ql, int qr, long long v) {
            if (ql > r || qr < l) return;

            if (ql <= l && r <= qr) {
                apply(node, l, r, v);
                return;
            }

            push(node, l, r);

            int mid = (l + r) / 2;

            update(node * 2, l, mid, ql, qr, v);
            update(node * 2 + 1, mid + 1, r, ql, qr, v);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        }

        void update(int l, int r, long long v) {
            if (l <= r)
                update(1, 0, n - 1, l, r, v);
        }

        long long getSquareSum() {
            return sq[1];
        }
    };

    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        SegmentTree st(n);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            st.update(last[x] + 1, i, 1);
            last[x] = i;

            ans = (ans + st.getSquareSum()) % MOD;
        }

        return ans;
    }
};
