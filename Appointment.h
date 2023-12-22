#ifndef _APPOINTMENT_H_
#define _APPOINTMENT_H_

#include "header.h"
#include "Doctor.h"

class Appointment {
	friend class AppointmentService;
	friend ostream& operator<<(ostream& os, const Appointment& appointment);
private:
	string id;				// 就诊编号
	string visitTime;		// 就诊时间
	Doctor doctor;			// 就诊医生
	double expense;			// 就诊费用

public:
	Appointment(){}
	Appointment(string id, string visitTime, Doctor doctor, double expense) :
		id(id), visitTime(visitTime), doctor(doctor), expense(expense) {}
};

#endif 
