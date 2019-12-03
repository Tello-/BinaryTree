#pragma once
#include <iostream>
#include "BinaryTreeInterface.h"

//#define _DEBUGGING_OUTPUT

class IntSearchTree :
	public BinaryTreeInterface<int>
{

private: // node type used for this tree

	struct BinaryIntNode
	{
		BinaryIntNode(int _data = 0, BinaryIntNode* _left = nullptr, BinaryIntNode* _right = nullptr)
			: m_data{ _data }, m_leftChild{ _left }, m_rightChild{ _right } {}

		BinaryIntNode*		m_leftChild;
		BinaryIntNode*		m_rightChild;
		int					m_data;
	};


public: // public methods
	IntSearchTree() : m_rootPtr{ nullptr }, m_numNodes{ 0 } {}
	virtual ~IntSearchTree();

	virtual bool	add(const int&);
	virtual bool	isEmpty() const { return m_numNodes == 0; }
	virtual bool	contains(const int&) const;

	void			inorderTraversal(void visit(int));

private: // private methods
	bool			pIsLeaf(BinaryIntNode* _root) const;
	BinaryIntNode*	pFind(BinaryIntNode* _root, int _target) const;
	BinaryIntNode*	pCreateNode(int _data) const;
	int				pIncrementNodeCount() { return ++m_numNodes; }
	int				pDecrementNodeCount() { return --m_numNodes; }

	void			pInorder(BinaryIntNode* _root, void visit(int));


private: // private data members
	BinaryIntNode*	m_rootPtr;
	int				m_numNodes;
};

