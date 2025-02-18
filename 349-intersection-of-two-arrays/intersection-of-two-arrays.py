class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:

        set_nums1 = set(nums1)
      
        
        set_nums2 = set(nums2)
      
        
        intersection_set = set_nums1 & set_nums2
      
        
        return list(intersection_set)