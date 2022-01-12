// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	string FirstNonRepeating(string A){
	    // Code here
	    string result;
	    deque<char> dq;
	    vector<int> freq(26,0);
	    for(char &ch: A){
	        freq[ch-'a']++;
	        dq.push_back(ch);
	        while((!dq.empty()) && freq[dq.front()-'a']>1){
	            dq.pop_front();
	        }
	        
	        result.push_back(dq.empty() ? '#' : dq.front());
	    }
	    return result;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends