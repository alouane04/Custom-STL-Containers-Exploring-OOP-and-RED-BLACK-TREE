/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:39:38 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/28 19:34:33 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>
#include <memory>

#include "lexicographical_compare.hpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"
#include "is_integral.hpp"
#include "enable_if.hpp"
#include "equal.hpp"
#include "pair.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
		
			// It's defining the types of the vector.

			typedef T														value_type;
			typedef Allocator												allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference 				reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef typename allocator_type::size_type						size_type;
			typedef typename allocator_type::difference_type				difference_type;
			typedef typename ft::random_access_iterator<value_type>			iterator;
			typedef typename ft::random_access_iterator<const value_type>	const_iterator;
			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> 			const_reverse_iterator;
		
		private:

			allocator_type _allocator;
			size_type _capacity;
			size_type _size;
			pointer _array;

		public:

		//////////////////////////////////// CONSTRUCTORS /////////////////////////////////////
		

			// It's a default constructor
 
			explicit vector(const allocator_type &alloc = allocator_type()) : _allocator(alloc)
			{
				_capacity = 0;
				_size = 0;
				_array = NULL;
			}

			// It's a fill constructor that takes a size and a value
			// 		and allocates an array of that size and fills it with the value.

			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _allocator(alloc), _array(NULL)
			{
				_capacity = n;
				_size = n;
				_array = _allocator.allocate(n);
				for (size_type i = 0; i < _size; ++i)
				{
					_allocator.construct(_array + i, val);
				}
			}

			// It's a constructor that takes two iterators
			// 		and allocates an array of the size of the distance between the two iterators
			//			and fills it with the values between the two iterators.

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()) : _allocator(alloc), _array(NULL), _size(ft::distance(first, last)), _capacity(ft::distance(first, last))
			{
				_array = _allocator.allocate(_capacity);
				for (size_type i = 0; i < _size; ++i)
				{
					_allocatr.construct(_array + i, *first++);
				}
			}
			
			// It's a copy constructor.

			vector(const vector &other) : _array(NULL), _allocator(other._allocator), _size(other._size), _capacity(other._size)
			{
				_array = _allocator.allocate(other._capacity);
				for (size_type i = 0; i < other._size; ++i)
				{
					_allocator.construct(_array + i, other._array[i]);
				}
			}
			
			// It's a destructor that calls the clear function and then deallocates the array.

			~vector()
			{
				clear();
				_allocator.deallocate(_array, _capacity);
			}

			// It's checking if the vector is different from the other vector, and if it is,
			// 	it assigns the other vector to the vector.

			vector &operator=(const vector &other)
			{
				if (*this != other)
					assign(other.begin(), other.end());
				return (*this);
			}

		///////////////////////////////////// ITERATORS ///////////////////////////////////////////

			// It's returning an iterator to the first element of the array.

			iterator begin()
			{
				return (iterator(_array));
			}

			const_iterator begin() const
			{
				return (const_iterator(_array));
			}

			// It's returning an iterator to the last element of the array.

			iterator end()
			{
				return (iterator(_array + _size));
			}

			const_iterator end() const
			{
				return (const_iterator(_array + _size));
			}

			// It's returning a reverse iterator to the last element of the array.
			
			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}
			
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}

			// It's returning a reverse iterator to the first element of the array.

			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}
			
		//////////////////////////////////// CAPACITY //////////////////////////////////////////

			// It's returning the size of the vector.

			size_type size() const
			{
				return (_size);
			}

			// It's returning the maximum size of the vector provided by the allocator.

			size_type max_size() const
			{
				return (_allocator.max_size());
			}

			// It's resizing the vector.

			void resize (size_type n, value_type val = value_type())
			{
				// It's checking if the size of the vector is smaller than the capacity of the vector,
				//		and if it is, it's adding the value to the vector.
				if (n > _capacity)
					for (size_type i = _size; i < n; i++)
					{
						if (_capacity == _size)
						{
							if (_capacity == 0)
								size_type capacity = 1;
							else
								size_type capacity = _capacity + 1;
							reserve(capacity);
						}
						_data[_size] = val;
						_size++;
					}
			}

			// It's returning the capacity of the vector.

			size_type capacity() const
			{
				return (_capacity);
			}

			// It's checking if the vector is empty.
			
			bool empty() const
			{
				return (_size == 0);
			}

			// It's checking if the size of the vector is smaller than the capacity of the vector,
			//		and if it is, it's adding the value to the vector.
			void	reserve(size_type n)
			{
				if (n > max_size())
					throw std::length_error("vector::reserve");
				if (n > _capacity)
				{
					pointer alloc = _allocator.allocate(n);
					for (size_type i = 0; i < _size; i++)
					{
						_allocator.construct(alloc + i, _array[i]);
						_allocator.destroy(_array + i);
					}
					_allocator.deallocate(_array, _capacity);
					_capacity = n;
					_array = alloc;
				}
			}
		
		///////////////////////////// ELEMENT ACCES //////////////////////////////////
		
			//	It's returning the value of the array at the index n.

			reference operator[](size_type n)
			{
				return (_array[n]);
			}

			const_reference operator[](size_type n) const
			{
				return (_array[n]);
			}

			// It's returning the value of the array at the index n.

			reference at(size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("vector::at");
				return (_array[n]);
			}

			const_reference at(size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("vector::at");
				return (_array[n]);
			}

			// It's returning the first element of the array.

			reference front()
			{
				return (_array[0]);
			}

			const_reference front() const
			{
				return (_array[0]);
			}

			// It's returning the last element of the array.

			reference back(void)
			{
				return (_array[_size - 1]);
			}

			const_reference back(void) const
			{
				return (_array[_size - 1]);
			}
		
		////////////////////////////// MODIFIERS //////////////////////////////////


			// It's assigning the values of the vector to the values between the two iterators.

			template <class InputIterator>
			void assing(InputIterator first, InputIterator last, typenamef ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
			{
				clear();
				size_type size = ft::distance(first, last);
				if (n > capacity)
				{
					_allocator.deallocate(_array, _capacity);
					_array = _allocator.allocate(n);
					_capacity = n;
				}
				while (first != last)
				{
					_allocator.construct(&_array + _size++, first++);
				}
			}

			// It's assigning the one val n time.

			void	assign(size_type n, const value_type &val)
			{
				clear();
				if (_capacity < n)
				{
					_allocator.deallocate(_array, _capacity);
					_array = _allocator.allocate(n);
					_capacity = n;
				}
				for (size_type i = 0; i < n; i++)
				{
					_allocator.construct(&_array[i], val);
				}
				_size = n;
			}

			// It's swapping the values of the vector with the values of the other vector.

			void swap(vector &other)
			{
				std::swap(_allocator, other._allocator);
				std::swap(_capacity, other._capacity);
				std::swap(_array, other._array);
				std::swap(_size, other._size);
			}

			// It's destroying the elements of the array and setting the size of the array to 0.

			void clear()
			{
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(_array + i);
				_size = 0;
			}

			// It's returning the allocator of the vector.

			allocator_type get_allocator() const
			{
				return (_allocator);
			}

			// It's destroying the last element of the array and decreasing the size of the array.
			void	pop_back()
			{
				_allocator.destroy(_array + _size - 1);
				_size--;	
			}

			// If no capacity available it add double 
			// and it's add the val to the data and add one to the size

			void	push_back(const value_type &val)
			{
				if (_size == _capacity)
				{
					if (_capacity == 0)
						reserve(1);
					else
						reserve(_capacity * 2);
				}
				_array[_size++] = val;
			}

			// It's inserting the value at the position of the iterator.

			iterator insert(iterator pos, const value_type &value)
			{
				size_type position = pos - begin();
				
				if (_size == _capacity)
				{
					if (_capacity == 0)
						reserve(1);
					else
						reserve(_capacity * 2);
					// It's updating the position of the iterator.
					pos = position + begin();
				}

				// It's moving the elements of the array to the right.

				for (size_type i = _size; i > position; i--)
				{
					_array[i] = _array[i - 1];
				}

				// adding the value to the array and returning the iterator to the position.

				_array[position] = value;
				_size++;
				return (begin() + position);
			}

			// Inserting n elements of value value at position pos.

			void	insert(iterator pos, size_type n, const value_type &value)
			{
				size_type position = pos - begin();
				
				if (n == 0)
					return ;
					
				if (_capacity == 0)
					reserve(n);
				else if (_capacity < _size + n)
				{
					reserve(_capacity * 2);
					pos = position + begin();
				}
				
				// It's moving the elements of the array to the right and considering n.

				for (size_type i = _size; i > position; i--)
				{
					_array[i + (n - 1)] = _array[i - 1];
				}

				// It's adding the value n times to the array.

				for (size_type i = 0; i < n; i++)
				{
					_array[position + i] = value;
				}
				_size += n;
			}

			// It's inserting elements from the array pointed to by first to the array pointed to by pos.

			template <typename InputIterator>
				void insert (iterator pos, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			{
				size_type position = pos - begin();
				
				size_type dist = last - first;
				
				if (_capacity == 0)
					reserve(dis);
				else if (_capacity < _size + dist)
				{
					reserve(_capacity * 2 + dist);
					pos = position + begin();
				}

				//	It's moving the elements of the array to the right and considering dist.

				for (size_type i = _size; i < position; i--)
				{
					_array[i + dist - 1] = _array[i - 1];
				}

				// Copying the elements from the array pointed to by first to the array pointed to by _array.

				for (size_type i = 0; i < dist; i++)
				{
					_array[position + i] = 	*first++;
				}
				_size += dist;
			}

			iterator erase(iterator pos)
			{
				return (erase(pos, pos + 1));
			}

			// Erasing the elements from the vector.

			iterator erase(iterator first, iterator last)
			{

				// Finding the distance between the first and last iterators.

				size_type start = ft::distance(begin(), first);
				size_type end = ft::distance(begin(), last);
				
				// Destroying the elements in the array.

				for (size_type i = start; i < end; i++)
				{
					_allocator.destroy(_array + i);
				}

				// Moving the elements after the erased elements to the left.

				size_type mark = ft::distance(first, last);
				for (size_type i = end; i < _size; i++)
				{
					_allocator.construct(&_array[i - mark], _array[i]);
					_allocator.destroy(_array + i);
				}

				_size -= mark;
				return (first);
			}

	};

	////////////////////////////////////// NON-MEMBER ////////////////////////////////////////
	
	// Defining the relational operators for the vector class.

	template<class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
		
	template<class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
		
	template<class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(rhs < lhs));
	}
		
	template<class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &lhs, vector<T, Alloc> &rhs)
	{
		lhs.swap(rhs);
	}

}

#endif