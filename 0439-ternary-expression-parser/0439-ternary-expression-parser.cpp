class Solution {
private:
    string getAnswer(string &expression, int i, int j)
    {
        if(i == j)
            return string(1, expression[i]);
        
        char cond = expression[i];
        
        int k = i + 2, questionMarks = 1;
        
        while(questionMarks > 0)
        {
            if(expression[k] == '?')
                questionMarks++;
            
            else if(expression[k] == ':')
                questionMarks--;
            
            k++;
        }
        
        return cond == 'T' ? getAnswer(expression, i + 2, k - 2) : getAnswer(expression, k, j);
    }
    
public:
    string parseTernary(string expression) {
        return getAnswer(expression, 0, expression.length() - 1);
    }
};