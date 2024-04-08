/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BooleanEvaluation.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:10:28 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/31 14:57:15 by hnaciri-         ###   ########.fr       */
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

int	main() {
	try
	{
		cout << eval_formula("10&") << endl;
		cout << eval_formula("10|") << endl;
		cout << eval_formula("11>") << endl;
		cout << eval_formula("10=") << endl;
		cout << eval_formula("1011||=") << endl;

		cout << eval_formula("101018001||=") << endl;
		cout << eval_formula("10101001||=") << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
