#ifndef SMART_ARRAY_COPY_AND_SWAP_H_
#define SMART_ARRAY_COPY_AND_SWAP_H_

#include <cstddef>
#include <iostream>
#include <memory>
#include <algorithm>

template <typename T>
class SmartArray {
public:
	class Iterator {
	public:
		Iterator(T* data, size_t size, size_t idx)
			: _data(data), _size(size), _currIdx(idx) {
		}

		T& operator*() {
			return _data[_currIdx];
		}

		Iterator& operator++() {
			++_currIdx;

			return *this;
		}

		bool operator!=(const Iterator& other) {
			return _currIdx != other._currIdx;
		}

	private:
		T* _data;
		size_t _size;
		size_t _currIdx;
	};

	SmartArray(size_t size) : _size(size), _data(_size ? new T[_size]{} : nullptr) {
	}

	SmartArray(const SmartArray& other) 
		: _size(other._size), _data(_size ? new T[_size]{} : nullptr) {
		std::copy(other._data.get(), other._data.get() + _size, _data.get());
	}

	// NOTE: make intentional copy to enable copy and swap idiom
	SmartArray& operator=(SmartArray other) {
		swap(*this, other);
		return *this;
	}

	friend void swap(SmartArray& left, SmartArray& right) {
		std::swap(left._size, right._size);
		std::swap(left._data, right._data);
	}

	// disable move constructor and move assignment operator
	SmartArray(SmartArray&& other) = delete;
	SmartArray& operator=(SmartArray&& other) = delete;

	size_t getSize() const {
		return _size;
	}

	T& operator[](size_t idx) {
		return _data[idx];
	}

	void print() {
		for (size_t i = 0; i < _size; ++i) {
			std::cout << _data[i] << " ";
		}
		std::cout << std::endl;
	}

	void resize(size_t newSize) {
		if (_size == newSize) {
			return;
		}

		std::unique_ptr<T[]> newData(new T[newSize]{});

		for (size_t i = 0; (i < _size) && (i < newSize); ++i) {
			newData[i] = _data[i];
		}
		_size = newSize;

		_data = std::move(newData);
	}

	Iterator begin() {
		return Iterator(_data.get(), _size, 0);
	}

	Iterator end() {
		return Iterator(_data.get(), _size, _size);
	}

private:
	size_t _size;
	std::unique_ptr<T[]> _data;
};

#endif // !SMART_ARRAY_COPY_AND_SWAP_H_
