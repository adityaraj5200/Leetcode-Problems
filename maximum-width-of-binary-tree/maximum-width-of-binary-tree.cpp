/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '"' << x << '"';}
void __print(const string &x) {cout << '"' << x << '"';}
void __print(bool x) {cout << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#define nline cout<<endl
#define tcends cout<<"-------------------This testcase ends here-------------------\n\n"
#else
#define debug(x...)
#endif


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,long long int>> q;
        q.push({root,1});
        int ans = 0;
        while(!q.empty()){
            int maxwidth = INT_MIN, minwidth = INT_MAX, n = q.size();
            int toSubtract = q.front().second*2-1;
            while(n--){
                TreeNode* node = q.front().first;
                int currwidth = q.front().second;
                q.pop();
                // debug(currwidth,toSubtract);
                maxwidth = max(maxwidth,currwidth);
                minwidth = min(minwidth,currwidth);
                if(node->left) q.push({node->left,currwidth*2-1 - toSubtract});
                if(node->right) q.push({node->right,currwidth*2 - toSubtract});
            }
            // nline;
            ans = max(ans,maxwidth-minwidth+1);
        }
        // tcends;
        return ans;
    }
};

// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         if (!root) return 0;
//         int max = 0;
//         queue<pair<TreeNode*, int>> q;
//         q.push(pair<TreeNode*, int>(root, 1));
//         while (!q.empty()) {
//             int l = q.front().second, r = l; // right started same as left
//             for (int i = 0, n = q.size(); i < n; i++) {
//                 TreeNode* node = q.front().first;
//                 r = q.front().second;
//                 q.pop();
                
//                 if (node->left) q.push(pair<TreeNode*, int>(node->left, r * 2));
//                 if (node->right) q.push(pair<TreeNode*, int>(node->right, r * 2 + 1));
//             }
//             max = std::max(max, r + 1 - l);
//         }
//         return max;
//     }
// };

// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) 
//     {
//         if(root==NULL)
//             return 0;
        
//         queue <pair<TreeNode*,int>> q;
//         q.push({root,0});
//         int ans=0,f=0,l=0;
//         int c=0;
//         while(q.size())
//         {
//             int n=q.size();
//             c=q.front().second;
//             for(int i=0;i<n;i++)
//             {
//                 auto it=q.front();
//                 if(i==0) 
//                     f=it.second;
//                 if(i==n-1)
//                     l=it.second;
                
//                 int k=it.second-c;
//                 if(it.first->left!=NULL)
//                     q.push({it.first->left,2*k+1});
//                 if(it.first->right!=NULL)
//                     q.push({it.first->right,2*k+2});
//                 q.pop();
//             }
//             ans=max(ans,l-f+1);
//         }
        
//         return ans;
//     }
// };