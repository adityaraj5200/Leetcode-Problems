class Solution {
public:
    vector<int> circularPermutation(int n, int start){
        vector<int> result(1<<n);
        result[0] = 0;
        result[1] = 1;
        for(int i=1,j=i+1,bitpos=1;--n;i=j-1,bitpos++){
            while(i>=0)
                result[j++] = result[i--] | (1<<bitpos);
        }
        const auto start_it = find(result.begin(), result.end(), start);
        rotate(result.begin(), start_it, result.end());
        return result;
    }
};