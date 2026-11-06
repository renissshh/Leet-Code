
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* slow = &dummy;
    struct ListNode* fast = &dummy;

    // Move fast n positions ahead
    for(int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // Move both pointers
    while(fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete the required node
    struct ListNode* temp = slow->next;
    slow->next = slow->next->next;
    free(temp);

    return dummy.next;
}
