class Solution {
public:
    int solve(vector<int>& nums,int target, int i, int currsum) {
        if(i == nums.size()) {
            if(currsum == target) {
                return 1;
            } else{
                return 0;
            }
        }
        int plus = solve(nums, target, i+1, currsum + nums[i]);
        int minus = solve(nums, target, i+1, currsum - nums[i]);

        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, 0);
        
    }
};