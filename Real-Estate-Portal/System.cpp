#include "System.h"
#include "User.h"
#include "Admin.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
void System::SignUp(string fName, string lName, int natId, string password) {
	if (users.find(natId) == users.end()) {
		users[natId] = new User(fName, lName, natId, password);
		cout << "Registered Successfully " << endl;
	}
	else {
		cout << "User already exists" << endl;
		//Call login
	}
}
void System::Login(int ID, string password) {
	if (users.find(ID) == users.end()) {
		//Call Sign Up
		cout << "User is not Registered to system" << " " << "Sign Up " << endl;
	}
	else {
		Admin* admin = dynamic_cast<Admin*>(users[ID]);
		if (users[ID]->GetPassword() == password) {
			if (admin) {
				cout << "Admin Signed In" << endl;
			}
			else {
				cout << "User Signed In" << endl;
			}
		}
		else {
			cout << "Invalid National ID or Password" << endl;
		}
	}
}
void System::RemoveUser(int adminID, int ID) {
	if (users.find(adminID) != users.end()) {
		Admin* admin = dynamic_cast<Admin*>(users[adminID]);
		if (admin) {
			admin->RemoveUser(ID, users);
		}
		else {
			cout << "Not an admin" << endl;
		}
	}
	else {
		cout << "Invalid ID" << endl;
	}
}
unordered_map<string, Property*> System::FilterBySquareFootage(int squareFootage) {
	return propertyFilterSquareFootage[squareFootage];
}
unordered_map<string, Property*> System::FilterByLocation(string locations) {
	return propertyFilterLocations[locations];
}
map<int, Property*> System::FilterByPrice(int minPrice, int maxPrice) {
	return propertyFilterPrice.getInRange(minPrice, maxPrice);
}