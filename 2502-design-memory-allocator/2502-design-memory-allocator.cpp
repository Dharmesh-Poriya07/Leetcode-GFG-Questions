class Allocator {
private:
    vector<int> memory;
    int msize;
public:
    Allocator(int n) {
        this->msize = n;
        for(int i=0;i<n;i++){
            memory.push_back(-1);
        }
    }
    
    int allocate(int size, int mid) {
        int status = -1;
        for(int i=0;i<msize;i++){
            if(-1==memory[i]){
                int len = 0;
                while(i<msize and len!=size and -1==memory[i]){
                    len++;
                    i++;
                }
                if(len >= size){
                    status = i-size;
                    i = status;
                    while(size--){
                        memory[i] = mid;
                        i++;
                    }
                    break;
                }
            }
        }
        return status;
    }
    
    int free(int mid) {
        int freeblock = 0;
        for(int i=0;i<msize;i++){
            if(mid==memory[i]){
                freeblock++;
                memory[i] = -1;
            }
        }
        return freeblock;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */