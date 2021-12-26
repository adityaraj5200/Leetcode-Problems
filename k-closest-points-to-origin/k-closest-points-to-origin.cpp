class Solution {
public:
    #define sq(x) (x)*(x)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto dist = [&](vector<int> &vec){
            return sq(vec[0]) + sq(vec[1]);
        };
        
        sort(points.begin(),points.end(),[&](vector<int> &lhs, vector<int> &rhs){
            return dist(lhs) < dist(rhs);
        });
        
        return vector<vector<int>>(points.begin(),points.begin()+k);
    }
};