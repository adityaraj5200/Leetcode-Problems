class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = fruits.size();
        for(int i=0,placed=0;i<fruits.size();i++){
            for(int j=0;j<baskets.size();j++){
                if(baskets[j]>=fruits[i]){
                    baskets[j] = -1;
                    unplaced--;
                    break;
                }
            }
        }

        return unplaced;
    }
};