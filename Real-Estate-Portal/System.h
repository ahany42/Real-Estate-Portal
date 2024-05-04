#pragma once
#include <unordered_map>
#include <map>
#include <string>
#include <queue>
#include "User.h"
#include "Admin.h"
#include "Property.h"
using namespace std;
class System{
public:
	unordered_map<string, User*> users;
	queue<Property*> unVerified;
	string currentUserId;
	string currentUserName;
	//Hashtables for filter
	unordered_map<int, unordered_map<string, Property*>> propertyFilterSquareFootage;
	unordered_map<string, unordered_map<string, Property*>> propertyFilterType;
	unordered_map<int, unordered_map<string, Property*>> propertyFilterBedRooms;
	unordered_map<string, unordered_map<string, Property*>> propertyFilterLocations;
	map<int, unordered_map<string, Property*>> propertyFilterPrice;
	unordered_map<string, Property*> propertyComparison;
	unordered_map<string, Property*> properties;
	unordered_map<string, User*> GetUsers();
	unordered_map<string, Property*> GetProperties();
	unordered_map<string, Property*> GetPropertyComparison();
	unordered_map<int, unordered_map<string, Property*>> GetPropertyFilterSquareFootage();
	unordered_map<int, unordered_map<string, Property*>> GetpropertyFilterBedRooms();
	unordered_map<string, unordered_map<string, Property*>> GetPropertyFilterType();
	unordered_map<string, unordered_map<string, Property*>> GetPropertyFilterLocations();
	map<int, unordered_map<string, Property*>>GetPropertyFilterPrice();


	//Filter functions 
	unordered_map<string, Property*> FilterBySquareFootage(int squareFootage);
	unordered_map<string, Property*> FilterByNumberOfBedrooms(int bedrooms);
	unordered_map<string, Property*>  FilterByLocation(string locations);
	map<int, unordered_map<string,Property*>> FilterByPrice(int minPrice, int maxPrice);
	unordered_map<string, Property*>  FilterByType(string type);


	void Request(Property *property);
	void SignUp(string fName, string lName, string natId, string password,string mobileNumber);
	void Login(string ID, string password);
	void UserChangePassword(string currentPassword,string newPassword,User& user);
	void RemoveUser(string adminID, string userID,System &system);
	void AddToCompare(string propertyId);
	void RemoveFromCompare(string propertyId);
	void AddProperty(string Location, string PropertyType, string BuildingNumber, int ApartmentNumber, int SquareFootage, int NumberOfBedrooms, int price, string currentUserName, string currentUserId, string propertyDescription);
	void EditProperty(string Location, string PropertyType, string BuildingNumber, int ApartmentNumber, int SquareFootage, int NumberOfBedrooms, int price, string currentUserName, string currentUserId, string propertyDescription, string propertyId);
	void RemoveProperty(string propertyId, string currentUserId);
	void EditMobileNumber(string currentUserId, string mobileNumber);
	void AddAdmin(string firstName, string lastName, string nationalId, string password);
	int UserCounter();
	int PropertiesCounter();
	bool FindUser(string nationalid);
	
};

