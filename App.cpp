#include <iostream>
#include "Tests.h"
#include "UI.h"

using namespace std;

int main()
{
	testCake();

	TestRepoSTL testRepoSTL;
	testRepoSTL.testAll();

	TestService testService;
	testService.testAll();

	splitStringAndAddToTupleTest();
	removeDuplicatesTest();
	allIngredientsAndPricesTest();

	RepoSTL<Cake>* repo;

	//Repo with a file:
	repo = new RepoFile<Cake>("CakesList.txt");

	//Repo without a file:
	//repo = new RepoSTL<Cake>();

	Service service(repo);
	UI userInterface(service);

	userInterface.runUI();

	delete repo;
	return 0;
}
