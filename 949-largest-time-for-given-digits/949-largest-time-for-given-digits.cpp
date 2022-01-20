class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        auto isValidTime = [&](vector<int> &arr) -> bool{
            return !( (arr[0]>2) || (arr[0]==2 && arr[1] >= 4) || (arr[2]>=6) );
        };
        
        sort(arr.begin(),arr.end(),greater<int>());
        
        string s;
        do{
            if(isValidTime(arr)){
                for(int &val: arr)
                    s.push_back(val+'0');
                s.insert(2, ":");
                return s;
            }
                
        }while(prev_permutation(arr.begin(),arr.end()));
        
        return s;
    }
};