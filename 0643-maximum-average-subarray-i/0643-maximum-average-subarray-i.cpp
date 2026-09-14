class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        long long windowsum = 0;
        for(int i = 0; i<k; i++) {
            windowsum += nums[i];    
        }

        long long maxsum = windowsum;

        for(int i=k; i<nums.size(); i++) {
            windowsum += nums[i];
            windowsum -= nums[i-k];
            
            maxsum = max(maxsum, windowsum);

        }
        return (double)maxsum/k;
        
    }
};