#include "Appointment.h"

ostream& operator<<(ostream& os, const Appointment& appointment)
{
	os << "������: " << appointment.id << endl;
	os << "����ʱ��: " << appointment.visitTime << endl;
	os << "����ҽ��: " << appointment.doctor << endl;
	os << "�������: " << appointment.expense << endl;

	return os;
}