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

} node_t;



node_t* tree_c(int);


node_t* tree_s(node_t*, int);


node_t* tree_a(node_t*, int);


void serialize(node_t*, FILE*);
node_t* deserialize(node_t*, FILE*);
#endif // __TREE__
