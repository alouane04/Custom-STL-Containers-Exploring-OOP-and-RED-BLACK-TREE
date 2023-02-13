/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:55:27 by ariahi            #+#    #+#             */
/*   Updated: 2023/02/13 12:08:40 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "RB_Tree.hpp"
#include <iostream>
#include "pair.hpp"
#include "map"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > > 
	class map
	{
		public:

			// It's a typedef that allows to use the type of the attribute instead of the attribute itself.
			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef Allocator allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;


			// It's a nested class that is used to compare two values of the map.
			class value_compare
			{
				private:

					// It's a friend declaration that allows the map class to access the private and protected members of the value_compare class.
					template <class T_1, class T_2, class T_3, class T_4>
					friend class map;

					// It's a friend declaration that allows the RB_Tree class to access the private and protected members of the value_compare class.
					template <class T_1, class T_2, class T_3>
					friend class RB_Tree;

				protected:
					Compare _comp;
					
					// It's a constructor of the value_compare class that takes a const Compare &c as parameter and initializes the comp attribute with the c parameter.
					value_compare(const Compare &c = Compare()) : _comp(c) {}
					
				public:
				 	typedef bool result_type;
 					typedef value_type first_argument_type;
 					typedef value_type second_argument_type;
					// It's a function that compares two values of the map.
					bool operator()(const value_type &x, const value_type &y) const
					{
						return (_comp(x.first, y.first));
					}
			};

			typedef ft::RB_Tree<value_type, value_compare, typename Allocator::template rebind<ft::RB_Node<value_type> >::other> rb_tree;

			typedef typename rb_tree::iterator iterator;
			typedef typename rb_tree::const_iterator const_iterator;
			typedef typename rb_tree::reverse_iterator reverse_iterator;
			typedef typename rb_tree::const_reverse_iterator const_reverse_iterator;

		private:

			// size_type _size;
			allocator_type _alloc;
			key_compare _key_compare;
			value_compare _value_comp;
			rb_tree _rb_tree;

		public:

			// It's the default constructor of the map class.
			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _key_compare(comp), _value_comp(value_compare(comp)), _rb_tree(_value_comp) {}

			// It's a range constructor that takes two iterators first, last as parameters.
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _key_compare(comp), _value_comp(value_compare(comp)), _rb_tree(_value_comp) {insert(first, last);}

			// It's the copy constructor of the map class.
			map(const map &other)
			{
				// _size = other._size;
				_alloc = other._alloc;
				_value_comp = other._value_comp;
				_key_compare = other._key_compare;
				_rb_tree = other._rb_tree;
			}

			// It's the destructor of the map class.
			~map() {}

			// It's the assignment operator of the map class.
			map &operator=(const map &other)
			{
				if (this != &other)
				{
					_alloc = other._alloc;
					_key_compare = other._key_compare;
					_value_comp = other._value_comp;
					_rb_tree = other._rb_tree;
				}
				return (*this);
			}

			//////////////////////////////// ITERATORS //////////////////////////////////

			// It's a function that returns an iterator to the first element of the map.
			iterator begin()
			{
				return (_rb_tree.begin());
			}

			// It's a function that returns a const_iterator to the first element of the map.
			const_iterator begin() const
			{
				return (_rb_tree.begin());
			}

			// It's a function that returns an iterator to the last element of the map.
			iterator end()
			{
				return (_rb_tree.end());
			}

			// It's a function that returns a const_iterator to the last element of the map.
			const_iterator end() const
			{
				return (_rb_tree.end());
			}

			// It's a function that returns a reverse_iterator to the first element of the map.
			reverse_iterator rbegin()
			{
				return (_rb_tree.rbegin());
			}

			// It's a function that returns a const_reverse_iterator to the first element of the map.
			const_reverse_iterator rbegin() const
			{
				return (_rb_tree.rbegin());
			}

			// It's a function that returns a reverse_iterator to the last element of the map.
			reverse_iterator rend()
			{
				return (_rb_tree.rend());
			}

			// It's a function that returns a const_reverse_iterator to the last element of the map.
			const_reverse_iterator rend() const
			{
				return (_rb_tree.rend());
			}

			///////////////////////////    Capacity:     ///////////////////////////////

			// It's a function that returns true if the map is empty and false otherwise.
			bool empty() const
			{
				return (_rb_tree.Empty());
			}

			// It's a function that returns the size of the map.
			size_type size() const
			{
				return (_rb_tree.get_size());
			}

			// It's a function that returns the maximum size of the map.
			size_type max_size() const
			{
				return (_rb_tree.get_max_size());
			}

			////////////////////////////	Element access:    ////////////////////////////////

			// Creating a new element if the key is not found.
			mapped_type &operator[](const key_type &key)
			{
				iterator it = find(key);
				if (it == end())
					return (insert(ft::make_pair(key, mapped_type())).first->second);
				return((*it).second /*it->second*/);
			}

			// It's a function that returns the value associated with the key k.
			mapped_type &at(const mapped_type &k)
			{
				iterator it = find(k);
				if (it == end())
					throw std::out_of_range("map::at:  key not found");
				return((*it).second /*it->second*/);
			}

			// It's a const function that returns the value associated with the key k.
			const mapped_type &at(const mapped_type &k) const
			{
				iterator it = find(k);
				if (it == end())
					throw std::out_of_range("map::at:  key not found");
				return((*it).second /*it->second*/);
			}

			////////////////////////////	Modifiers:     ////////////////////////////////

			// It's a function that inserts a new element in the map and return pair with ierator the value and bool indicate that if the value already exist.
			ft::pair<iterator, bool> insert(const value_type &value)
			{
				// It's checking if the key exists in the map.
				bool exists = _rb_tree.key_exists(value);

				// If exist return pair with iterator to the existing value and false
				if (exists)
					return (ft::pair<iterator, bool>(iterator(_rb_tree.get_node(value), _rb_tree.get_root()), !exists));

				// Else insert the value to the tree and return pair with iterator to the new value and true
				_rb_tree.insert_node(value);
				return (ft::pair<iterator, bool>(iterator(_rb_tree.get_node(value), _rb_tree.get_root()), !exists));
			}

			// It's a function that inserts a new element in the map and return iterator.
			iterator insert(iterator position, const value_type &value) { return ((void)position, insert(value).first); }
			
			// It's a function that inserts a range of elements in the map.
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
				// It's checking if the key exists in the map, if so it delete it and return true.
				if (_rb_tree.key_exists(ft::make_pair(key, mapped_type())))
					return (_rb_tree.Delete(_rb_tree.get_node(ft::make_pair(key, mapped_type()))), 1);
				// Else false
				return (0);
			}

			// It's a function that deletes all the elements between the first and the last iterator.
			void erase(iterator first, iterator last)
			{
				iterator it;

				// It's a way to save the first iterator in order to increment it in the for loop.
				it = first;
				for (; first != last; first = it)
				{	it++;
					_rb_tree.Delete(*first);
				}
			}

			// It's a function that swaps the content of the map with the content of the map x.
			void swap(map &x)
			{
				std::swap(_alloc, x._alloc);
				std::swap(_key_compare, x._key_compare);
				std::swap(_value_comp, x._value_comp);
				_rb_tree.Swap(x._rb_tree);
			}

			// It's a function that deletes all the elements of the map.
			void clear() { _rb_tree.Clear(); }

			////////////////////////////    Observers:    ////////////////////////////////////

			// It's a function that returns the key_compare object.
			key_compare key_comp() const
			{
				return (_key_compare);
			}

			// It's a function that returns the value_compare object.
			value_compare value_comp() const
			{
				return (_value_comp);
			}

			////////////////////////////    Operations:    //////////////////////////////////

			// It's a function that returns an iterator to the element with the key.
			iterator find(const key_type &key)
			{
				// It's checking if the key exists in the map true if does.
				bool exists = _rb_tree.key_exists(ft::make_pair(key, mapped_type()));

				if (exists)
					// It's returning an iterator to the node that has the key.
					return (iterator(_rb_tree.get_node(ft::make_pair(key, mapped_type())), _rb_tree.get_root()));
				// Else return the end of map.
				return (end());
			}

			// It's a function that returns a const_iterator to the element with the key.
			const_iterator find(const key_type &key) const
			{
				// It's checking if the key exists in the map.
				bool exists = _rb_tree.key_exists(ft::make_pair(key, mapped_type()));

				// If true it's returning an const_iterator to the node that has the key.
				if (exists)
					return (const_iterator(_rb_tree.get_node(ft::make_pair(key, mapped_type())), _rb_tree.get_root()));
				// Else return the end of map.
				return (end());
			}

			// It's a function that returns the number of elements with the key.
			size_type count(const key_type &key) const
			{
				// It's checking if the key exists in the map, if does not it return 0.
				if (_rb_tree.key_exists(ft::make_pair(key, mapped_type())))
					return (0);
				// else it's exists and the count is 1.
				return (1);
			}

			// It's a function that returns an iterator to the first element that is not less than the key.
			iterator lower_bound(const key_type &k) { return (iterator(_rb_tree.lower_bound(value_type(k, mapped_type())), _rb_tree.get_root())); }

			// It's a function that returns an const_iterator to the first element that is not less than the key.
			const_iterator lower_bound(const key_type &k) const { return (const_iterator(_rb_tree.lower_bound(value_type(k, mapped_type())), _rb_tree.get_root())); }

			// It's a function that returns an iterator to the first element that is not more than the key.
			iterator upper_bound(const key_type &k) { return (iterator(_rb_tree.upper_bound(value_type(k, mapped_type())), _rb_tree.get_root())); }

			// It's a function that returns an const_iterator to the first element that is not more than the key.
			const_iterator upper_bound(const key_type &k) const { return (const_iterator(_rb_tree.upper_bound(value_type(k, mapped_type())), _rb_tree.get_root())); }

			// The bellow code is finding the first element in the map that is not less than the key and the first element in the container that is greater than the key.
			pair<const_iterator, const_iterator> equal_range(const key_type &k) const
			{
				// Finding the first element in the map that is not less than the key.
				const_iterator lower = lower_bound(k);

				// Finding the first element in the container that is greater than the key.
				const_iterator upper = upper_bound(k);

				// Return a pair of the lower_bound and upper_bound.
				return (ft::make_pair(lower, upper));
			}

			// The bellow code is finding the first element in the map that is not less than the key and the first element in the container that is greater than the key.
			pair<iterator, iterator> equal_range(const key_type &k)
			{
				// Finding the first element in the map that is not less than the key.
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
			template <class __Key, class __T, class __Compare, class __Alloc>
			friend bool operator==(const map<__Key, __T, __Compare, __Alloc> &lhs,
					const map<__Key, __T, __Compare, __Alloc> &rhs);

			// Declaring a friend function.
			template <class __Key, class __T, class __Compare, class __Alloc>
			friend bool operator<(const map<__Key, __T, __Compare, __Alloc> &lhs,
					const map<__Key, __T, __Compare, __Alloc> &rhs);

	};

	// It's calling the == operator in rb_tree.
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (lhs._rb_tree == rhs._rb_tree);
	}

	// Defining the operator!= for the map class.
	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	// It's calling the < operator in rb_tree.
	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (lhs._rb_tree < rhs._rb_tree);
	}

	// Defining the operator > for the map class.
	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (lhs < rhs);
	}

	// Defining the operator <= for the map class.
	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs > rhs);
	}

	// Defining the relational operators >= for the map class.
	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}

	// A template function that swaps the contents of two maps.
	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc> &lhs, map<Key, T, Compare, Alloc> &rhs)
	{
		lhs.swap(rhs);
	}

} // namespace ft

#endif