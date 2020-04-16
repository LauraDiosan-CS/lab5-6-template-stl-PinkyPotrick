#pragma once
#include "RepoFile.h"
#include <tuple>

class Service {
private:
	RepoSTL<Cake>* repo;
public:
	/*
	Description: This is a default constructor
	Input: -
	Output: -
	*/
	Service();
	/*
	Description: This is a constructor with parameters
	Input: r - RepoSTL<Cake>&, creates a RepoSTL class type object
	Output: -
	*/
	Service(RepoSTL<Cake>*& r);
	/*
	Description: This is a destructor
	Input: -
	Output: -
	*/
	~Service();
	/*
	Description: Sets the repo
	Input: newElements - vector<Cake>, the new list of elements
	Output: -
	*/
	void setRepo(vector<Cake> newElements);
	/*
	Description: Adds a cake to the repository
	Input: ID - int, the ID of the cake
		   name - const char*, the name of the cake
		   ingredients - const char*, the ingredients of the cake
		   price - double, the price of the cake
	Output: -
	*/
	void addCake(int ID, string name, string ingredients, double price);
	/*
	Description: Returns all the cakes from the repository
	Input: -
	Output: -
	*/
	vector<Cake> getAll();
	/*
	Description: Returns the cake at a certain position
	Input: pos - int, the specified position in the list of cakes
	Output: -
	*/
	Cake getCakeAtPosition(int pos);
	/*
	Description: Updated the cake by its ID
	Input: ID - int, the ID of the cake that needs to be updated
		   newName - const char*, the new name for the cake
		   newIngredients - const char*, the new ingredients for the cake
		   newPrice - double, the new price for the cake
	Output: - 
	*/
	void updateCakeByID(int ID, string newName, string newIngredients, double newPrice);
	/*
	Description: Deletes the cake by its ID
	Input: ID - int, the ID of the cake that needs to be deleted
	Output: -
	*/
	void deleteCakeByID(int ID);
	/*
	Description: Creates a Service object
	Input: s - Service&, a Service class object
	Output: a new Service type object equal with s
	*/
	Service& operator=(Service& s);
	/*
	Description: Splits a string in words, finds the average price and puts values in tuples
	Input: str - string, the string that will be split
	       listOfCakes - vector<Cake>, the lsit of cakes
		   tuples - vector<tuple>, the list of ingredients and their average prices
		   ingredientsCount - int&, the number of distinct ingredients
	Output: -
	*/
	void splitStringAndAddToTuple(string str, vector<Cake> listOfCakes, vector< tuple<string, double> > &tuples, int &ingredientsCount);
	/*
	Description: Removes the duplicated words from a string and also the commas used as separators
	Input: str - string, the string where the duplicates will be removed
	Output: -
	*/
	void removeDuplicates(string &str);
	/*
	Description: Returns a list of tuples (an array) with the ingredient and the average price
	Input: listOfCakes - vector<Cake>, the lsit of cakes
		   tuples - vector<tuple>, the list of ingredients and their average prices
		   ingredientsCount - int&, the number of distinct ingredients
	Output: -
	*/
	void allIngredientsAndPrices(vector<Cake> listOfCakes, vector< tuple<string, double> > &tuples, int &ingredientsCount);
};
