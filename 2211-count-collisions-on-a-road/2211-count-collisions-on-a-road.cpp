class Solution {
public:
    int countCollisions(string directions) {
        int collisions = 0;
        stack<char> st;
        
        for(char &car : directions)
        {
            if(car == 'R')
                st.push(car);
            
            else
            {
                if(car == 'L')
                {   
                    if(st.empty())
                        continue;
                    
                    collisions++;
                    
                    if(st.top() == 'R')
                    {
                        collisions++;
                        st.pop();
                    }
                    
                    car = 'S';
                }
                
                // When car is stationary.
                while(!st.empty() and st.top() == 'R')
                {
                    st.pop();
                    collisions++;
                }
                
                st.push(car);
            }
        }
        
        return collisions;
    }
};