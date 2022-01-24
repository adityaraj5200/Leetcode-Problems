class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> finalEmails;
        for(string &email: emails){
            int i=0,n=email.length();
            string truncatedEmail;
            for(;email[i]!='+' && email[i]!='@';i++){
                if(email[i]=='.') continue;
                truncatedEmail += email[i];
            }
            while(email[i] != '@')
                i++;
            truncatedEmail += '@';
            while(i<n)
                truncatedEmail += email[i++];
            
            finalEmails.insert(truncatedEmail);
        }
        return finalEmails.size();
    }
};