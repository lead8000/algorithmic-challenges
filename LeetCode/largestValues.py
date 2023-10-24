# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

from typing import Optional, List

class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []

        h = self.height(root)
        res = [-2147483649 for _ in range(h)]

        self.update_max(root, res, 0)

        return res

    def height(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        return 1 + max(self.height(root.left), self.height(root.right))
    
    def update_max(self, root: Optional[TreeNode], heights: list, h: int):
        if root == None:
            return

        heights[h] = max(heights[h], root.val)

        self.update_max(root.left, heights, h+1)
        self.update_max(root.right, heights, h+1)
