/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	if (K == 1 || K <= 0)	//Invalid case or case where everything should be deleted, returning NULL;
		return NULL;
	int counter;
	struct node *temp_ptr, *prev_ptr;
	temp_ptr = head;
	prev_ptr = head;
	counter = 1;
	while (temp_ptr != NULL)
	{
		if (counter == K)	//Remove the kth node
		{
			prev_ptr->next = temp_ptr->next;
			//free(temp_ptr);
			counter = 1;
			temp_ptr = prev_ptr->next;
		}
		else
		{
			prev_ptr = temp_ptr;
			temp_ptr = temp_ptr->next;
			counter++;
		}
	}
	return head;
}