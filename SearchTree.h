#pragma once
#include <iostream>
using namespace std;


class SearchTree {
	struct Node {
		int 	key_;
		Node* llink_;
		Node* rlink_;
		Node* parent_;
		Node(int key = 0, Node * llink = 0, Node * rlink = 0, Node * parent = 0) :
			key_(key), llink_(llink), rlink_(rlink), parent_(parent) {}
	};

	static  void	clear(const Node* tree);
	static	void	print(const Node* tree, int indent = 0);
	Node* search1(int key) const;

public:
	SearchTree() :tree_(0) {}							
	~SearchTree() { clear(tree_); }		

	bool	search(int key) const { return	search1(key) != 0; }

	void	insert(int key);		

	void	remove(int key);	

	void print()const 
	{
		cout << "- - - - - - - - - -" << endl;
		print(tree_);
		cout << "- - - - - - - - - -" << endl;
	}
private:
	Node* tree_;
};

