class TrieNode:
    def __init__(self, value, word_end = False):
        self.value = value
        self.childs = []
        self.word_end = word_end

class Trie:


    def __init__(self):
        self.roots = []

    def insert(self, word: str) -> None:
        for root in self.roots:
            if root.value == word[0]:
                trie, suffix = self.__visit_dfs(root, word)
                if len(suffix) == 0:
                    if not trie.word_end:
                        trie.word_end = True
                    return
                trie.childs.append(self.__build_trie(suffix))
                return
        trie = self.__build_trie(word)
        self.roots.append(trie)
        
    def search(self, word: str) -> bool:
        for root in self.roots:
            if root.value == word[0]:
                trie, suffix = self.__visit_dfs(root, word)
                if len(suffix) == 0 and trie.word_end:
                    return True
                print(suffix)
        return False

    def startsWith(self, prefix: str) -> bool:
        for root in self.roots:
            if root.value == prefix[0]:
                _, suffix = self.__visit_dfs(root, prefix)
                if len(suffix) == 0:
                    return True
        return False

    def __visit_dfs(self, trie_root: TrieNode, word: str):
        if len(word) > 0 and word[0] != trie_root.value:
            return trie_root, word

        if len(word) == 1:
            return trie_root, ""

        for root in trie_root.childs:
            if root.value == word[1]:
                return self.__visit_dfs(root, word[1:])

        return trie_root, word[1:]

    def __build_trie(self, word: str):
        root = TrieNode(word[0])
        
        if len(word) == 1:
            root.word_end = True
            return root

        curr = root
        for i, char in enumerate(word[1:], 1):
            new_trie = TrieNode(char)
            if i+1 == len(word):
                new_trie.word_end = True
            curr.childs.append(new_trie)
            curr = new_trie
        
        return root

word = "r"

# Your Trie object will be instantiated and called as such:
obj = Trie()
obj.insert(word)
param_2 = obj.search(word)
param_3 = obj.startsWith(word)

print(param_2, param_3)