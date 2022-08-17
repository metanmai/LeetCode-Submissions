class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        code = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        
        morse = set()
        for i in words:
            temp = ""
            for j in i:
                temp += code[ord(j) - ord('a')]
            morse.add(temp)
        
        return len(set(morse))