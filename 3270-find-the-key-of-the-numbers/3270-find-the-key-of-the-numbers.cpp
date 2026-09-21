class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string ans = "";
        while(num1 || num2>0 || num3>0) {
            int dig1 = num1 % 10;
            int dig2 = num2 % 10;
            int dig3 = num3 % 10;
            int mini = min(dig1, min(dig2, dig3));
            ans= to_string(mini) + ans;
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;

        }
        return stoi(ans);

        
    }
};