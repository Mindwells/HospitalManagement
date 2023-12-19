#ifndef _PATIENT_H_
#define _PATIENT_H_

#include "header.h"
#include "Appointment.h"

class Patient {
private:
    int id;
    string name;
    string gender;
    string dateOfBirth;
    int age;
    double weight;
    string phoneNumber;
    string address;
    Appointment appointment;

public:
    Patient(){}
};

#endif