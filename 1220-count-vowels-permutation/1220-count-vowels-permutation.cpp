class Solution {
    const int mod=1e9+7;
public:
    int recur(unordered_map<char,vector<char>> &adj,int n,int i,char src,vector<vector<int>> &dp){
        if(i==n){  //base condition when our string of length n has been formed
            return 1; //simply return 1 denoting 1 string has been formed
        }
        if(dp[i][src-'a']!=-1)return dp[i][src-'a']; //using value that has been calculated before
        long int temp=0;
        for(auto nbr : adj[src]){  //using char that we are present in adjMap of curr src char
            temp=((temp%mod) + (recur(adj,n,i+1,nbr,dp)%mod))%mod;
        }
        return dp[i][src-'a']=temp; //returning ans for string of length i with last char as src
    }
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n+1,vector<int>(26,-1)); //26 size because alphabets can from 0-25.
        unordered_map<char,vector<char>> adj;   //creating the Adjacency map
        adj['a'].push_back('e'); adj['e'].push_back('a');  
        adj['e'].push_back('i'); adj['i'].push_back('a');
        adj['i'].push_back('e'); adj['i'].push_back('o');  //adj['i']=>{a,e,o,u}
        adj['i'].push_back('u'); adj['o'].push_back('i');
        adj['o'].push_back('u'); adj['u'].push_back('a');
        long int ans=0;
        for(auto it : adj){
			// using every vowel as the start for the current sequence
            ans=(ans%mod + (recur(adj,n,1,it.first,dp)%mod))%mod;
        }
        return ans;
    }
};