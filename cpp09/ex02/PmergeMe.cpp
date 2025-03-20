/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:07:58 by ilyanar           #+#    #+#             */
/*   Updated: 2025/03/20 10:23:50 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <iterator>
#include <vector>

int VectSort::_count = 0;
int VectSort::_debug = 0;

int DequeSort::_count = 0;
int DequeSort::_debug = 0;

int F(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

VectSort::VectSort(char *av) : _order(1){

	std::stringstream	stream(av);
	std::string			tmp;
	char *delem;
	long int nbr;

	while (stream >> tmp){
		nbr = std::strtol(tmp.c_str(), &delem, 10);
		if (*delem)
			throw std::runtime_error("Bad number input: " + tmp);
		if (nbr < 0 || nbr > INT_MAX)
			throw std::runtime_error("Bad range number: " + tmp);
		_data.push_back(nbr);
	}
}

VectSort::~VectSort(){
}

void VectSort::endSortInfo() const{
	if (DEBUG)		std::cout << std::endl << std::endl;
	clock_t end = clock() - _start;
	std::cout << "After:\t";
	for (vi::const_iterator it = _data.begin(), end = _data.end(); it != end;){
		std::cout << *it;
		it++;
		if (it != end)
			std::cout << " ";
	}
	std::cout << std::endl << std::fixed;
	std::cout << "list is sorted:\t" << (std::is_sorted(_data.begin(), _data.end()) ? "true" : "false") << std::endl;
	std::cout << "Time to process a range of " << _data.size()
		<< " elements with std::vector with " << _count
		<< " comparaison, worstCast: " << F(_data.size()) <<  " :\t" << 	(float)end / CLOCKS_PER_SEC  << std::endl << std::endl;
}

VectSort::VectSort(const VectSort &other) : _data(other._data){}

void VectSort::print() const{
	std::cout << std::endl << "count: " << _count <<  std::endl << "list: ";
	for (vi::const_iterator it = _data.begin(), end = _data.end(); it != end;){
		std::cout << *it;
		it++;
		if (it != end)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

VectSort& VectSort::operator=(const VectSort &other){
	if (this != &other){
		_data = other._data;
	}
	return *this;
}

void VectSort::debugCmd(char *cmd = NULL, char **args = NULL) const{
	pid_t pid = fork();

	if (!pid){
		if (!args)
			execv(cmd, (char *[]){cmd, NULL});
		else
			execv(args[0], args);
		std::cerr << "excev failed" << std::endl;
		exit(EXIT_FAILURE);
	}
	else{
		int status = 0;
		waitpid(pid, &status, 0);
	}
}

void VectSort::debugMode(int mode = 0, int tmpi = 0, int tmpj = 0){
	if ((mode == 1 || mode == 2) && (!_debug || _debug == 1))
		debugCmd((char *)"/usr/bin/clear");
	if ((mode == 2 || mode == 3) && (!_debug || _debug == 1)){
		for (size_t i = 0; i < _data.size(); i++){
			if (i == (size_t)tmpi)
				std::cout << "\033[31m" << _data[i] << "\033[0m";
			else if (i == (size_t)tmpj)
				std::cout << "\033[32m" << _data[i] << "\033[0m";
			else
				std::cout << _data[i];
			if (i+1 < _data.size())
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "count:\t" << _count << std::endl;
		std::cin.get();
	}

}

void VectSort::debugInsert(vi &main, vi &pend) const{

	std::cout << "with order: " << _order << "\nmain: ";
	for (size_t i = 0; i < main.size(); i++){
		std::cout << main[i];
		if (i+1 < main.size())
			std::cout << ", ";
	}
	std::cout << std::endl << "pend: ";
	for (size_t i = 0; i < pend.size(); i++){
		std::cout << pend[i];
		if (i+1 < pend.size())
			std::cout << ", ";
	}
	std::cout << std::endl << std::endl;
	std::cin.get();
}

std::vector<long> VectSort::jacobsthal(size_t size) const{
	std::vector<long> j;
	size_t range = 0;

	j.push_back(0);
	j.push_back(1);
	while (true){
		size_t next = j[j.size() - 1] + 2 * j[j.size() - 2];
		if (range >= size)
			break ;
		range += (size_t)(j[j.size() - 1] - j[j.size() - 2]); 
		j.push_back(next);
	}
	return (j);
}

void VectSort::debugBinary(vi &main, vit sbegin, vit send, vit begin, vit end, vit mid, int range, int mode){

	if (mode == 1){
		std::cout << "\n\033[32m[ Binary Search ]\033[0m" << std::endl;
		std::cout << "range:\t" << range << std::endl;
		std::cout << "mid:\t" << *mid << std::endl;
		std::cout << "insert:\t[" << *sbegin << "] to [" << *send << "]" << std::endl;
		std::cout << "count:\t" << _count << std::endl;
		std::cout << "main:\t";
		size_t j = 0;
		for (vit i = main.begin(); i != main.end(); i++){
			if (j == 0)
				std::cout << "{";
			j++;
			if (i == begin)
				std::cout << "\033[33m" << "[" << "\033[0m";
			else if (i == end)
				std::cout << "\033[33m" << "[" << "\033[0m";
			if (i == mid && (i != begin && i != end))
				std::cout << "\033[32m[" << *i << "]\033[0m";
			else if (i == mid && (i == begin || i == end))
				std::cout << "\033[32m" << *i << "\033[0m";
			else if (i == begin || i == end)
				std::cout << "\033[33m" << *i << "\033[0m";
			else
				std::cout << *i;
			if (i == begin)
				std::cout << "\033[33m" << "]" << "\033[0m";
			else if (i == end)
				std::cout << "\033[33m" << "]" << "\033[0m";
			if (j == _order){
				std::cout << "}";
				j = 0;
			}
			if ((i + 1) != main.end())
				std::cout << ", ";
		}
		std::cin.get();
		std::cout << std::endl << std::endl;
	}
	else if (mode == 2){
		std::cout << "[insert]" << std::endl;
		std::cin.get();
		std::cout << "main:\t";
		size_t j = 0;
		for (vit i = main.begin(); i != main.end(); i++){
			if (j == 0)
				std::cout << "{";
			j++;
			if (j-1 == 0 || j == _order)
				std::cout << "\033[33m" << *i << "\033[0m";
			else
				std::cout << *i;
			if (j == _order){
				std::cout << "}";
				j = 0;
			}
			if ((i + 1) != main.end())
				std::cout << ", ";
		}
		std::cout << std::endl << std::endl;
		std::cin.get();
	}
}

vit VectSort::binarySearch(vi &main, vit sbegin, vit send, vit begin, vit end){

	int range = std::distance(begin, end + 1) / _order;
	vit mid = end - 1;
	if (range == 3)
		mid -= _order;
	if (range <= 1)
		mid = end - (_order * range);
	else
		mid = end - ((range / 2) * _order);

	while(true){
		if (DEBUG && (!_debug || _debug == 2))
			debugBinary(main, sbegin, send, begin, end, mid, range, 1);
		if (range <= 2){
			if (range <= 1){
				if (++_count && *send >= *end)
					return ((_order - 1) + (main.insert(end+1, sbegin, send + 1)));
				else
					return ((_order - 1) + (main.insert(begin, sbegin, send + 1)));
				if (DEBUG && (!_debug || _debug == 2))
					debugBinary(main, sbegin, send, begin, end, mid, range, 2);
				}
			else if (range == 2){
				if (++_count && *send <= *mid)
					return ((_order - 1) + (main.insert(begin, sbegin, send + 1)));
				else {
					if (++_count && *send <= *end)
						return ((_order - 1) + (main.insert(mid + 1, sbegin, send + 1)));
					else
						return ((_order - 1) + (main.insert(end+1, sbegin, send + 1)));
				}
				if (DEBUG && (!_debug || _debug == 2))
					debugBinary(main, sbegin, send, begin, end, mid, range, 2);
				}
			break;
		}
		if (++_count && *send <= *mid){
			if ((std::distance(begin, end + 1) / _order) > 2)
				end = mid - _order;
			else
				end = mid;
		}
		else
			begin = mid + 1;
		range = std::distance(begin, end + 1) / _order;
		if (range == 3)
			mid = end - _order;
		if (range <= 1)
			mid = end;
		else
			mid = end - ((range / 2) * _order);
	}
	if (DEBUG && (!_debug || _debug == 2)){
		std::cout << "\nFINISH\n";
		std::cin.get();
		debugCmd((char *)"/usr/bin/clear");
	}
	return (main.end());
}

void VectSort::standardBinarySearch(vi &main, vi &pend){
	vit sbegin = pend.end() - _order;
	vit send = pend.end() - 1;

	while (!pend.empty()){
		if (DEBUG && (!_debug || _debug == 2)){
			std::cout << "\033[32m[ Standard binary sorting ]\33[0m" << std::endl;
			debugInsert(main, pend);
		}
		binarySearch(main, sbegin, send, main.begin(), main.end() - 1);
		sbegin -= _order;
		send -= _order;
		for (size_t j = _order; j > 0; j--)
			pend.pop_back();
		if (DEBUG && (!_debug || _debug == 2)){
			debugInsert(main, pend);
			debugCmd((char *)"/usr/bin/clear");
		}
	}
}

void VectSort::jacobsthalBinarySearch(vi &main, vi &pend, std::vector<long>::iterator &j){

	while (!pend.empty()){
		size_t nbrInsert = *j - (*(j - 1));
		if (nbrInsert > (pend.size() / _order)){
			standardBinarySearch(main, pend);
			break ;
		}
		while (nbrInsert > 0){
			if (DEBUG && (!_debug || _debug == 2)){
				std::cout << "\033[32m[ Jacobsthal binary sorting ]\033[0m" << std::endl << std::endl;
				std::cout << "nbr insert left:\t" << nbrInsert << std::endl;
			}
			int jRange = (*j + (*(j - 1))) - 1;
			vit sbegin = pend.begin() + (_order * nbrInsert) - _order;
			vit send = pend.begin() + (_order * nbrInsert) - 1;
			vit begin = main.begin();
			int range = (main.size() / _order) - jRange;
			vit end = main.end() - (range * _order) - 1;
			if (DEBUG && (!_debug || _debug == 2)){
				std::cout << "will be inserted:\t";
				for (vit i = sbegin; i != send + 1; i++){
					std::cout << *i;
					if (i != send)
						std::cout << ", ";
				}
				std::cout << std::endl;
				std::cout << "jacob range:\t" << jRange << std::endl;
				debugInsert(main, pend);
			}
			vit newEnd = binarySearch(main, sbegin, send, begin, end);
			(void)newEnd;
			nbrInsert--;
			pend.erase(sbegin, send + 1);
			if (DEBUG && (!_debug || _debug == 2)){
				debugInsert(main, pend);
				debugCmd((char *)"/usr/bin/clear");
			}
		}
		j++;
	}
}

void VectSort::sort(vi &main, vi &pend, vi &trash){
	std::vector<long> j = jacobsthal(pend.size() / _order);
	if (DEBUG && (!_debug || _debug == 2)){
		std::cout << "\nJ: ";
		for (size_t i = 0; i < j.size(); i++){
				std::cout << j[i];
				if (i+1 < j.size())
					std::cout << ", ";
			}
			std::cout << std::endl << std::endl;
	}
	std::vector<long>::iterator it = std::find(j.begin(), j.end(), 3);
	if (it == j.end())
		standardBinarySearch(main, pend);
	else
		jacobsthalBinarySearch(main, pend, it);
	if (!trash.empty()){
		for (vit ite = trash.begin(); ite != trash.end(); ite++)
			main.push_back(*ite);
		trash.clear();
	}

}

void VectSort::insert(){
	if ((_data.size() / _order) <= 2)
		return ;

	if (DEBUG && (!_debug || _debug == 2)){
		debugCmd((char *)"/usr/bin/clear");
		std::cout << "Starting sequence: ";
		for (size_t i = 0; i < _data.size(); i++){
			std::cout << _data[i];
			if (i+1 < _data.size())
				std::cout << ", ";
		}
		std::cout << std::endl << std::endl;
	}

	vi main;
	vi pend;
	vi trash;

	for (size_t j = 0; j < _order; j++)
		main.push_back(_data[j]);
	for (size_t j = _order; j < _order * 2; j++)
		main.push_back(_data[j]);

	size_t nbrPair = (_data.size() / _order);
	size_t p_nbr = 2;
	size_t delem = 0;

	while (p_nbr < nbrPair){
		if ((p_nbr + 1) % 2 == 0){
			for (size_t j = (p_nbr) * _order; j < (p_nbr + 1) * _order; j++)
				main.push_back(_data[j]);
		}
		else{
			for (size_t j = (p_nbr) * _order; j < (p_nbr + 1) * _order; j++)
				pend.push_back(_data[j]);
		}
		p_nbr++;
		if (p_nbr >= nbrPair){
			delem = (p_nbr) * _order;
			for(; delem < _data.size(); delem++)
				trash.push_back(_data[delem]);
		}
	}
	_data.clear();
	if (DEBUG && (!_debug || _debug == 2)){
		std::cout << std::endl << "trash: ";
		for (size_t i = 0; i < trash.size(); i++){
			std::cout << trash[i];
			if (i+1 < trash.size())
				std::cout << ", ";
		}
		std::cout << std::endl << std::endl;
		std::cout << "count:\t" << _count << std::endl;
		debugInsert(main, pend);
		debugCmd((char *)"/usr/bin/clear");
	}
	sort(main, pend, trash);
	_data = main;
	if (DEBUG && (!_debug || _debug == 2)){
		std::cout << "Main after: ";
		for (size_t i = 0; i < _data.size(); i++){
			std::cout << _data[i];
			if (i+1 < _data.size())
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cin.get();
		debugCmd((char *)"/usr/bin/clear");
	}
}

void VectSort::merge(){
	if ((size_t)_order * 2 > _data.size())
		return ;
	for (int i = _order - 1, j = (_order * 2) - 1, size = _data.size(); i < size && j < size;){
		if (++_count && _data[i] > _data[j]){
			int tmpi = i;
			int tmpj = j;
			int len = _order - 1;
			int swap = 0;
				if (DEBUG) {debugMode(1);}
			while (len >= 0){
				swap = _data[tmpi];
				_data[tmpi] = _data[tmpj];
				_data[tmpj] = swap;
				if (DEBUG) {debugMode(3, tmpi, tmpj);}
				tmpi--;
				tmpj--;
				len--;
			}
			if (DEBUG) {debugMode(1);}
		}
		i = j + _order;
		j = i + _order;
	}
	_order *= 2;
	merge();
	_order /= 2;
	insert();
}

void VectSort::FordJonhson(){
	_start = clock();

	std::cout << "Before:\t";
	for (vit it = _data.begin(), end = _data.end(); it != end;){
		std::cout << *it;
		it++;
		if (it != end)
			std::cout << " ";
	}
	std::cout << std::endl;
	if (DEBUG)	{std::cout << std::endl << std::endl;}
	merge();
	endSortInfo();
}

void VectSort::setDebug(int nb){_debug = nb;}










// verifier pendant le jaconbsthal si nbrInsert < initial nbr insert 
//  reduire la range de recherche du jacobsthal
//  verifier le end du debut






























DequeSort::DequeSort(char *av) : _order(1){

	std::stringstream	stream(av);
	std::string			tmp;
	char *delem;
	long int nbr;

	while (stream >> tmp){
		nbr = std::strtol(tmp.c_str(), &delem, 10);
		if (*delem)
			throw std::runtime_error("Bad number input: " + tmp);
		if (nbr < 0 || nbr > INT_MAX)
			throw std::runtime_error("Bad range number: " + tmp);
		_data.push_back(nbr);
	}
}

DequeSort::~DequeSort(){
}

void DequeSort::endSortInfo() const{
	if (DEBUG)		std::cout << std::endl << std::endl;
	clock_t end = clock() - _start;
	std::cout << "After:\t";
	for (std::deque<int>::const_iterator it = _data.begin(), end = _data.end(); it != end;){
		std::cout << *it;
		it++;
		if (it != end)
			std::cout << " ";
	}
	std::cout << std::endl << std::fixed;
	std::cout << "Time to process a range of " << _data.size()
		<< " elements with std::vector with " << _count
		<< " comparaison, worstCast: << " << F(_data.size()) <<  " : " << 	(float)end / CLOCKS_PER_SEC  << std::endl;
}

DequeSort::DequeSort(const DequeSort &other) : _data(other._data){}

void DequeSort::print() const{
	std::cout << std::endl << "count: " << _count <<  std::endl << "list: ";
	for (std::deque<int>::const_iterator it = _data.begin(), end = _data.end(); it != end;){
		std::cout << *it;
		it++;
		if (it != end)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

DequeSort& DequeSort::operator=(const DequeSort &other){
	if (this != &other){
		_data = other._data;
	}
	return *this;
}

void DequeSort::debugCmd(char *cmd = NULL, char **args = NULL) const{
	pid_t pid = fork();

	if (!pid){
		if (!args)
			execv(cmd, (char *[]){cmd, NULL});
		else
			execv(args[0], args);
		std::cerr << "excev failed" << std::endl;
		exit(EXIT_FAILURE);
	}
	else{
		int status = 0;
		waitpid(pid, &status, 0);
	}
}

void DequeSort::debugMode(int mode = 0, int tmpi = 0, int tmpj = 0){
	if ((mode == 1 || mode == 2) && (!_debug || _debug == 1))
		debugCmd((char *)"/usr/bin/clear");
	if ((mode == 2 || mode == 3) && (!_debug || _debug == 1)){
		for (size_t i = 0; i < _data.size(); i++){
			if (i == (size_t)tmpi)
				std::cout << "\033[31m" << _data[i] << "\033[0m";
			else if (i == (size_t)tmpj)
				std::cout << "\033[32m" << _data[i] << "\033[0m";
			else
				std::cout << _data[i];
			if (i+1 < _data.size())
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cin.get();
	}

}

void DequeSort::debugInsert(std::deque<int> &main, std::deque<int> &pend, std::deque<int>& trash) const{

	std::cout << "with order: " << _order << "\nmain: ";
	for (size_t i = 0; i < main.size(); i++){
		std::cout << main[i];
		if (i+1 < main.size())
			std::cout << ", ";
	}
	std::cout << std::endl << "pend: ";
	for (size_t i = 0; i < pend.size(); i++){
		std::cout << pend[i];
		if (i+1 < pend.size())
			std::cout << ", ";
	}
	std::cout << std::endl << "trash: ";
	for (size_t i = 0; i < trash.size(); i++){
		std::cout << trash[i];
		if (i+1 < trash.size())
			std::cout << ", ";
	}
	std::cout << std::endl << std::endl;
	std::cin.get();
	debugCmd((char *)"/usr/bin/clear");
}

void DequeSort::insert(){
	if ((_data.size() / _order) <= 2)
		return ;

	if (DEBUG && (!_debug || _debug == 2)){
		debugCmd((char *)"/usr/bin/clear");
		std::cout << "Starting sequence: ";
		for (size_t i = 0; i < _data.size(); i++){
			std::cout << _data[i];
			if (i+1 < _data.size())
				std::cout << ", ";
		}
		std::cout << std::endl << std::endl;
	}

	std::deque<int> main;
	std::deque<int> pend;
	std::deque<int> trash;

	for (size_t j = 0; j < _order; j++)
		main.push_back(_data[j]);
	for (size_t j = _order; j < _order * 2; j++)
		main.push_back(_data[j]);

	size_t nbrPair = (_data.size() / _order);
	size_t p_nbr = 2;
	size_t delem = 0;

	while (p_nbr < nbrPair){
		if ((p_nbr + 1) % 2 == 0){
			for (size_t j = (p_nbr) * _order; j < (p_nbr + 1) * _order; j++)
				main.push_back(_data[j]);
		}
		else{
			for (size_t j = (p_nbr) * _order; j < (p_nbr + 1) * _order; j++)
				pend.push_back(_data[j]);
		}
		p_nbr++;
		if (p_nbr >= nbrPair){
			delem = (p_nbr) * _order;
			for(; delem < _data.size(); delem++)
				trash.push_back(_data[delem]);
		}
	}

	if (DEBUG && (!_debug || _debug == 2)){
		debugInsert(main, pend, trash);
	}
}

void DequeSort::merge(){
	if ((size_t)_order * 2 > _data.size())
		return ;
	for (int i = _order - 1, j = (_order * 2) - 1, size = _data.size(); i < size && j < size;){
		if (++_count && _data[i] > _data[j]){
			int tmpi = i;
			int tmpj = j;
			int len = _order - 1;
			int swap = 0;
				if (DEBUG) {debugMode(1);}
			while (len >= 0){
				swap = _data[tmpi];
				_data[tmpi] = _data[tmpj];
				_data[tmpj] = swap;
				if (DEBUG) {debugMode(3, tmpi, tmpj);}
				tmpi--;
				tmpj--;
				len--;
			}
			if (DEBUG) {debugMode(1);}
		}
		i = j + _order;
		j = i + _order;
	}
	_order *= 2;
	merge();
	_order /= 2;
	insert();
}

void DequeSort::FordJonhson(){
	_start = clock();

	std::cout << "Before:\t";
	for (std::deque<int>::iterator it = _data.begin(), end = _data.end(); it != end;){
		std::cout << *it;
		it++;
		if (it != end)
			std::cout << " ";
	}
	std::cout << std::endl;
	if (DEBUG)	{std::cout << std::endl << std::endl;}
	merge();
	endSortInfo();
}

void DequeSort::setDebug(int nb){_debug = nb;}
