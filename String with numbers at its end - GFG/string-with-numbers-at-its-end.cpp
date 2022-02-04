// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int isSame(string s){
	    int str_len = 0, given_len = 0;
	    for(char &ch: s){
	        if(!isdigit(ch)) str_len++;
	        else given_len = given_len*10 + (ch-'0');
	    }
	    return str_len==given_len;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isSame(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends