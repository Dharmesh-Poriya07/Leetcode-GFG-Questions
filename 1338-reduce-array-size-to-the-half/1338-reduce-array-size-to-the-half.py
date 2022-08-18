class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        freq = Counter(arr);
        f = [];
        for val in freq.values():
            f.append(val);
        f.sort(reverse=True)
        ans = 0;
        n = 0;
        while(len(arr)//2>n):
            n += f[ans];
            ans += 1;
        return ans;