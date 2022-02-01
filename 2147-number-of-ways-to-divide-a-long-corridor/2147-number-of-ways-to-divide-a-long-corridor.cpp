class Solution {
public:
    int numberOfWays(string corridor) {
        // corridor += 'S';
        vector<long long> lengths;
        long long mod = 1e9+7, sofa=0, len=0;
        for(char &ch: corridor){
            if(ch == 'S'){
                sofa++;
            }
            
            if(sofa==3){
                sofa = 1;
                lengths.push_back(len);
                len = 0;
                
            }
            else if(sofa == 2){
                len++;
            }
        }
        
        if((sofa & 1) || sofa==0) return 0;
        
        long long ans = 1;
        for(long long &val: lengths){
            ans = (ans*val)%mod;
        }
        
        return (int)ans;
    }
};