#pragma once
#include "Service.h"

class UI {
private:
	Service service;
	//Description: Shows the menu
	void showMenu();
	//Description: Adds a cake
	void handleAddCake();
	//Description: Updates a cake
	void handleUpdateCake();
	//Description: Shows all the cakes
	void handleShowAll();
	//Description: Deletes a cake by ID
	void handleDeleteByID();
	//Description: Shows the average price for every ingredient
	void handleShowAveragesPerIngredient();
public:
	//Description: This is a default constructor
	UI();
	//Description: This is a constructor with parameters
	UI(Service& service);
	//Description: This is a destructor
	~UI();
	//Description: Runs the UI
	void runUI();
};
