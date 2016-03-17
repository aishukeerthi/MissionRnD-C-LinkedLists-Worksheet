/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	else{
		struct node *first, *newnode;
		int temp;
		first = head;
		for (; first->next != NULL; first = first->next)
		{
			for (newnode = first->next; newnode != NULL; newnode = newnode->next)
			{
				if (first->num > newnode->num)
				{
					temp = first->num;
					first->num = newnode->num;
					newnode->num = temp;
				}
			}
		}
		return head;
	}
}