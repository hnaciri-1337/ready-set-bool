/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Adder.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:45:08 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/29 18:54:36 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

uint32_t adder(uint32_t a, uint32_t b) {
	uint32_t	_sum = 0;
	uint32_t	_bit = 1;

	while (a != 0 || b != 0) {
		uint32_t	aBit = a & 1, bBit = b & 1;
		a = a >> 1, b = b >> 1;

		if (aBit && bBit) {
			_sum = _sum | _bit << 1;
		}
		else {
			if ((_sum & _bit) == 0) {
				if (aBit || bBit) {
					_sum = _sum | _bit;
				}
			}
			else {
				if (aBit || bBit) {
					_sum = _sum ^ _bit;
					_sum = _sum | _bit << 1;
				}
			}
		}
		_bit = _bit << 1;
	}
	return _sum;
}

int	main() {
	cout << "19 + 40 = " << 19 + 40 << endl;
	cout << "58415 + 982543 = " << 58415 + 982543 << endl;
	cout << "895484256 + 754845 = " << 895484256 + 754845 << endl;

	cout << "-------------------------------" << endl;

	cout << "19 + 40 = " << adder(19, 40) << endl;
	cout << "58415 + 982543 = " << adder(58415, 982543) << endl;
	cout << "895484256 + 754845 = " << adder(895484256, 754845) << endl;

	if (19 + 40 != adder(19, 40) || 58415 + 982543 != adder(58415, 982543) || 895484256 + 754845 != adder(895484256, 754845))
		cout << "Error : The results are not equal" << endl;
	else
		cout << "The results are equal" << endl;
}
