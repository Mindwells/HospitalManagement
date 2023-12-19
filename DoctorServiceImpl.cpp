#include "DoctorService.h"

vector<Doctor> DoctorService::getAllDoctor()
{
	return this->doctors;
}

bool DoctorService::addDoctor()
{
	cout << "请输入工号：";
	string id = "";
	/*while (true) {
		cin >> id;
		if (!isExist(id)) {
			cout << "工号已存在，请重新输入！" << endl;
		}
		else {
			break;
		}
	}*/

	cout << "请输入姓名：";
	string name = "";
	cin >> name;
	
	cout << "请输入年龄：";
	int age = 0;
	cin >> age;

	cout << "请输入性别：" << endl;
	cout << "1-男" << endl;
	cout << "2-女" << endl;
	int sex = 0;
	while (true) {
		cin >> sex;
		if (sex != 1 && sex != 2) {
			cout << "输入有误，请按提示输入！" << endl;
		}
		else {
			break;
		}
	}

	cout << "请输入家庭地址：";
	string address = "";
	cin >> address;

	cout << "请输入所属部门：";
	string department = "";
	cin >> department;

	//Doctor* doctor = new Doctor(id, name, age, sex, address, department);
	//this->doctors.push_back(*doctor);

	return true;
}