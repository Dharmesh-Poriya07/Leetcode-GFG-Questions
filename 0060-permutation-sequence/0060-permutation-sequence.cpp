class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        for(int i=1;i<n;i++){
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        string ans = "";
        k--;

        while(true){
            ans.push_back('0'+numbers[k/fact]);
            numbers.erase(numbers.begin()+ k/fact);
            if(0==numbers.size()) break;

            k %= fact;
            fact /= numbers.size();
        }
        return ans;
    }
};