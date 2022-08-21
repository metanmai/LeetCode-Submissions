# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        
        answer = []
        q = deque()
        q.append(root)
        
        while q:
            level = []
            curr_length = len(q)
            
            for _ in range(curr_length):
                temp = q.popleft()
                level.append(temp.val)
                if temp.left:
                    q.append(temp.left)
                if temp.right:
                    q.append(temp.right)
            
            if level:
                answer.append(level)
        
        for i in range(1, len(answer), 2):
            answer[i] = answer[i][ : : -1]
            
        return answer