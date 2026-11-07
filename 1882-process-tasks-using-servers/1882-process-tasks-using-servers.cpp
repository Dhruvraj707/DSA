
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // {weight, index}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> available;

        // {freeTime, weight, index}
        using T = tuple<long long, int, int>;

        priority_queue<T, vector<T>, greater<T>> busy;

        int n = servers.size();
        int m = tasks.size();

        vector<int> ans(m);

        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        long long time = 0;

        for (int j = 0; j < m; j++) {

            // Move time forward, but never move backward
            time = max(time, (long long)j);

            // Release all servers available by current time
            while (!busy.empty() &&
                   get<0>(busy.top()) <= time) {

                auto [freeTime, weight, index] = busy.top();
                busy.pop();

                available.push({weight, index});
            }

            // If no server is available, jump to earliest free time
            if (available.empty()) {
                time = get<0>(busy.top());

                // Release all servers becoming free simultaneously
                while (!busy.empty() &&
                       get<0>(busy.top()) <= time) {

                    auto [freeTime, weight, index] = busy.top();
                    busy.pop();

                    available.push({weight, index});
                }
            }

            // Select server with minimum weight, then index
            auto [weight, index] = available.top();
            available.pop();

            ans[j] = index;

            // Update server's next available time
            busy.push({
                time + tasks[j],
                weight,
                index
            });
        }

        return ans;
    }
};
