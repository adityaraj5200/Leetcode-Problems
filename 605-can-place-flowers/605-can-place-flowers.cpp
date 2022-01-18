class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0)
            return true;
        int cnt = 1;
        flowerbed.push_back(0);
        for(int &val: flowerbed){
            if(val==0){
                cnt++;
                if(cnt == 3){
                    n--;
                    if(n==0)
                        return true;
                    cnt = 1;
                }
            }
            else cnt = 0;
        }
        return false;
    }
};