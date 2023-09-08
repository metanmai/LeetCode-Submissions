// Suffix characters solution.

class Solution {
private:
    int findMaxConfusion(string &answerKey, int k, vector<int> &right, char ch, int n)
    {
        int maxConfusion = 0, i = 0, flips = 0, left = 0, curr = 0;
        
        for(int j = 0; j < n; j++)
        {
            if(answerKey[j] == ch)
                curr++;
            
            else if(flips < k)
                curr++, flips++;
            
            else
            {
                while(answerKey[i] == ch)
                    i++;
                
                if(i < j)
                    i++;
            }
            
            maxConfusion = max(maxConfusion, j - i + 1 + right[j]);
        }
        
        return maxConfusion;
    }
    
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length(), maxConfusion = 0;
        vector<vector<int>> right(2, vector<int> (n + 1)); // 0 = F, 1 = T.
        
        for(int k = n - 1; k >= 0; k--)
        {
            right[1][k] = answerKey[k + 1] == 'T' ? right[1][k + 1] + 1 : 0;
            right[0][k] = answerKey[k + 1] == 'F' ? right[0][k + 1] + 1 : 0;
        }
        
        return max(findMaxConfusion(answerKey, k, right[1], 'T', n),
                   findMaxConfusion(answerKey, k, right[0], 'F', n));
    }
};