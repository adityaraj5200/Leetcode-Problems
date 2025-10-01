class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int emptyBottles = numBottles;
        while(emptyBottles>=numExchange){
            int fullBottles = emptyBottles/numExchange;
            int rest = emptyBottles % numExchange;

            ans += fullBottles;
            emptyBottles = fullBottles + rest;
        }

        return ans;
    }
};