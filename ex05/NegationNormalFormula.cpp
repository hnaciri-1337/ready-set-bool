/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NegationNormalFormula.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:00:00 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/02/13 17:07:24 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

void	apply_operation(stack<bool> &_stack, char operation) {
	bool	a = _stack.top();
	_stack.pop();

	switch (operation)
	{
		case '!':
			_stack.push(!a);
			break;

		case '&':
			_stack.top() = a & _stack.top();
			break;

		case '|':
			_stack.top() = a | _stack.top();
			break;

		case '^':
			_stack.top() = a ^ _stack.top();
			break;

		case '>':
			_stack.top() = !_stack.top() | a;
			break;

		case '=':
			_stack.top() = _stack.top() == a;
			break;

		default:
			throw invalid_argument(string("Invalide character detected: ") + operation);
	}
}

bool	eval_formula(string const &str) {
	stack <bool>	_stack;

	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] == '0' || str[i] == '1')
			_stack.push(str[i] - 48);
		else {
			if (_stack.size() == 0 || (_stack.size() == 1 && str[i] != '!'))
				throw invalid_argument("Invalid RPN formula");
			apply_operation (_stack, str[i]);
		}
	}
	if (_stack.size() != 1)
		throw invalid_argument("Invalid RPN formula");
	return _stack.top();
}

string	generate_formula(string formula, vector<bool> const &assignment) {
	for (size_t i = 0; i < assignment.size(); ++i)
		replace(formula.begin(), formula.end(), (char)('A' + i), (assignment[i]) ? '1' : '0');
	return formula;
}

void	make_string_consecutive(string &s) {
	vector<char>	exist, not_exist;
	int				hash_table[26];

	memset(hash_table, 0, 26 * 4);
	for (size_t i = 0; i < s.size(); i++)
        if (isalpha(s[i]))
			hash_table[s[i] - 'A'] = 1;

	for (size_t i = 0; i < 26; i++)
		(hash_table[i] == 1) ? exist.push_back((char)('A' + i)) : not_exist.push_back((char)('A' + i));

	for (size_t i = 0; i < exist.size();) {
		if (exist[i] > not_exist[0]) {
			replace(s.begin(), s.end(), exist[i], not_exist[0]);
			exist.erase(exist.begin() + i);
			exist.push_back(not_exist[0]);
			not_exist.erase(not_exist.begin());
			not_exist.push_back(exist[i]);
			sort(exist.begin(), exist.end());
			sort(not_exist.begin(), not_exist.end());
		}
		else
			i++;
	}
}

void	print_truth_table(string formula) {
    set<char>	variables_set;
    
    for (size_t i = 0; i < formula.size(); i++)
        if (isalpha(formula[i]))
            variables_set.insert(formula[i]);

    size_t			num_variables = variables_set.size();
	size_t			total_rows = 1 << num_variables;
    vector<bool>	assignment(num_variables, false);


    cout << "| ";
	for (set<char>::iterator it = variables_set.begin(); it != variables_set.end(); it++)
    	cout << *it << " | ";
    cout << "= |" << endl;
	
    cout << "|";
    for (size_t i = 0; i < num_variables; ++i)
        cout << "---|";
    cout << "---|" << endl;

	make_string_consecutive(formula);

	for (size_t row = 0; row < total_rows; row++) {
		for (size_t var = 0; var < num_variables; var++) {
			assignment[var] = ((row & (1 << var)) ? true : false);
            cout << "| " << assignment[var] << " ";
		}
        cout << "| " << eval_formula(generate_formula(formula, assignment)) << " |" << endl;
	}
}

bool isOperator(char c) {
    return c == '!' || c == '&' || c == '|';
}

string negation_normal_form(string formula) {
    stack<string> stack;
    for (char c : formula) {
        if (!isOperator(c)) {
            stack.push(string(1, c));
        } else {
            if (c == '!') {
                if (stack.empty()) {
                    cerr << "Invalid input formula!" << endl;
                    exit(1);
                }
                string operand = stack.top();
                stack.pop();
                stack.push("!" + operand);
            } else {
                if (stack.size() < 2) {
                    cerr << "Invalid input formula!" << endl;
                    exit(1);
                }
                string operand2 = stack.top();
                stack.pop();
                string operand1 = stack.top();
                stack.pop();
                stack.push(operand1 + c + operand2);
            }
        }
    }
    if (stack.size() != 1) {
        cerr << "Invalid input formula!" << endl;
        exit(1);
    }
    return stack.top();
}

int main() {
	cout << negation_normal_form("AB&!") << endl;
	print_truth_table("AB&!");
	print_truth_table(negation_normal_form("AB&!"));

	// cout << negation_normal_form("AB&!") << endl;
	// // A!B!|
	// cout << negation_normal_form("AB|!") << endl;
	// // A!B!&
	// cout << negation_normal_form("AB>") << endl;
	// // A!B|
	// cout << negation_normal_form("AB=") << endl;
	// // AB&A!B!&|
	// cout << negation_normal_form("AB|C&!") << endl;
	// // A!B!&C!|

    return 0;
}
