class Solution {
public:

    // BFS to find shortest distance from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> distance(n, -1); // distance from src to each node
        queue<pair<int, int>> q;     // pair: (node, distance)

        q.push({src, 0});
        distance[src] = 0; // Mark src as visited with distance 0

        while (!q.empty()) {
            int v = q.front().first;
            int d = q.front().second;
            q.pop();

            for (auto it : adj[v]) {
                if (distance[it] == -1) {
                    distance[it] = d + 1;
                    q.push({it, d + 1});
                }
            }
        }

        return distance;
    }

    int ladderLength(string bw, string ew, vector<string>& wl) {
        bool present = false;
        int pos = -1; // Index of endWord in word list

        // Check if endWord is in the word list
        for (int i = 0; i < wl.size(); i++) {
            if (wl[i] == ew) {
                present = true;
                pos = i;
                break;
            }
        }

        if (!present) return 0; // If endWord not present, return 0

        int nofWords = wl.size() + 1; // Total nodes = word list + beginWord
        vector<vector<int>> adj(nofWords); // Graph adjacency list

        // Build the graph
        for (int i = 0; i < nofWords; i++) {
            string word = (i == 0) ? bw : wl[i - 1]; // 0 -> beginWord, others from wordList

            for (int j = 0; j < wl.size(); j++) {
                int diff = 0;

                // Count number of differing characters
                for (int k = 0; k < wl[j].size(); k++) {
                    if (wl[j][k] != word[k]) {
                        diff++;
                        if (diff > 1) break; // Stop if more than 1 difference
                    }
                }

                // If words differ by exactly 1 character, connect them
                if (diff == 1) {
                    int u = i;
                    int v = j + 1; // wordList index shifted by +1

                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }

        // Perform BFS from beginWord (node 0)
        vector<int> distance = shortestPath(adj, 0);

        int length = distance[pos + 1]; // Index of endWord = pos + 1
        return (length == -1 ? 0 : length + 1); // +1 for including beginWord
    }
};