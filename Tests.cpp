#include <iostream>
#include <cassert>
#include "Tests.h"

void testCake() {

	Cake c1;
	assert(c1.getID() == 0);
	assert(c1.getPrice() == 0);

	string name = "Cake1";
	string ingredients = "Ingredient1, Ingredient2, Ingredient3";
	Cake c2(1, name, ingredients, 16.5);
	assert(c2.getID() == 1);
	assert(c2.getName() == "Cake1");
	assert(c2.getIngredients() == "Ingredient1, Ingredient2, Ingredient3");
	assert(c2.getPrice() == 16.5);

	Cake c3(c2);
	assert(c3.getID() == 1);
	assert(c3.getName() == "Cake1");
	assert(c3.getIngredients() == "Ingredient1, Ingredient2, Ingredient3");
	assert(c3.getPrice() == 16.5);

	string name2 = "Cake2";
	string ingredients2 = "Ingredient4, Ingredient5";
	c3.setID(2);
	assert(c3.getID() == 2);
	c3.setName(name2);
	assert(c3.getName() == name2);
	c3.setIngredients(ingredients2);
	assert(c3.getIngredients() == ingredients2);
	c3.setPrice(30.2);
	assert(c3.getPrice() == 30.2);

	Cake c4;
	c4 = c2;
	assert(c4.getID() == 1);
	assert(c4.getName() == name);
	assert(c4.getIngredients() == ingredients);
	assert(c4.getPrice() == 16.5);
}

TestRepoSTL::TestRepoSTL()
{
	Cake c1(1, "Cake1", "Ingredient1", 23);
	Cake c2(2, "Cake2", "Ingredient2", 24);
	Cake c3(3, "Cake3", "Ingredient3", 66);
	Cake c4(4, "Cake4", "Ingredient4", 40);
	this->cakesIn.push_back(c1);
	this->cakesIn.push_back(c2);
	this->cakesIn.push_back(c3);
	this->cakesIn.push_back(c4);
}

void TestRepoSTL::testGetAll() {
	RepoSTL<Cake> repo;
	Cake c1(1, "Cake1", "Ingredient1", 23);
	Cake c2(2, "Cake2", "Ingredient2", 24);
	repo.addElement(c1);
	repo.addElement(c2);
	vector<Cake> cakesList = repo.getAll();
	assert(cakesList[0] == c1);
	assert(cakesList[1] == c2);
}
void TestRepoSTL::testGetSize() {
	RepoSTL<Cake> repo;
	Cake c1(1, "Cake1", "Ingredient1", 23);
	Cake c2(2, "Cake2", "Ingredient2", 24);
	repo.addElement(c1);
	repo.addElement(c2);
	assert(repo.getSize() == 2);
}
void TestRepoSTL::testGetCakeAtPosition() {
	RepoSTL<Cake> repo;
	Cake c1(1, "Cake1", "Ingredient1", 23);
	Cake c2(2, "Cake2", "Ingredient2", 24);
	repo.addElement(c1);
	repo.addElement(c2);
	assert(repo.getElementAtPosition(0) == c1);
	assert(repo.getElementAtPosition(1) == c2);
}
void TestRepoSTL::testAddCake() {
	RepoSTL<Cake> repo;
	Cake c1(1, "Cake1", "Ingredient1", 23);
	Cake c2(2, "Cake2", "Ingredient2", 24);
	repo.addElement(c1);
	repo.addElement(c2);
	assert(repo.getSize() == 2);
	assert(repo.getElementAtPosition(0) == c1);
	assert(repo.getElementAtPosition(1) == c2);
}
void TestRepoSTL::testUpdateCake() {
	RepoSTL<Cake> repo;
	Cake c1(1, "Cake1", "Ingredient1", 23);
	Cake c2(2, "Cake2", "Ingredient2", 24);
	repo.addElement(c1);
	repo.addElement(c2);
	assert(repo.getElementAtPosition(0) == c1);
	assert(repo.getElementAtPosition(1) == c2);
	Cake newC1(1, "NewCake1", "NewIngredient1, Ingredient2", 100);
	repo.updateElement(c1, newC1);
	assert(repo.getElementAtPosition(0) == newC1);
}
void TestRepoSTL::testDeleteCake() {
	RepoSTL<Cake> repo;
	Cake c1(1, "Cake1", "Ingredient1", 23);
	Cake c2(2, "Cake2", "Ingredient2", 24);
	repo.addElement(c1);
	repo.addElement(c2);
	assert(repo.getSize() == 2);
	repo.deleteElement(c1);
	assert(repo.getSize() == 1);
}

void TestRepoSTL::testAll() {
	testGetAll();
	testGetSize();
	testGetCakeAtPosition();
	testAddCake();
	testUpdateCake();
	testDeleteCake();
}

TestService::TestService()
{
}

void TestService::testAll()
{
}

void TestService::testAddCake()
{
	RepoSTL<Cake>* repoTest;
	repoTest = new RepoSTL<Cake>;
	//this->service.setRepo(repo);
	char name[] = "Cake";
	char ingredients[] = "Ingredients";
	Cake c(1, name, ingredients, 40);
	this->service.addCake(1, name, ingredients, 40);
	assert(this->service.getCakeAtPosition(0) == c);
	delete repoTest;
}

