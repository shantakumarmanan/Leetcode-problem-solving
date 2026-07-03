class Solution {
public:
    void buildGraph(TreeNode* root, unordered_map<int, vector<int>>& adj) {
        if (!root) return;
        if (root->left) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            buildGraph(root->left, adj);
        }
        if (root->right) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            buildGraph(root->right, adj);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        buildGraph(root, adj);
        queue<int> q;
        unordered_set<int> vis;
        q.push(start);
        vis.insert(start);
        int time = -1;
        while (!q.empty()) {
            int sz = q.size();
            time++;
            while (sz--) {
                int node = q.front();
                q.pop();
                for (int nei : adj[node]) {
                    if (!vis.count(nei)) {
                        vis.insert(nei);
                        q.push(nei);
                    }
                }
            }
        }
        return time;
    }
};