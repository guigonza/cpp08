/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:38:31 by Guille            #+#    #+#             */
/*   Updated: 2026/04/30 12:06:16 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main(void)
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	try 
	{
		std::vector<int>::iterator it = easyfind(v, 2);
		std::cout << "Encontrado: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
			
	try
	{
		std::vector<int>::iterator it = easyfind(v, 4);
		std::cout << "Encontrado: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	try
	{
		std::list<int>::iterator it = easyfind(l, 3);
		std::cout << "Encontrado: " << *it << std::endl;

	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
}