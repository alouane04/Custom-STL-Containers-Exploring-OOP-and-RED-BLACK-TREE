/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RB_Tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:20:28 by ariahi            #+#    #+#             */
/*   Updated: 2023/02/13 11:44:24 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include "equal.hpp"
#include "RB_Node.hpp"
#include "RB_iterator.hpp"
#include "reverse_iterator.hpp"
#include "lexicographical_compare.hpp"

namespace ft
{
	template <class T, class Comparator, class Allocator>
	class RB_Tree
	{
		public:

			// Defining the types of the RB_Tree.

			typedef T value_type;
			typedef Comparator comparator_type;
			typedef Allocator allocator_type;
			typedef T* value_type_pointer;
			typedef size_t size_type;
			typedef ft::RB_Node<value_type> *node_pointer;
			typedef RB_iterator<value_type, RB_Tree<value_type, comparator_type, allocator_type> > iterator;
			typedef RB_iterator<const value_type, RB_Tree<value_type, comparator_type, allocator_type> > const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		private:
		
			node_pointer root;
			node_pointer nil;
			size_type size;
			comparator_type comparator;
			allocator_type allocator;

		public:

			// It's the default constructor of the RB_Tree.
			RB_Tree()
			{
				nil = alloc_node();
				root = nil;
				size = 0;
				comparator = comparator_type();
				allocator = allocator_type();
			}

			// It's the comparator constructor of the RB_Tree.
			RB_Tree(const comparator_type cmp)
			{
				nil = alloc_node();
				root = nil;
				size = 0;
				comparator = cmp;
				allocator = allocator_type();
				nil->nil = true;
			}

			// It's copy constructor that copying the tree.
			RB_Tree(const RB_Tree &other)
			{
				nil = alloc_node();
				size = 0;
				comparator = other.comparator;
				allocator = other.allocator;
				nil->nil = true;
				root = copy_tree(other.root, other.nil, nil);
			}

			// It's the operator= of the RB_Tree.
			const RB_Tree<T, Comparator, Allocator> &operator=(const RB_Tree<T, Comparator, Allocator> &other)
			{
				delete_node(nil);
				free_tree(root);
				comparator = other.comparator;
				allocator = other.allocator;
				size = 0;
				nil->nil = true;
				nil = alloc_node();
				root = copy_tree(other.root, other.nil, nil);
				return (*this);
			}

			// It's freeing the tree and deleting the nil node.
			~RB_Tree()
			{
				free_tree(root);
				delete_node(nil);
			}



			// It's searching for a node in root tree with the key value.
			node_pointer search(const value_type &key) const
			{
				node_pointer node = root;
				while (node)
				{
					if (comparator(node->key_value, key))
						node = node->right;
					else if (comparator(key, node->key_value))
						node = node->left;
					else
						return (node);
				}
				return (nil);
			}

			// It's searching for the minimum value in the tree.
			node_pointer minimum(node_pointer node) const
			{
				while (node != nil && node->left != nil)
					node = node->left;
				return (node);
			}

			// It's searching for the maximum value in the tree.
			node_pointer maximum(node_pointer node) const
			{
				while (node != nil && node->right != nil)
					node = node->right;
				return (node);
			}

			// It's searching for the successor (the next greater value node) of the node.
			node_pointer successor(node_pointer node)
			{
				if (node == nil)
					return (maximum(root));
				if (node->right != nil)
					return (minimum(node->right));
				node_pointer parent = node->parent;
				while (parent != nil && node == parent->right)
				{
					node = parent;
					parent = parent->parent;
				}
				return (parent);
			}

			// It's searching for the predcessor (the next lesser value node) of the node.
			node_pointer predcessor(node_pointer node)
			{
				if (node == nil)
					return (minimum(root));
				if (node->left != nil)
					return (maximum(node->left));
				node_pointer parent = node->parent;
				while (parent != nil && node == parent->left)
				{
					node = parent;
					parent = parent->parent;
				}
				return (parent);
			}

			// The bellow code is defining the begin and end functions for the iterator, const_iterator, reverse_iterator, and const_reverse_iterator.

			iterator begin()
			{
				return (iterator(minimum(root), root));
			}

			const_iterator begin() const
			{
				return (const_iterator(minimum(root), root));
			}

			iterator end()
			{
				return (iterator(nil, root));
			}

			const_iterator end() const
			{
				return (const_iterator(nil, root));
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}

			//////////////////////////////////////////////////////////////////////////////////////////////////

			// The below code is deleting the node from the tree.
			// for more info about the algo please referce to this article:
			// https://www.programiz.com/dsa/deletion-from-a-red-black-tree
			void	Delete(node_pointer node)
			{
				node_pointer sib;
				node_pointer tmp;
				bool tmp_black;

				// It's assigning the node to the tmp.
				tmp = node;

				// It's assigning the color of the node to the tmp_black.
				tmp_black = node->black;

				// It's checking if the left child of the node is nil,
				// if it is, then the right child of the node is the sibling,
				// and the node is replaced with its right child.
				if (node->left == nil)
				{
					sib = node->right;
					transplant(node, node->right);
				}

				// It's checking if the right child of the node is nil,
				// if it is, then the left child of the node is the sibling,
				// and the node is replaced with its left child.
				else if (node->right == nil)
				{
					sib = node->left;
					transplant(node, node->left);
				}

				// if bot children present then:
				else
				{
					// It's assigning the minimum value of the right child of the node to the tmp.
					tmp = minimum(node->right);

					// It's assigning the color of the tmp (minimum value of the right child of node) to the tmp_black.
					tmp_black = tmp->black;
					
					// It's assigning the right child of the tmp (minimum value of the right child of node) to the sib.
					sib = tmp->right;
					
					// It's checking if the tmp parent equal to node,
					// if it is, then the assign the tmp to the sib parent.
					if (tmp->parent == node)
						sib->parent = tmp;
					else
					{
						transplant(tmp, tmp->right);
						tmp->right = node->left;
						tmp->right->parent = tmp;
					}
					transplant(node, tmp);
					tmp->left = node->left;
					tmp->left->parent = tmp;
					tmp->black = node->black;
				}
				size--;
				delete_node(node);
				if (tmp_black)
					delete_fix_up(sib);
			}

			// It's searching for the node with the key value,
			// if it's not found, it returns, if it's found,
			// it calls the Delete function with the node.
			void Delete(value_type key)
			{
				node_pointer node = search(key);
				if (node == nil)
					return ;
				Delete(node);
			}

			// The bellow code is inserting a node into the tree.
			// for more info about the algo please referce to this article:
			// https://www.programiz.com/dsa/insertion-in-a-red-black-tree
			void	insert_node(node_pointer node)
			{
				node_pointer x = root;
				node_pointer y = nil;

				// Finding the correct place to insert the new node.
				while (x != nil)
				{
					y = x;

					// Finding the successor of the node to be deleted.
					if (comparator(node->key_value, y->key_value))
						x = x->left;
					else
						x = x->right;
				}
				// assign node parent the successor (nil if tree empty).
				node->parent = y;

				// If the tree empty (nil) assign node to the root.
				if (y == nil)
					root = node;

				// If the node lesser than the successor assign node to the left, else to the right.
				else if(comparator(node->key_value, y->key_value))
					y->left = node;
				else
					y->right = node;

				// assign nil to the left and right node and red to the color.
				node->left = nil;
				node->right = nil;
				node->black = false;

				// fix the properties after insertion.
				insert_fix_up(node);
			}

			// Inserting a key node into the tree.
			// for more info about the algo please referce to this article:
			// https://www.programiz.com/dsa/insertion-in-a-red-black-tree
			void insert_node(const value_type &key)
			{
				insert_node(alloc_node(key));
			}

			void Clear()
			{
				free_tree(root);
				root = nil;
			}
			
			// Searching for the node with the key value.
			node_pointer 
			get_node(const value_type &key)
			{
				return (search(key));
			}

			// Returning the root node of the tree.
			node_pointer get_root()
			{
				return (root);
			}

			size_type get_size() const
			{
				return (size);
			}
			
			size_type get_max_size() const
			{
				return (allocator.max_size());
			}

			// Swapping the contents of the two RB_Trees.
			void Swap(RB_Tree &other)
			{
				std::swap(root, other.root);
				std::swap(nil, other.nil);
				std::swap(allocator, other.allocator);
				std::swap(comparator, other.comparator);
				std::swap(size, other.size);
			}

			// Checking if the key exists in the tree.
			bool key_exists(const value_type &key) const
			{
				// Searching for the key in the tree. If it is found, it returns true.
				return (search(key) != nil);
			}

			bool Empty() const
			{
				if (root == nil)
					return (true);
				return (false);
			}

			// Finding the first node that is greater than the key.
			node_pointer upper_bound(value_type key)
			{
				node_pointer _root = root;
				node_pointer ret = nil;

				while (_root != nil)
				{
					if (comparator(key, _root->key_value))
						_root = _root->right;
					else
					{
						if (ret == nil || comparator(_root->key_value, ret->key_value))
							ret = _root;
						_root = _root->left;
					}
				}
				return (ret);
			}

			// Finding the first node in the tree that is greater than or equal to the key.
			node_pointer lower_bound(value_type key)
			{
				node_pointer _root = root;
				node_pointer ret = nil;

				while (_root != nil)
				{
					if (comparator(_root->key_value, key))
						_root = _root->right;
					else
					{
						if (ret == nil || comparator(_root->key_value, ret->key_value))
							ret = _root;
						_root = _root->left;
					}
				}
				return (ret);
			}

			
			//////////////////////////////////////////////////////////////////////////////////////

			private:

			// It's replacing the node u with the node v.
			void	transplant(node_pointer u, node_pointer v)
			{
				// It's checking if the parent of the node u is nil, if it is, then the root is v.

				if (u->parent == nil)
					root = v;

				// It's checking if the node u is the left child of its parent,
				// if it is, then the left child of the parent of the node u is the node v.

				else if (u == u->parent->left)
					u->parent->left = v;

				// It's checking if the node u is the right child of its parent,
				// if it is, then the right child of the parent of the node u is the node v.

				else
					u->parent->right = v;

				// v parent take u parent.

				v->parent = u->parent;
			}


			

			// It's rotating the node to the left.
			void	left_rotation(node_pointer node)
			{
				// It's assigning the right child of the node to the sib.

				node_pointer sib = node->right;

				// It's assigning the left child of the sibling to the right child of the node.

				node->right = sib->left;

				// It's checking if the left child of the sibling is nil, if it's not, then the parent of the left child of the sibling is the node.

				if (sib->left != nil)
					sib->left->parent = node;

				// It's assigning the parent of the sibling to the parent of the node.

				sib->parent = node->parent;

				// It's checking if the parent of the node is nil, if it is, then the root is sib (right child of node).

				if (node->parent == nil)
					root = sib;

				// It's checking if the node is the left child of its parent,
						// if it is, then the left child of the parent of the node is the sib (right child of node).

				else if (node == node->parent->left)
					node->parent->left = sib;
				else
					node->parent->right = sib;
				
				// It's assigning the node to the left child of the sibling.

				sib->left = node;
				
				// It's assigning the node to the left child of the sibling.

				node->parent = sib;
			}

			// It's same as above just right instead of left ( vice versa ).
			void	right_rotation(node_pointer node)
			{
				node_pointer sib = node->left;

				node->left = sib->right;
				if (sib->right != nil)
					sib->right->parent = node;
				sib->parent = node->parent;
				if (node->parent == nil)
					root = sib;
				else if (node == node->parent->left)
					node->parent->left = sib;
				else
					node->parent->right = sib;
				sib->right = node;
				node->parent = sib;
			}


			// It's to fix the properties after the deletion,
			// for more info about the algo please referce to this article:
			// https://www.programiz.com/dsa/deletion-from-a-red-black-tree
			void delete_fix_up(node_pointer node)
			{
				node_pointer sib;
				while (node != root && node->black)
				{
					if (node == node->parent->left)
					{
						sib = node->parent->right;
						if (sib->black == false)
						{
							sib->black = true;
							node->parent->black = false;
							left_rotation(node->parent);
							sib = node->parent->right;
						}
						if (sib->left->black && sib->right->black)
						{
							sib->black = false;
							node = node->parent;
						}
						else if (sib->right->black)
						{
							sib->left->black = true;
							sib->black = false;
							right_rotation(sib);
							sib = node->parent->right;
						}
						else
						{
							sib->black = node->parent->black;
							node->parent->black = true;
							sib->right->black = true;
							left_rotation(node->parent);
							node = root;
						}
					}
					else
					{
						sib = node->parent->left;
						if (sib->black == false)
						{
							sib->black = true;
							node->parent->black = false;
							right_rotation(node->parent);
							sib = node->parent->left;
						}
						if (sib->right->black && sib->left->black)
						{
							sib->black = false;
							node = node->parent;
						}
						else if (sib->left->black)
						{
							sib->right->black = true;
							sib->black = false;
							left_rotation(sib);
							sib = node->parent->left;
						}
						else
						{
							sib->black = node->parent->black;
							node->parent->black = true;
							sib->left->black = true;
							right_rotation(node->parent);
							node = root;
						}
					}
				}
				node->black = true;
			}

			// It's to fix the properties after the insertion,
			// for more info about the algo please referce to this article:
			// https://www.programiz.com/dsa/insertion-in-a-red-black-tree
			void	insert_fix_up(node_pointer node)
			{
				while (node->parent->black == false)
				{
					if (node->parent == node->parent->parent->left)
					{
						if (node->parent->parent->right->black == false)
						{
							node->parent->parent->right->black = true;
							node->parent->black = true;
							node->parent->parent->black = false;
							node = node->parent->parent;
						}
						else
						{
							if (node == node->parent->right)
							{
								node = node->parent;
								left_rotation(node);
							}
							node->parent->black = true;
							node->parent->parent->black = false;
							right_rotation(node->parent->parent);
						}
					}
					else
					{
						if (node->parent->parent->left->black == false)
						{
							node->parent->parent->left->black = true;
							node->parent->black = true;
							node->parent->parent->black = false;
							node = node->parent->parent;
						}
						else
						{
							if (node == node->parent->left)
							{
								node = node->parent;
								right_rotation(node);
							}
							node->parent->black = true;
							node->parent->parent->black = false;
							left_rotation(node->parent->parent);
						}
					}
				}
				root->black = true;
			}




			
			//////////////////////////////////////////////////////////////////////////////////////////////////

			// It's allocating a node and constructing it with the default value of the value_type.
			node_pointer alloc_node()
			{
				node_pointer node = allocator.allocate(1);
				allocator.construct(node, value_type());
				return (node);
			}

			// It's allocating a node and constructing it with the value of the value_type.
			node_pointer alloc_node(const value_type &key)
			{
				node_pointer node = allocator.allocate(1);
				allocator.construct(node, key);
				size++;
				return (node);
			}

			// It's destroying the node and deallocating it.
			void	delete_node(node_pointer node)
			{
				allocator.destroy(node);
				allocator.deallocate(node, 1);
			}
			
			// It's freeing the tree.
			void	free_tree(node_pointer node)
			{
				if (node == nil)
					return ;
				free_tree(node->left);
				free_tree(node->right);
				delete_node(node);
				size--;
			}

			// It's copying the tree.
			node_pointer copy_tree(node_pointer node, node_pointer other_nil, node_pointer parent)
			{
				if (node == other_nil)
					return (nil);

				node_pointer new_node;

				new_node = alloc_node(node->key_value);
				new_node->nil = node->nil;
				new_node->parent = parent;
				new_node->black = node->black;
				new_node->left = copy_tree(node->left, other_nil, new_node);
				new_node->right = copy_tree(node->right, other_nil, new_node);

				return (new_node);
			}

			
	};

	// It's comparing two RB_Tree.

	// Comparing the two RB_Tree's by comparing their elements.
	template <class RB_Tree>
	bool operator<(const RB_Tree &lhs, const RB_Tree &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class RB_Tree>
	bool operator>(const RB_Tree &lhs, const RB_Tree &rhs)
	{
		return (lhs < rhs);
	}

	// Comparing the size of the two RB_Trees and then comparing the elements of the two RB_Trees.
	template <class RB_Tree>
	bool operator==(const RB_Tree &lhs, const RB_Tree &rhs)
	{
		return (lhs.get_size() == rhs.get_size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

} // namespace ft

#endif