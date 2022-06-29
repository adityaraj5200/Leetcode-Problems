class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(), [](vector<int> &p1, vector<int> &p2){
            // Greater height person will be at front in queue.
            // And if there is a tie in their height 
            // then guy with the smaller k value will be given preference.
            return p1[0]==p2[0] ? p1[1]<p2[1] : p1[0]>p2[0];
        });
        
        for(int i=0;i<people.size();i++){
            if(people[i][1] != i){
                int shifts = i-people[i][1];
                int tempi = i;
                while(shifts--){
                    swap(people[tempi],people[tempi-1]);
                    tempi--;                    
                }
            }
        }
        
        return people;
    }
};