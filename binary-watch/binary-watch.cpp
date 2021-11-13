class Solution {
public:
    vector<int> times = {1,2,4,8,16,32};
    int numLEDS(int num,bool isHour){
        int idx = isHour ? 4 : 6, cnt = 0;
        for(int i=idx-1;i>=0 && num>0;i--)
            if(times[i] <= num){   
                num -= times[i];
                cnt++;
            }
        return cnt;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int i=0;i<12;i++)
            for(int j=0;j<60;j++)
                if(numLEDS(i,true) + numLEDS(j,false) == turnedOn)
                    ans.push_back(to_string(i)+":"+(j<10?"0":"")+to_string(j));
        return ans;
    }
};