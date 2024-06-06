class Solution:
    def isAnagram(self, s: str, t: str) -> bool:        
        vocabulary = "abcdefghijklmnopqrstuvwxyz"
        freq_s = {char:0 for char in vocabulary}
        freq_t = {char:0 for char in vocabulary}
        
        for char in s:
            freq_s[char] += 1
        for char in t:
            freq_t[char] += 1

        for char in vocabulary:
            if freq_s[char] != freq_t[char]:
                return False

        return True

print(Solution().isAnagram("anagram","nagaram"))
print(Solution().isAnagram("rat","car"))