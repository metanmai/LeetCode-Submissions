class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0
        
        # Default value for any new element in the dictionary will be an empty list.
        neighbours = defaultdict(list) 
        
        # Since beginWord is not a part of the list we first append it.
        wordList.append(beginWord)
        
        for word in wordList:
            for j in range(len(word)):
                pattern = word[ : j] + '*' + word[j + 1 : ]
                neighbours[pattern].append(word)
        
        visited = set([beginWord])
        q = deque([beginWord])
        result = 1
        
        # Breadth First Search.
        while q:
            for _ in range(len(q)):
                word = q.popleft()
                if word == endWord:
                    return result
                
                for j in range(len(word)):
                    pattern = word[ : j] + '*' + word[j + 1 : ]
                    
                    for neighbour in neighbours[pattern]:
                        if neighbour not in visited:
                            visited.add(neighbour)
                            q.append(neighbour)
                            
            result += 1
        
        # We return zero if we never find endWord even after performing BFS.
        return 0