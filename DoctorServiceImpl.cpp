#include "DoctorService.h"

vector<Doctor> DoctorService::getAllDoctor()
{
	return this->doctors;
}

bool DoctorService::addDoctor()
{
	cout << "�����빤�ţ�";
	string id = "";
	while (true) {
		cin >> id;
		if (!isExist(id)) {
			cout << "�����Ѵ��ڣ����������룡" << endl;
		}
		else {
			break;
		}
	}

	cout << "������������";
	string name = "";
	cin >> name;
	
	cout << "���������䣺";
	int age = 0;
	cin >> age;

	cout << "�������Ա�" << endl;
	cout << "0-��" << endl;
	cout << "1-Ů" << endl;
	int sex = 0;
	while (true) {
		cin >> sex;
		if (sex != 0 && sex != 1) {
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

	Doctor* doctor = new Doctor(id, name, age, sex, address, department);
	this->doctors.push_back(*doctor);

	return true;
}

bool DoctorService::delDoctor(string id)
{
	for (auto it = doctors.begin(); it != doctors.end(); it++) {
		if (it->id == id) {
			doctors.erase(it);
			return true;
		}
	}

	// û�ҵ�
	return false;
}

void DoctorService::changeDoctorInfo(string id)
{
	Doctor* changeDoctor = new Doctor();
	try {
		// �����ҵ�ҽ�������
		*changeDoctor = findDoctorById(id);
	}
	catch (const exception e) {
		// ���������Ϣ���߽��������߼�����
		cout << "�����쳣��" << e.what() << endl;
		return;
	}

    bool exit = false;
    while (!exit) {
        cout << "��ѡ��Ҫ�޸ĵ���Ϣ��" << endl;
        cout << "1. ����" << endl;
        cout << "2. ����" << endl;
        cout << "3. �Ա�" << endl;
        cout << "4. ��ַ" << endl;
        cout << "5. ����" << endl;
        cout << "6. �˳�" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "�������µ�������";
                cin >> changeDoctor->name;
                break;
            case 2:
                cout << "�������µ����䣺";
                cin >> changeDoctor->age;
                break;
            case 3:
                cout << "�������µ��Ա�0��ʾ�У�1��ʾŮ����";
                cin >> changeDoctor->sex;
                break;
            case 4:
                cout << "�������µĵ�ַ��";
                cin >> changeDoctor->address;
                break;
            case 5:
                cout << "�������µĲ��ţ�";
                cin >> changeDoctor->department;
                break;
            case 6:
                exit = true;  // �˳�ѭ��
                break;
            default:
                cout << "��Чѡ�����������" << endl;
                break;
        }
		if(choice<=5&&choice>=1)
			updateDoctor(*changeDoctor);
    }
}

// ����ʱ��Ĭ��ԭ���ź��ֹ�������ͬ��
bool DoctorService::updateDoctor(Doctor& doctor)
{
	/*for (auto it = doctors.begin(); it != doctors.end(); it++) {
		if (it->id == doctor.id) {
			*it = doctor;
		}
	}*/

	try {
		// �����ҵ�ҽ�������
		Doctor& foundDoctor = findDoctorById(doctor.id);
		foundDoctor = doctor;
	}
	catch (const exception e) {
		// ���������Ϣ���߽��������߼�����
		cout << "�����쳣��" << e.what() << endl;
		return false;
	}
	
	return true;
}

vector<Doctor> DoctorService::findDoctorsByName(string name)
{
	vector<Doctor> findDoctors;
	for (auto it = doctors.begin(); it != doctors.end(); it++) {
		if (it->name == name)
			findDoctors.push_back(*it);
	}

	return findDoctors;
}

Doctor& DoctorService::findDoctorById(string id)
{
	for (auto it = doctors.begin(); it != doctors.end(); it++) {
		if (it->id == id)
			return *it;
	}

	// û�ҵ����׳��쳣
	throw out_of_range("û���ҵ�");
}

vector<Doctor> DoctorService::sortById()
{
	vector<Doctor> doctorsSortById = doctors;
	
	sort(doctorsSortById.begin(), doctorsSortById.end(), [](const Doctor& a, const Doctor& b) {
		return a.id < b.id;		// ����ҽ��id������������
	});

	return doctorsSortById;
}

bool DoctorService::isExist(string id)
{
	for (Doctor doctor : doctors) {
		if (doctor.id == id)
			return false;
	}

	return true;
}

void DoctorService::showInfo(vector<Doctor> v)
{
	for (const auto& doctor : v) {
		cout << doctor;
		cout << "------------------------" << endl;
	}
}