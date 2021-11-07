/*
*Copyright(c) nameix.2021-2021.All right reserved.
*Description: circle buffer by C++
*Author: nameix
*Create: 2021-11-1
*/

#ifndef COMMON_UTILS_CIRCLEBUFFER
#define COMMON_UTILS_CIRCLEBUFFER

#include <cstdlib>

namespace commonUtils {
template <typename T> class CircleBuffer {
public:
    CircleBuffer(size_t capacity) : capacity_(capacity),size_(0),
		start_idx(0),end_idx(0)
    {
		buffer = new T[capacity];
	}
	
	~CircleBuffer()
	{
		delete[] buffer;
		buffer = NULL;
	}
	
	void Reset(size_t capacity = 1)
	{
		delete[] buffer;
		buffer = NULL;
		size_ = 0;
		start_idx = 0;
		end_idx = 0;
		buffer = new T[capacity];
	}
	
	const size_t size()
	{
		return size_;
	}
	
	const size_t capacity()
	{
		return capacity_;
	}
	
	bool empty()
	{
		return size_ == 0;
	}
	
	T& operator[](const size_t& i)
	{
		return buffer[(start_idx + i) % capacity_];
	}
	
	const T& operator[](const size_t& i) const
	{
		return buffer[(start_idx + i) % capacity_];
	}
	
	T& first()
	{
		return buffer[start_idx];
	}
	
	const T& first() const
	{
		return buffer[start_idx];
	}
	
	T& last()
	{
		size_t idx = (size_ == 0) ? 0 : (start_idx + size_ - 1) % capacity_;
		return buffer[idx];
	}
	
	const T& last() const
	{
		size_t idx = (size_ == 0) ? 0 : (start_idx + size_ - 1) % capacity_;
		return buffer[idx];
	}
	
	void push(const T& element)
	{
		buffer[end_idx] = element;
		end_idx = (end_idx + 1) % capacity_;
		if (size_ < capacity_) {
			++size_;
		} else {
			start_idx = (start_idx + 1) % capacity_;
		}
	}
	
	void pop()
	{
		end_idx = (end_idx + 1 + capacity_) % capacity_;
		--size_;
	}
private:
	size_t capacity_;
	size_t size_;
	size_t start_idx;
	size_t end_idx;
	T* buffer;
}; // class CircleBuffer 
} // commonUtils 
#endif