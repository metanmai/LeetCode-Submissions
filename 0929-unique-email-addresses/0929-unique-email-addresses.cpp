class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> allEmails;
        
        for(auto email : emails)
        {
            int i = 0; 
            string currEmail = "";
            
            while(email[i] != '@')
            {
                if(email[i] == '.')
                {
                    i++;
                    continue;
                }
                
                else if(email[i] == '+')
                    while(email[i] != '@')
                        i++;
                
                else
                {
                    currEmail.push_back(email[i]);
                    i++;
                }
            }
            
            currEmail += email.substr(i, email.length() - i);
            allEmails.insert(currEmail);
        }
        
        return allEmails.size();
    }
};