#pragma once
template<typename A>
class SharedPtrInt
{
private:
	A* ptr;
	size_t* count;
public:
	SharedPtrInt() : ptr(nullptr), count(nullptr) {}
	SharedPtrInt(A* p) : ptr(p)
	{
		if (p)
		{
			count = new size_t(1);
		}
		else
		{
			count = nullptr;
		}
	}
	SharedPtrInt(const A& value)
		:ptr(new A(value))
	{
		count = new size_t(1);
	}
	~SharedPtrInt()
	{
		release();
	}

	void release()
	{
		if (count)
		{
			--(*count);
			if (*count == 0)
			{
				delete ptr;
				delete count;
			}
		}
		ptr = nullptr;
		count = nullptr;
	}

	// 1. void someFunc (SharedPtrInt<int> sp) //2.SharedPtrInt<int> a(new int(5)); SharedPtrInt<int> b(a);
	SharedPtrInt(const SharedPtrInt& other)
	{
		ptr = other.ptr;
		count = other.count;
		if (count) ++(*count);
	}
	// Just a = b (1. delete a // 2. next b copy to a)
	SharedPtrInt& operator=(const SharedPtrInt& other)
	{
		if (this == &other) return *this;
		release();
		ptr = other.ptr;
		count = other.count;
		if (count) ++(*count);
		return *this;
	}

	SharedPtrInt(const SharedPtrInt&&) = delete;
	SharedPtrInt& operator=(const SharedPtrInt&&) = delete;

	bool isValid() const {
		return (ptr != nullptr);
	}
	operator bool() const {
		return (ptr != nullptr);
	}

	int GetCount()
	{
		if(count)
		return *count;
		else
		{
			return 0;
		}
	}

	sharedPtr(sharedPtr&& other) noexcept
		: ptr(other.ptr)
		, count(other.count)
	{
		other.ptr = nullptr;
		other.count = nullptr;
	}

	sharedPtr& operator=(sharedPtr&& other) noexcept {
		if (this != &other) {
			release();
			ptr = other.ptr;
			count = other.count;
			other.ptr = nullptr;
			other.count = nullptr;
		}
		return *this;
	}

	A GetPtr()
	{
		return *ptr;
	}
};
