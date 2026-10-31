struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* groupPrev = &dummy;

    while (1)
    {
        // Find the kth node of the current group
        struct ListNode* kth = groupPrev;

        for (int i = 0; i < k && kth != NULL; i++)
        {
            kth = kth->next;
        }

        // Fewer than k nodes remain
        if (kth == NULL)
        {
            break;
        }

        struct ListNode* groupNext = kth->next;

        // Reverse the current group
        struct ListNode* prev = groupNext;
        struct ListNode* curr = groupPrev->next;

        while (curr != groupNext)
        {
            struct ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Connect the reversed group to the list
        struct ListNode* temp = groupPrev->next;
        groupPrev->next = kth;
        groupPrev = temp;
    }

    return dummy.next;
}
