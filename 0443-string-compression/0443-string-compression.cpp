class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i=0;
        int j=0;
        
        while(i<n){
            char ch = chars[i];
            int count = 0;
            while(i<n and chars[i]==ch){
                ch = chars[i];
                count ++;
                i++;
            }
            chars[j] = ch;
            j++;
            if(1<count){
                string num = "";
                while(0<count){
                    num.push_back('0'+count%10);
                    count /= 10;
                }
                while(num.size()>0)
                   chars[j++] = num.back(),num.pop_back();
            }
        }
        return j;
    }
};