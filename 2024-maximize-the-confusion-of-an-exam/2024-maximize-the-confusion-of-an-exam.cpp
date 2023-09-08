// Pure Sliding Window Solution.
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length(), maxSize = k, i = 0;
        unordered_map<char, int> count;
        
        for (int i = 0; i < k; i++)
            count[answerKey[i]]++;
        
        for (int j = k; j < n; j++)
        {
            count[answerKey[j]]++;
            
            while (min(count['T'], count['F']) > k)
                count[answerKey[i]]--, i++;
            
            maxSize = max(maxSize, j - i + 1);
        }
                    
        return maxSize;
    }
};