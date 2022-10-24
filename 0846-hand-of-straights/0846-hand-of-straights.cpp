class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize)
            return false;
        
        sort(hand.begin(), hand.end());
        vector<stack<int>> groups(hand.size() / groupSize, stack<int>());
        
        for(int i = 0; i < hand.size(); i++)
        {
            int inserted = 0, k = 0;
            while(k < hand.size() / groupSize)
            {
                if(groups[k].size() == groupSize)
                    k++;
                
                else if(groups[k].empty() or hand[i] == groups[k].top() + 1)
                {
                    
                    inserted = 1;
                    groups[k].push(hand[i]);
                }
                
                else
                    k++;
                
                if(inserted)
                    break;
            }
            
            if(!inserted)
                return false;
        }
        
        return true;
    }
};