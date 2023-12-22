#include "Patient.h"

ostream& operator<<(ostream& os, const Patient& patient)
{
    os << "ID: " << patient.id << endl;
    os << "����: " << patient.name << endl;
    os << "��������: " << patient.dateOfBirth << endl;
    os << "����: " << patient.age << endl;
    os << "�Ա�: " << (patient.sex == 0 ? "��" : "Ů") << endl;
    os << "����: " << patient.weight << " ����" << endl;
    os << "�绰����: " << patient.phoneNumber << endl;
    os << "��ַ: " << patient.address << endl;
    os << "ԤԼ���: " << endl;
    for (const auto& appointment : patient.appointments) {
        os << appointment;
        os << "*********" << endl;
    }

    return os;
}