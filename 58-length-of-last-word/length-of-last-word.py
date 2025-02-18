class Solution:
    def lengthOfLastWord(self, s: str) -> int:
          words = list(s.strip().split())
          return len(words[-1])

    
    
        