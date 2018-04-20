#include <iostream>
#include <cstdio>
#include <stack>
#include <cmath>
#include <string>
#include "binary_tree.hpp"
#include "express_tree.hpp"
using namespace std;

bool is_digit(char c) {
	return ('0' <= c && c <= '9');
}

bool is_op(char c) {
	return (c == '+' || c == '-'
			|| c == '*' || c == '/'
			|| c == '(' || c == ')');
}

int priority(char c) {
	if (c == '+' || c == '-')
		return 1;
	else // '*' and '/'
		return 2;
}

double read_number(const string &s, size_t &i) {
	double ans = 0;
	while (is_digit(s[i])) {
		ans = ans * 10 + s[i] - '0';
		i++;
	}
	if (s[i] == '.') {
		int point = 0;
		i++;
		while (is_digit(s[i])) {
			ans = ans * 10 + s[i] - '0';
			i++;
			point++; // remember point pos
		}
		ans /= pow(10, point);
	}
	i--;
	return ans;
}

string infix_to_suffix(const string &s) {
	string num;
	stack<char> op;
	for (size_t i = 0; i < s.size(); ++i) {
		if (s[i] == ' ') // ignore space
			continue;
		else if (is_digit(s[i])) {
			double read_num = read_number(s, i);
			if ((int)read_num == read_num) // if value is int
				num += to_string((int)read_num);
			else
				num += to_string(read_num);
			num.push_back(' '); // separate by space
		}
		else if (is_op(s[i]))
		{
			if (s[i] == ')')
			{
				if (op.empty()) {
					cout << "illegal expression" << endl;
					return "";
				}
				while (op.top() != '(') {
					num.push_back(op.top());
					num.push_back(' '); // separate by space
					op.pop();
				}
				op.pop(); // pop '('
			}
			else if (op.empty() || op.top() == '(' || s[i] == '(' ||
					 priority(s[i]) > priority(op.top()))
				op.push(s[i]);
			else
			{	// pop until meets '(' , or op.empty, or priorty meets
				while (1)
				{
					num.push_back(op.top());
					num.push_back(' '); // separate by space
					op.pop();
					if (op.empty() || op.top() == '(' ||
						priority(s[i]) > priority(op.top())) {
						op.push(s[i]);
						break;
					}
				}
			}
		}
		else
		{
			cout << "illegal expression" << endl;
			return "";
		}
	}
	while (!op.empty()) {
		num.push_back(op.top());
		op.pop();
	}
	return num;
}

double cal_single(const double &a, const double &b, const char &op) {
	if (op == '+')
		return a + b;
	else if (op == '-')
		return a - b;
	else if (op == '*')
		return a * b;
	else if (op == '/')
		return a / b;
}

double cal_suffix(const string &s) {
	stack<double> num;
	stack<char> op;
	for (size_t i = 0; i < s.size(); i++) {
		if (is_digit(s[i])) {
			num.push(read_number(s, i));
		}
		else if (is_op(s[i])) {
			double a = num.top();
			num.pop();
			double b = num.top();
			num.pop();
			double ans = cal_single(b, a, s[i]);
			num.push(ans);
		}
	}

	return num.top();
}

TreeNode<string> * suffix_to_exp_tree(string suffix) {
	stack< TreeNode<string>* > s;
	for (size_t i = 0; i < suffix.size(); i++) {
		if (is_digit(suffix[i])) {
			TreeNode<string>* tn = new TreeNode<string>(string(1, suffix[i]));
			s.push(tn);
		}
		else if (is_op(suffix[i])) {
			TreeNode<string> *temp = new TreeNode<string>(string(1, suffix[i]));
			temp->add_right(s.top());
			s.pop();
			temp->add_left(s.top());
			s.pop();
			s.push(temp);
		}
	}
	return s.top();
}

int main() {
//	freopen("input.txt", "r", stdin);
	string infix_exp, suffix_exp;
	getline(cin, infix_exp);
	suffix_exp = infix_to_suffix(infix_exp);
	TreeNode<string>* exp_tree_root = suffix_to_exp_tree(suffix_exp);
	BinaryTree<string> bt(exp_tree_root);
	bt.level_order();
	ExpressTree<string> et(exp_tree_root);
	et.print_like_tree();

//	cout << bt.get_tree_height(exp_tree_root) << endl;




	return 0;
}