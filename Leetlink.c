
struct ListNode* addTwoNumbers(struct ListNode* l1,
                               struct ListNode* l2) {
    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode* current = &dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;

        int sum = x + y + carry;

        carry = sum / 10;
        int digit = sum % 10;

        struct ListNode* newNode =
            malloc(sizeof(struct ListNode));

        newNode->val = digit;
        newNode->next = NULL;

        current->next = newNode;
        current = newNode;

        if (l1 != NULL)
            l1 = l1->next;

        if (l2 != NULL)
            l2 = l2->next;
    }

    return dummy.next;
}
