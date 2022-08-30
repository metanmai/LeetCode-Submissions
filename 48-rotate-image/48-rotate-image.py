class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # First rotate along diagonal.
        for i in range(len(matrix)):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        # Then reverse each row.
        for i in range(len(matrix)):
            matrix[i] = matrix[i][ : : -1]
        
        
        