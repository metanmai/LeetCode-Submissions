class Solution:
    def grayCode(self, n: int) -> List[int]:
            codes = ['0', '1']
            answer = []
            for _ in range(1, n):
                codes2 = codes[ : : -1]
                for i in range(len(codes)):
                    codes[i] = '0' + codes[i]
                    codes2[i] = '1' + codes2[i]
            
                codes += codes2
                
            for num in codes:
                answer.append(int(num, 2))
            
            return answer