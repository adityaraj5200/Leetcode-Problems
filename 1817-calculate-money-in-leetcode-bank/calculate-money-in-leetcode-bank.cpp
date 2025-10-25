class Solution {
public:
    int totalMoney(int n) {
        int money = 0, moneyPutLastDay = 0, moneyPutLastMonday = 0;
        for(int i=0;i<n;i++){
            if(i%7 == 0){
                // monday
                moneyPutLastDay = moneyPutLastMonday;
                moneyPutLastMonday = moneyPutLastDay+1;
            }
            money += moneyPutLastDay+1;
            moneyPutLastDay++;
        }

        return money;
    }
};