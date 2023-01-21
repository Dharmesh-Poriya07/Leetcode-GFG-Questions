class Node{
    public:
    int val;
    Node *next;
    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};
class MyLinkedList {
private:
    Node *head;
    int size;
public:
    MyLinkedList() {
        this->head = nullptr;
        this->size = 0;
    }
    
    int get(int index) {
        if(0>index or index>=this->size) return -1;
        Node *current = head;
        while(index--){
            current = current->next;
        }
        return current->val;
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        this->size++;
    }
    
    void addAtTail(int val) {
        if(!head){
            addAtHead(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *current = head;
        while(current->next){
            current = current->next;
        }
        current->next = newNode;
        this->size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>this->size) return;
        index --;
        if(-1==index){
            addAtHead(val);
            return;
        }
        Node *current = this->head;
        while(index--){
            current = current->next;
        }
        Node *newNode = new Node(val);
        newNode->next = current->next;
        current->next = newNode;
        this->size++;
    }
    
    void deleteAtIndex(int index) {
        if(0>index or this->size<=index) return;
        index--;
        if(-1==index){
            this->size--;
            head = head->next;
            return;
        }
        Node *current = head;
        while(index--){
            current = current->next;
        }
        current->next = current->next->next;
        this->size--;
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