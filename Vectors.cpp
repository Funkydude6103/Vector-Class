#include<iostream>
using namespace std;
template<typename T>
class Vector {
private:
	T* Data;
	int Size;
	int Capacity;
	int count;
	void ReAlloc(int newCapacity)
	{
		T* newBlock = new T[newCapacity];
		if (newCapacity < Size)
		{
			Size = newCapacity;
		}

		for (int i = 0; i < Size; i++)
		{
			newBlock[i] = Data[i];
		}
		delete[] Data;
		Data = newBlock;
		Capacity = newCapacity;
	}
	int partition(T* arr, int start, int end)
	{

		int pivot = arr[start];

		int count = 0;
		for (int i = start + 1; i <= end; i++) {
			if (arr[i] <= pivot)
				count++;
		}

		// Giving pivot element its correct position
		int pivotIndex = start + count;
		swap(arr[pivotIndex], arr[start]);

		// Sorting left and right parts of the pivot element
		int i = start, j = end;

		while (i < pivotIndex && j > pivotIndex) {

			while (arr[i] <= pivot) {
				i++;
			}

			while (arr[j] > pivot) {
				j--;
			}

			if (i < pivotIndex && j > pivotIndex) {
				swap(arr[i++], arr[j--]);
			}
		}

		return pivotIndex;
	}
	void quickSort(T* arr, int start, int end)
	{

		// base case
		if (start >= end)
			return;

		// partitioning the array
		int p = partition(arr, start, end);

		// Sorting the left part
		quickSort(arr, start, p - 1);

		// Sorting the right part
		quickSort(arr, p + 1, end);
	}

public:
	Vector()
	{
		count = 0;
		ReAlloc(2);
	}
	Vector(int i)
	{
		count = 0;
		ReAlloc(2);
		for (int j = 0; j < i; j++)
		{
			T a = 0;
			this->PushBack(a);
		}
	}
	~Vector()
	{
		delete[] Data;
	}
	Vector<T>& operator=(const Vector<T>& classObj)
	{
		Size = classObj.Size;
		Capacity = classObj.Capacity;
		Data = new T[Size];
		for (int i = 0; i < Size; i++)
		{
			Data[i] = classObj.Data[i];
		}
		return *this;
	}
	void PushBack(T value)
	{
		count++;
		if (Size >= Capacity)
		{
			ReAlloc(Capacity + Capacity / 2);
		}
		Data[Size] = value;
		Size++;
	}
	int size() { return Size; }
	const T& operator[] (int index) const
	{
		if (index >= Size)
		{
			cout << "Subscript Out of Range\n";
			exit(0);
		}
		return Data[index];
	}
	T& operator [] (int index)
	{
		if (index >= Size)
		{
			cout << "Subscript Out of Range\n";
			exit(0);
		}
		return Data[index];
	}
	void Pop_back()
	{
		count--;
		Size--;
	}
	void sort()
	{
		quickSort(Data, 0, Size - 1);
	}
	size_t max_size()
	{
		return size_t(-1) / sizeof(T);
	}
	bool empty()
	{
		if (Size == 0 && count <= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	T& at(int index)
	{
		if (index >= Size)
		{
			cout << "Subscript Out of Range\n";
			exit(0);
		}
		return Data[index];
	}
	T& front()
	{
		return *Data;
	}
	T& back()
	{
		return *(Data + (Size - 1));
	}
	T* data()
	{
		return Data;
	}
	void assign(int s, T a)
	{
		ReAlloc(s);
		this->Size = 0;
		for (int i = 0; i < s; i++)
		{
			this->PushBack(a);
		}
	}
	void assign(T* a, T* b)
	{
		ReAlloc(2);
		this->Size = 0;
		for (int i = 0; *(a) != *b; i++)
		{
			this->PushBack(*a);
			a++;
		}

	}
	void clear()
	{
		this->Size = 0;
		delete[] Data;
		ReAlloc(2);
	}
	bool operator==(const Vector<T>& classObj)
	{
		if (this->Size != classObj.Size)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < Size; i++)
			{
				if (this->Data[i] == classObj.Data[i])
				{
				}
				else
				{
					return false;
				}
			}
		}
		return true;
	}
	bool operator!=(const Vector<T>& classObj)
	{
		if (this->Size != classObj.Size)
		{
			return true;
		}
		else
		{
			for (int i = 0; i < Size; i++)
			{
				if (this->Data[i] == classObj.Data[i])
				{
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}
	class itteraotor {
	private:
		T* Pointer;
	public:
		itteraotor()
		{
			Pointer = 0;
		}
		itteraotor(T* Location)
		{
			Pointer = Location;
		}
		bool operator!=(itteraotor otherPointer)
		{
			if (Pointer != otherPointer.Pointer)
				return true;
			return false;
		}
		itteraotor& operator++()
		{
			Pointer++;
			return *this;
		}
		itteraotor& operator++(int i)
		{
			itteraotor Copy;
			Copy.Pointer = this->Pointer;
			Pointer++;
			return Copy;
		}
		itteraotor& operator--()
		{
			--Pointer;
			return *this;
		}
		T& operator*()
		{
			return *Pointer;
		}
		itteraotor& operator+(int number)
		{
			this->Pointer += number;
			return *this;
		}
		itteraotor& operator-(int number)
		{
			this->Pointer -= number;
			return *this;
		}
		int operator-(itteraotor& SecondIterator)
		{
			return (Pointer - SecondIterator.Pointer);
		}
	};
	itteraotor begin()
	{
		return itteraotor(Data);
	}
	itteraotor end()
	{
		return itteraotor(Data + Size);
	}
	itteraotor insert(itteraotor i, T value)
	{
		Size = Size + 1;
		itteraotor e = this->end();
		int k = 0;
		for (int j = Size - 1; j >= 0; j--)
		{
			if (i != e)
			{
				this->Data[j] = this->Data[j - 1];
				e = e - 1;
			}
			else
			{
				break;
			}
		}
		*e = value;
		return i;
	}
	void erase(itteraotor k)
	{
		itteraotor b = this->begin();
		for (int i = 0; i < Size; i++)
		{
			if (b != k)
			{
				b++;
			}
			else
			{
				for (int j = i; j < (Size - 1); j++)
					this->Data[j] = this->Data[j + 1];
				i--;
				this->Size = this->Size - 1;
				break;
			}
		}

	}
	void insert(int p, T a)
	{
		T* newBlock = new T[Size];
		for (int i = 0; i < Size; i++)
		{
			newBlock[i] = Data[i];
		}
		Data = new T[Size + 1];
		int m = 0;
		for (int i = 0; i < Size + 1; i++)
		{
			if (i != p)
			{
				Data[i] = newBlock[m];
				m++;
			}
		}
		delete[]newBlock;
		Size = Size + 1;
		Data[p] = a;
	}
	void print()
	{
		for (int i = 0; i < Size; i++)
		{
			cout << Data[i] << " ";
		}
		cout << endl;
	}


};

template<>
class Vector<bool> {
private:
	bool* Data;
	int Size;
	int Capacity;
	int count;
	void ReAlloc(int newCapacity)
	{
		bool* newBlock = new bool[newCapacity];
		if (newCapacity < Size)
		{
			Size = newCapacity;
		}

		for (int i = 0; i < Size; i++)
		{
			newBlock[i] = Data[i];
		}
		delete[] Data;
		Data = newBlock;
		Capacity = newCapacity;
	}
	int partition(bool* arr, int start, int end)
	{

		int pivot = arr[start];

		int count = 0;
		for (int i = start + 1; i <= end; i++) {
			if (arr[i] <= pivot)
				count++;
		}

		// Giving pivot element its correct position
		int pivotIndex = start + count;
		swap(arr[pivotIndex], arr[start]);

		// Sorting left and right parts of the pivot element
		int i = start, j = end;

		while (i < pivotIndex && j > pivotIndex) {

			while (arr[i] <= pivot) {
				i++;
			}

			while (arr[j] > pivot) {
				j--;
			}

			if (i < pivotIndex && j > pivotIndex) {
				swap(arr[i++], arr[j--]);
			}
		}

		return pivotIndex;
	}
	void quickSort(bool* arr, int start, int end)
	{

		// base case
		if (start >= end)
			return;

		// partitioning the array
		int p = partition(arr, start, end);

		// Sorting the left part
		quickSort(arr, start, p - 1);

		// Sorting the right part
		quickSort(arr, p + 1, end);
	}

public:
	Vector()
	{
		count = 0;
		ReAlloc(2);
	}
	Vector(int i)
	{
		count = 0;
		ReAlloc(2);
		for (int j = 0; j < i; j++)
		{
			bool a = 0;
			this->PushBack(a);
		}
	}
	~Vector()
	{
	}
	Vector<bool>& operator=(const Vector<bool>& classObj)
	{
		Size = classObj.Size;
		Capacity = classObj.Capacity;
		Data = new bool[Size];
		for (int i = 0; i < Size; i++)
		{
			Data[i] = classObj.Data[i];
		}
		return *this;
	}
	void PushBack(bool value)
	{
		count++;
		if (Size >= Capacity)
		{
			ReAlloc(Capacity + Capacity / 2);
		}
		Data[Size] = value;
		Size++;
	}
	int size() { return Size; }
	const bool& operator[] (int index) const
	{
		if (index >= Size)
		{
			cout << "Subscript Out of Range\n";
			exit(0);
		}
		return Data[index];
	}
	bool& operator [] (int index)
	{
		if (index >= Size)
		{
			cout << "Subscript Out of Range\n";
			exit(0);
		}
		return Data[index];
	}
	void Pop_back()
	{
		count--;
		Size--;
	}
	void sort()
	{
		quickSort(Data, 0, Size - 1);
	}
	size_t max_size()
	{
		return size_t(-1) / sizeof(bool);
	}
	bool empty()
	{
		if (Size == 0 && count <= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool& at(int index)
	{
		if (index >= Size)
		{
			cout << "Subscript Out of Range\n";
			exit(0);
		}
		return Data[index];
	}
	bool& front()
	{
		return *Data;
	}
	bool& back()
	{
		return *(Data + (Size - 1));
	}
	bool* data()
	{
		return Data;
	}
	void assign(int s, bool a)
	{
		ReAlloc(s);
		this->Size = 0;
		for (int i = 0; i < s; i++)
		{
			this->PushBack(a);
		}
	}
	void assign(bool* a, bool* b)
	{
		ReAlloc(2);
		this->Size = 0;
		for (int i = 0; *(a) != *b; i++)
		{
			this->PushBack(*a);
			a++;
		}

	}
	void clear()
	{
		this->Size = 0;
		delete[] Data;
		ReAlloc(2);
	}
	bool operator==(const Vector<bool>& classObj)
	{
		if (this->Size != classObj.Size)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < Size; i++)
			{
				if (this->Data[i] == classObj.Data[i])
				{
				}
				else
				{
					return false;
				}
			}
		}
		return true;
	}
	bool operator!=(const Vector<bool>& classObj)
	{
		if (this->Size != classObj.Size)
		{
			return true;
		}
		else
		{
			for (int i = 0; i < Size; i++)
			{
				if (this->Data[i] == classObj.Data[i])
				{
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}
	class itteraotor {
	private:
		bool* Pointer;
	public:
		itteraotor()
		{
			Pointer = 0;
		}
		itteraotor(bool* Location)
		{
			Pointer = Location;
		}
		bool operator!=(itteraotor otherPointer)
		{
			if (Pointer != otherPointer.Pointer)
				return true;
			return false;
		}
		itteraotor& operator++()
		{
			Pointer++;
			return *this;
		}
		itteraotor& operator++(int i)
		{
			itteraotor Copy;
			Copy.Pointer = this->Pointer;
			Pointer++;
			return Copy;
		}
		itteraotor& operator--()
		{
			--Pointer;
			return *this;
		}
		bool& operator*()
		{
			return *Pointer;
		}
		itteraotor& operator+(int number)
		{
			this->Pointer += number;
			return *this;
		}
		itteraotor& operator-(int number)
		{
			this->Pointer -= number;
			return *this;
		}
		int operator-(itteraotor& SecondIterator)
		{
			return (Pointer - SecondIterator.Pointer);
		}
	};
	itteraotor begin()
	{
		return itteraotor(Data);
	}
	itteraotor end()
	{
		return itteraotor(Data + Size);
	}
	itteraotor insert(itteraotor i, bool value)
	{
		Size = Size + 1;
		itteraotor e = this->end();
		int k = 0;
		for (int j = Size - 1; j >= 0; j--)
		{
			if (i != e)
			{
				this->Data[j] = this->Data[j - 1];
				e = e - 1;
			}
			else
			{
				break;
			}
		}
		*e = value;
		return i;
	}
	void erase(itteraotor k)
	{
		itteraotor b = this->begin();
		for (int i = 0; i < Size; i++)
		{
			if (b != k)
			{
				b++;
			}
			else
			{
				for (int j = i; j < (Size - 1); j++)
					this->Data[j] = this->Data[j + 1];
				i--;
				this->Size = this->Size - 1;
				break;
			}
		}

	}
	void print()
	{
		for (int i = 0; i < Size; i++)
		{
			cout << Data[i] << " ";
		}
		cout << endl;
	}
	void insert(int p, bool a)
	{
		bool* newBlock = new bool[Size];
		for (int i = 0; i < Size; i++)
		{
			newBlock[i] = Data[i];
		}
		Data = new bool[Size + 1];
		int m = 0;
		for (int i = 0; i < Size + 1; i++)
		{
			if (i != p)
			{
				Data[i] = newBlock[m];
				m++;
			}
		}
		delete[]newBlock;
		Size = Size + 1;
		Data[p] = a;
	}
};



int main()
{

	Vector<int> v1;
	Vector<bool> v2;

	v1.PushBack(4);
	v1.PushBack(3);
	v1.PushBack(2);
	v1.Pop_back();
	v1.print();
	v1.PushBack(3);
	v1.PushBack(9);
	cout << "Size of V1 = " << v1.size() << endl;

	v2.PushBack(0);
	v2.PushBack(1);
	v2.PushBack(1);
	v2.Pop_back();
	v2.print();
	v2.PushBack(0);
	v2.PushBack(1);

	cout << "Max Size of V2 = " << v2.max_size() << endl;
	cout << "If V2 empty = " << v1.empty() << endl;

	v1.insert(3, 10);
	v2.insert(3, 1);

	cout << v1.front() << " is front element of v1\n";
	cout << v1.back() << " is last element of v1\n";

	v1.assign(7, 100);

	v1.sort();
	v1.print();


	Vector<bool> v3 = v2;

	if (v3 == v2)
		cout << "v3 equals v2\n";
	else
		cout << "v3 not equals v2\n";


	int k = 0;
	for (Vector<bool>::itteraotor i = v3.begin(); i != v3.end(); ++i, k++)
	{
		cout << "value by iterator " << *i << endl;
		cout << "value by bracket " << v3[k] << endl;
		cout << "value by at " << v3.at(k) << endl;
	}


















	/*Vector<int> myvector;
	myvector.PushBack(1);
	myvector.PushBack(2);
	myvector.PushBack(3);
	myvector.insert(1, 6);
	myvector.insert(2, 76);


	for (int i = 0; i < myvector.size(); i++)
	{
		cout << myvector[i] << " ";
	}

	 */

	 //Vector<int> myvector;
	 //for (int i = 1; i <= 5; i++) myvector.PushBack(i);

	 //cout << "myvector contains:";
	 //for (Vector<int>::itteraotor it = myvector.begin(); it != myvector.end(); ++it)
	 //	std::cout << ' ' << *it;
	 //std::cout << '\n';

	 //Vector<int> r;  
	 //Vector<int> ::itteraotor l;
	 //for (int i = 0; i < 10; i++)
	 //{
	 //	r.PushBack(i);
	 //}

	 //Vector<int> p;
	 //for (int i = 0; i < 10; i++)
	 //{
	 //	p.PushBack(i);
	 //}

	 //cout << (r == p);
	 //cout << (r != p);


  //
	 //for (int i = 0; i < r.size(); i++)
	 //	r.at(i) = i;

	 //cout << "myvector contains:";
	 //for (int i = 0; i <r.size(); i++)
	 //	cout << ' ' <<r.at(i);
	 //cout << '\n';


	 //r.front()=78;
	 //
	 //r.back()=16;

	 //Vector<int> myvector(5);

	 //int* p = myvector.data();
	 //*p = 10;
	 //cout << *p;
	 //++p;
	 //*p = 20;
	 //p[2] = 100;

	 //std::cout << "myvector contains:";
	 //for (int i = 0; i < myvector.size(); ++i)
	 //	std::cout << ' ' << myvector[i];
	 //std::cout << '\n';

	 //Vector<int>third;
	 //Vector<int>first;
	 //first.assign(7, 100);
	 //int myints[] = { 1776,7,4 };
	 //third.assign(myints, myints + 3);
	 //for (int i = 0; i < third.size(); i++)
	 //{
	 //	cout << third[i] << " ";
	 //}
	 //for (int i = 0; i < first.size(); i++)
	 //{
	 //	cout << first[i] << " ";
	 //}

return 0;




}