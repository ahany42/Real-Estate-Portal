#include "Property.h"
#include <string>
using namespace std;
Property::Property(string Location, string PropertyType, string BuildingNumber, int ApartmentNumber, int SquareFootage, int NumberOfBedrooms, bool verified, int price, string currentUserName, int currentUserId, bool highlighted, string propertyDescription)
{
	this->location = Location;
	this->propertyType = PropertyType;
	this->buildingNumber = BuildingNumber;
	this->apartmentNumber = ApartmentNumber;
	this->squareFootage = SquareFootage;
	this->numberOfBedrooms = NumberOfBedrooms;
	this->verified = verified;
	this->price = price;
	this->userName = currentUserName;
	this->userId = currentUserId;
	this->highlighted = highlighted;
	this->propertyDescription = propertyDescription;
}

Property::Property(string Location, string PropertyType, string BuildingNumber, int ApartmentNumber, int SquareFootage, int NumberOfBedrooms, bool verified, int price, string currentUserName, int currentUserId, bool highlighted) {
	Property(Location, PropertyType, BuildingNumber, ApartmentNumber, SquareFootage, NumberOfBedrooms, verified, price, currentUserName, currentUserId, highlighted, "");
}
Property::Property(string Location, string PropertyType, string BuildingNumber, int ApartmentNumber, int SquareFootage, int NumberOfBedrooms, bool verified, int price, string currentUserName, int currentUserId) {
	Property(Location, PropertyType, BuildingNumber, ApartmentNumber, SquareFootage, NumberOfBedrooms, verified, price, currentUserName, currentUserId, false);
}
Property::Property(string Location, string PropertyType, string BuildingNumber, int ApartmentNumber, int SquareFootage, int NumberOfBedrooms, bool verified, int price, string currentUserName)
{
	Property(Location, PropertyType, BuildingNumber, ApartmentNumber, SquareFootage, NumberOfBedrooms, verified, price, currentUserName, 0);
}
Property::Property(string Location, string PropertyType, string BuildingNumber, int ApartmentNumber, int SquareFootage, int NumberOfBedrooms, bool verified, int price)
{
	Property(Location, PropertyType, BuildingNumber, ApartmentNumber, SquareFootage, NumberOfBedrooms, verified, price, "");
}
Property::Property(string Location, string PropertyType, string BuildingNumber, int ApartmentNumber, int  SquareFootage, int NumberOfBedrooms, bool verified)
{
	Property(Location, PropertyType, BuildingNumber, ApartmentNumber, SquareFootage, NumberOfBedrooms, verified, 0);

}
Property::Property(string Location, string PropertyType, string BuildingNumber, int ApartmentNumber, int SquareFootage, int NumberOfBedrooms)
{
	Property(Location, PropertyType, BuildingNumber, ApartmentNumber, SquareFootage, NumberOfBedrooms, false);
}
Property::Property(string Location, string PropertyType, string BuildingNumber, int ApartmentNumber, int SquareFootage)
{
	Property(Location, PropertyType, BuildingNumber, ApartmentNumber, SquareFootage, 0);
}
Property::Property(string Location, string PropertyType, string BuildingNumber, int ApartmentNumber)
{
	Property(Location, PropertyType, BuildingNumber, ApartmentNumber, 0);
}
Property::Property(string Location, string PropertyType, string BuildingNumber)
{
	Property(Location, PropertyType, BuildingNumber, 0);
}
Property::Property(string Location, string PropertyType) {
	Property(Location, PropertyType, "");
}
Property::Property(string Location) {
	Property(Location, "");
}
Property::Property()
{
	Property("");
}
Property::Property(const Property& Other)
{
	this->location = Other.location;
	this->propertyType = Other.propertyType;
	this->buildingNumber = Other.buildingNumber;
	this->apartmentNumber = Other.apartmentNumber;
	this->squareFootage = Other.squareFootage;
	this->numberOfBedrooms = Other.numberOfBedrooms;
	this->verified = Other.verified;
	this->price = Other.price;
	this->userName = Other.userName;
	this->userId = Other.userId;
	this->highlighted = Other.highlighted;
	this->propertyDescription = Other.propertyDescription;
}

void Property::SetLocation(string Location)
{
	this->location = Location;
}
void Property::SetPropertyType(string PropertyType)
{
	this->propertyType = PropertyType;
}
void Property::SetBuildingNumber(string BuildingNumber)
{
	this->buildingNumber = BuildingNumber;
}
void Property::SetApartmentNumber(int ApartmentNumber)
{
	this->apartmentNumber = ApartmentNumber;
}
void Property::SetSquareFootage(int SquareFootage)
{
	this->squareFootage = SquareFootage;
}
void Property::SetNumberOfBedrooms(int NumberOfBedrooms)
{
	this->numberOfBedrooms = NumberOfBedrooms;
}
void Property::SetVerified(bool Verified)
{
	this->verified = Verified;
}
void Property::SetPrice(int price) {
	this->price = price;
}
void Property::SetPropertyId(string propertyId) {
	this->propertyId = propertyId;
}
void Property::SetHighlight(bool value) {
	highlighted = value;
}
void Property::SetPropertyDescription(string propertyDescription) {
	this->propertyDescription = propertyDescription;
}
string Property::GetLocation()
{
	return location;
}
string Property::GetPropertyType()
{
	return propertyType;
}
string Property::GetBuildingNumber()
{
	return buildingNumber;
}
string Property::GetUserName() {
	return userName;
}
string Property::GetpropertyId() {
	return propertyId;
}
int Property::GetApartmentNumber()
{
	return apartmentNumber;
}
int Property::GetSquareFootage()
{
	return squareFootage;
}
int Property::GetNumberOfBedrooms()
{
	return numberOfBedrooms;
}
int Property::GetPrice() {
	return price;
}
int Property::GetUserId() {
	return userId;
}
bool Property::GetHighlighted() {
	return highlighted;
}
bool Property::GetVerfied()
{
	return verified;
}

string Property::GetPropertyDescription() {
	return propertyDescription;
}



