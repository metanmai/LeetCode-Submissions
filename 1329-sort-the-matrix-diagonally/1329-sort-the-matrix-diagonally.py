# https://leetcode.com/problems/sort-the-matrix-diagonally/discuss/1031671/Python-straight-solution

class Solution(object):
    def diagonalSort(self, mat):
        d = dict()
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if (i - j) not in d:
                    d[i-j] = []
                d[i-j].append(mat[i][j])
        
        for key in d:
            d[key].sort() 
        
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                mat[i][j] = d[i-j].pop(0) #you can try with deque for improving the time complexity
        
        return mat