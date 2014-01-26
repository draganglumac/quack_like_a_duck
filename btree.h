/*
 * =====================================================================================
 *
 *       Filename:  btree.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/01/14 11:30:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dragan Glumac (draganglumac), dragan.glumac@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __BTREE__
#define __BTREE__

typedef struct
{
	void *key;
	void *val;
} btree_record;

typedef struct _btree_node
{
	btree_record *records[5];
	struct _btree_node *children[6];

} btree_node;

typedef struct
{
	btree_node *root;

} btree;

btree *create_btree();
void add_to_btree(btree *tree, void *key, void *val);

#endif
