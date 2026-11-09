struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *prev = &dummy;

    while(prev->next != NULL && prev->next->next != NULL)
    {
        struct ListNode *first = prev->next;
        struct ListNode *second = first->next;

        prev->next = second;
        first->next = second->next;
        second->next = first;

        prev = first;
    }

    return dummy.next;
}
