#pragma once
#include "Repo.h"

template <class T> class RepoFile : public RepoSTL<T> {
private:
	char* fileName;
public:
	/*
	Description: This is a default constructor
	Input: -
	Output: -
	*/
	RepoFile():RepoSTL<T>() {
		this->fileName = NULL;
	}
	/*
	Description: This is a destructor
	Input: -
	Output: -
	*/
	~RepoFile() {
		if (this->fileName) {
			delete[] this->fileName;
			this->fileName = NULL;
		}
	}
	/*
	Description: Creates a RepoFile class object
	Input: fileName - const char*, the name of the file
	Output: -
	*/
	RepoFile(const char* fileName):RepoSTL<T>() {
		this->fileName = new char[strlen(fileName) + 1];
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		this->loadFromFile();
	}
	/*
	Description: Loads the list of elements from a file
	Input: -
	Output: -
	*/
	void loadFromFile() {
		if (this->fileName != NULL) {
			ifstream in(this->fileName);
			T elem;
			//in >> elem;
			//cout << "\nelem = " << elem << "\n";

			while (in >> elem)
				RepoSTL<T>::addElement(elem);

			in.close();
		}
		else
			RepoSTL<T>::clearRepo();
	}
	/*
	Description: Saves the list of elements in a file
	Input: -
	Output: -
	*/
	void saveToFile() {
		if (this->fileName != NULL) {
			ofstream out(this->fileName);

			int size = RepoSTL<T>::getSize();
			for (int index = 0; index < size; index++)
				out << RepoSTL<T>::getElementAtPosition(index);

			out.close();
		}
	}
	/*
	Description: Sets the name of the file for a RepoFile
	Input: - fileName - const char*, the new name for the file
	Output: -
	*/
	void setFileName(const char* fileName) {
		if (this->fileName)
			delete[] this->fileName;

		if (fileName != NULL) {
			this->fileName = new char[strlen(fileName) + 1];
			strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		}
		else
			this->fileName = NULL;
	}
	/*
	Description: Returns the name of the file
	Input: -
	Output: fileName - char, the name of the file
	*/
	char* getFileName() {
		return this->fileName;
	}
	/*
	Description: Adds an element to the repository file
	Input: elem - T, the element that will be added
	Output: - 
	*/
	void addElement(const T elem) {
		RepoSTL<T>::addElement(elem);
		this->saveToFile();
	}
	/*
	Description: Deletes an element from the repository file
	Input: elem - T&, the element that will be deleted
	Output: - 
	*/
	void deleteElement(T& elem) {
		RepoSTL<T>::deleteElement(elem);
		this->saveToFile();
	}
	/*
	Description: Updated an element from the repository file
	Input: oldElem - T&, the old element that needs to be updated
		   newElem - T&, the new element which replaces the old one
	Output: -
	*/
	void updateElement(T& oldElem, T& newElem) {
		RepoSTL<T>::updateElement(oldElem, newElem);
		this->saveToFile();
	}
	/*
	Description: Returns all the elements from the repository file
	Input: -
	Output: -
	*/
	vector<T> getAll() {
		return RepoSTL<T>::getAll();
	}
	/*
	Description: Creates a repoFile object
	Input: r - RepoFile<T>&, a RepoFile class object
	Output: a new RepoFile type object equal with r
	*/
	RepoFile<T>& operator=(RepoFile<T>& r) {
		this->RepoSTL<T>::setRepo(r.getAll());
		this->setFileName(r.fileName);
		return *this;
	}
};
