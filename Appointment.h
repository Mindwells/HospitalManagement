#ifndef _APPOINTMENT_H_
#define _APPOINTMENT_H_

#include "header.h"
#include "Doctor.h"

class Appointment {
private:
	string visitTime;		// ����ʱ��
	Doctor doctor;			// ����ҽ��
	string department;		// ���ﲿ��
	double expense;			// �������

public:
	Appointment(){}
};

#endif 
