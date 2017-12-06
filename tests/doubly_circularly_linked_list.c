#include "doubly_circularly_linked_list.h"
#include <stdio.h>

struct test {
	struct test *fp;
	struct test *bp;
	char chr;
} entries[] = {
	{NULL, NULL, 'a'},
	{NULL, NULL, 'b'},
	{NULL, NULL, 'c'},
	{NULL, NULL, 'd'},
	{NULL, NULL, 'e'},
};

void print_list(struct test *head);

struct test header;

int main(void) {
	header.fp = header.bp = &header;
	
	INSERT_TO_LIST_TAIL(&header, &entries[0]);
	INSERT_TO_LIST_TAIL(&header, &entries[1]);
	INSERT_TO_LIST_TAIL(&header, &entries[2]);
	INSERT_TO_LIST_TAIL(&header, &entries[3]);
	INSERT_TO_LIST_TAIL(&header, &entries[4]);

	print_list(&header);
	/* a b c d e */

	REMOVE_FROM_LIST(&header, &entries[2]);
	print_list(&header);
	INSERT_TO_LIST_HEAD(&header, &entries[2]);
	print_list(&header);
}

void print_list(struct test *head) 
{
	int i;
	struct test *p;
	for (p = head->fp; p != head; p = p->fp) {
		printf("%c ", p->chr);
	}
	putchar('\n');
}

