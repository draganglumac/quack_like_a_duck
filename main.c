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

#include "btree.h"

int main(int argc, char **argv)
{
	btree *tree = create_btree();

	printf("btree = %ld\n", tree);

	char *bob = "Bob's your uncle.";
	add_to_btree(tree, (void *)bob, (void *)bob);

	assert((void *)bob == tree->root->records[0]->key);
	assert((void *)bob == tree->root->records[0]->val);
	printf("All is well. Goodbye.\n");

	return 0;
}
