class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> vec;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                vec.push_back(nums[i]);
                i++; 
            }
        }

        return vec;
    }
};