/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:58:44 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/27 02:38:10 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	std::cout << "bps function say: "
		<< (bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 15)) ? "inside" : "outside") << std::endl;
	std::cout << "bps function say: "
		<< (bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 15)) ? "inside" : "outside") << std::endl;
	std::cout << "bps function say: "
		<< (bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(15, 10)) ? "inside" : "outside") << std::endl;
	std::cout << "bps function say: "
		<< (bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(15, 150)) ? "inside" : "outside") << std::endl;
	std::cout << "bps function say: "
		<< (bsp(Point(10, 0), Point(10, 50), Point(200, 0), Point(100, 20)) ? "inside" : "outside") << std::endl;
	return 0;
}
