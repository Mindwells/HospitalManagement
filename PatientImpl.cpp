#include "Patient.h"

ostream& operator<<(ostream& os, const Patient& patient)
{
    os << "ID: " << patient.id << endl;
    os << "姓名: " << patient.name << endl;
    os << "出生日期: " << patient.dateOfBirth << endl;
    os << "年龄: " << patient.age << endl;
    os << "性别: " << (patient.sex == 0 ? "男" : "女") << endl;
    os << "体重: " << patient.weight << " 公斤" << endl;
    os << "电话号码: " << patient.phoneNumber << endl;
    os << "地址: " << patient.address << endl;
    os << "预约情况: " << endl;
    for (const auto& appointment : patient.appointments) {
        os << appointment;
        os << "*********" << endl;
    }

    return os;
}