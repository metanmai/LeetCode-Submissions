class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        if endWord not in wordList :
            return []
        
        wordSet = set(wordList)
        wordSet.add(beginWord)
        wordSet.remove(endWord)
        graph = collections.defaultdict(list)
        prevLayer = collections.defaultdict(list)
        prevLayer[endWord] = [endWord]

        #print all the paths of the graph
        def path() :
            ans = [[beginWord]]
            while ans[0][-1] is not endWord :
                temp_ans = []
                for lst in ans :
                    last_word = lst[-1]                
                    for word in graph[last_word] :
                        cur = lst + [word]
                        temp_ans.append(cur)
                print(temp_ans)
                ans = temp_ans
            return ans
            
        #prevLayer keys are the keys at current layer leading to endWord
        while prevLayer :
            #if this layer already has beginWord, answer has ben found
            if beginWord in graph :
                return path()
            
            
            newLayer = collections.defaultdict(list)
            #for each letter of each key in prevLayer, change the letter to find it in wordSet
            for key in prevLayer :
                for i in range(len(key)) :
                    for c in 'abcdefghijklmnopqrstuvwxyz' :
                        newKey = key[:i] + c + key[i+1 :]
                        if newKey in wordSet :
                            #create an edge from newKey to key
                            newLayer[newKey] += [key]
                            graph[newKey] += [key]
            wordSet -= set(newLayer.keys())
            prevLayer = newLayer #newLayer is the latest found sequences to endWord
        return []