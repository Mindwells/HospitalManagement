#include "Doctor.h"

ostream& operator<<(ostream& os, const Doctor& doctor)
{
	os << "����: " << doctor.id << endl;
	os << "����: " << doctor.name << endl;
	os << "����: " << doctor.age << endl;
	os << "�Ա�: " << 1 << endl;
	os << "��ͥ��ַ: " << doctor.address << endl;
	os << "��������: " << doctor.department << endl;

	return os;
}