class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int singledigitSum = 0;
        int doubledigitSum = 0;
        for(int i = 0; i<n; i++) {
            if(nums[i] < 10) {
                singledigitSum+= nums[i];
            }else{
                doubledigitSum+=nums[i];

            }

        }
        return singledigitSum!= doubledigitSum;
        
    }
};