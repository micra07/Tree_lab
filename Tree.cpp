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

	vector<int> vec1 = { 3, 2, 2, 4 };
	vector<int> vec2 = { 1, 2, 3, 4, 5, 6, 7, 1, 3, 4, 7 };
	vector<int> vec3 = { 1, 1 };

	vector<int> for_task1 = delete_repeat(vec1);
	vector<int> for_task2 = delete_repeat(vec2);
	vector<int> for_task3 = delete_repeat(vec3);

	print(for_task1);
	print(for_task2);
	print(for_task3);

	return 0;
}