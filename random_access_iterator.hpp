/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:14:08 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/24 09:25:20 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"
#include <cstddef>

namespace ft
{
	template <class T, class Category = ft::random_access_iterator_tag, 
				class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class random_access_iterator : ft::iterator<T, ft::random_access_iterator_tag>
	{
		public:
			typedef T value_type;
			typedef Distance difference_type;
			typedef Pointer pointer;
			typedef Reference reference;
			typedef Category iterator_category;
			
		private:
			pointer _IT;

		public:
			random_access_iterator() {}
			random_access_iterator(pointer p) : _IT(p) {}
			random_access_iterator(const random_access_iterator &other) : _IT(other._IT) {}
			~random_access_iterator() {}

		random_access_iterator &operator=(const random_access_iterator &other)
		{
			_IT = other._IT;
			return (*this);
		}

		reference operator*() const {return (*_IT);}

		pointer operator->() const {return (_IT);}
		
		reference operator[](difference_type n) const {return (_IT[n]);}

		difference_type operator-(const random_access_iterator &other) const {return (_IT - other._IT);}

		difference_type operator+(const random_access_iterator &other) const {return (_IT + other._IT);}

		random_access_iterator &operator++()
		{
			_IT++;
			return (*this);
		}

		random_access_iterator &operator--()
		{
			_IT--;
			return (*this);
		}

		random_access_iterator operator++(int)
		{
			random_access_iterator tmp(*this);
			_IT++;
			return (tmp);
		}

		random_access_iterator operator--(int)
		{
			random_access_iterator tmp(*this);
			_IT--;
			return (tmp);
		}

		random_access_iterator &operator+=(const difference_type &n)
		{
			_IT += n;
			return (*this);
		}

		random_access_iterator &operator-=(const difference_type &n)
		{
			_IT -= n;
			return (*this);
		}

		random_access_iterator operator+(difference_type n) const
		{
			random_access_iterator tmp(*this);
			tmp += n;
			return (tmp);
		}

		random_access_iterator operator-(difference_type n) const
		{
			random_access_iterator tmp(*this);
			tmp -= n;
			return (tmp);
		}

		bool	operator==(const random_access_iterator &other) const {return (_IT ==&(*other));}

		bool	operator!=(const random_access_iterator &other) const {return (_IT !=&(*other));}

		bool	operator>(const random_access_iterator &other) const {return (_IT >&(*other));}

		bool	operator<(const random_access_iterator &other) const {return (_IT <&(*other));}

		bool	operator<=(const random_access_iterator &other) const {return (_IT <=&(*other));}

		bool	operator>=(const random_access_iterator &other) const {return (_IT >=&(*other));}

	};
	
	template <class InputIterator, class Distance>
	void advane(InputIterator &IT, Distance n)
	{
		IT += n;
	}


} // namespace ft

#endif