#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cake {
private:
	int ID;
	string name;
	string ingredients;
	double price;
public:
	/*
	Description: This is a default constructor
	Input: -
	Output: -
	*/
	Cake();
	/*
	Description: This is a constructor with parameters
	Input: ID - int, the ID of the cake
		   name - string, the name of the cake
		   ingredients - string, ingredients of the cake
		   price - double, the price of the cake
	Output: -
	*/
	Cake(int ID, string name, string ingredients, double price);
	/*
	Description: This is a copy constructor
	Input: c - const class, the Cake class object
	Output: -
	*/
	Cake(const Cake& c);
	/*
	Description: This is a destructor
	Input: -
	Output: -
	*/
	~Cake();
	/*
	Description: Returns the ID of the cake
	Input: -
	Output: ID - int, the ID of the cake
	*/
	int getID();
	/*
	Description: Returns the name of the cake
	Input: -
	Output: name - char, the name of the cake
	*/
	string getName();
	/*
	Description: Returns the ingredients of the cake
	Input: -
	Output: ingredients - char, the ingredients of the cake
	*/
	string getIngredients();
	/*
	Description: Returns the price of the cake
	Input: -
	Output: price - double, the price of the cake
	*/
	double getPrice();
	/*
	Description: Sets the ID for the cake
	Input: newID - int, the new ID
	Output: -
	*/
	void setID(int newID);
	/*
	Description: Sets the name for thr cake
	Input: newName - string, the new name
	Output: -
	*/
	void setName(string newName);
	/*
	Description: Sets the ingredients for the cake
	Input: newIngredients - string, the new ingredients
	Output: -
	*/
	void setIngredients(string newIngredients);
	/*
	Description: Sets the price for a cake
	Input: newPrice - double, the new price
	Output: -
	*/
	void setPrice(double newPrice);
	/*
	Description: Creates a new Cake (equal to a given Cake c)
	Input: c - class, the Cake class object
	Output: a new cake (equal to c)
	*/
	Cake& operator=(const Cake& c);
	/*
	Description: Compares the two objects
	Input: c - class, the Cake class object
	Output: true/false
	*/
	bool operator==(const Cake& c);
	/*
	Description: Shows the cake using an output stream
	Input: os - ostream&, the output stream
		   c - class, the Cake class object
	Output: os - ostream&, the read Cake
	*/
	friend ostream& operator<<(ostream& os, const Cake& c);
	/*
	Description: Reads the cake using an input stream
	Input: is - istream&, the input stream
		   c - class, the Cake class object
	Output: is - istream&, a new Cake class object
	*/
	friend istream& operator>>(istream& is, Cake& c);
};
