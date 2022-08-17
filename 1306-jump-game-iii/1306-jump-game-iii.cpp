class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        const int n = arr.size();
        
        vector<bool> visited(n,false);
        
        queue<int> q;
        q.push(start);
        visited[start] = true;
        
        while(!q.empty()){
            int idx = q.front();
            q.pop();
            
            if(arr[idx] == 0)
                return true;
            
            int front = idx + arr[idx];
            int back = idx - arr[idx];
            
            if(front<n && visited[front]==false){
                visited[front] = true;
                q.push(front);
            }
            if(back>=0 && visited[back]==false){
                visited[back] = true;
                q.push(back);
            }
        }
        
        return false;
    }
};