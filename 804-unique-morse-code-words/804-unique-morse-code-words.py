class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        s = set();
        morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        for word in words:
            morse_code = []
            for ch in word:
                for c in morse[ord(ch)-ord('a')]:
                    morse_code.append(c);
            s.add(''.join(morse_code));
            
        return len(s);