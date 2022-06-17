#pragma once
#ifndef __TREE__
#define __TREE__
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct node {

	int key;
	struct node* left;
	struct node* right;

} node_tr;



node_tr* tree_c(int);


node_tr* tree_s(node_tr*, int);


node_tr* tree_a(node_tr*, int);


void serialize(node_tr*, FILE*);
node_tr* deserialize(node_tr*, FILE*);
#endif // __TREE__
