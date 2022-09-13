class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int rbytes = 0;
        for(int val: data){
            if(0==rbytes){
                if((val>>5)==0b110){
                    rbytes = 1;
                }else if((val>>4)==0b1110){
                    rbytes = 2;
                }else if((val>>3)==0b11110){
                    rbytes = 3;
                }else if(val>>7){
                    return false;
                }
            }else{
                if((val>>6)==0b10){
                    rbytes--;
                }else{
                    return false;
                }
            }
        }
        if(rbytes==0)
            return true;
        return false;
    }
};