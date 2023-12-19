#ifndef _PATIENTSERVICE_H_
#define	_PATIENTSERVICE_H_

#include "header.h"
#include "entityHeader.h"

class PatientService {
private:
	vector<Patient> patients;

public:
	vector<Patient> getAllPatients();
	bool addPatient(Patient patient);
	bool delPatient(string id);
	bool updatePatient(Patient patient);
	vector<Patient> findPatientsByName();
	Patient findPatientById();
	vector<Patient> sortById();
};

#endif
