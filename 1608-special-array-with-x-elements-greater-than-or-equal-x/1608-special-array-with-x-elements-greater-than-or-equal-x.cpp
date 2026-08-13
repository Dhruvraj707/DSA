class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        

        for(int x = 1; x <= n; x++) {
            int count = 0;

            for(int j = 0; j < n; j++) {
                if(nums[j] >= x) {
                    count++;
                }
            }

            if(count == x) {
                return x;
            }
        }

        return -1;
    }
};
       