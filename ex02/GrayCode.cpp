/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GrayCode.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:45:08 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/30 11:00:49 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

uint32_t gray_code(uint32_t n) {
	return n ^ n >> 1;
}

int	main() {
	cout << "gray_code(5) = " << gray_code(5) << endl;
	cout << "gray_code(9) = " << gray_code(9) << endl;
	cout << "gray_code(950) = " << gray_code(950) << endl;
	cout << "gray_code(1589) = " << gray_code(1589) << endl;
}
