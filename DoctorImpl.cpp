#include "Doctor.h"

ostream& operator<<(ostream& os, const Doctor& doctor)
{
	os << "工号: " << doctor.id << endl;
	os << "姓名: " << doctor.name << endl;
	os << "年龄: " << doctor.age << endl;
	os << "性别: " << 1 << endl;
	os << "家庭地址: " << doctor.address << endl;
	os << "所属部门: " << doctor.department << endl;

	return os;
}