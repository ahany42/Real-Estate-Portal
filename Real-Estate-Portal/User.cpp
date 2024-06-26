#include "User.h"
#include <iostream>
#include <string>
#include "System.h"
#include "Admin.h"
#include <unordered_map>
#include "Property.h"

using namespace std;
User::User(string fName, string lName, string natId, string password, string mobileNumber) {
	firstName = fName;
	lastName = lName;
	nationalId = natId;
	this->password = password;
	this->mobileNumber = mobileNumber;
}
User::User(string fName, string lName, string natId, string password) :User(fName, lName, natId, password, "") {

}
User::User(string fName, string lName, string natId) :User(fName, lName, natId, "") {

}
User::User(string fName, string lName) :User(fName, lName, "") {

}
User::User(string fName) :User(fName, "") {

}
User::User() :User("") {

}
User::User(const User& other) {
	this->firstName = other.firstName;
	this->lastName = other.lastName;
	this->nationalId = other.nationalId;
	this->password = other.password;
	this->mobileNumber = other.mobileNumber;
}
string User::GetFirstName() {
	return this->firstName;
}
string User::GetLastName() {
	return this->lastName;
}
string User::GetName() {
	return firstName + " " + lastName;
}
string User::GetPassword() {
	return password;
}
string User::GetMobileNumber() {
	return mobileNumber;
}
string User::GetNationalId() {
	return this->nationalId;
}
int User::GetUserCountProperty() {
	return UserCountProperty;
}

void User::SetFirstName(string firstname) {
	this->firstName = firstname;
}
void User::SetLastName(string lastname) {
	this->lastName = lastname;
}
void User::SetNationalId(string nationalId) {
	this->nationalId = nationalId;
}
void User::SetPassword(string password) {
	this->password = password;
}
void User::SetMobileNumber(string mobileNumber) {
	this->mobileNumber = mobileNumber;
}

void User::AddProperty(string Location, string PropertyType, string City, string AddressLine, int SquareFootage, int NumberOfBedrooms, int price, string currentUserName, string currentUserId, string propertyDescription, System& system) {
	Property* NewProperty = new Property(Location, PropertyType, City, AddressLine, SquareFootage, NumberOfBedrooms, false, price, currentUserName, currentUserId, false, propertyDescription, 0);
	string propertyId = NewProperty->GeneratePropertyId();
	while (system.properties.find(propertyId) != system.properties.end()) {
		propertyId = NewProperty->GeneratePropertyId();
	}
	//may cause problems
	NewProperty->SetPropertyId(propertyId);
	system.properties[propertyId] = NewProperty;
	UserAddedProperty(propertyId, NewProperty);
	system.Request(NewProperty);


}
void User::RemoveProperty(string propertyId, System& system) {
	Property* property = system.properties[propertyId];
	if (properties.find(propertyId) != properties.end()) {
		if (!property->GetVerfied()) {
			system.properties.erase(propertyId);
			properties.erase(propertyId);
			delete property;
		}
		else {
			auto it = std::find(system.propertyComparison.begin(), system.propertyComparison.end(), property);
			if (it != system.propertyComparison.end()) {
				system.propertyComparison.erase(it);
			}
			system.propertyFilterBedRooms[property->GetNumberOfBedrooms()].erase(propertyId);
			system.propertyFilterLocations[property->GetLocation()].erase(propertyId);
			system.propertyFilterType[property->GetPropertyType()].erase(propertyId);
			system.propertyFilterSquareFootage[property->GetSquareFootage()].erase(propertyId);
			system.propertyFilterComparison[property->GetCompareCounter()].erase(propertyId);
			system.properties.erase(propertyId);
			properties.erase(propertyId);			
			system.propertiesCount--;
			system.SortUserByPropertyCount(nationalId, false);
			delete property;
		}
	}
	else {
		throw exception("Property doesn't belong to User");
	}


}
unordered_map<string, Property*> User::GetUserProperties() {
	return properties;
}
void User::UserAddedProperty(string propertyId, Property* property) {
	//properties[propertyId] = property;
	properties.insert({ propertyId,property });
}
void User::UserEditProperty(string Location, string PropertyType, string City, string AddressLine, int SquareFootage, int NumberOfBedrooms, int price, string propertyDescription, System& system, string editPropertyId) {
	if (properties.find(editPropertyId) != properties.end()) {
		Property* property = system.properties[editPropertyId];
		EditPropertyRequest* CurrentRequest = new EditPropertyRequest(property->GetLocation(), property->GetPropertyType(), property->GetCity(), property->GetAddressLine(), property->GetSquareFootage(), property->GetNumberOfBedrooms(), property->GetPrice(), property->GetPropertyDescription(), Location, PropertyType, City, AddressLine, SquareFootage, NumberOfBedrooms, price, propertyDescription, property->GetpropertyId(), property->GetUserId());
		if (property->GetLocation() != Location)
		{
			system.propertyFilterLocations[property->GetLocation()].erase(editPropertyId);
			system.propertyFilterLocations[Location][editPropertyId] = property;
			property->SetLocation(Location);
		}
		if (property->GetPropertyType() != PropertyType)
		{
			system.propertyFilterType[property->GetPropertyType()].erase(editPropertyId);
			system.propertyFilterType[PropertyType][editPropertyId] = property;
			property->SetPropertyType(PropertyType);
		}
		if (property->GetSquareFootage() != SquareFootage)
		{
			system.propertyFilterSquareFootage[property->GetSquareFootage()].erase(editPropertyId);
			system.propertyFilterSquareFootage[SquareFootage][editPropertyId] = property;
			property->SetSquareFootage(SquareFootage);
		}
		if (property->GetNumberOfBedrooms() != NumberOfBedrooms)
		{
			system.propertyFilterBedRooms[property->GetNumberOfBedrooms()].erase(editPropertyId);
			system.propertyFilterBedRooms[NumberOfBedrooms][editPropertyId] = property;
			property->SetNumberOfBedrooms(NumberOfBedrooms);
		}
		if (property->GetPrice() != price)
		{
			system.propertyFilterPrice[property->GetPrice()].erase(editPropertyId);
			system.propertyFilterPrice[price][editPropertyId] = property;
			property->SetPrice(price);
		}
		property->SetCity(City);
		property->SetAddressLine(AddressLine);
		property->SetPropertyDescription(propertyDescription);
		system.EditPropertyLogs.push_back(CurrentRequest);
	}
}
bool User::HasProperty(string propertyId) {
	return (properties.find(propertyId) != properties.end());
}
User::~User() {

}