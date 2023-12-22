#ifndef _PATIENTSERVICE_H_
#define	_PATIENTSERVICE_H_

#include "header.h"
#include "Patient.h"
#include "AppointmentService.h"

class PatientService {
private:
	vector<Patient> patients;
	AppointmentService as;

public:
	vector<Patient> getAllPatients();
	bool addPatient();
	bool delPatient(string id);
	void changePatientInfo(string id);
	bool updatePatient(Patient& patient);
	vector<Patient> findPatientsByName(string name);
	Patient& findPatientById(string id);
	vector<Patient> sortById();

	bool isExist(string id);
	void showInfo(vector<Patient> v);
};

#endif
