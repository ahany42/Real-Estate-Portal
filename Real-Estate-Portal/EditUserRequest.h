#pragma once
#include <ctime>
#include <iostream>
#include"User.h"
using namespace std;
class EditUserRequest
{
	string oldFirstName;
	string oldLastName;
	string oldMobileNumber;
	string newFirstName;
	string newLastName;
	string newMobileNumber;
	bool password;
	string timeStamp;
    string NationalID;
public:
    EditUserRequest(string oldFirstName, string newFirstName, string oldLastName, string newLastName, string oldMobileNumber, string newMobileNumber, bool password, string NationalID, string time);
	EditUserRequest(string oldFirstName,string newFirstName,string oldLastName,string newLastName,string oldMobileNumber,string newMobileNumber,bool password,string NationalID);

    //setters

    void SetOldFirstName(string firstName);
    void SetOldLastName(string lastName);
    void SetOldMobileNumber(string mobileNumber);
    void SetNewFirstName(string firstName);
    void SetNewLastName(string lastName);
    void SetNewMobileNumber(string mobileNumber);


    // Getters 

    string GetOldFirstName();
    string GetOldLastName();
    string GetOldMobileNumber();
    string GetNewFirstName();
    string GetNewLastName();
    string GetNewMobileNumber();
    string GetNationalId();
    bool GetPasswordChanged();
    string GetTime();
};

