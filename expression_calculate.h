#ifndef DS_TREE_EXPRESSION_CALCULATE_H
#define DS_TREE_EXPRESSION_CALCULATE_H

#include <string>
#include "tree_node.hpp"

bool is_digit(char c);
bool is_op(char c);
int priority(char c);

double read_number(const std::string &s, size_t &i);

std::string infix_to_suffix(const std::string &s);

double cal_single(const double &a, const double &b, const char &op);
double cal_suffix(const std::string &s);

TreeNode<std::string> * suffix_to_exp_tree(std::string suffix);

#endif //DS_TREE_EXPRESSION_CALCULATE_H
