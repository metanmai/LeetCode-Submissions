class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> answer;

        for(int ast : asteroids)
        {
            bool destroyed = false;
            
            while(answer.size() and ast < 0 and answer.back() > 0 and !destroyed)
            {
                if(abs(ast) > answer.back())
                    answer.pop_back();
                
                else
                {
                    if(abs(ast) == answer.back())
                        answer.pop_back();

                    destroyed = true;
                }
            }
            
            if(!destroyed) 
                answer.push_back(ast);
        }

        return answer;
    }
};