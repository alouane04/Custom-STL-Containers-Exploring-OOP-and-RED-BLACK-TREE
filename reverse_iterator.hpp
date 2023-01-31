/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:22:04 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/29 16:23:31 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "random_access_iterator.hpp"

namespace ft
{
	template<class Iter>
	struct const_reverse_iterator;

	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef Iterator iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
			typedef typename iterator_traits<Iterator>::value_type value_type;
			typedef typename iterator_traits<Iterator>::difference_type difference_type;
			typedef typename iterator_traits<Iterator>::pointer pointer;
			typedef typename iterator_traits<Iterator>::reference reference;

		protected:
			iterator_type 	current;

		public:
			reverse_iterator() : current() {}

			explicit reverse_iterator(iterator_type other) : current(other) {};
			
			template <class IT>
			reverse_iterator(const reverse_iterator<IT> &other) {current = other.base();}

			iterator_type base() const {return (current);}
			
			reference operator*() const
			{
				iterator_type tmp = current;
				return (*--tmp);
			}

			reverse_iterator operator+(difference_type n) const {return (reverse_iterator(current - n));}

			reverse_iterator operator-(difference_type n) const {return (reverse_iterator(current + n));}

			reverse_iterator &operator++()
			{
				--current;
				return (*this);
			}
			
			reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;
				++(*this);
				return (tmp);
			}

			reverse_iterator &operator+= (difference_type n)
			{
				current -= n;
				return (*this);
			}

			reverse_iterator &operator--()
			{
				++current;
				return (*this);
			}

			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				--(*this);
				return (tmp);
			}

			reverse_iterator &operator-=(difference_type n)
			{
				current += n;
				return (*this);
			}

			pointer operator->() const
			{
				return &(operator*());
			}

			reference operator[](difference_type n) const
			{
				return *(*this + n);
			}

			operator const_reverse_iterator<Iterator>() const
			{
				return (const_reverse_iterator<Iterator>(current));
			}

	}; // reverse_iterator

	template <class L_Iterator, class R_Iterator>
	typename reverse_iterator<L_Iterator>::difference_type
	operator-(const reverse_iterator<L_Iterator> &lhs, const reverse_iterator<R_Iterator> &rhs)
	{
		return (rhs.base() - lhs.base());
	}

	template <class L_Iterator, class R_Iterator>
	bool operator==(const reverse_iterator<L_Iterator> &lhs, const reverse_iterator<R_Iterator> &rhs)
	{
		return (rhs.base() == lhs.base());
	}

	template <class L_Iterator, class R_Iterator>
	bool operator!=(const reverse_iterator<L_Iterator> &lhs, const reverse_iterator<R_Iterator> &rhs)
	{
		return (rhs.base() != lhs.base());
	}

	template <class L_Iterator, class R_Iterator>
	bool operator>(const reverse_iterator<L_Iterator> &lhs, const reverse_iterator<R_Iterator> &rhs)
	{
		return (rhs.base() > lhs.base());
	}

	template <class L_Iterator, class R_Iterator>
	bool operator<(const reverse_iterator<L_Iterator> &lhs, const reverse_iterator<R_Iterator> &rhs)
	{
		return (rhs.base() < lhs.base());
	}

	template <class L_Iterator, class R_Iterator>
	bool operator>=(const reverse_iterator<L_Iterator> &lhs, const reverse_iterator<R_Iterator> &rhs)
	{
		return (rhs.base() >= lhs.base());
	}

	template <class L_Iterator, class R_Iterator>
	bool operator<=(const reverse_iterator<L_Iterator> &lhs, const reverse_iterator<R_Iterator> &rhs)
	{
		return (rhs.base() <= lhs.base());
	}

} // namespace ft

#endif