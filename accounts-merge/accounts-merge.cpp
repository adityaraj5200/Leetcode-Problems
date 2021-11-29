class Solution {
public:
    //function to check if two vectors share a common e-mail
    bool haveCommon(vector<string> &a,vector<string> &b)
    {
	//if their names are not same, they cann't be merged
        if(a[0] != b[0]) return false;
        for(auto &ele : b)
        {
			//excluding the check for name
            if(ele == b[0]) continue;
            for(auto &cand : a) 
            {
			// if we found a common mail, return true
                if(cand == ele) return true;
            }
        }
        
        return false;
    }
    
	// just normal DFS
    void dfs(vector<int> adj[],int node,vector<int> &con,bool *vis)
    {
        vis[node] = 1;
        con.push_back(node);
        for(auto &child : adj[node])
        {
            if(!vis[child]) dfs(adj,child,con,vis);
        }
    }
    
	//function to merge all the elements of connected components
	//and append the merged vector to our result
    void merge(vector<int> &con,vector<vector<string>> &res,vector<vector<string>> &acc)
    {
        vector<string> arr(1);
		//pushing the name
        arr[0] = acc[con[0]][0];
		
		//here we use a set as we want all the merged mails to be unique and in sorted order
        set<string> st;
		
		//put all the elements of the connected component's indices in the set
        for(auto &idx : con)
        {
			//we skipped 0 as we have already added the name in out arr vector before 
            for(int i=1;i<acc[idx].size();i++)
                st.insert(acc[idx][i]);
        }
        
		//put all the elements of set in arr
        for(auto &ele : st) arr.push_back(ele);
		
		//push arr in res 
        res.push_back(arr);
    }
	
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
	//initialize an adjacency list with indices as vertices
        vector<int> adj[accounts.size()];
        
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=i+1;j<accounts.size();j++)
            {
			//here we check if accounts[i] can be merged with accounts[j]
                bool check = haveCommon(accounts[i],accounts[j]);
				
				//if it is we'll add a bi-directional edge
                if(check) 
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
		//vector to store our ans and visited array
        vector<vector<string>> res;
        bool vis[accounts.size()];
        memset(vis,false,sizeof(vis));
		
        // int cnt = 0;
		
		//we'll traverse using dfs and find connected components
		//in order to merge them
        for(int i=0;i<accounts.size();i++)
        {
		//vector to store all the indices of connected components
		// i.e., components which can be merged
            vector<int> con;
            if(!vis[i])
            {
			//do dfs to find all the connected components
                dfs(adj,i,con,vis);
                merge(con,res,accounts);
            }
        }
        
        
        //returning the ans
        return res;
    }
};