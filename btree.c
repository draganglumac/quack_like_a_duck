/*
 * =====================================================================================
 *
 *       Filename:  btree.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/01/14 11:35:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dragan Glumac (draganglumac), dragan.glumac@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include "btree.h"

// C can't make this one static but I guess we don't have to expose it
// so even though the symbol will be available for those in the know
// the struct will effectively be hidden from veiw for most clients
typedef struct
{
	// btree members here
	btree_node *root;

	// btree_internal extension start here
	void *(*mallocate)(size_t size);
	void *(*callocate)(size_t num, size_t size);

} btree_internal;

btree *create_btree()
{
	// implementation, so using internal btree structure
	btree_internal *tree = malloc(sizeof(btree_internal));

	// initialise btree memebers first
	tree->root = NULL;
	// now initialise btree_internal members
	tree->mallocate = malloc;
	tree->callocate = calloc;

	// returning to client caller, so casting to btree
	return (btree *)tree;
}

void add_to_btree(btree *tree, void *key, void *val)
{
	// implementation, so casting to internal btree structure
	btree_internal *itree = (btree_internal*)tree;

	// allocate root node if needed
	if ( itree->root == NULL )
		itree->root = itree->callocate(1, sizeof(btree_node));
	btree_node *root = itree->root;

	// allocate and populate the new record
	btree_record *r = itree->mallocate(sizeof(btree_record));
	r->key = key;
	r->val = val;

	root->records[0] = r;
}
