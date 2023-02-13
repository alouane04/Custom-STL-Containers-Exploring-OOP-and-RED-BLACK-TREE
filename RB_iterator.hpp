/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RB_iterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:22:11 by ariahi            #+#    #+#             */
/*   Updated: 2023/02/12 12:39:53 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_ITERATOR_HPP
#define RB_ITERATOR_HPP

#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"
#include "RB_Node.hpp"

namespace ft
{
	template <class T, class RB_Tree, class Distance = ptrdiff_t, class Reference = T&, class Pointer = T*>
	class RB_iterator
	{
		public:
			// It's a way to get the type of the iterator.

			typedef typename ft::iterator<T, ft::bidirectional_iterator_tag>::iterator_category iterator_category;
			typedef typename ft::iterator<T, ft::bidirectional_iterator_tag>::difference_type difference_type;
			typedef typename ft::iterator<T, ft::bidirectional_iterator_tag>::pointer pointer;
			typedef typename ft::iterator<T, ft::bidirectional_iterator_tag>::reference reference;
			typedef typename ft::iterator<T, ft::bidirectional_iterator_tag>::value_type value_type;
			typedef typename RB_Tree::node_pointer _Node;

			_Node	node_pointer;
			_Node	root_pointer;

			// It's the constructors and destructor of the RB_iterator class.

			RB_iterator() : node_pointer(NULL), root_pointer(NULL) {}
			RB_iterator(_Node node, _Node root) : node_pointer(node), root_pointer(root) {}
			RB_iterator(const RB_iterator &other) : node_pointer(other.node_pointer), root_pointer(other.root_pointer) {}
			~RB_iterator() {}

			// It's the operators for the RB_iterator class.

			RB_iterator &operator=(const RB_iterator &other)
			{
				node_pointer = other.node_pointer;
				root_pointer = other.root_pointer;
				return (*this);
			}

			reference operator*() const
			{
				return (node_pointer->key_value);
			}

			pointer operator->() const
			{
				return (&node_pointer->key_value);
			}

			RB_iterator &operator++()
			{
				if (node_pointer->nil == true)
				{
					node_pointer = root_pointer;
					while (node_pointer->left->nil == false)
						node_pointer = node_pointer->left;
				}
				else if (node_pointer->right->nil == false)
				{
					node_pointer = node_pointer->right;
					while (node_pointer->left->nil == false)
						node_pointer = node_pointer->left;
				}
				else
				{
					_Node p = node_pointer->parent;
					while (p->nil == false && node_pointer == p->right)
					{
						node_pointer = p;
						p = p->parent;
					}
					node_pointer = p;
				}
				return (*this);
			}

			RB_iterator operator++(int)
			{
				RB_iterator tmp(*this);
				++*this;
				return (tmp);
			}

			RB_iterator &operator--()
			{
				if (node_pointer->nil == true)
				{
					node_pointer = root_pointer;
					while (node_pointer->right->nil == false)
						node_pointer = node_pointer->right;
				}
				else if (node_pointer->left->nil == false)
				{
					node_pointer = node_pointer->left;
					while (node_pointer->right->nil == false)
						node_pointer = node_pointer->right;
				}
				else
				{
					_Node p = node_pointer->parent;
					while (p->nil == false && node_pointer == p->left)
					{
						node_pointer = p;
						p = p->parent;
					}
					node_pointer = p;
				}
				return (*this);
			}

			RB_iterator operator--(int)
			{
				RB_iterator tmp(*this);
				--*this;
				return (tmp);
			}
			
			bool operator==(const RB_iterator &other)
			{
				return (node_pointer == other.node_pointer);
			}
			
			bool operator!=(const RB_iterator &other)
			{
				return (node_pointer != other.node_pointer);
			}

			//It's a type conversion operator. It allows you to convert a non-const rbtree_iterator object to a const rbtree_iterator object,
			//		which can be useful if you want to iterate over a const red-black tree and ensure that the elements are not modified during iteration.
			operator RB_iterator<const T, RB_Tree>() const
			{
				return (RB_iterator<const T, RB_Tree>(node_pointer, root_pointer));
			}

			// It's a function that returns the next element of the RB_iterator.
			// And it's use the operator++.
			RB_iterator successor()
			{
				RB_iterator tmp(*this);
				tmp++;
				return (tmp);
			}
			
			// It's a function that returns the next element of the RB_iterator.
			// And it's use the operator--.
			RB_iterator predecessor()
			{
				RB_iterator tmp(*this);
				tmp--;
				return (tmp);
			}

	};

	template <class Iter>
	typename Iter::difference_type Distance(const Iter &first, const Iter &last)
	{
		typename Iter::difference_type i = 0;
		Iter tmp(first);
		while (tmp != last)
		{
			tmp++;
			i++;
		}
		return (i);
	}
	
} // namespace ft

#endif