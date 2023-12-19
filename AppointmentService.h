#ifndef _APPOINTMENTSERVICE_H_
#define _APPOINTMENTSERVICE_H_

#include "header.h"
#include "Appointment.h"

class AppointmentService {
private:
	vector<Appointment> appointments;

public:
	vector<Appointment> getAllAppointments();
	bool delAppointment(string id);
	bool addAppointment(Appointment appointment);
	Appointment getAppointment(string id);
	bool updateAppointment(Appointment appointment);
};

#endif