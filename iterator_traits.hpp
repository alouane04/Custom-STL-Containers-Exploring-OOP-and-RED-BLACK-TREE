/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:53:26 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/29 16:21:03 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAIT_HPP
#define ITERATOR_TRAIT_HPP

#include <cstddef>
#include <iterator>

namespace ft
{
	
	// It's a way to get the type of the iterator.
	struct	input_iterator_tag {};
	struct	output_iterator_tag {};
	struct	forward_iterator_tag : public input_iterator_tag {};
	struct	bidirectional_iterator_tag : public forward_iterator_tag {};
	struct	random_access_iterator_tag : public bidirectional_iterator_tag {};


	// It's a template struct that is used to get the type of the iterator.
	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef ft::random_access_iterator_tag iterator_category;
	};

	template<class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef random_access_iterator_tag iterator_category;
	};

	template <class T, class Category, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};




	template<class IT>
	typename ft::iterator_traits<IT>::difference_type do_distance(IT first, IT last, ft::input_iterator_tag)
	{
		// It's a way to get the type of the iterator.
		typename ft::iterator_traits<IT>::difference_type res = 0;
		
		// It's a way to get the distance between the first and the last iterator.
		while (first != last)
		{
			first++;
			res += 1;
		}
		return (res);
	}

	template<class IT>
	typename ft::iterator_traits<IT>::difference_type do_distance(IT first, IT last, ft::random_access_iterator_tag)
	{
		return (last - first);
	}

	// template<class IT>
	// typename ft::iterator_traits<IT>::ifference_type do_distance(IT first, IT last, std::input_iterator_tag)
	// {
	// 	// It's a way to get the type of the iterator.
	// 	typename std::iterator_traits<IT>::difference_type res = 0;
		
	// 	// It's a way to get the distance between the first and the last iterator.
	// 	while (first != last)
	// 	{
	// 		first++;
	// 		res += 1;
	// 	}
	// 	return (res);
	// }

	// template<class IT>
	// typename ft::iterator_traits<IT>::difference_type do_distance(IT first, IT last, ft::random_acces_iterator_tag)
	// {
	// 	return (last - first);
	// }
	
	template<class IT>
	typename ft::iterator_traits<IT>::difference_type distance(IT first, IT last)
	{
		return (ft::do_distance(first, last, typename ft::iterator_traits<IT>::iterator_category()));
	}	
	
} // namespace ft

#endif