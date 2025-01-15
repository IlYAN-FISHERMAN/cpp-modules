/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:24:26 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/15 14:04:47 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cstdlib>
#include <cstring>


int main()
{
	srand(time(0));
	int array_len = 10;
	int* tmp1 = new int[array_len];
	double* tmp2 = new double[array_len];
	float* tmp3 = new float[array_len];

	for (int i = 0; i < array_len; i++){
		tmp1[i] = rand() % 100;
		tmp2[i] = (rand() % 100);
		tmp2[i] += tmp2[i] / 100.0 * 2.4241;
		tmp3[i] = rand() % 100;
		tmp3[i] += tmp3[i] / 100.0f * 2.44422f;
	}
	iter(tmp1, array_len, ::display);
	std::cout << std::endl;
	iter(tmp1, array_len, divise);
	std::cout << std::endl;
	iter(tmp2, static_cast<double>(array_len), ::display);
	std::cout << std::endl;
	iter(tmp2, static_cast<double>(array_len), divise);
	std::cout << std::endl;
	iter(tmp3, static_cast<float>(array_len), ::display);
	std::cout << std::endl;
	iter(tmp3, static_cast<float>(array_len), divise);
	std::cout << std::endl;

	delete [] tmp1;
	delete [] tmp2;
	delete [] tmp3;
}
