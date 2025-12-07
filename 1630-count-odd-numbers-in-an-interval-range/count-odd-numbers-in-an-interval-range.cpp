class Solution {
public:
    int countOdds(int low, int high) {
        if(low&1) low--; // even
        if(high%2==0) high--; // odd

        return (high-low+1)/2;
    }
};