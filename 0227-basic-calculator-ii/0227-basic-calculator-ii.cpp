class Solution {
public:

    bool isDigital(char c) {
        return c >= '0' && c <= '9';
    }

    int calculate(string s) {

        stack<int> skt;

        int n = s.size();
        int res = 0;
        int i = 0;

        char Op = '+';

        while (i < n) {

           
            if (s[i] == ' ') {
                i++;
                continue;
            }

            
            int num = 0;

            while (i < n && isDigital(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }

            
            if (Op == '+') {
                skt.push(num);
            }
            else if (Op == '-') {
                skt.push(-num);
            }
            else if (Op == '*') {
                int num1 = skt.top();
                skt.pop();

                skt.push(num1 * num);
            }
            else if (Op == '/') {
                int num1 = skt.top();
                skt.pop();

                skt.push(num1 / num);
            }

            
            while (i < n && s[i] == ' ') {
                i++;
            }

           
            if (i < n) {
                Op = s[i];
                i++;
            }
        }

        
        while (!skt.empty()) {
            res += skt.top();
            skt.pop();
        }

        return res;
    }
};