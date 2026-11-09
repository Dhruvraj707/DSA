
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        set<int> available;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {finishTime, serverId}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            // Release servers that have completed their requests
            while (!busy.empty() &&
                   busy.top().first <= arrival[i]) {

                int server = busy.top().second;

                available.insert(server);
                busy.pop();
            }

            // If all servers are busy, drop the request
            if (available.empty()) {
                continue;
            }

            // Preferred server
            int target = i % k;

            // Find first available server >= target
            auto it = available.lower_bound(target);

            // Wrap around if necessary
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Assign request
            available.erase(it);

            count[server]++;

            // Calculate finishing time
            long long finishTime =
                (long long)arrival[i] + load[i];

            busy.push({finishTime, server});
        }

        // Find maximum number of requests
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
