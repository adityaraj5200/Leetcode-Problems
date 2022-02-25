class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0, j=0, n=version1.length(), m=version2.length();
        while(i<n || j<m){
            int v1=0, v2=0;
            
            while(i<n && version1[i]!='.')
                v1 = (v1*10) + (version1[i++]-'0');
            
            while(j<m && version2[j]!='.')
                v2 = (v2*10) + (version2[j++]-'0');
            
            i++,j++;
            
            if(v1 != v2)
                return v1>v2 ? 1 : -1;
        }
        
        return 0;
    }
};