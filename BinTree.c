#include "Bintree.h"

#define MARKER -1
node_tr* tree_c(int key) {

	node_tr* node;
	node = (node_tr*)malloc(sizeof(node_t));

	if (node == NULL) {
		return NULL;
	}

	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
};


node_tr* tree_s(node_tr* root, int key) {

	if (root == NULL) {
		return NULL;
	}


	if (root->key == key) {
		return root;
	}
	if (key < root->key) {
		return tree_s(root->left, key);
	}
	else {
		return tree_s(root->right, key);
	}
};


node_tr* tree_a(node_tr* root, int key) {


	if (root == NULL) {
		return NULL;
	}

	if (key < root->key) {	
	
		if (root->left == NULL) {
			return root->left = tree_c(key);
		}

		else {
			return tree_a(root->left, key);
		}
	}
	else {

		if (root->right == NULL) {
			return root->right = tree_c(key);
		}

		else {
			return tree_a(root->right, key);
		}
	}

	return NULL;
};

void serialize(node_tr* root, FILE* fp) {
	if (fp == NULL) {
		printf("Could not open file");
		return;
	}

	if (root == NULL) {
		fprintf(fp,"%d ", MARKER);
		return;
	}

	fprintf(fp, "%d ", root->key);
	serialize(root->left, fp);
	serialize(root->right, fp);
};

node_tr* deserialize(node_tr* root, FILE* fp) {
	
	int key;
	if (!fscanf(fp, "%d ", &key) || key == MARKER) {
		return NULL;
	}

	root = tree_c(key);
	root->left = deserialize(root->left, fp);
	root->right = deserialize(root->right, fp);

	return root;
};
