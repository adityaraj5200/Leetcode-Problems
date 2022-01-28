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
#else
#define debug(x...)
#define nline
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        queue<TreeNode*> q;
        q.push(root);
        string s;
        
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            
            if(node != NULL){
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
            else s += "n,";
        }
        // debug(s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0) return NULL;
        map<int,TreeNode*> hash;
        int i = 0, j = 0, n = data.length();
        while(i<n){
            int idx=i;
            if(data[i]=='n'){
                hash[i] = NULL;
                i += 2;
            }
            else{
                int num=0, sign=1;
                if(data[i]=='-'){
                    sign = -1;
                    i++;
                }
                while(i<n && data[i]!=',')
                    num = num*10 + (data[i++]-'0');
                i++;

                hash[idx] = new TreeNode(num * sign);
            }
        }
        
        // debugging
        // for(auto &p: hash){
        //     if(p.second != NULL){
        //         debug(p.first, p.second->val);
        //     }
        //     else{
        //         debug(p.first, "NULL");
        //     }
        // }
        
        i = j = 0;
        while(j<n && data[j]!=',')
            j++;
        j++;
        
        
        
        while(i<n && j<n){
            // debug(i,hash[i]->val);
            hash[i]->left = hash[j];
            while(j<n && data[j]!=',') 
                j++;
            j++;
            hash[i]->right = hash[j];
            while(j<n && data[j]!=',')
                j++;
            j++;
            
            while(i<n && data[i]!=',')
                i++;
            i++;
            while(i<n && !isdigit(data[i]) && data[i]!='-')
                i++;
        }
        
        return hash[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));