
struct ListNode* mergeTwoLists(struct ListNode* a, struct ListNode* b)
{
    struct ListNode dummy;
    struct ListNode* tail = &dummy;

    dummy.next = NULL;

    while(a != NULL && b != NULL)
    {
        if(a->val <= b->val)
        {
            tail->next = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            b = b->next;
        }

        tail = tail->next;
    }

    if(a != NULL)
        tail->next = a;
    else
        tail->next = b;

    return dummy.next;
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if(listsSize == 0)
        return NULL;

    if(listsSize == 1)
        return lists[0];

    int mid = listsSize / 2;

    struct ListNode* left =
        mergeKLists(lists, mid);

    struct ListNode* right =
        mergeKLists(lists + mid, listsSize - mid);

    return mergeTwoLists(left, right);
}
