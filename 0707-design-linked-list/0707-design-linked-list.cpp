class Node{
    public:
    int val;
    Node *next;
    Node *prev;
    Node(int val){
        this->val = val;
        this->next = this->prev = nullptr;
    }
};
class MyLinkedList {
private:
    Node *head,*tail;
    int size;
public:
    MyLinkedList() {
        this->head = this->tail = nullptr;
        this->size = 0;
    }
    
    int get(int index) {
        if(0>index or index>=this->size) return -1;
        Node *current = head;
        if(index>this->size/2){
            current = tail;
            index = this->size-index-1;
            while(index--)
                current = current->prev;
        }else{
            while(index--)
                current = current->next;
        }
        return current->val;
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node(val);
        if(!head){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        this->size++;
    }
    
    void addAtTail(int val) {
        if(!head){
            addAtHead(val);
            return;
        }
        Node *newNode = new Node(val);
        this->tail->next = newNode;
        newNode->prev = this->tail;
        this->tail = newNode;
        this->size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>this->size) return;
        if(index==this->size){
            addAtTail(val);
            return;
        }
        if(-1==index-1){
            addAtHead(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *current = this->head;
        if(index>this->size/2){
            current = tail;
            index = this->size-index-1;
            while(index--){
                current = current->prev;
            }
        }else{
            while(index--){
                current = current->next;
            }
        }
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev = newNode;
        newNode->prev->next = newNode;
        this->size++;
    }
    
    void deleteAtIndex(int index) {
        if(0>index or this->size<=index) return;
        Node *current = head;
        if(index>this->size/2){
            current = tail;
            index = this->size-index-1;
            while(index--){
                current = current->prev;
            }
        }else{
            while(index--){
                current = current->next;
            }
        }
        if(head==current){
            head = current->next;
            if(!head) tail = head;
            if(head)
                head->prev = nullptr;
            this->size--;
            return;
        }
        if(tail == current){
            tail = current->prev;
            if(!tail) head = tail;
            if(tail)
                tail->next = nullptr;
            this->size--;
            return;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
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