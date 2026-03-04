/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guille <Guille@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:57:03 by Guille            #+#    #+#             */
/*   Updated: 2026/03/04 18:36:29 by Guille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>

class Span {
public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int n);
    int  shortestSpan() const;
    int  longestSpan() const;

    // para añadir rango de iteradores
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end);

private:
    unsigned int        _maxSize;
    std::vector<int>    _numbers;
};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	if (_numbers.size() + std::distance(begin, end) > _maxSize)
		throw std::runtime_error("Span is full");
	_numbers.insert(_numbers.end(), begin, end);
}
#endif