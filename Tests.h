#pragma once
#include "Service.h"

//Description: Tests the functions from the Cake class
void testCake();

//Description: The class for the Repo test functions
class TestRepoSTL {
private:
	RepoSTL<Cake> repo;
	vector<Cake> cakesIn;

	//Description: Tests the return of all the cakes from the Repo
	void testGetAll();
	//Description: Tests the return of the size of the Repo
	void testGetSize();
	//Description: Tests the return of the cake from the specified position
	void testGetCakeAtPosition();
	//Description: Tests the add function for a cake
	void testAddCake();
	//Description: Tests the update function for a cake
	void testUpdateCake();
	//Description: Tests the delete function for a cake
	void testDeleteCake();
public:
	//Description: Tests the RepoSTL class
	TestRepoSTL();
	//Description: Tests all the functions from the RepoSTL class
	void testAll();
};

//Description: The class for the Service test functions
class TestService {
private:
	Service service;

	//Description: Tests the add function for a cake
	void testAddCake();
	//Description: Tests the return of all the cakes from the Repo using the Service class
	void testGetAll();
	//Description: Tests the return of the cake from the specified position
	void testGetCakeAtPosition();
	//Description: Tests the update by ID function
	void testUpdateCakeByID();
	//Description: Tests the delete by ID function
	void testDeleteCakeByID();
public:
	//Description: Tests the Service class
	TestService();
	//Description: Tests all the functions from the Service class
	void testAll();
};

//Description: Tests the function which adds elements to tuple
void splitStringAndAddToTupleTest();
//Description: Tests the funnction which removes the duplicates from a string
void removeDuplicatesTest();
//Description: Tests the function which assembles the other functions and gives the answer for the ingredients and prices
void allIngredientsAndPricesTest();
