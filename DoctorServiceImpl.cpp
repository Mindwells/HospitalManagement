#include "DoctorService.h"

vector<Doctor> DoctorService::getAllDoctor()
{
	return this->doctors;
}

bool DoctorService::addDoctor()
{
	cout << "�����빤�ţ�";
	string id = "";
	/*while (true) {
		cin >> id;
		if (!isExist(id)) {
			cout << "�����Ѵ��ڣ����������룡" << endl;
		}
		else {
			break;
		}
	}*/

	cout << "������������";
	string name = "";
	cin >> name;
	
	cout << "���������䣺";
	int age = 0;
	cin >> age;

	cout << "�������Ա�" << endl;
	cout << "1-��" << endl;
	cout << "2-Ů" << endl;
	int sex = 0;
	while (true) {
		cin >> sex;
		if (sex != 1 && sex != 2) {
			cout << "���������밴��ʾ���룡" << endl;
		}
		else {
			break;
		}
	}

	cout << "�������ͥ��ַ��";
	string address = "";
	cin >> address;

	cout << "�������������ţ�";
	string department = "";
	cin >> department;

	//Doctor* doctor = new Doctor(id, name, age, sex, address, department);
	//this->doctors.push_back(*doctor);

	return true;
}