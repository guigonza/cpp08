/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guille <Guille@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:59:04 by Guille            #+#    #+#             */
/*   Updated: 2026/03/04 19:18:10 by Guille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n): _maxSize(n) {}
Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}
Span& Span::operator=(const Span& other)
{
	if (this == &other)
		return (*this);
	_maxSize = other._maxSize;
	_numbers = other._numbers;
	return (*this);
}
Span::~Span() {}

void Span::addNumber(int n)
{
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Size too large");
	_numbers.push_back(n);
}
int  Span::longestSpan() const 
{
	if (_numbers.size() <= 1)
		throw std::runtime_error("Size too short");
	return (*std::max_element(_numbers.begin() , _numbers.end()) - *std::min_element(_numbers.begin() , _numbers.end()));
}

int  Span::shortestSpan() const 
{
	std::vector<int> tmp;
	int minSpan;
	if (_numbers.size() <= 1)
		throw std::runtime_error("Size too short");
	tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());
	minSpan = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++)
		minSpan= std::min(minSpan, tmp[i] - tmp[i - 1]);
	return (minSpan);
}