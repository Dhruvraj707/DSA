class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int totalkamai = accumulate(begin(gas), end(gas), 0);
        int totalkharch = accumulate(begin(cost), end(cost),0);

        if(totalkamai < totalkharch)
            return -1;

        int result_Index = 0;
        int total = 0;

        for(int i = 0; i<n; i++) {
            total += gas[i] - cost[i];

            if(total < 0) {
                result_Index = i + 1;
                total = 0;
            }
        }
        return result_Index;    
        
    }
};