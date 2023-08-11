struct MyListNode
{
    int val;
    MyListNode *left, *right;
    
    MyListNode(int val) : val(val), left(NULL), right(NULL) {}
};

class MyLinkedList {
private:
    MyListNode *head, *tail;
    int length;
    
public:
    MyLinkedList() : head(NULL), tail(NULL), length(0) {}
    
    MyListNode *goToIndex(int index)
    {
        int i = 0;
        MyListNode *temp = head;
        
        while(temp and i < index)
        {
            temp = temp->right;
            i++;
        }
        
        return temp;
    }
    
    int get(int index) {
        MyListNode *temp = goToIndex(index);
        
        return temp ? temp->val : -1;
    }
    
    void addAtHead(int val) {
        MyListNode *curr = new MyListNode(val);
        length++;
        
        if(!head)
        {
            head = tail = curr;
            return;
        }
        
        curr->right = head;
        head->left = curr;
        head = curr;
    }
    
    void addAtTail(int val) {
        MyListNode *curr = new MyListNode(val);
        length++;
        
        if(!tail)
        {
            head = tail = curr;
            return;
        }
        
        curr->left = tail;
        tail->right = curr;
        tail = curr;
    }
    
    void addAtIndex(int index, int val) {
        if(index > length)
            return;
        
        MyListNode *temp = goToIndex(index), *curr = new MyListNode(val);
        
        if(index == 0)
        {
            addAtHead(val);
            return;
        }
        
        if(!temp)
        {
            addAtTail(val);
            return;
        }
        
        curr->right = temp;
        curr->left = temp->left;
        temp->left->right = curr;
        temp->left = curr;
        length++;
    }
    
    void deleteAtIndex(int index) {
        MyListNode *temp = goToIndex(index);
        
        if(!temp)
            return;

        if(temp == head)
            head = temp->right;
        
        if(temp == tail)
            tail = temp->left;
        
        if(temp->left)
            temp->left->right = temp->right;
        
        if(temp->right)
            temp->right->left = temp->left;
        
        length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */