#include "Appointment.h"

ostream& operator<<(ostream& os, const Appointment& appointment)
{
	os << "就诊编号: " << appointment.id << endl;
	os << "就诊时间: " << appointment.visitTime << endl;
	os << "就诊医生: " << appointment.doctor << endl;
	os << "就诊费用: " << appointment.expense << endl;

	return os;
}