class Solution {
private:
    int findUniqueNodes(vector<int> &edges, vector<int> &uniqueNodes, 
                        vector<int> &steps, int node, int currStep)
    {
        if(uniqueNodes[node] != 0)
            return currStep;
        
        if(steps[node] != 0) // We have already encountered this node.
        {
            uniqueNodes[node] = currStep - steps[node];
            return steps[node];
        }
        
        steps[node] = currStep;
        int cycleStart = findUniqueNodes(edges, uniqueNodes, steps, edges[node], currStep + 1);
        
        /* 
        If cycleStart is less than equal to currStep, that means current node is part of a cycle,
        So we count the current node only if it is not part of a cycle. 
        Because if it was part of a cycle, then it is already counted in uniqueNodes[edges[i]].
        */
        uniqueNodes[node] = uniqueNodes[edges[node]] + (cycleStart > currStep);
        return cycleStart;
    }
    
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> uniqueNodes(n), steps(n);
        
        for(int i = 0; i < n; i++)
            findUniqueNodes(edges, uniqueNodes, steps, i, 1);
        
        return uniqueNodes;
    }
};