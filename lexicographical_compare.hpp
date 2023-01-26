/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:19:29 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/24 18:18:10 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{

	// The bellow code is comparing two arrays and returning true if the first array is less than the second array.
	// The code is comparing the first element of the first array to the first element of the second array.
	// If the first element of the first array is less    than the first element of the second array, then the function returns true.
	// If the first element of the first array is greater than the first element of the second array, then the function returns false.
	// If the first element of the first array is equal to the first element of the second array, it moves on to the next element of each array and compares
	
	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			if (*first1 < *first2)
				return (true);
			first1++;
			first2++;
		}
		return (first2 != last2);
	}
	
	template< class InputIt1, class InputIt2, class Compare >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2 < *first1))
				return (false);
			if (comp(*first1 < *first2))
				return (true);
			first1++;
			first2++;
		}
		return (first2 != last2);
	}
	
} // namespace ft

#endif