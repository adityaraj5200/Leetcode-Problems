class Solution {
public:
    int smallestNumber(int n) {
        bool sawHighestBit = false;
        int x = n;
        for(int i=10;i>=0;i--){
            if(n&(1<<i)){
                sawHighestBit = true;
            }

            if(sawHighestBit){
                x |= (1<<i);
            }
        }

        return x;
    }
};