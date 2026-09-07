class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> vec;

        int duplicate = 1;
        int unique = 1;

        for (int i = 0; i < n - 1; i++) {

           
            if (nums[i] == nums[i + 1]) {
                duplicate = nums[i];
            }

            
            if (nums[i + 1] - nums[i] > 1) {
                unique = nums[i] + 1;
            }
        }

       
        if (nums[0] != 1) {
            unique = 1;
        }

       
        if (nums[n - 1] != n) {
            unique = n;
        }

        vec.push_back(duplicate);
        vec.push_back(unique);

        return vec;
    }
};