
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long both = min(need1, need2);
        
        // Buy type 3 for the common requirement
        long long costA = both * costBoth
                       + (need1 - both) * cost1
                       + (need2 - both) * cost2;

        // Buy only type 1 and type 2
        long long costB = 1LL * need1 * cost1
                        + 1LL * need2 * cost2;

        // Buy type 3 items for the maximum requirement
        long long costC = 1LL * max(need1, need2) * costBoth;

        return min({costA, costB, costC});
    }
};
