#include <vector>
#include <iostream>
#include "Tree.h"
#include <ctime>

using namespace std;

void print(vector<int> vec) {
	if (vec.size() == 0) {
		cout << "Vector is empty." << endl;
	}
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

vector<int> _random_vector(int size, int i) {
	std::vector<int> vector;
	srand(i);
	for (int i = 0; i < size; ++i) {
		vector.push_back(rand());
	}
	return vector;
}

Tree _random_tree(int size, int i) {
	Tree tree;
	srand(i);
	for (int i = 0; i < size; ++i) {
		tree.insert(rand());
	}
	return tree;
}



int main()
{
	Tree tree;
	tree.insert(0);
	tree.insert(1);
	tree.insert(3);
	tree.insert(2);
	tree.insert(4);
	tree.insert(-1);

	tree.print();

	tree.erase(3);
	tree.erase(4);
	tree.erase(2);
	tree.erase(-10);
	tree.erase(0);

	tree.print();

	Tree tree2(tree);

	tree2.print();
	tree2.insert(3);

	Tree tree3 = tree2;
	tree3.print();

	int count = 1000;
	int insert_count = 100;
	int length = 1000;

	int time_vec = 0;
	int time_tree = 0;

	for (int i = 0; i < insert_count; ++i) {
		int start_time = clock();
		vector<int> vec = _random_vector(length, i);
		time_vec += clock();
	}

	for (int i = 0; i < insert_count; ++i) {
		int start_time = clock();
		Tree tree_stat = _random_tree(length, i);
		time_tree += clock();
	}

	cout << "Vector insert time: " << double(time_vec) / count << "ms" << endl;
	cout << "Tree insert time: " << double(time_tree) / count << "ms" << endl;

	vector<int> vector = _random_vector(length, 0);
	Tree tree_stat = _random_tree(length, 0);


	for (int i = 0; i < count; ++i) {
		int start_time = clock();
		srand(i);
		std::find(vector.begin(), vector.end(), rand());
		time_vec += clock();
	}

	for (int i = 0; i < count; ++i) {
		int start_time = clock();
		srand(i);
		tree_stat.contains(rand());
		time_tree += clock();
	}

	cout << "Vector search time: " << double(time_vec) / count << "ms" << endl;
	cout << "Tree search time: " << double(time_tree) / count << "ms" << endl;

	for (int i = 0; i < count; ++i) {
		int start_time = clock();
		srand(i);
		vector.push_back(rand());
		auto found = std::find(vector.begin(), vector.end(), rand());
		if (found != vector.end()) {
			vector.erase(found);
		}
		time_vec += clock();
	}

	for (int i = 0; i < count; ++i) {
		int start_time = clock();
		srand(i);
		tree_stat.insert(rand());
		tree_stat.erase(rand());
		time_tree += clock();
	}

	cout << "Vector insert and delete time time: " << double(time_vec) / count << "ms" << endl;
	cout << "Tree insert and delete time: " << double(time_tree) / count << "ms" << endl;

	return 0;
}