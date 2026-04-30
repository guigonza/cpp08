/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:57:03 by Guille            #+#    #+#             */
/*   Updated: 2026/04/30 15:28:25 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iterator>

class Span {
public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int n);
    int  shortestSpan() const;
    int  longestSpan() const;

    template <typename Iterator>
    void addRange(Iterator begin, Iterator end);

private:
    unsigned int        _maxSize;
    std::vector<int>    _numbers;
};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
    std::vector<int> tmp(begin, end);
	if (_numbers.size() + tmp.size() > _maxSize)
		throw std::runtime_error("Span is full");
    _numbers.reserve(_numbers.size() + tmp.size());
	_numbers.insert(_numbers.end(), tmp.begin(), tmp.end());
}
#endif