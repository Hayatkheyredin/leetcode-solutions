var deleteDuplicates = function(head) {
    let dummy = new ListNode(-1);
    dummy.next = head;
    let prev = dummy;
    let cur = head;

    while (cur && cur.next) {
        if (cur.val === cur.next.val) {
            while (cur.next && cur.val === cur.next.val) {
                cur = cur.next;
            }
            prev.next = cur.next; // Skip all duplicates
        } else {
            prev = prev.next; // Move to next distinct node
        }
        cur = cur.next;
    }

    return dummy.next;
};