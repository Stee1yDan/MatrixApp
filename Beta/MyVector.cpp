using namespace std;

template<typename T> class MyVector
{
private:
	T* arr;
	int size;
	int capacity;
public:
	MyVector()
	{
		size = 0;
		capacity = 1;
	}

	MyVector(int currentSize)
	{
		size = currentSize;
		capacity = currentSize;

		T* arr;

		arr = new T[currentSize];
	}

	T* begin()
	{
		return arr;
	}

	T* end()
	{
		return arr  + size;
	}

	// if size < capacity push
	// if size == allocate new array

	void newAllocation()
	{
		T* temp = new T[size + 5];
		capacity = size + 5;

		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}

		arr = temp;

		delete[] temp;
	}

	void push_back(const T& element)
	{
		if (size == capacity)
		{
			newAllocation();
		}

		arr[size] = element;
		size++;
	}

	void pop_back()
	{
		if (size != 0)
		{
			return;
		}

		size--;
	}

	void erase(T* pointer)
	{
		size_t k = pointer - begin();

		for (size_t i = k; i < size; i++)
		{
			arr[i] = arr[i + 1];
		}

		size--;

	}

	int getSize()
	{
		return size;
	}

	int getCapacity()
	{
		return capacity;
	}

	T& operator[](int index)
	{
		return arr[index];
	}

};
