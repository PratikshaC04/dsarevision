node middle_node(node head)
{
    if (head == NULL) return NULL;

    node slow = head;
    node fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // move 1 step
        fast = fast->next->next;     // move 2 steps
    }

    return slow; // slow is now at the middle
}
