/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:18:56 by Guille            #+#    #+#             */
/*   Updated: 2026/04/30 15:20:59 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::vector<int> bv;
	for (int i = 0; i < 10000; i++)
		bv.push_back(rand());
	Span big = Span(10000);
	big.addRange(bv.begin(), bv.end());
	std::cout << big.shortestSpan() << std::endl;
	std::cout << big.longestSpan() << std::endl;
	try {
		sp.addNumber(99);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Span empty(5);
		empty.shortestSpan();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}