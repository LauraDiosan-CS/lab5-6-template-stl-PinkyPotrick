#include "Cake.h"
#include <cstddef>
#include <string.h>
#include <iostream>

using namespace std;

Cake::Cake() {
	this->ID = 0;
	this->price = 0;
}

Cake::Cake(int ID, string name, string ingredients, double price)
{
	this->ID = ID;
	this->name = name;
	this->ingredients = ingredients;
	this->price = price;
}

Cake::Cake(const Cake &c) {
	
	this->ID = c.ID;
	this->name = c.name;
	this->ingredients = c.ingredients;
	this->price = c.price;
}

Cake::~Cake() {
	this->name.clear();
	this->ingredients.clear();
}

int Cake::getID() {
	return this->ID;
}

string Cake::getName() {
	return this->name;
}

string Cake::getIngredients() {
	return this->ingredients;
}

double Cake::getPrice() {
	return this->price;
}

void Cake::setID(int newID) {
	this->ID = newID;
}

void Cake::setName(string newName) {
	this->name = newName;
}

void Cake::setIngredients(string newIngredients) {
	this->ingredients = newIngredients;
}

void Cake::setPrice(double newPrice) {
	this->price = newPrice;
}

Cake& Cake::operator=(const Cake& c) {
	this->setID(c.ID);
	this->setName(c.name);
	this->setIngredients(c.ingredients);
	this->setPrice(c.price);
	return *this;
}

bool Cake:: operator==(const Cake& c) {
	return (this->ID == c.ID) && (this->name == c.name) && (this->ingredients == c.ingredients) && (this->price == c.price);
}

ostream& operator<<(ostream& os, const Cake& c)
{
	os << c.ID << "|" << c.name << "|" << c.ingredients << "|" <<  c.price << "\n";
	return os;
}

istream& operator>>(istream& is, Cake& c)
{
	is >> c.ID;
	is.get();
	getline(is, c.name, '|');
	getline(is, c.ingredients, '|');
	is >> c.price;
	is.get();
	return is;
}
