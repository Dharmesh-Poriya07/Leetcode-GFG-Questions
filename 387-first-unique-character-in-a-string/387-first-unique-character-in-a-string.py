class Solution:
    def firstUniqChar(self, s: str) -> int:
        freq = Counter(s);
        # for ch in s:
        #     if ch in freq:
        #         freq[ch] += 1;
        #     else:
        #         freq[ch] = 1;
        i = 0;
        for ch in s:
            if 1==freq[ch]:
                return i;
            i += 1;
        return -1;