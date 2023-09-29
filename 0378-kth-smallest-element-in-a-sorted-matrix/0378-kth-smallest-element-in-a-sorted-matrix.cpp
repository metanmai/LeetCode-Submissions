/*
Min-Heap Solution
Time Complexity: O(klog k)
Space Complexity: O(k)
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), answer;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        for (int r = 0; r < min(n, k); ++r)
            minHeap.push({matrix[r][0], r, 0});

        for (int i = 1; i <= k; ++i) {
            auto top = minHeap.top(); minHeap.pop();
            int r = top[1], c = top[2];
            answer = top[0];
            
            if (c + 1 < n) 
                minHeap.push({matrix[r][c + 1], r, c + 1});
        }
        return answer;
    }
};