#include "IntSearchTree.h"


IntSearchTree::~IntSearchTree()
{
}

bool IntSearchTree::add(const int &_newData)
{
#ifdef _DEBUGGING_OUTPUT
	std::cout << "Hello from public add() method" << std::endl;
#endif // _DEBUGGING_OUTPUT


	if (contains(_newData))
	{
		return false;
	}
	else // _newData not in tree already
	{
		BinaryIntNode* newNode = new BinaryIntNode{ _newData, nullptr, nullptr };
		BinaryIntNode* potentialLocation = pFind(m_rootPtr, _newData);

		if (potentialLocation == nullptr)
		{
			m_rootPtr = newNode;
		}
		else if (_newData < potentialLocation->m_data)
		{
			potentialLocation->m_leftChild = newNode;
		}
		else
		{
			potentialLocation->m_rightChild = newNode;
		}
		
		pIncrementNodeCount();
		return true;
	}


}

bool IntSearchTree::contains(const int &_target) const
{
#ifdef _DEBUGGING_OUTPUT
	std::cout << "Hello from public contains() method" << std::endl;
#endif // _DEBUGGING_OUTPUT

	BinaryIntNode* potentialLocation = pFind(m_rootPtr, _target);
	if (potentialLocation == nullptr)
	{
		return false;
	}
	else if (potentialLocation->m_data == _target)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void IntSearchTree::inorderTraversal(void visit(int))
{
	pInorder(m_rootPtr, visit);
}

bool IntSearchTree::pIsLeaf(BinaryIntNode * _root) const
{
	if ((_root->m_leftChild == nullptr) && (_root->m_rightChild == nullptr))
	{
		return true;
	}
	else
		return false;
}

IntSearchTree::BinaryIntNode * IntSearchTree::pFind(BinaryIntNode * _root, int _target) const
{
#ifdef _DEBUGGING_OUTPUT
	std::cout << "Hello from private pFind() method" << std::endl;
#endif // _DEBUGGING_OUTPUT

	if (_root == nullptr || _root->m_data == _target || pIsLeaf(_root) )
		return _root;
	
	if (_target < _root->m_data)
	{
		if (_root->m_leftChild != nullptr)
			return pFind(_root->m_leftChild, _target);
		else
			return _root;
	}
	if (_target > _root->m_data)
	{
		if (_root->m_rightChild != nullptr)
			return pFind(_root->m_rightChild, _target);
		else
			return _root;
	}
		
}

IntSearchTree::BinaryIntNode* IntSearchTree::pCreateNode(int _data) const
{
	BinaryIntNode* newNode = new BinaryIntNode{ _data, nullptr, nullptr };
	return newNode;
}

void IntSearchTree::pInorder(BinaryIntNode * _root, void visit(int))
{
}
