class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> vec;

        int duplicate = -1;
        int missing = -1;

        for (int i = 0; i < n - 1; i++) {

           
            if (nums[i] == nums[i + 1]) {
                duplicate = nums[i];
            }

            
            if (nums[i + 1] - nums[i] > 1) {
                missing = nums[i] + 1;
            }
        }

       
        if (nums[0] != 1) {
            missing = 1;
        }

       
        if (nums[n - 1] != n) {
            missing = n;
        }

        vec.push_back(duplicate);
        vec.push_back(missing);

        return vec;
    }
};