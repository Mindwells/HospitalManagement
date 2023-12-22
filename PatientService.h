#ifndef _PATIENTSERVICE_H_
#define	_PATIENTSERVICE_H_

#include "header.h"
#include "entityHeader.h"

class PatientService {
private:
	vector<Patient> patients;

public:
	vector<Patient> getAllPatients();
	bool addPatient();
	bool delPatient(string id);
	void changePatientInfo(string id);
	bool updatePatient(Patient patient);
	vector<Patient> findPatientsByName(string name);
	Patient findPatientById(string id);
	vector<Patient> sortById();

	bool isExist(string id);
	void showInfo(vector<Doctor> v);
};

#endif
