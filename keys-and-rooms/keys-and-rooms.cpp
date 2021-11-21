class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms){
        int n = rooms.size(),keysLeft = n-1;
        vector<bool> foundkey(n,false);
        foundkey[0] = true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int room_no = q.front();
            q.pop();
            for(int &keys: rooms[room_no]){
                if(!foundkey[keys]){
                    foundkey[keys] = true;
                    q.push(keys);
                    keysLeft--;
                }
            }
        }
        return keysLeft==0;
    }
};