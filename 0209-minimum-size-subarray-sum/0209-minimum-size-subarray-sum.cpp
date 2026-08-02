class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int Sum = 0;
        int minL = INT_MAX;
        while(j<n) {
            Sum += nums[j];
            while(Sum >= target) {
                minL = min(minL, j - i+1);
                Sum -= nums[i];
                i++;
            }
            j++;
        }
        return minL == INT_MAX? 0 : minL;
    }
};