#ifndef _DOCTORSERVICE_H_
#define _DOCTORSERVICE_H_

#include "header.h"
#include "Doctor.h"

class DoctorService {
private:
	vector<Doctor> doctors;

public:
	vector<Doctor> getAllDoctor();
	bool addDoctor();
	bool delDoctor(string id);
	bool updateDoctor(Doctor doctor);
	vector<Doctor> findDoctorsByName(string name);
	Doctor findDoctorById();
	vector<Doctor> sortById();
};

#endif
