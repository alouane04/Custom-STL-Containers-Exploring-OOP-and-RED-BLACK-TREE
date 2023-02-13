/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:58:29 by ariahi            #+#    #+#             */
/*   Updated: 2023/02/12 17:00:47 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include "RB_Tree.hpp"
#include "RB_Node.hpp"
#include "pair.hpp"

namespace ft
{
	template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
	class set
	{
		public:

			typedef T key_type;
			typedef T value_type;
			typedef Compare key_compare;
			typedef Compare value_compare;
			typedef Allocator allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;

			typedef RB_Tree<value_type, value_compare, typename Allocator::template rebind<ft::RB_Node<value_type> >::other> rb_tree;

			typedef typename rb_tree::iterator iterator;
			typedef typename rb_tree::const_iterator const_iterator;
			typedef typename rb_tree::reverse_iterator reverse_iterator;
			typedef typename rb_tree::const_reverse_iterator const_reverse_iterator;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;

		private:

			allocator_type _alloc;
			key_compare _key_compare;
			value_compare _value_compare;
			rb_tree _rb_tree;

		public:

			explicit set(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _key_compare(comp), _value_compare(comp), _rb_tree(_value_compare) {}

			template <class InputIterator>
			set(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _key_compare(comp), _value_compare(comp), _rb_tree(_value_compare)
			{
				insert(first, last);
			}

			set(const set &x) : _alloc(x._alloc), _key_compare(x._key_compare), _value_compare(x._value_compare), _rb_tree(x._rb_tree) {}

			~set() {}

			set &operator=(const set &x)
			{
				if (this != &x)
				{
					_alloc = x._alloc;
					_key_compare = x._key_compare;
					_value_compare = x._value_compare;
					_rb_tree = x._rb_tree;
				}
				return (*this);
			}

			iterator begin()
			{
				return (_rb_tree.begin());
			}

			const_iterator begin() const
			{
				return (_rb_tree.begin());
			}

			iterator end()
			{
				return (_rb_tree.end());
			}

			const_iterator end() const
			{
				return (_rb_tree.end());
			}

			reverse_iterator rbegin()
			{
				return (_rb_tree.rbegin());
			}

			const_reverse_iterator rbegin() const
			{
				return (_rb_tree.rbegin());
			}

			reverse_iterator rend()
			{
				return (_rb_tree.rend());
			}

			const_reverse_iterator rend() const
			{
				return (_rb_tree.rend());
			}
			
			bool empty() const
			{
				return (_rb_tree.Empty());
			}

			size_type size() const
			{
				return (_rb_tree.get_size());
			}

			size_type max_size() const
			{
				return (_rb_tree.get_max_size());
			}

			////////////////////////////	Modifiers:     ////////////////////////////////

			// It's a function that inserts a new element in the set and return pair with ierator the value and bool indicate that if the value already exist.
			ft::pair<iterator, bool> insert(const value_type &value)
			{
				// It's checking if the key exists in the set.
				bool exists = _rb_tree.key_exists(value);

				// If exist return pair with iterator to the existing value and false
				if (exists)
				{
					struct ft::RB_Node<value_type>* node = _rb_tree.get_node(value);
					return (ft::pair<iterator, bool>(iterator(node, _rb_tree.get_root()), !exists));
				}

				// Else insert the value to the tree and return pair with iterator to the new value and true
				_rb_tree.insert_node(value);
				return (ft::pair<iterator, bool>(iterator(_rb_tree.get_node(value), _rb_tree.get_root()), exists));
			}

			// It's a function that inserts a new element in the set and return iterator.
			iterator insert(iterator position, const value_type &value) { return ((void)position, insert(value).first); }

			// It's a function that inserts a range of elements in the set.
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				for (; first != last; ++first)
					insert(*first);
			}

			// It's a function that deletes the element with the iterator position.
			void erase(iterator position) { _rb_tree.Delete(*position); }

			// It's a function that deletes the element with the key.
			size_type erase(const key_type &key)
			{
				// It's checking if the key exists in the set, if so it delete it and return true.
				if (_rb_tree.key_exists(key))// ????????????????????????????????????wtf??
					return (_rb_tree.Delete(key), 1);
				// Else false
				return (0);
			}

			// It's a function that deletes all the elements between the first and the last iterator.
			void erase(iterator first, iterator last)
			{
				for (iterator it; first != last; first = it)// that too why ????????????
				{
					it = first.successor(); // ????????????????????????/why
					erase(first);
				}
			}

			// It's a function that swaps the content of the set with the content of the set x.
			void swap(set &x)
			{
				std::swap(_alloc, x._alloc);
				std::swap(_key_compare, x._key_compare);
				std::swap(_value_compare, x._value_compare);
				_rb_tree.Swap(x._rb_tree);
			}

			// It's a function that deletes all the elements in the set.
			void clear() { _rb_tree.Clear(); }

			////////////////////////////    Operations:    //////////////////////////////////

			// It's a function that returns an iterator to the element with the key.
			iterator find(const key_type &key)
			{
				// It's checking if the key exists in the set.
				bool exists = _rb_tree.key_exists(key);

				if (exists)
					// It's returning an iterator to the node that has the key.
					return (iterator(_rb_tree.get_node(key), _rb_tree.get_root()));
				// Else return the end of set.
				return (end());
			}

			// It's a function that returns an const_iterator to the element with the key.
			const_iterator find(const key_type &key) const
			{
				// It's checking if the key exists in the set.
				bool exists = _rb_tree.key_exists(key);

				if (exists)
					// It's returning an const_iterator to the node that has the key.
					return (const_iterator(_rb_tree.get_node(key), _rb_tree.get_root()));
				// Else return the end of set.
				return (end());
			}

			// It's a function that returns the number of elements with the key.
			size_type count(const key_type &key) const
			{
				// It's checking if the key exists in the set, if does not it return 0.
				if (_rb_tree.key_exists(key))
					return (0);
				// else it's exists and the count is 1.
				return (1);
			}

			// It's a function that returns an iterator to the first element that is not less than the key.
			iterator lower_bound(const key_type &k) { return (iterator(_rb_tree.lower_bound(k), _rb_tree.get_root())); }

			// It's a function that returns an const_iterator to the first element that is not less than the key.
			const_iterator lower_bound(const key_type &k) const { return (const_iterator(_rb_tree.lower_bound(k), _rb_tree.get_root())); }

			// It's a function that returns an iterator to the first element that is not more than the key.
			iterator upper_bound(const key_type &k) { return (iterator(_rb_tree.upper_bound(k), _rb_tree.get_root())); }

			// It's a function that returns an const_iterator to the first element that is not more than the key.
			const_iterator upper_bound(const key_type &k) const { return (const_iterator(_rb_tree.upper_bound(k), _rb_tree.get_root())); }

			// The bellow code is finding the first element in the set that is not less than the key and the first element in the container that is greater than the key.
			pair<const_iterator, const_iterator> equal_range(const key_type &k) const
			{
				// Finding the first element in the set that is not less than the key.
				const_iterator lower = lower_bound(k);

				// Finding the first element in the container that is greater than the key.
				const_iterator upper = upper_bound(k);

				// Return a pair of the lower_bound and upper_bound.
				return (ft::make_pair(lower, upper));
			}

			// The bellow code is finding the first element in the set that is not less than the key and the first element in the container that is greater than the key.
			pair<iterator, iterator> equal_range(const key_type &k)
			{
				// Finding the first element in the set that is not less than the key.
				iterator lower = lower_bound(k);

				// Finding the first element in the container that is greater than the key.
				iterator upper = upper_bound(k);

				// Return a pair of the lower_bound and upper_bound.
				return (ft::make_pair(lower, upper));
			}

			//////////////////////////////      Allocator:      ////////////////////////////////

			allocator_type get_allocator() const { return (_alloc); }

			/////////    bc i use rb_tree outside class so i need to use friend keyword in this case:    ////////////////////////

			// Declaring a friend function.
			template <class __Key, class __Compare, class __Alloc>
			friend bool operator==(const set<__Key, __Compare, __Alloc> &lhs,
					const set<__Key, __Compare, __Alloc> &rhs);

			// Declaring a friend function.
			template <class __Key, class __Compare, class __Alloc>
			friend bool operator<(const set<__Key, __Compare, __Alloc> &lhs,
					const set<__Key, __Compare, __Alloc> &rhs);

	};

	// It's calling the == operator in rb_tree.
	template <class Key, class Compare, class Alloc>
	bool operator==(const set<Key, Compare, Alloc> &lhs, const set<Key, Compare, Alloc> &rhs)
	{
		return (lhs._rb_tree == rhs._rb_tree);
	}

	// Defining the operator!= for the set class.
	template <class Key, class Compare, class Alloc>
	bool operator!=(const set<Key, Compare, Alloc> &lhs, const set<Key, Compare, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	// It's calling the < operator in rb_tree.
	template <class Key, class Compare, class Alloc>
	bool operator<(const set<Key, Compare, Alloc> &lhs, const set<Key, Compare, Alloc> &rhs)
	{
		return (lhs._rb_tree < rhs._rb_tree);
	}

	// Defining the operator > for the set class.
	template <class Key, class Compare, class Alloc>
	bool operator>(const set<Key, Compare, Alloc> &lhs, const set<Key, Compare, Alloc> &rhs)
	{
		return (lhs < rhs);
	}

	// Defining the operator <= for the set class.
	template <class Key, class Compare, class Alloc>
	bool operator<=(const set<Key, Compare, Alloc> &lhs, const set<Key, Compare, Alloc> &rhs)
	{
		return !(lhs > rhs);
	}

	// Defining the relational operators >= for the set class.
	template <class Key, class Compare, class Alloc>
	bool operator>=(const set<Key, Compare, Alloc> &lhs, const set<Key, Compare, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}

	// A template function that swaps the contents of two sets.
	template <class Key, class Compare, class Alloc>
	void swap(set<Key, Compare, Alloc> &lhs, set<Key, Compare, Alloc> &rhs)
	{
		lhs.swap(rhs);
	}

} // namespace ft

#endif