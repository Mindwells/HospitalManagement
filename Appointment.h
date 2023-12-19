#ifndef _APPOINTMENT_H_
#define _APPOINTMENT_H_

#include "header.h"
#include "Doctor.h"

class Appointment {
private:
	string visitTime;		// 就诊时间
	Doctor doctor;			// 就诊医生
	string department;		// 就诊部门
	double expense;			// 就诊费用

public:
	Appointment(){}
};

#endif 
