#include <iostream>

using namespace std;


class Tree
{
	Tree* left ;
	Tree* right ;
public:
	int num;
	Tree(int val): num(val){
		left = nullptr;
		right = nullptr;
	}
	

	void Add( int val) {
		if (left == nullptr && val < num)
		{
			left = new Tree( val);

		}
		else if (right == nullptr&& val > num) {
			right = new Tree( val);
		}

		else {
			if (left->num < right->num)
			{
				left->Add(val);
			}
			else {
				right->Add( val);
			}
		}


	}
	void del(int val) {
		if (val == num&& left != nullptr) {
			num = left->num;
			if (left->left != nullptr) {

				left = left->left;
				delete left->left;
			}
			else {
				delete left;
			}
			
		}
		else if (val == num && right != nullptr) {
			num = right->num;
			if (right->left != nullptr) {

				right = right->left;
				delete right->left;
			}
			else {
				delete right;
			}
		}
		else if (val < num && left != nullptr&& left->left== nullptr&& left->right == nullptr) {
			delete left;
		}
		else if (val > num && right != nullptr && right->left == nullptr && right->right == nullptr) {
			delete right;
		}
		else if (val < num && left != nullptr) {
			left->del(val);
		}
		else if (val > num && right != nullptr) {
			right->del(val);
		}
	}

};



void main() {
	Tree tr(5);
	tr.Add(4);
	tr.Add(6);
	tr.del(7);

}