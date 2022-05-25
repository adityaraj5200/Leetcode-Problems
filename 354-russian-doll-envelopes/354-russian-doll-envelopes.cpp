class Solution {
public:
    static bool comp(vector<int> &a ,vector<int> &b){
        if(a[0]!=b[0])return a[0]<b[0];
        return a[1]>b[1];
    }
    int maxEnvelopes(vector<vector<int>>& en) {
        //see LIS(question no 300 binay search method,*lower_bound for x , gives >=x wala index)
        //(1,3), (3,5), (6,8), (6,7), (8,4), (9,5) after sorting,a[0] inc and a[1] in decreasing
        // now use LIS for 2nd terms i.e(3,5,8,7,4,5)
        sort(en.begin(),en.end(),comp);
        vector<int> sub;
        for(auto it:en){
            if(sub.empty() || sub[sub.size()-1]<it[1]){
                sub.push_back(it[1]);
            }
            else{
                auto x=lower_bound(sub.begin(),sub.end(),it[1]);
                *x=it[1];
            }
        }
        return sub.size();
    }
};