ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || head == NULL)
        return head;
    int cnt = 0;
    ListNode *temp = head;
    while (cnt < k)
    {
        if (temp == NULL)
            return head;
        temp = temp->next;
        cnt++;
    }
    ListNode *prev = reverseKGroup(temp, k);
    temp = head;
    cnt = 0;
    while (cnt < k)
    {
        ListNode *next = temp->next;
        temp->next = prev;

        prev = temp;
        temp = next;
        cnt++;
    }
    return prev;
}