#pragma once

template<typename T>
class BinaryTreeInterface
{
public:
	virtual ~BinaryTreeInterface() {}

	virtual bool	add(const T&) = 0;
	virtual bool	isEmpty() const = 0;
	virtual bool	contains(const T&) const = 0;

};