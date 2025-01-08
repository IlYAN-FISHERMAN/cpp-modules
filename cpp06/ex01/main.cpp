/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:19:01 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/08 19:52:24 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Serializer.hpp"

int main(void)
{
	uintptr_t	ptr = 0;
	Data		data = {42};
	Data		*rep = NULL;

	std::cout << "ptr: " << ptr << ", data: " << &data << ", rep: " << rep << std::endl;
	ptr = Serializer::serialize(&data);
	std::cout << "ptr: " << ptr << ", data: " << &data << ", rep: " << rep << std::endl;
	rep = Serializer::deserialize(ptr);
	std::cout << "ptr: " << ptr << ", data: " << &data << ", rep: " << rep << std::endl;
	std::cout << "Nb: " << rep->nb << std::endl;
	return 0;}
