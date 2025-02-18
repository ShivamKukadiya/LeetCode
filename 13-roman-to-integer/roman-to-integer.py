class Solution:
    def romanToInt(self, s: str) -> int:
        roman = {'I': 1, 'V': 5, 'X': 10, 'L': 50,
                 'C': 100, 'D': 500, 'M': 1000}
        
        ans = 0
        prev_value = 0
        
        for char in reversed(s):
            curr_value = roman[char]
            
            if curr_value < prev_value:  
                ans -= curr_value
            else:
                ans += curr_value
            
            prev_value = curr_value
        
        return ans
