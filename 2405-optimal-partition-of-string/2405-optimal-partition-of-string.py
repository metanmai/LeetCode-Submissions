class Solution:
    def partitionString(self, s: str) -> int:
        st = set()
        count = 1
        
        for i in s:
            if i not in st:
                st.add(i)
                
            else:
                st = set(i)
                count += 1
        
        return count