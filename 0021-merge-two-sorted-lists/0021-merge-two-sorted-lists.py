class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # 1. Initialize a dummy node and a tail pointer
        # The dummy node simplifies the logic by giving us a fixed starting point for the new list.
        dummy = ListNode()
        tail = dummy
        
        # 2. Iterate while both lists have nodes
        while list1 and list2:
            if list1.val <= list2.val:
                # Append the node from list1 to the new list (via 'tail')
                tail.next = list1
                # Move the list1 pointer to the next node
                list1 = list1.next
            else:
                # Append the node from list2 to the new list (via 'tail')
                tail.next = list2
                # Move the list2 pointer to the next node
                list2 = list2.next
                
            # Always move the tail pointer to the newly appended node
            tail = tail.next
            
        # 3. Handle the remaining nodes
        # After the loop, at least one list is empty. 
        # Attach the non-empty list's remaining part to the end of the merged list.
        if list1:
            tail.next = list1
        elif list2:
            tail.next = list2
            
        # 4. Return the merged list
        # The merged list starts at dummy.next, as dummy was just a placeholder.
        return dummy.next

# Note: The 'Optional' type hint for the input and output is common in modern Python solutions
# for linked list problems, as the list can be empty (None).