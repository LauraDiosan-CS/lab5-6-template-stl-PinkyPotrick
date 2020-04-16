/*
#include <iostream>
#include "Repo.h"

using namespace std;

template <class T>
RepoSTL<T>::RepoSTL()
{
	this->fileNameIn = NULL;
	this->fileNameOut = NULL;
}

template <class T>
RepoSTL<T>::RepoSTL(const char* fileNameIn, const char* fileNameOut)
{
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);

	this->loadFromFile();
}

template <class T>
RepoSTL<T>::~RepoSTL()
{
	this->elements.clear();
}

template <class T>
void RepoSTL<T>::setFileNameIn(const char* fileNameIn)
{
	if (this->fileNameIn != NULL)
	{
		delete[] this->fileNameIn;
	}
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
}

template <class T>
void RepoSTL<T>::setFileNameOut(const char* fileNameOut)
{
	if (this->fileNameOut != NULL)
	{
		delete[] this->fileNameOut;
	}
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
}

template <class T>
void RepoSTL<T>::addElement(const T& elem)
{
	this->elements.push_back(elem);
	this->saveToFile();
}

template <class T>
vector<T> RepoSTL<T>::getAll()
{
	return this->elements;
}

template <class T>
int RepoSTL<T>::getSize()
{
	return this->elements.size();
}

template <class T>
T RepoSTL<T>::getElementAtPosition(int pos)
{
	return this->elements[pos];
}

template <class T>
void RepoSTL<T>::updateElement(T& oldElem, T& newElem)
{
	typename vector<T>::iterator it;

	it = find(this->elements.begin(), this->elements.end(), oldElem);
	if (it != this->elements.end())
	{
		*it = newElem;
	}

	this->saveToFile();
}

template <class T>
void RepoSTL<T>::deleteElement(T& elem)
{
	typename vector<T>::iterator it;

	it = find(this->elements.begin(), this->elements.end(), elem);
	if (it != this->elements.end())
	{
		this->elements.erase(it);
	}

	this->saveToFile();
}

template <class T>
void RepoSTL<T>::loadFromFile()
{
	if (this->fileNameIn != NULL)
	{
		this->elements.clear();
		ifstream f(this->fileNameIn);
		T element;
		while (!f.eof())
		{
			f >> element;
			if (!!element)
			{
				this->addElement(element);
			}
		}
		f.close();
	}
}

template <class T>
void RepoSTL<T>::saveToFile()
{
	if (this->fileNameOut != NULL)
	{
		ofstream f(this->fileNameOut);
		for (int i = 0; i < this->elements.size(); i++)
		{
			f << this->elements[i] << endl;
		}
		f.close();
	}
}
*/
