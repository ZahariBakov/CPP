#ifndef SMART_ARRAY_H
#define SMART_ARRAY_H

#include <cstddef>
#include <iostream>

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

	~SmartArray() {
		if (_data != nullptr) {
			delete[] _data;
			_data = nullptr;
		}
	}

	// disable copy and move constructors
	SmartArray(const SmartArray& other) = delete;
	SmartArray(SmartArray&& other) = delete;

	// disable copy and move assignment oparators
	SmartArray& operator=(const SmartArray& other) = delete;
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

		T* newData = new T[newSize]{};

		for (size_t i = 0; (i < _size) && (i < newSize); ++i) {
			newData[i] = _data[i];
		}
		_size = newSize;

		delete[] _data;
		_data = newData;
		newData = nullptr;
	}

	Iterator begin() {
		return Iterator(_data, _size, 0);
	}

	Iterator end() {
		return Iterator(_data, _size, _size);
	}

private:
	size_t _size;
	T* _data;
};

#endif // !SMART_ARRAY_H
