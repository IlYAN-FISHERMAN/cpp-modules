/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:07:29 by ilyanar           #+#    #+#             */
/*   Updated: 2025/03/20 14:32:39 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <ctime>
#include <deque>
#include <math.h>
#include <cmath>
#include <utility>
#include <vector>
#include <iostream>
#include <list>
#include <unistd.h>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <stdexcept>
#include <sys/wait.h>
#include <unistd.h>
#include <cassert>
#include <vector>

# ifndef DEBUG
#  define DEBUG 0
# endif

#define vit std::vector<int>::iterator
#define vi std::vector<int>
#define det std::deque<int>::iterator
#define de std::deque<int>

template <class T>
bool isSorted(T begin, T end){
	begin++;
	while (begin != end){
		if (*begin - 1 > *begin)
			return false;
		begin++;
	}
	return true;
}

class VectSort
{
	private:
		vi	_data;
		clock_t _start;
		static int _count;
		static int _debug;
		size_t _order;
		VectSort();
		void endSortInfo() const;
		void debugCmd(char*, char**) const;
		void debugInsert(vi &, vi &) const;
		void merge();
		void insert();
		void sort(vi &, vi &, vi &);
		void standardBinarySearch(vi &, vi &);
		void debugBinary(vi &, vit, vit, vit, vit, vit, int, int);
		void binarySearch(vi &, vit, vit, vit, vit);
		std::vector<long> jacobsthal(size_t) const;
		void jacobsthalBinarySearch(vi &, vi &, std::vector<long>::iterator &);
	public:
		VectSort(char *);
		~VectSort();
		VectSort(const VectSort &other);
		VectSort& operator=(const VectSort &other);

		void FordJonhson();
		void print() const;
		void debugMode(int, int, int);
		void setDebug(int);
};

class DequeSort
{
	private:
		de	_data;
		clock_t _start;
		static int _count;
		static int _debug;
		size_t _order;
		DequeSort();
		void endSortInfo() const;
		void debugCmd(char*, char**) const;
		void debugInsert(de&, de&) const;
		void merge();
		void insert();
		void sort(de&, de&, de&);
		void standardBinarySearch(de&, de&);
		void debugBinary(de&, det, det, det, det, det, int, int);
		void binarySearch(de&, det, det, det, det);
		std::vector<long> jacobsthal(size_t) const;
		void jacobsthalBinarySearch(de&, de&, std::vector<long>::iterator &);
	public:
		DequeSort(char *);
		~DequeSort();
		DequeSort(const DequeSort &other);
		DequeSort& operator=(const DequeSort &other);

		void FordJonhson();
		void print() const;
		void debugMode(int, int, int);
		void setDebug(int);
};

#endif
