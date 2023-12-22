#ifndef _APPOINTMENT_H_
#define _APPOINTMENT_H_

#include "header.h"
#include "Doctor.h"

class Appointment {
	friend class AppointmentService;
	friend ostream& operator<<(ostream& os, const Appointment& appointment);
private:
	string id;				// ������
	string visitTime;		// ����ʱ��
	Doctor doctor;			// ����ҽ��
	double expense;			// �������

public:
	Appointment(){}
	Appointment(string id, string visitTime, Doctor doctor, double expense) :
		id(id), visitTime(visitTime), doctor(doctor), expense(expense) {}
};

#endif 
