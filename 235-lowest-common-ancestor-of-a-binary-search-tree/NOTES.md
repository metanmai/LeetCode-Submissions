This is a Binary Search Tree. So we can use it's properties to our advantage.
​
The LCA of 2 nodes is basically the point at which the '*split*' occurs. For the split to occur, one of the nodes has to be in the left subtree and the other must be in the right subtree or when the root itself is equal to p or q.
​
First, check the root node's value.
* If both p and q have greater values, then the split must be in the right subtree.
* If both p and q have lesser values, then the split must be in the left subtree.
* If it is not either of the above 2 cases, that means that you are currently at the split, so return that node.