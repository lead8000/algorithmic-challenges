from typing import List

class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        dictionary = sorted(dictionary)
        sentence = sentence.split(' ')

        for i, word in enumerate(sentence):
           for root in dictionary:
               if word.startswith(root):
                   sentence[i] = root
                   break
        
        return ' '.join(sentence)
    
dict = ["a", "aa", "aaa", "aaaa"]
sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"

print(Solution().replaceWords(dict, sentence))