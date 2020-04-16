#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include "Cake.h"

using namespace std;

template <class T> class RepoSTL {
private:
	vector<T> elements;
public:
	/*
	Description: This is a default constructor
	Input: -
	Output: -
	*/
	RepoSTL();
	/*
	Description: This is a destructor
	Input: -
	Output: -
	*/
	~RepoSTL();
	/*
	Description: This following function adds an element to the repository
	Input: elem - const T, the elements that is added
	Output: -
	*/
	virtual void addElement(const T elem);
	/*
	Description: Returns all the elements from the repository
	Input: -
	Output: elements - vector, the list of elements
	*/
	virtual vector<T> getAll();
	/*
	Description: Retuns the size of the repository
	Input: -
	Output: the size of the list
	*/
	virtual int getSize();
	/*
	Description: Returns the element at a specified position
	Input: pos - int, the position from the list
	Output: element - vector, the element from the specified position
	*/
	virtual T getElementAtPosition(int pos);
	/*
	Description: Updates an old element from the repository with a new one
	Input: oldElem - T&, the old element
	       newElem - T&, the new element
	Output: -
	*/
	virtual void updateElement(T& oldElem, T& newElem);
	/*
	Description: Deletes an element from the repository
	Input: elem - T&, the element that will be deleted
	Output: -
	*/
	virtual void deleteElement(T& elem);
	/*
	Description: Sets the new list of elements for the repository
	Input: newElements - vector<T>, the new list of elements
	Output: -
	*/
	virtual void setRepo(vector<T> newElements);
	/*
	Description: Creates a repo object
	Input: r - const Repo<T>&, a Repo class object
	Output: a new Repo type object equal with r
	*/
	virtual RepoSTL<T>& operator=(const RepoSTL<T>& r);
	/*
	Description: Clears the repo
	Input: -
	Output: -
	*/
	virtual void clearRepo();
};

template <class T> RepoSTL<T>::RepoSTL() {

}

template <class T> RepoSTL<T>::~RepoSTL() {

}

template <class T> void RepoSTL<T>::addElement(const T elem) {
	this->elements.push_back(elem);
}

template <class T> void RepoSTL<T>::deleteElement(T& elem) {
	typename vector<T>::iterator it;

	it = find(this->elements.begin(), this->elements.end(), elem);
	if (!(it == this->elements.end())) {
		this->elements.erase(it);
	}
}

template <class T> void RepoSTL<T>::updateElement(T& oldElem, T& newElem) {
	typename vector<T>::iterator it;

	it = find(this->elements.begin(), this->elements.end(), oldElem);
	if (!(it == this->elements.end())) {
		*it = newElem;
	}
}

template <class T> T RepoSTL<T>::getElementAtPosition(int pos) {
	return this->elements[pos];
}

template <class T> void RepoSTL<T>::setRepo(vector<T> newElements) {
	this->elements = newElements;
}

template <class T> vector<T> RepoSTL<T>::getAll() {
	return this->elements;
}

template <class T> int RepoSTL<T>::getSize() {
	return this->elements.size();
}

template <class T> void RepoSTL<T>::clearRepo() {
	this->elements.clear();
}

template <class T> RepoSTL<T>& RepoSTL<T>::operator=(const RepoSTL<T>& r) {
	this->elements = r.elements;
	return *this;
}
