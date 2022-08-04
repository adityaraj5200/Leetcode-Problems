class Solution {
public:
    int mirrorReflection(int p, int q) {
//         int temp_q;
        
//         temp_q = q;
//         while(temp_q <= p/2){
//             if(temp_q == p/2) 
//                 return 2;
//             temp_q *= 2;
//         }
        
//         temp_q = q;
//         while(temp_q <= p/3){
//             if(temp_q == p/3) 
//                 return 3;
//             temp_q *= 3;
//         }
        
//         temp_q = q;
//         while(temp_q <= (2*p)/3){
//             if(temp_q == (2*p)/3) 
//                 return 0;
//             temp_q *= 3;
//         }
        
//         return -1;
        int i=1;
        while(1)
        {
            if((i*q)%p==0)
            {
                if(i%2==0)
                    return 2;
                else
                {
                    if(((i*q)/p)%2==0)
                        return 0;
                    else
                        return 1;
                }
            }
            i++;
        }
        return 1;
    }
};