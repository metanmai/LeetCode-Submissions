class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        triangle = []
        if numRows >= 1:
            triangle.append([1])
        
        if numRows >= 2:
            triangle.append([1,1])
            for i in range(2, numRows):
                temp = []
                k = 0
                while k <= i:
                    if k == 0 or k == i:
                        temp.append(1)
                    
                    else:
                        temp.append(triangle[i - 1][k - 1] + triangle[i - 1][k])
                    k += 1
                triangle.append(temp)
            
        return triangle