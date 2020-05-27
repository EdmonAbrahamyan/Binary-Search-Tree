#include "SearchTree.h"
#include <string>

void
SearchTree::clear(const Node* tree)
{
	if (tree)
	{
		clear(tree->llink_);
		clear(tree->rlink_);
		delete tree;
	}
}

void
SearchTree::print(const Node* tree, int indent)
{
	if (tree == 0) return;

	print(tree->rlink_, indent + 5);
	cout << string(indent, ' ') << tree->key_ << endl;
	print(tree->llink_, indent + 5);
}


SearchTree::Node*
SearchTree::search1(int key) const
{
	Node* current = tree_;
	while (current)
	{
		if (current->key_ == key)
			return current;
		current = (key < current->key_) ? current->llink_ : current->rlink_;
	}
	return 0;
}

void
SearchTree::insert(int key)
{
	if (!tree_) 
	{
		tree_ = new Node(key); 
		return; 
	}

	Node* prevPtr = nullptr;
	Node* runningPtr = tree_;
	while (runningPtr) {
		prevPtr = runningPtr;
		if (runningPtr->key_ > key)
			runningPtr = runningPtr->llink_;
		else
			runningPtr = runningPtr->rlink_;
	}
	if (prevPtr->key_ > key)  
		prevPtr->llink_ = new Node(key, 0, 0, prevPtr);
	else 
		prevPtr->rlink_ = new Node(key, 0, 0, prevPtr);
}

void
SearchTree::remove(int key)
{
	Node* rNode = search1(key);
	if (rNode) 
	{
		Node* parent = rNode->parent_;
		if (!(rNode->llink_)) 
		{  // left link = NULL;
			if (!parent) 
				tree_ = rNode->rlink_;
			else if (parent->llink_ == rNode) 
				parent->llink_ = rNode->rlink_;
			else
				parent->rlink_ = rNode->rlink_;
			if (rNode->rlink_)
				rNode->rlink_->parent_ = parent;
			delete rNode; 
			rNode = nullptr;
		}
		else if (!(rNode->rlink_)) 
		{  // right link = NULL
			if (!parent) 
				tree_ = rNode->llink_;
			else if (parent->llink_ == rNode) 
				parent->llink_ = rNode->llink_;
			else 
				parent->rlink_ = rNode->llink_;
			if (rNode->llink_)
				rNode->llink_->parent_ = parent;
			delete rNode; 
			rNode = nullptr;
		}
		else 
		{ // left and right links != NULL
			Node* runningPtr = rNode->llink_;
			while (runningPtr->rlink_)
				runningPtr = runningPtr->rlink_;
			rNode->key_ = runningPtr->key_;
			rNode = runningPtr; 
			parent = rNode->parent_;
			if (!parent) 
				tree_ = rNode->llink_;
			else if (parent->llink_ == rNode) 
				parent->llink_ = rNode->llink_;
			else 
				parent->rlink_ = rNode->llink_;
			if (rNode->llink_)
				rNode->llink_->parent_ = parent;
			delete rNode; 
			rNode = nullptr;
		}
		while (parent)
		{
			parent = parent->parent_;
		}
	}
}
