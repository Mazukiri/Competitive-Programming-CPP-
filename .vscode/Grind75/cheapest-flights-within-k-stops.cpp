class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            const int INF = 1e9; // Large value for unreachable nodes
            vector<vector<pair<int, int>>> adj(n); // Adjacency list {cost, destination}
            vector<vector<int>> f(n, vector<int>(k + 2, INF)); // f[node][stops] = min cost to reach node
            
            // Construct graph
            for (auto& flight : flights) {
                int u = flight[0], v = flight[1], cost = flight[2];
                adj[u].push_back({cost, v});
            }
    
            // Min-heap priority queue (cost, node, stops)
            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
            pq.push({0, src, 0});
            f[src][0] = 0;
    
            while (!pq.empty()) {
                auto [cost, u, stops] = pq.top();
                pq.pop();
    
                if (u == dst) return cost; // If we reach destination, return the cost
                
                if (stops > k) continue; // If we exceed k stops, skip
    
                for (auto [price, v] : adj[u]) {
                    if (cost + price < f[v][stops + 1]) {
                        f[v][stops + 1] = cost + price;
                        pq.push({f[v][stops + 1], v, stops + 1});
                    }
                }
            }
    
            return -1; // If no valid route found
        }
    };  