class Solution {
public:
    vector<int> circularPermutation(int n, int start){
        vector<int> result(1<<n);
        result[0] = 0;
        result[1] = 1;
        int bitpos = 1, i = 1, j ;
        while(--n){
            j = i+1;
            while(i>=0)
                result[j++] = result[i--] | (1<<bitpos);
            bitpos++;
            i = j-1;
        }
        const auto start_it = find(result.begin(), result.end(), start);
        rotate(result.begin(), start_it, result.end());
        return result;
    }
};