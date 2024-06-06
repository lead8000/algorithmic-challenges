from typing import List

class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        sorted_words = [sorted(word) for word in words]
        indexs = [0 for _ in range(len(words))]
        common_chars = []

        for char in "abcdefghijklmnopqrstuvwxyz":
            there_is_char = True
            while there_is_char:

                there_is_char = False
                amount_chars = 0                
                for i, word in enumerate(sorted_words):
                    if indexs[i] == len(word):
                        return common_chars

                    if word[indexs[i]] == char:
                        there_is_char = True
                        indexs[i] += 1
                        amount_chars += 1

                if amount_chars == len(sorted_words):
                    common_chars.append(char)
