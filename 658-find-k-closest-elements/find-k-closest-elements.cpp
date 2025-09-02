class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(),arr.end(),[&](int &a,int &b){
            return abs(a-x)==abs(b-x) ? a<b : abs(a-x)<abs(b-x);
        });
        
        arr.resize(k);
        
        sort(arr.begin(),arr.end());
        
        return arr;
    }
};