class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        def dp(start,k):
            if (start,k) in memo:
                return memo[(start,k)]
            
            if start == n or n-start <= k:
                return 0;
            
            ans = sys.maxsize
            count = defaultdict(int)
            most_freq = 0
            
            for j in range(start,n):
                c = s[j]
                count[c] += 1
                most_freq = max(most_freq,count[c])
                
                compressed_length = 1 + (len(str(most_freq)) if most_freq > 1 else 0)
                
                if k>= j-start+1-most_freq:
                    ans = min(ans,compressed_length + dp(j+1,k-(j-start+1-most_freq)))
                    
            memo[(start,k)] = ans
            return ans
        
        
        n = len(s)
        memo = {}
        return dp(0,k)