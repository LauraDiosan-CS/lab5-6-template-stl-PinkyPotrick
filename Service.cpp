#include "Service.h"
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

Service::Service() {
	this->repo = new RepoSTL<Cake>;
}

Service::Service(RepoSTL<Cake>*& r) {
	this->repo = r;
}

Service::~Service() {

}

void Service::setRepo(vector<Cake> newElements) {
	this->repo->setRepo(newElements);
}

void Service::addCake(int ID, string name, string ingredients, double price) {
	Cake cake(ID, name, ingredients, price);
	this->repo->addElement(cake);
}

vector<Cake> Service::getAll() {
	return this->repo->getAll();
}

Cake Service::getCakeAtPosition(int pos) {
	if (pos >= 0 && pos < this->repo->getSize())
	{
		return this->repo->getElementAtPosition(pos);
	}
	return Cake();
}

void Service::updateCakeByID(int ID, string newName, string newIngredients, double newPrice) {
	vector<Cake> cakes = this->repo->getAll();
	Cake newCake(ID, newName, newIngredients, newPrice);
	for (int i = 0; i < this->repo->getSize(); i++)
	{
		if (cakes[i].getID() == ID)
		{
			Cake oldCake(ID, cakes[i].getName(), cakes[i].getIngredients(), cakes[i].getPrice());
			this->repo->updateElement(oldCake, newCake);
			return;
		}
	}
}

void Service::deleteCakeByID(int ID) {
	vector<Cake> cakes = this->repo->getAll();
	for (int i = 0; i < this->repo->getSize(); i++)
	{
		if (cakes[i].getID() == ID)
		{
			Cake cakeToBeDeleted(ID, cakes[i].getName(), cakes[i].getIngredients(), cakes[i].getPrice());
			this->repo->deleteElement(cakeToBeDeleted);
			return;
		}
	}
}

Service& Service::operator=(Service& s) {
	this->repo = s.repo;
	return *this;
}

void Service::splitStringAndAddToTuple(string str, vector<Cake> listOfCakes, vector< tuple<string, double> > &tuples, int &ingredientsCount) {
	str.erase(remove(str.begin(), str.end(), ','), str.end());
	/*
	Method 1:

	std::string separator = " ";
	int pos = 0;
	string token;
	while ((pos = str.find(separator)) != string::npos) {
		token = str.substr(0, pos);
		cout << token << endl;
		str.erase(0, pos + separator.length());
	}
	cout << str << endl;

	Method 2:
	*/
	string word = "";
	int sum, count;
	double average;
	ingredientsCount = 0;
	for (auto x : str) {
		if (x == ' ') {
			sum = 0;
			count = 0;
			for (int index = 0; index < listOfCakes.size(); index++) {
				if (listOfCakes[index].getIngredients().find(word) != string::npos) {
					sum += listOfCakes[index].getPrice();
					count++;
				}
			}
			average = (double)sum / count;
			tuples.push_back(tuple<string, double>(word, average));
			ingredientsCount++;
			word = "";
		}
		else {
			word = word + x;
		}
	}
	sum = 0;
	count = 0;
	for (int index = 0; index < listOfCakes.size(); index++) {
		if (listOfCakes[index].getIngredients().find(word) != string::npos) {
			sum += listOfCakes[index].getPrice();
			count++;
		}
	}
	average = sum / count;
	tuples.push_back(tuple<string, double>(word, average));
}

void Service::removeDuplicates(string &str) {
	str.erase(remove(str.begin(), str.end(), ','), str.end());
	string noDupsString;
	string subString = "";
	for (auto x : str) {
		if (x == ' ') {
			string word = subString;

			if (noDupsString.find(word) == string::npos) {
				noDupsString.append(word);
				noDupsString.append(" ");
			}
			subString = "";
		}
		else {
			subString = subString + x;
		}
	}
	if (noDupsString.find(subString) == string::npos) {
		noDupsString.append(subString);
	}
	str = noDupsString;
}

void Service::allIngredientsAndPrices(vector<Cake> listOfCakes, vector< tuple<string, double> > &tuples, int &ingredientsCount) {
	string allIngredients;
	for (int index = 0; index < listOfCakes.size(); index++) {
		string ingredients = listOfCakes[index].getIngredients();
		allIngredients.append(ingredients);
		if (index != listOfCakes.size() - 1)
			allIngredients.append(", ");
	}
	removeDuplicates(allIngredients);
	splitStringAndAddToTuple(allIngredients, listOfCakes, tuples, ingredientsCount);
}
