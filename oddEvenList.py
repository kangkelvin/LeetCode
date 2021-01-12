# https://leetcode.com/problems/odd-even-linked-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:       
        if head == None:
            return None
        
        oddHead = head
        odd = head
        
        if head.next == None:
            return head
        
        evenHead = head.next
        even = head.next
        
        while (even is not None) and (odd is not None):       
            odd.next = even.next
            if odd.next == None:
                break
            odd = odd.next
            even.next = odd.next
            even = even.next

            
        
        odd.next = evenHead
        return oddHead
