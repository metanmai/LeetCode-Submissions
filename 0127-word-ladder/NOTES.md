Consider example 1.
*beginWord* is 'hit'. So it has 3 possible 'neighbours' :
1. The 1st letter is changed ('*it').
2. The 2nd letter is changed ('h*t').
3. The 3rd letter is changed ('hi*').
​
Therefore, for a word of length m, there will be m different branches, i.e., neighbours.
The first step is to create a dictionary, which will act as an adjacency list. The dictionary *neighbours* will have the keys as the patterns and the values as the words which follow that pattern.
​
Once the dictionary is created, we begin the BFS.
The first level of the graph will have *beginWord*. So we insert that into the queue *q*.
Then we go to the subsequent branches. So in example 1, we check pattern 1, then pattern 2, then pattern 3. In this case, pattern 2 happens to be the only one with additional branches so that is traversed. And as we traverse the nodes, we keep checking if it is the *endWord*. If it is, then we return the level at which it was found. The current level is maintained in *result*. When the word is found, we return result.
​
Since we are performing BFS, the shortest path is always the one that is returned as we are going level by level, starting at level 1, then going downwards, and checking if *endWord* exists in that particular level.
​
This problem can technically be solved using DFS as well, but the first path that we find might not be the minimum one. So we will have to use the min() function there.
​
The final case is when the *endWord* is unreachable, at which point we return 0 after we complete the BFS.
​
The time complexity will be of the order O(n * m * m).
​
For more clarity (especially the time complexity), watch https://youtu.be/h9iTnkgv05E or check the solution provided by LeetCode.