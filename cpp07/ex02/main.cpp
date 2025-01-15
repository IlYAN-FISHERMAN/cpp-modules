/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:09:00 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/15 12:14:24 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#include <exception>

int main(){
	srand(time(0));

	Array<int> x(5);
	Array<int> empty;
	Array<double> arrayD(5);
	Array<double> arrayD_tmp(5);

	std::cout << x.size() << std::endl;
	std::cout << empty.size() << std::endl;
	std::cout << x.size() << std::endl;
	std::cout << std::endl;

	try{
		std::cout << "x before" << std::endl;
		for (int i = 0; i < x.size(); i++)
			std::cout << x[i] << std::endl;
		std::cout << "x after" << std::endl;
		for (int i = 0; i < x.size(); i++){
			x[i] = rand() % 100;
			std::cout << x[i] << std::endl;
		}
	}
	catch (std::exception &other){
		std::cout << other.what() << std::endl;
	}
	std::cout << std::endl;

	try{
		std::cout << "x" << std::endl;
		for (int i = 0; i < x.size(); i++)
			std::cout << x[i] << std::endl;
		std::cout << std::endl;
		empty = x;
		std::cout << std::endl;
		std::cout << "empty after" << std::endl;
		for (int i = 0; i < empty.size(); i++)
			std::cout << empty[i] << std::endl;
	}
	catch (std::exception &other){
		std::cout << other.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	try{
		std::cout << std::endl;
		std::cout << "arrayD before" << std::endl;
		for (int i = 0; i < arrayD.size(); i++)
			std::cout << arrayD[i] << std::endl;
		std::cout << "arrayD after" << std::endl;
		for (int i = 0; i < arrayD.size(); i++){
			arrayD[i] = rand() % 100;
			arrayD[i] += arrayD[i] / 100 * 2;
			std::cout << arrayD[i] << std::endl;
		}
		std::cout << std::endl;
		std::cout << "arrayD_tmp before" << std::endl;
		for (int i = 0; i < arrayD_tmp.size(); i++)
			std::cout << arrayD_tmp[i] << std::endl;
		arrayD_tmp = arrayD;
		std::cout << "arrayD_tmp after" << std::endl;
		for (int i = 0; i < arrayD_tmp.size(); i++)
			std::cout << arrayD_tmp[i] << std::endl;
		std::cout << std::endl;

		Array<float> *alloc = new Array<float>(5);
		std::cout << "alloc_float" << std::endl;
		std::cout << "size: " << alloc->size() << std::endl;
		for (int i = 0; i < alloc->size(); i++){
			(*alloc)[i] = rand() % 100;
			(*alloc)[i] += (rand() % 100) / 100;
			std::cout << (*alloc)[i] << std::endl;
		}
		std::cout << std::endl;
		Array<float> test_alloc = *alloc;
		std::cout << std::endl;
		std::cout << "alloc_float_tmp" << std::endl;
		for (int i = 0; i < test_alloc.size(); i++)
			std::cout << test_alloc[i] << std::endl;
		std::cout << std::endl;

		delete alloc;
		std::cout << "alloc deleted !" << std::endl;
		std::cout << "alloc_float_tmp" << std::endl;
		for (int i = 0; i < test_alloc.size(); i++)
			std::cout << test_alloc[i] << std::endl;
		std::cout << std::endl;
		std::cout << "arraD_tmp[-100]: " << arrayD_tmp[-100] << std::endl;
	}
	catch (std::exception &other){
		std::cout << other.what() << std::endl;
	}
	return (0);
}
