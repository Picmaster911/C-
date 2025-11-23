#pragma once
#include <stdexcept>
class uniquePtr
{
	int* ptr = nullptr;

public:
	explicit uniquePtr (int* p = nullptr)
		: ptr(p)
	{}
	explicit uniquePtr (int value)
		:ptr(new int(value))
	{}
	~uniquePtr()
	{
		delete ptr;
	}
	// ÊÎÏÈÐÎÂÀÍÈÅ ÇÀÏÐÅÙÅÍÎ uniquePtr b(a); && operator "="
	uniquePtr(const uniquePtr&) = delete;
	uniquePtr& operator=(const uniquePtr&) = delete;

	bool isValid() const {
		return ptr != nullptr;
	}

	operator bool() const {
		return ptr != nullptr;
	}

	// MOVE-ÊÎÍÑÒÐÓÊÒÎÐ
	uniquePtr(uniquePtr&& other) noexcept
		: ptr(other.ptr)
	{
		other.ptr = nullptr;   // çàáðàëè âëàäåíèå
	}

	int& operator*() const {
		if (!ptr)
			throw std::runtime_error("Dereferencing null IntPtr");
		return *ptr;
	}
	int* operator->() const {
		if (!ptr)
			throw std::runtime_error("Accessing null IntPtr");
		return ptr;
	}

	int* getPtr() const {
		return ptr;
	}

	void reset(int* p = nullptr) {
		if (ptr != p) {
			delete ptr;
			ptr = p;
		}
	}
};

