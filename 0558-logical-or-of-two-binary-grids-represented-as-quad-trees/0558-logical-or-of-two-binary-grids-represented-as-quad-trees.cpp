/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    Node *findIntersection(Node *root1, Node *root2)
    {
        if(root1->isLeaf)
            return root1->val ? root1 : root2;
        
        if(root2->isLeaf)
           return root2->val ? root2 : root1;
        
        Node *root = new Node();
        
        root->topLeft = findIntersection(root1->topLeft, root2->topLeft);
        root->topRight = findIntersection(root1->topRight, root2->topRight);
        root->bottomLeft = findIntersection(root1->bottomLeft, root2->bottomLeft);
        root->bottomRight = findIntersection(root1->bottomRight, root2->bottomRight);
        
        if(root->topLeft and root->topRight and 
           root->bottomLeft and root->bottomRight and 
           root->topLeft->isLeaf and root->topRight->isLeaf and 
           root->bottomLeft->isLeaf and root->bottomRight->isLeaf and 
           root->topLeft->val == true and root->topRight->val == true and 
           root->bottomLeft->val == true and root->bottomRight->val == true)
            root = new Node(true, true);
        
        else if(root->topLeft and root->topRight and 
                root->bottomLeft and root->bottomRight and 
                root->topLeft->isLeaf and root->topRight->isLeaf and 
                root->bottomLeft->isLeaf and root->bottomRight->isLeaf and 
                root->topLeft->val == false and root->topRight->val == false and 
                root->bottomLeft->val == false and root->bottomRight->val == false)
            root = new Node(false, true);
        
        return root;
    }
    
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        return findIntersection(quadTree1, quadTree2);
    }
};