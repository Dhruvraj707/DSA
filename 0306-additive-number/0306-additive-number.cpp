class Solution {
public:

    // Add two numbers represented as strings
    string addStrings(string a, string b) {
        string ans = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0)
                sum += a[i--] - '0';

            if (j >= 0)
                sum += b[j--] - '0';

            ans += char((sum % 10) + '0');
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool check(string num, int start, string first, string second) {
        int n = num.size();

        string sum = addStrings(first, second);

        // Sum must fit inside remaining string
        if (start + sum.size() > n)
            return false;

        // Next number must exactly match sum
        if (num.substr(start, sum.size()) != sum)
            return false;

        // If we reached the end, we have a valid sequence
        if (start + sum.size() == n)
            return true;

        return check(
            num,
            start + sum.size(),
            second,
            sum
        );
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();

        // Choose the first number
        for (int len1 = 1; len1 <= n - 2; len1++) {

            // First number cannot have leading zero
            if (num[0] == '0' && len1 > 1)
                break;

            string first = num.substr(0, len1);

            // Choose the second number
            for (int len2 = 1;
                 len1 + len2 <= n - 1;
                 len2++) {

                // Second number cannot have leading zero
                if (num[len1] == '0' && len2 > 1)
                    break;

                string second = num.substr(len1, len2);

                if (check(num, len1 + len2, first, second))
                    return true;
            }
        }

        return false;
    }
};