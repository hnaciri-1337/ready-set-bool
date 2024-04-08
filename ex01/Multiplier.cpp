/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Multiplier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:18:02 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/30 10:40:32 by hnaciri-         ###   ########.fr       */
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

uint32_t multiplier(uint32_t a, uint32_t b) {
	uint32_t	_result = 0;

	while (b != 0) {
		uint32_t	bBit = b & 1;
		b = b >> 1;

		if (bBit == 1)
			_result = adder(_result, a);

		a = a << 1;
	}
	return _result;
}

int	main() {
	cout << "40 * 19 = " << 40 * 19 << endl;
	cout << "585 * 9843 = " << 585 * 9843 << endl;
	cout << "89256 * 745 = " << 89256 * 745 << endl;

	cout << "-------------------------------" << endl;

	cout << "40 * 19 = " << multiplier(40, 19) << endl;
	cout << "585 * 9843 = " << multiplier(585, 9843) << endl;
	cout << "89256 * 745 = " << multiplier(89256, 745) << endl;

	if (40 * 19 != multiplier(40, 19) || 585 * 9843 != multiplier(585, 9843) || 89256 * 745 != multiplier(89256, 745))
		cout << "Error : The results are not equal" << endl;
	else
		cout << "The results are equal" << endl;
}