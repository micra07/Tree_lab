
#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int _data;
	Node* _left;
	Node* _right;
	Node(int data) : _data(data), _left(nullptr), _right(nullptr) {};
};

class Tree {
	Node* _root;

	void print(const Node* root) {
		if (!root) return;
		print(root->_left);
		cout << root->_data << " ";
		print(root->_right);
	}

	void remove(int key) {
		Node* current = _root;
		Node* prev = nullptr;

		while (current && current->_data != key) {
			prev = current;
			if (key < current->_data) {
				current = current->_left;
			}
			else {
				current = current->_right;
			}
		}

		if (!current) return;

		if (!current->_left) {
			if (!prev) {
				_root = current->_right;
			}
			else if (prev->_left == current) {
				prev->_left = current->_right;
			}
			else {
				prev->_right = current->_right;
			}
			delete current;
		}
		else if (!current->_right) {
			if (!prev) {
				_root = current->_left;
			}
			else if (prev->_left == current) {
				prev->_left = current->_left;
			}
			else {
				prev->_right = current->_left;
			}
			delete current;
		}
		else {
			Node* replacement = current->_right;
			prev = nullptr;

			while (replacement->_left) {
				prev = replacement;
				replacement = replacement->_left;
			}

			current->_data = replacement->_data;

			if (prev) {
				if(replacement->_right){ 
					prev->_left = replacement->_right; 
				}
			}
			else {
				current->_right = replacement->_right;
			}

			delete replacement;
		}
	}


	void clear(Node* root) {
		if (root) {
			clear(root->_left);
			clear(root->_right);
			remove(root->_data);
		}
		return;
	}

	void clear_tree() {
		clear(_root);
	}

	void add(int key) {
		if (!_root) {
			_root = new Node(key);
			return;
		}
		Node* current = _root;
		while (current) {
			if (key < current->_data && !current->_left) {
				current->_left = new Node(key);
				return;
			}
			if (key > current->_data && !current->_right) {
				current->_right = new Node(key);
				return;
			}
			if (key < current->_data) {
				current = current->_left;
			}
			else current = current->_right;

		}
	}

	void copy(Node* original_root) {
		if (!original_root) return;
		add(original_root->_data);
		copy(original_root->_left);
		copy(original_root->_right);
	}

public:
	Tree() : _root(nullptr) {};

	Tree(const Tree& other) {
		_root = nullptr;
		if (other._root) {
			copy(other._root);
		}
	}

	Tree operator=(const Tree& other) {
		clear_tree();
		if (other._root) {
			copy(other._root);
		}
	}

	~Tree() {
		clear_tree();
	}

	void print() {
		if (!_root) {
			cout << "BinaryTree is empty" << endl;
		}
		else {
			cout << "Elements of BinaryTree:" << endl;
			print(_root);
			cout << endl << endl;
			return;
		}
	}

	bool insert(int key) {
		if (contains(key)) return false;
		else {
			add(key);
			return true;
		}
	}

	bool contains(int key) {
		Node* current = _root;
		while (current) {
			if (key == current->_data) return true;
			if (key < current->_data) {
				current = current->_left;
			}
			else {
				current = current->_right;
			}
		}
		return false;
	}

	bool erase(int key) {
		if (contains(key)) {
			remove(key);
			return true;
		}
		return false;

	}
};

std::vector<int> delete_repeat(std::vector<int> vec) {
	std::vector<int> unique_elements;
	std::vector<int> result;

	for (int i = 0; i < vec.size(); ++i) {
		if ((std::count(unique_elements.begin(), unique_elements.end(), vec[i]) == 0)) {
			unique_elements.push_back(vec[i]);
			result.push_back(vec[i]);
		}
		else {
			result.erase(std::remove(result.begin(), result.end(), vec[i]), result.end());
		}
	}

	return result;
}
