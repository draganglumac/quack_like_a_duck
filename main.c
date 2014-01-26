/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/01/14 11:24:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dragan Glumac (draganglumac), dragan.glumac@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "mem.h"
#include "btree.h"

int main(int argc, char **argv)
{
	btree *tree = create_btree();

	printf("btree = %ld\n", tree);

	char *bob = "Bob's your uncle.";
	add_to_btree(tree, (void *)bob, (void *)bob);

	assert((void *)bob == tree->root->records[0]->key);
	assert((void *)bob == tree->root->records[0]->val);
	printf("Key and value seem to be ok.\n");

	printf("Now, I am going to MALLOC some data.\n");
	printf("If I compile with DEBUG flag I expect to see just one mem_malloc call here.\n");
	printf("If I compile without DEBUG flag I don't expect to see any mem_malloc calls.\n");
	printf("->\n");
	void *temp = MALLOC( sizeof(int) );
	
	printf("All is well. Goodbye.\n");
	
	return 0;
}
