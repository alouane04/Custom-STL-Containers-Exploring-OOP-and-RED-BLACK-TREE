/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:41:03 by ariahi            #+#    #+#             */
/*   Updated: 2023/02/12 17:17:05 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
	template<class T1, class T2>
	struct pair
	{
		typedef T1 first_T;
		typedef T2 second_T;

		first_T first;
		second_T second;

		pair() : first(), second() {}
		
		template<class A, class B>
		pair(const pair<A,B>& other) : first(other.first), second(other.second) {}

		pair(const first_T &a, const second_T &b) : first(a), second(b) {}

		pair& operator=(const pair &other)
		{
			first = other.first;
			second = other.second;
			return (*this);
		}

		~pair() {}
	};

	template<class T1, class T2>
	bool operator==(const pair<T1, T2> &first, const pair<T1, T2> &second)
	{
		return (first.first == second.first && first.second == second.second);
	}

	template<class T1, class T2>
	bool operator!=(const pair<T1, T2> &first, const pair<T1, T2> &second)
	{
		return (!first == second);
	}

	template<class T1, class T2>
	bool operator<(const pair<T1, T2> &first, const pair<T1, T2> &second)
	{
		return (first.first < second.first || (!(second.first < first.first) && first.second < second.second));
	}

	template<class T1, class T2>
	bool operator>(const pair<T1, T2> &first, const pair<T1, T2> &second)
	{
		return (second < first);
	}

	template<class T1, class T2>
	bool operator>=(const pair<T1, T2> &first, const pair<T1, T2> &second)
	{
		return !(first < second);
	}

	template<class T1, class T2>
	bool operator<=(const pair<T1, T2> &first, const pair<T1, T2> &second)
	{
		return !(second < first);
	}

	template<class T1, class T2>
	pair<T1, T2> make_pair(T1 first, T2 second)
	{
		return (pair<T1, T2> (first, second));
	}

} // namespace ft

#endif