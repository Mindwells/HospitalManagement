#ifndef _PATIENT_H_
#define _PATIENT_H_

#include "header.h"
#include "Appointment.h"

class Patient {
    friend class PatientService;
    friend ostream& operator<<(ostream& os, const Patient& patient);
private:
    string id;
    string name;
    string dateOfBirth;
    int age;
    int sex;
    double weight;
    string phoneNumber;
    string address;
    vector<Appointment> appointments;

public:
    Patient(){}
    Patient(string id, string name, string dateOfBirth, int age, int sex, double weight, string phoneNumber, 
        string address, vector<Appointment> appointments) :
        id(id), name(name), dateOfBirth(dateOfBirth), age(age), sex(sex), weight(weight), phoneNumber(phoneNumber),
        address(address), appointments(appointments) {}
};

#endif