/*
 * =====================================================================================
 *
 *       Filename:  mem.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/01/14 12:30:29
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

#include "btree.h"
#include "mem.h"

// guarantees vanilla malloc and calloc in memtree
static btree *memtree = NULL;

void *mem_malloc(size_t size)
{
	if ( memtree == NULL )
		memtree = create_btree_internal();

	printf("Calling mem_malloc(%ld)\n", size);
	void *temp = malloc(size);
	add_to_btree(memtree, temp, temp);

	return temp;
}

void *mem_calloc(size_t num, size_t size)
{
	if ( memtree == NULL )
		memtree = create_btree_internal();

	printf("Calling mem_calloc(%ld, %ld)\n", num, size);
	void *temp = calloc(num, size);
	add_to_btree(memtree, temp, temp);

	return temp;
}
