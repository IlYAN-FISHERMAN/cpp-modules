/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:07:29 by ilyanar           #+#    #+#             */
/*   Updated: 2025/03/11 18:39:35 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <list>

class VectSort
{
	private:
		std::vector<int>	_data;
		VectSort();
	public:
		VectSort(char *);
		~VectSort();
		VectSort(const VectSort &other);
		VectSort& operator=(const VectSort &other);

		void sort();

};

class ListSort
{
	private:
		std::list<int>	_data;
		ListSort();
	public:
		ListSort(std::string);
		~ListSort();
		ListSort(const ListSort &other);
		ListSort& operator=(const ListSort &other);

		void sort();
};
#endif
