/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guille <Guille@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 20:46:54 by Guille            #+#    #+#             */
/*   Updated: 2026/03/04 21:08:30 by Guille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <list>
#include <iostream>
template<typename T>
class MutantStack : public std::stack<T> 
{
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator       iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	
		iterator begin() { return this->c.begin(); }
		iterator end()   { return this->c.end(); }

		const_iterator begin() const { return this->c.begin(); }
		const_iterator end()   const { return this->c.end(); }
	
};

#include "MutantStack.tpp"

#endif