class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int col = temp.second.first;
            int row = temp.second.second;
            mp[col][row].insert(node->val);
            if(node->left)
                q.push({node->left, {col-1, row+1}});
            if(node->right)
                q.push({node->right, {col+1, row+1}});
        }
        vector<vector<int>> ans;
        for(auto &col : mp){
            vector<int> vertical;
            for(auto &row : col.second){
                vertical.insert(vertical.end(),
                                row.second.begin(),
                                row.second.end());
            }
            ans.push_back(vertical);
        }
        return ans;
    }
};