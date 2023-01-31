/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:43:46 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/29 20:16:02 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"
#include <stack>

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:

			// It's defining the type of the container, the type of the value and the type of the size.

			typedef Container container_type;
			typedef typename container_type::value_type value_type;
			typedef typename container_type::size_type size_type;

		protected:

			// It's a container that will be used to store the elements of the stack.

			container_type c;

		public:

			// It's a copy constructor.

			stack(const stack &other)
			{
				c = other.c;
			}
			
			// It's a constructor that takes a container_type as a parameter.

			explicit stack(const container_type &_cont = container_type())
			{
				c = _cont;
			}

			// It's a empty destructor bc vector destructor gonna take care of it.

			~stack() {}
			
			// It's an operator that is assigning the stack to the other stack.

			stack &operator=(const stack &rhs)
			{
				c = rhs.c;
				return (*this);
			}

			// It's returning true if the stack is empty and false if it's not.

			bool empty() const
			{
				return (c.empty());
			}

			// It's returning the size of the stack.

			size_type size() const
			{
				return (c.size());
			}

			// It's returning the last element of the stack.

			value_type &top()
			{
				return (c.back());
			}

			// It's returning the last element of the stack.

			value_type &top() const
			{
				return (c.back());
			}

			// It's pushing a value at the end of the stack.

			void push(const value_type &value)
			{
				return (c.push_back(value));
			}

			// It's removing the last element of the stack.

			void pop()
			{
				return (c.pop_back());
			}

			// It's swapping the content of the stack with the content of the other stack.

			void swap(stack &other)
			{
				c.swap(other);
			}

			// It's comparing the content of the stack with the content of the other stack.
			//	and we use the friend keyword bc we compare a private(protacted) member.

			friend bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
			{
				return (lhs.c == rhs.c);
			}

			friend bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
			{
				return (lhs.c <= rhs.c);
			}

			friend bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
			{
				return (lhs.c >= rhs.c);
			}

			friend bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
			{
				return (lhs.c != rhs.c);
			}

			friend bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
			{
				return (lhs.c < rhs.c);
			}

			friend bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
			{
				return (lhs.c > rhs.c);
			}

	};
} // namespace ft


#endif