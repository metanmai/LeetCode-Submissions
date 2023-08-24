class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> answer;
        string currLine = "";
        int startWord = 0, spaces = 0, lineLength = words[0].length();
        
        for(int i = 1; i < n; i++)
        {
            if(lineLength + spaces + words[i].length() + 1 <= maxWidth)
                lineLength += words[i].length(), spaces++;
            
            else
            {
                if(spaces == 0)
                {
                    currLine += words[startWord];
                    
                    while(currLine.size() < maxWidth)
                        currLine.push_back(' ');
                }
                
                else
                {
                    int k = startWord;
                    int totalSpaceLen = maxWidth - lineLength;
                    int spaceLen = ceil((double) totalSpaceLen / spaces);

                    while(totalSpaceLen)
                    {
                        currLine += words[k] + string(spaceLen, ' ');
                        totalSpaceLen -= spaceLen, k++, spaces--;

                        if(spaces != 0 and totalSpaceLen % spaces == 0)
                            spaceLen = totalSpaceLen / spaces;
                    }
                
                    currLine += words[i - 1];
                }
                
                answer.push_back(currLine);
                currLine = "";
                startWord = i, spaces = 0, lineLength = words[i].length();
            }
        }
        
        for(int i = startWord; i < n; i++)
        {
            currLine += words[i];
            
            if(i != n - 1)
                currLine.push_back(' ');
        }
        
        while(currLine.size() != maxWidth)
            currLine.push_back(' ');
        
        answer.push_back(currLine);
        
        return answer;
    }
};