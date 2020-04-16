#include <iostream>
#include "UI.h"

using namespace std;

UI::UI() {
}

UI::UI(Service& service) {
	this->service = service;
}

UI::~UI() {
}

void UI::showMenu() {
	cout << "-------------------------------------------------------------------\n";
	cout << "Menu:\n\n";
	cout << "1. Add cake.\n";
	cout << "2. Show all.\n";
	cout << "3. Update cake.\n";
	cout << "4. Delete cake.\n";
	cout << "5. Show all average prices of cakes for every ingredient.\n";
	cout << "6. Exit.\n\n";
}

void UI::handleAddCake() {
	int ID;
	double price;
	string name;
	string ingredients;
	cout << "Program: Write the ID.\nUser: ID = ";
	cin >> ID;
	cin.get();
	cout << "Program: Write a cake name.\nUser: name = ";
	getline(cin, name);
	cout << "Program: Write the ingredients for the cake.\nUser: ingredients = ";
	getline(cin, ingredients);
	cout << "Program: Write a price for the cake.\nUser: price = ";
	cin >> price;
	cin.get();
	Cake cake(ID, name, ingredients, price);
	this->service.addCake(cake.getID(), cake.getName(), cake.getIngredients(), cake.getPrice());
	cout << "Program: The cake has been added.\n";
}

void UI::handleShowAll() {
	vector<Cake> cakes = this->service.getAll();
	if (cakes.size() == 0)
		cout << "Program: No cakes have been found in the repository.\n";
	for (int index = 0; index < cakes.size(); index++)
		cout << cakes[index].getID() << " | " << cakes[index].getName() << " | " << cakes[index].getIngredients() << " | " << cakes[index].getPrice() << endl;
	cout << endl;
}

void UI::handleUpdateCake() {
	int ID;
	double newPrice;
	string newName;
	string newIngredients;
	cout << "Program: Write the ID of the cake that you want to update.\nUser: ";
	cin >> ID;
	cin.get();
	cout << "Program: Write the new name for the current selected cake.\nUser: ";
	getline(cin, newName);
	cout << "Program: Write the new ingredients for the current selected cake.\nUser: ";
	getline(cin, newIngredients);
	cout << "Program: Write the new price for the current selected cake.\nUser: ";
	cin >> newPrice;
	cin.get();
	this->service.updateCakeByID(ID, newName, newIngredients, newPrice);
	cout << "Program: The cake has been updated!\n";
}

void UI::handleDeleteByID() {
	int ID;
	cout << "Program: Write the ID of the cake that you want to delete.\nUser: ";
	cin >> ID;
	cin.get();
	this->service.deleteCakeByID(ID);
	cout << "Program: The cake has been deleted!\n";
}

void UI::handleShowAveragesPerIngredient() {
	vector<Cake> cakes = this->service.getAll();
	if (cakes.size() == 0)
		cout << "Program: No cakes have been found in the repository.\n";
	else {
		cout << "Program: The following are the ingredients and their average prices for every cake.\n\n";
		vector< tuple<string, double> > tuples;
		int tupleLength;
		service.allIngredientsAndPrices(service.getAll(), tuples, tupleLength);
		for (int ingredientIndex = 0; ingredientIndex < tuples.size() - 1; ingredientIndex++) {
			cout << get<0>(tuples[ingredientIndex]) << " : ";
			cout << get<1>(tuples[ingredientIndex]) << endl;
		}
	}
}

void UI::runUI() {

	bool shouldRun = true;
	int option;
	while (shouldRun) {
		showMenu();
		cout << "Program: Give an option.\nUser: ";
		cin >> option;
		if (option == 1) {
			this->handleAddCake();
		}
		else if (option == 2) {
			this->handleShowAll();
		}
		else if (option == 3) {
			this->handleUpdateCake();
		}
		else if (option == 4) {
			this->handleDeleteByID();
		}
		else if (option == 5) {
			this->handleShowAveragesPerIngredient();
		}
		else if (option == 6) {
			shouldRun = false;
		}
		else {
			cout << "Program: Error! The given option does not exist!\n";
		}
	}
	cout << "Program: Bye!\n";
	system("pause");
	return;
}
