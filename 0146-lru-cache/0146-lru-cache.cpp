class DLL{
    public:
    int key,val;
    DLL *prev,*next;

    DLL(int k,int v){
        key = k;
        val = v;
        prev = next = nullptr;
    }
};

class LRUCache {
    unordered_map<int,DLL*> ump;
    DLL *head,*tail;
    int capacity, curr_cap;
public:
    LRUCache(int capacity) {
        head = new DLL(-1,-1);
        tail = new DLL(-1,-1);
        head->next = tail;
        tail->prev = head;

        this->capacity = capacity;
        curr_cap = 0;
    }
    
    int get(int key) {
        if(ump.find(key)==ump.end()) return -1;

        auto curr = ump[key];
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        curr->next = head->next;
        curr->prev = head;
        head->next->prev = curr;
        head->next = curr;
        return curr->val;
    }
    
    void put(int key, int value) {
        // key already exist
        if(ump.find(key)!=ump.end()){
            auto curr = ump[key];
            curr->val = value;

            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;

            curr->next = head->next;
            curr->prev = head;
            head->next->prev = curr;
            head->next = curr;
            return;
        }

        // capacity full
        if(curr_cap == capacity){
            auto removed = ump[tail->prev->key];
            ump.erase(removed->key); // removing least reently used node

            removed->prev->next = tail;
            tail->prev = removed->prev;

            DLL *newnode = new DLL(key,value);
            ump[key] = newnode;
            newnode->prev = head;
            newnode->next = head->next;
            head->next->prev = newnode;
            head->next = newnode;
            return;
        }

        // adding newnode
        DLL *newnode = new DLL(key,value);
        ump[key] = newnode;
        newnode->prev = head;
        newnode->next = head->next;
        head->next->prev = newnode;
        head->next = newnode;
        curr_cap++;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */