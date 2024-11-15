/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:20:33 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/15 14:05:50 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

# define LVL_LEN 4

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		std::string _cmd[LVL_LEN];
		void (Harl::*_func[LVL_LEN])();

	public:
		Harl(void);
		~Harl();
		void complain( std::string level );
};


#endif
