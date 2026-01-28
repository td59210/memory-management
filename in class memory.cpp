//memory management in class

#include <iostream>

using namespace std;

class vec {

	int* arr;

public:

	vec(int size) {
		arr = new int[size];
		cout << "Constructed:" << endl;
	}

	~vec() {
		delete[] arr;
		cout << "Destructed:" << endl;
	}

	int& at(int idx) {
		return arr[idx];
	}

};

int main() {

	cout << "Point A" << endl;
	{
		vec v1 = vec(100);
		v1.at(99) = 12673;

		cout << v1.at(99) << endl;
		cout << "Point B" << endl;
	} //end of scope __> gets destroyed and off the stack at the end and for class, calls destructor

	cout << "Point C" << endl;

	{
		vec* v2 = new vec(100);
		(*v2).at(99) = 12673;

		cout << v2->at(99) << endl;
		//arrow operator is a derefrence + pointer

	}

	int* ptr = new int;
	//new int allocates space for an int on the heap and returns a pointer to it

	*ptr = 123;

	cout << ptr << endl; //gives location at heap (large number)
	cout << *ptr << endl; //gives value stored at that space

	delete ptr;
	//deallocate the space pointed to by ptr

	//cout << ptr << endl; 
	//cout << *ptr << endl;
	//read access violation bc we deallocated
	//maintain access to variable when you delete it but can't access it

	cout << "How big of an array do you want?";
	int size;
	cin >> size;

	//int arr[size]; <-- can't do this bc it doesn't have a given size

	int* arr = new int[size]; //asking for size of given array

	for (int i = 0, i < size, i++) {
		*(arr + i) = i;
		//arr[i] = i; <-- same thing

	}


	for (int i = 0, i < size, i++) {
		cout << arr[i] << endl;

	}


	delete[] arr; //deallocating the array

}