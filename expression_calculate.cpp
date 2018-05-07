#include "expression_calculate.h"
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using std::string;
using std::stack;
using std::cin;
using std::cout;
using std::endl;

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

double read_number(const std::string &s, std::size_t &i) {
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
				num += std::to_string((int)read_num);
			else
				num += std::to_string(read_num);
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

void prefix_to_infix(stack<char> &s, string &str) {
	char temp;
	while (1) {
		temp = s.top();
		s.pop();
		if (temp != ' ')
			break;
	}

	if (is_op(temp)) {
		str.append("(");
		prefix_to_infix(s, str);
		str.append(1, temp);
		prefix_to_infix(s, str);
		str.append(")");
	}
	else if (is_digit(temp)){
		while (1) {
			str.append(std::to_string(temp-'0'));
			if (!s.empty() && is_digit(s.top())) {
				temp = s.top();
				s.pop();
			} else {
				break;
			}
		}
	}
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

TreeNode<string> *suffix_to_exp_tree(string suffix) {
	stack< TreeNode<string>* > s;
	for (size_t i = 0; i < suffix.size(); i++) {
		if (is_digit(suffix[i])) {
			double temp = read_number(suffix, i);
			string temp_s;
			if ((int)temp == temp)
				temp_s = std::to_string((int)temp);
			else
				temp_s = std::to_string(temp);
			TreeNode<string>* tn = new TreeNode<string>(temp_s);
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
