#pragma once
#include <iostream>
using namespace std;


struct node {
	int data;
	node* left;
	node* right;
	node(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

void printNode(node* tree) {
	if (tree == nullptr) {
		return;
	}
	cout << tree->data << " ";
	if (tree->left)
	{
		printNode(tree->left);
	}
	if (tree->right)
	{
		printNode(tree->right);
	}
	
}
void showNodeIn(node* tree) {
	if (tree == nullptr) {
		return;
	}
	if (tree->left)
	{
		showNodeIn(tree->left);
	}
	cout << tree->data << " ";
	if (tree->right)
	{
		showNodeIn(tree->right);
	}
}
void showNodePost(node* tree) {
	if (tree == nullptr) {
		return;
	}
	if (tree->left)
	{
		showNodePost(tree->left);
	}
	if (tree->right)
	{
		showNodePost(tree->right);
	}
	cout << tree->data << " ";
}

//zad1
bool search(node* tree, int x) {

	if (!tree) 
	{
		return false;
	}

	if (tree->data == x) 
	{
		return true;
	}
	if (search(tree->left, x))
	{
		return true;
	}
	return search(tree->right, x);
}

//zad 2.a
int node_count(node* tree) {
	if (tree == nullptr) {
		return 0;
	}
	if (tree->left != nullptr || tree->right != nullptr)
	{
		return 1 + node_count(tree->left) + node_count(tree->right);
	}
	return 0;
}

//zad 2.b
int leaves_count(node* tree) {
	if (tree == nullptr) {
		return 0;
	}
	if (tree->left == nullptr && tree->right == nullptr)
	{
		return 1;
	}
	else
	{
		return leaves_count(tree->left) + leaves_count(tree->right);
	}
	return 0;


}

//zad 2.c
int right_children_count(node* tree) {
	if (tree == nullptr) {
		return 0;
	}
	if (tree->right != nullptr)
	{
		if (tree->left != nullptr)
		{
			return 1 + right_children_count(tree->left) + right_children_count(tree->right);
		}
		return 1 +  right_children_count(tree->right);
	}
	return 0;
}

//zad 2.d
int tree_height(node* tree) {
	if (!tree) {
		return 0;
	}
	return max(tree_height(tree->left), tree_height(tree->right)) + 1;
}

//zad 3
bool is_balanced(node* tree) 
{
	int lh; 
	int rh; 

	if (tree == NULL)
		return 1;

	lh = tree_height(tree->left);
	rh = tree_height(tree->right);

	if (abs(lh - rh) <= 1 && is_balanced(tree->left) && is_balanced(tree->right))
		return 1;

	return 0;
}

//zad 4
bool is_BST(node* tree) {
	if (tree == nullptr)
	{
		return true;
	}
	if (tree->left != nullptr && tree->left->data > tree->data)
	{
		return false;
	}
	if (tree->right != nullptr && tree->right->data < tree->data)
	{
		return false;
	}
	if (!is_BST(tree->left) || !is_BST(tree->right))
	{
		return false;
	}
	return true;
}

//zad 5
bool is_Leaf(node* node)
{
	if (node->left == nullptr && node->right == nullptr)
	{
		return true;
	}
	return false;
}

void delete_leaves(node* tree) {
	if (tree)
	{
		if (is_Leaf(tree->left))
		{
			delete (tree->left);
			tree->left = nullptr;
		}
		else
		{
			delete_leaves(tree->left);
		}
		if (is_Leaf(tree->right))
		{
			delete (tree->right);
			tree->right = nullptr;
		}
		else
		{
			delete_leaves(tree->right);
		}
	}
}


//zad 6
void preorder(node* tree) {
	if (tree == nullptr) {
		return;
	}
	if (tree->left != 0 && tree->data - tree->left->data < 2) {
		tree->left->data += 2;
	}
	preorder(tree->left);
	preorder(tree->right);
	
}
void inorder(node* tree) {
	if (tree == nullptr) {
		return;
	}
	inorder(tree->left);
	if (tree->left != 0 && tree->data - tree->left->data < 2) {
		tree->left->data += 2;
	}
	inorder(tree->right);
}
void postorder(node* tree) {
	if (tree == nullptr) {
		return;
	}
	postorder(tree->left);
	postorder(tree->right);
	if (tree->left != 0 && tree->data - tree->left->data < 2) {
		tree->left->data += 2;
	}
}

void preorderB(node*& tree) {
	if (tree == nullptr) {
		return;
	}
	if (tree->left == 0) {
		tree->right = 0;
	}
	preorderB(tree->left);
	preorderB(tree->right);
}
void inorderB(node*& tree) {
	if (tree == nullptr) {
		return;
	}
	inorderB(tree->left);
	if (tree->left == 0) {
		tree->right = 0;
	}
	inorderB(tree->right);
}
void postorderB(node*& tree) {
	if (tree == nullptr) {
		return;
	}
	postorderB(tree->left);
	postorderB(tree->right);
	if (tree->left == 0) {
		tree->right = 0;
	}
}

//zad 8
node* mirror_tree(node* tree) {
	if (tree != nullptr) {
		node* tmp = new node(tree->data);
		tmp->left = mirror_tree(tree->right);
		tmp->right = mirror_tree(tree->left);
		return tmp;
	}
	return nullptr;
	
}

//zad 9
void print_tree(node* tree, int depth = 0) {
	if (tree == nullptr) {
		depth--;
		return;
	}
	if (depth != 0) {
		for (int i = 0; i < depth; ++i) {
			cout << ".";
		}
	}
	cout << tree->data << endl;
	depth++;
	print_tree(tree->left, depth);
	print_tree(tree->right, depth);
}


struct node_calc {
	char op;
	int number;
	node_calc* left;
	node_calc* right;
};

double eval(node_calc* tree)
{
	if (tree)
	{
		if (tree->op)
		{
			if (tree->op == '*')
			{
				return eval(tree->left) * eval(tree->right);
			}
			if (tree->op == '/')
			{
				return eval(tree->left) / eval(tree->right);
			}
			if (tree->op == '-')
			{
				return eval(tree->left) - eval(tree->right);
			}
			if (tree->op == '+')
			{
				return eval(tree->left) + eval(tree->right);
			}
		}
		else
		{
			return tree->number;
		}

	}
	return 0;
}

int main() {

	node* drzewo = new node(1);
	drzewo->left = new node(3);
	drzewo->right = new node(2);
	drzewo->left->left = new node(4);
	drzewo->left->right = new node(5);


	printNode(drzewo);
	if (search(drzewo, 3)) {
		cout << "jest" << endl;
	}
	else {
		cout << "nie jest" << endl;
	}
	cout << "wierzcholki " << node_count(drzewo) << endl;
	cout << "liscie " << leaves_count(drzewo) << endl;
	cout << "prawi " << right_children_count(drzewo) << endl;
	cout << "wysokosc " << tree_height(drzewo) << endl;
	if (is_balanced(drzewo) == true) {
		cout << "jest zbalansowane" << endl;
	}
	else {
		cout << "nie jest zbalansowane" << endl;
	}
	if (is_BST(drzewo) == true) {
		cout << "jest BST" << endl;
	}
	else {
		cout << "nie jest BST" << endl;
	}
	delete_leaves(drzewo);
	printNode(drzewo);

	cout << endl << "----------" << endl;


	node* tree = new node(10);
	tree->left = new node(5);
	tree->left->left = new node(4);
	tree->left->left->left = new node(0);
	tree->left->right = new node(6);
	tree->left->right->right = new node(7);
	tree->left->right->right->right = new node(9);
	tree->right = new node(20);
	tree->right->left = new node(15);
	tree->right->left->left = new node(13);
	tree->right->right = new node(30);


	// a
	cout << endl << "przed ";
	printNode(tree);
	preorder(tree);
	cout << endl << "pre   ";
	printNode(tree);
	inorder(tree);
	cout << endl << "in    ";
	showNodeIn(tree);
	postorder(tree);
	cout << endl << "post  ";
	showNodePost(tree);

	// b

	cout << endl << "-----------";

	node* tree2 = new node(10);
	tree2->left = new node(5);
	tree2->left->left = new node(4);
	tree2->left->left->left = new node(0);
	tree2->left->right = new node(6);
	tree2->left->right->right = new node(7);
	tree2->left->right->right->right = new node(9);
	tree2->right = new node(20);
	tree2->right->left = new node(15);
	tree2->right->left->left = new node(13);
	tree2->right->right = new node(30);

	cout << endl << "przed ";
	printNode(tree2);
	preorderB(tree2);
	cout << endl << "pre   ";
	printNode(tree2);
	inorderB(tree2);
	cout << endl << "in    ";
	showNodeIn(tree2);
	postorderB(tree2);
	cout << endl << "post  ";
	showNodePost(tree2);
	cout << endl;

	//zadanie 7
	//drzewo musi nie mieć prawych synow
	node* tree4 = new node(1);
	tree4->right = new node(4);
	tree4->right->right = new node(5);
	printNode(tree4);
	cout << endl;
	showNodeIn(tree4);

	//zad 8

	node* tree3 = new node(1);
	tree3->left = new node(2);
	tree3->right = new node(3);
	tree3->left->left = new node(4);
	cout << endl << "przed ";
	printNode(tree3);
	node * mirrored_tree3 = mirror_tree(tree3);
	cout << endl << "po ";
	printNode(mirrored_tree3);

	cout << endl;
	print_tree(tree2);

	node_calc* calc_tree = new node_calc();
	calc_tree->op = '*';
	calc_tree->left = new node_calc();
	calc_tree->left->op = '+';
	calc_tree->right = new node_calc();
	calc_tree->right->op = '-';
	calc_tree->left->left = new node_calc();
	calc_tree->left->right = new node_calc();
	calc_tree->right->left = new node_calc();
	calc_tree->right->right = new node_calc();

	calc_tree->left->left->number = 7;
	calc_tree->left->right->number = 8;
	calc_tree->right->left->number = 3;
	calc_tree->right->right->number = 2;

	cout << eval(calc_tree) << endl;
	return 0;
}


