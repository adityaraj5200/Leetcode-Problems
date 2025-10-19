// Time Complexity: O(10 * n * n)
//  - At most 10 additions (since digits cycle every 10 times) * n rotations * O(n) string operations
// Space Complexity: O(10 * n)
//  - For storing visited states and strings of length n

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string ans = s;
        int n = s.size();
        unordered_set<string> seen;
        queue<string> q;
        seen.insert(s);
        q.push(s);
        
        while(!q.empty()) {
            string cur = q.front();
            q.pop();
            
            if(cur < ans) ans = cur;
            
            // Operation 1: Add 'a' to digits at odd indices
            string s1 = cur;
            for(int i=1;i<n;i+=2){
                int digit = s1[i]-'0';
                digit = (digit + a) % 10;
                s1[i] = char('0' + digit);
            }
            if(!seen.count(s1)){
                seen.insert(s1);
                q.push(s1);
            }

            // Operation 2: Rotate right by 'b'
            string s2 = cur.substr(n-b) + cur.substr(0,n-b);
            if(!seen.count(s2)){
                seen.insert(s2);
                q.push(s2);
            }
        }
        return ans;
    }
};
