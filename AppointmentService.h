#ifndef _APPOINTMENTSERVICE_H_
#define _APPOINTMENTSERVICE_H_

#include "Appointment.h"
#include "DoctorService.h"

class AppointmentService {
private:
	vector<Appointment> appointments;
	DoctorService doctorService;

public:
	vector<Appointment> getAllAppointments();
	bool addAppointment();
	bool delAppointment(string id);
	Appointment& getAppointment(string id);
	bool updateAppointment(Appointment& appointment);
	Appointment& findAppointmentById(string id);

	bool isExist(string id);
	void showInfo(vector<Appointment> v);
};

#endif