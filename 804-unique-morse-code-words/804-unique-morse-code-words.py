class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        s = set();
        morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        for word in words:
            morse_code = []
            for ch in word:
                morse_code.append(morse[ord(ch)-ord('a')]);
            s.add(''.join(morse_code));
            
        return len(s);