// Lab5.2.12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <queue>

/////////////////////////////////Structures////////////////////////////////

struct elemsForTree {
	int numOfTree;
	char action;
	int data;
};

struct Item {
	int data;
	Item* right;
	Item* left;
	Item* parent;

};

/////////////////////////////////Functions/////////////////////////////////

void AddNode(int data, Item **node, Item* parent = NULL) {
	if (*node == NULL) { 
		*node = new Item;
		(*node)->data = data; 
		(*node)->left = (*node)->right = NULL; 
		(*node)->parent = parent;
	}
	else {
		if (data < (*node)->data)  
			AddNode(data, &(*node)->left, *node);
		else if (data >(*node)->data)     
			AddNode(data, &(*node)->right, *node);
		else  
			puts("There is such element in the tree");
	}
}

Item* Rightmost(Item* node) {
	if (node == NULL) {
		return NULL;
	} 
	if (node->right != NULL) {
		return Rightmost(node->right);
	}
	return node;
}

Item* Leftmost(Item* node) {
	if (node == NULL) {
		return NULL;
	}
	if (node->left != NULL) {
		return Leftmost(node->left);
	}
	return node;
}

void deleteNode(int data, Item* node) {
	if (node == NULL) return;

	if (data < (node)->data)
		return deleteNode(data, node->left);
	else if (data > node->data) 
		return deleteNode(data, node->right);
	else {
		if (node->left == NULL && node->right == NULL) {
			if (node->parent->left == node) {
				node->parent->left = NULL;
			}
			else {
				node->parent->right = NULL;
			}
			delete node;
		}
		else {
			Item* newNode = NULL;
			if (node->left != NULL) {
				newNode = Rightmost(node->left);
			}
			else {
				newNode = Leftmost(node->right);
			}

			if (newNode->parent->left == newNode) {
				newNode->parent->left = NULL;
			}
			else {
				newNode->parent->right = NULL;
			}

			if (node->parent->left == node) {
				node->parent->left = newNode;
			}
			else {
				node->parent->right = newNode;
			}

			if (node->parent != NULL) {
				newNode->parent = node->parent;
			}
			else {
				newNode->parent = NULL;
			}
			if (node->right != newNode && node->right) {
				newNode->right = node->right;
				node->right->parent = newNode;
			}
			else {
				newNode->right = NULL;
			}
			if (node->left != newNode && node->left) {
				newNode->left = node->left;
				node->left->parent = newNode;
			}
			else {
				newNode->left = NULL;
			}

			delete node;
		}
	}
}

void printTree(Item* tree) {
	if (tree) {
		if (tree->left) printTree(tree->left);
		std::cout << tree->data << " ";
		if (tree->right) printTree(tree->right);
	}
}

void performQueue(Item** treesArr, std::queue<elemsForTree> &q) {
	while (!q.empty()) {
		elemsForTree elem = q.front();
		q.pop();
		if (elem.action == 'A') {
			AddNode(elem.data, &treesArr[elem.numOfTree]);
		}
		else if (elem.action == 'D') {
			deleteNode(elem.data, treesArr[elem.numOfTree]);
		}
	}
}

///////////////////////////Program//////////////////////////////////////

int main()
{
	Item* tree = NULL;

	Item** treesArr = new Item*[3];
	for (int i = 0; i < 3; i++) {
		Item* tree = NULL;
		treesArr[i] = tree;
	}

	std::queue<elemsForTree> queueForTree;
	queueForTree.push({ 0, 'A', 17 });
	queueForTree.push({ 0, 'A', 15 });
	queueForTree.push({ 0, 'A', 7 });
	queueForTree.push({ 0, 'A', 32 });
	queueForTree.push({ 0, 'A', 4 });
	queueForTree.push({ 0, 'A', 13 });
	queueForTree.push({ 0, 'A', 19 });
	queueForTree.push({ 0, 'A', 17 });
	queueForTree.push({ 0, 'A', 20 });

	performQueue(treesArr, queueForTree);

	queueForTree.push({ 0, 'D', 15 });
	queueForTree.push({ 0, 'D', 7 });

	performQueue(treesArr, queueForTree);

	for (int i = 0; i < 3; i++) {
		printTree(treesArr[i]);
		std::cout << std::endl;
	}
	/*AddNode(10, &tree);
	AddNode(7, &tree);
	AddNode(13, &tree);
	AddNode(15, &tree);
	AddNode(11, &tree);
	AddNode(5, &tree);
	AddNode(9, &tree);
	AddNode(10, &tree);
	printTree(tree);
	std::cout << std::endl;

	deleteNode(5, tree);
	deleteNode(13, tree);
	printTree(tree);*/

	_getch();
    return 0;
}