void TestService::testGetAll()
{
	RepoSTL<Cake>* repoTest;
	repoTest = new RepoSTL<Cake>;
	char name1[] = "Cake1";
	char name2[] = "Cake2";
	char ingredients1[] = "Ingredients1";
	char ingredients2[] = "Ingredients2";
	Cake c1(1, name1, ingredients1, 40);
	Cake c2(2, name2, ingredients2, 30);
	this->service.addCake(1, name1, ingredients1, 40);
	this->service.addCake(2, name2, ingredients2, 30);
	vector<Cake> cakes = this->service.getAll();
	cout << cakes.size() << "\n";
	assert(cakes.size() == 2);
	assert(cakes[0] == c1);
	assert(cakes[1] == c2);
	delete repoTest;
}

void TestService::testGetCakeAtPosition()
{
	RepoSTL<Cake>* repoTest;
	repoTest = new RepoSTL<Cake>;
	RepoSTL<Cake> repoSTL;
	char name[] = "Cake";
	char ingredients[] = "Ingredients";
	Cake c(1, name, ingredients, 40);
	this->service.addCake(1, name, ingredients, 40);
	assert(this->service.getCakeAtPosition(0) == c);
	delete repoTest;
}

void TestService::testUpdateCakeByID()
{
	RepoSTL<Cake>* repoTest;
	repoTest = new RepoSTL<Cake>;
	RepoSTL<Cake> repoSTL;
	char name1[] = "Cake1";
	char name2[] = "Cake2";
	char ingredients1[] = "Ingredients1";
	char ingredients2[] = "Ingredients2";
	Cake c1(1, name1, ingredients1, 40);
	Cake c2(2, name2, ingredients2, 30);
	this->service.addCake(1, name1, ingredients1, 40);
	this->service.updateCakeByID(-1, c2.getName(), c2.getIngredients(), c2.getPrice());
	assert(this->service.getCakeAtPosition(0) == c1);
	this->service.updateCakeByID(1, c2.getName(), c2.getIngredients(), c2.getPrice());
	assert(this->service.getCakeAtPosition(0) == c2);
	delete repoTest;
}

void TestService::testDeleteCakeByID()
{
	RepoSTL<Cake>* repoTest;
	repoTest = new RepoSTL<Cake>;
	RepoSTL<Cake> repoSTL;
	char name[] = "Cake";
	char ingredients[] = "Ingredients";
	Cake c(1, name, ingredients, 40);
	this->service.addCake(1, name, ingredients, 40);
	this->service.deleteCakeByID(-1);
	vector<Cake> cakes = this->service.getAll();
	assert(cakes.size() == 1);
	assert(cakes[0] == c);
	this->service.deleteCakeByID(1);
	cakes = this->service.getAll();
	assert(cakes.size() == 0);
	delete repoTest;
}

void splitStringAndAddToTupleTest() {
	Service service;
	vector<Cake> cakesList;
	vector< tuple<string, double> > tuples;
	Cake c1(1, "Cake1", "Ingredient1, Ingredient2", 20);
	Cake c2(2, "Cake2", "Ingredient2, Ingredient3, Ingredient4", 15);
	Cake c3(3, "Cake3", "Ingredient4", 30);
	string str = "Ingredient1 Ingredient2 Ingredient3 Ingredient4 ";
	int ingredientsCount;
	cakesList.push_back(c1);
	cakesList.push_back(c2);
	cakesList.push_back(c3);
	service.splitStringAndAddToTuple(str, cakesList, tuples, ingredientsCount);
	assert(get<0>(tuples[0]) == "Ingredient1");
	assert(get<1>(tuples[0]) == 20);
	assert(get<0>(tuples[1]) == "Ingredient2");
	assert(get<1>(tuples[1]) == 17.5);
	assert(get<0>(tuples[2]) == "Ingredient3");
	assert(get<1>(tuples[2]) == 15);
	assert(get<0>(tuples[3]) == "Ingredient4");
	assert(get<1>(tuples[3]) == 22.5);
}

void removeDuplicatesTest() {
	Service service;
	string duplicatesString = "Ana are mere, dar Ana nu are pere";
	service.removeDuplicates(duplicatesString);
	assert(duplicatesString == "Ana are mere dar nu pere");
}

void allIngredientsAndPricesTest() {
	Service service;
	vector<Cake> listOfCakes;
	vector< tuple<string, double> > tuples;
	int ingredientsCount;
	Cake c1(1, "Cake1", "Ingredient1, Ingredient2", 20);
	Cake c2(2, "Cake2", "Ingredient2, Ingredient3, Ingredient4", 15);
	Cake c3(3, "Cake3", "Ingredient4", 30);
	listOfCakes.push_back(c1);
	listOfCakes.push_back(c2);
	listOfCakes.push_back(c3);
	service.allIngredientsAndPrices(listOfCakes, tuples, ingredientsCount);
	assert(get<0>(tuples[0]) == "Ingredient1");
	assert(get<1>(tuples[0]) == 20);
	assert(get<0>(tuples[1]) == "Ingredient2");
	assert(get<1>(tuples[1]) == 17.5);
	assert(get<0>(tuples[2]) == "Ingredient3");
	assert(get<1>(tuples[2]) == 15);
	assert(get<0>(tuples[3]) == "Ingredient4");
	assert(get<1>(tuples[3]) == 22.5);
}
