#include  "PatientService.h"

vector<Patient> PatientService::getAllPatients()
{
    return this->patients;
}

bool PatientService::addPatient()
{
    cout << "�����뻼��ID��";
    string id = "";
    while (true) {
        cin >> id;
        if (isExist(id)) {
            cout << "����ID�Ѵ��ڣ����������룡" << endl;
        }
        else {
            break;
        }
    }

    cout << "�����뻼��������";
    string name = "";
    cin >> name;

    cout << "�����뻼�߳������ڣ�";
    string dateOfBirth = "";
    cin >> dateOfBirth;

    cout << "�����뻼�����䣺";
    int age = 0;
    cin >> age;

    cout << "�����뻼���Ա�" << endl;
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

    cout << "�����뻼�����أ�";
    double weight = 0.0;
    cin >> weight;

    cout << "�����뻼����ϵ�绰��";
    string phoneNumber = "";
    cin >> phoneNumber;

    cout << "�����뻼�߼�ͥ��ַ��";
    string address = "";
    cin >> address;

    as.addAppointment();
    Patient patient(id, name, dateOfBirth, age, sex, weight, phoneNumber, address, as.appointments);
    this->patients.push_back(patient);

    return true;
}

bool PatientService::delPatient(string id)
{
    for (auto it = patients.begin(); it != patients.end(); it++) {
        if (it->id == id) {
            patients.erase(it);
            return true;
        }
    }

    // û�ҵ�
    return false;
}

void PatientService::changePatientInfo(string id)
{
    Patient& changePatient = findPatientById(id);

    bool exit = false;
    while (!exit) {
        cout << "��ѡ��Ҫ�޸ĵ���Ϣ��" << endl;
        cout << "1. ����" << endl;
        cout << "2. ��������" << endl;
        cout << "3. ����" << endl;
        cout << "4. �Ա�" << endl;
        cout << "5. ����" << endl;
        cout << "6. ��ϵ�绰" << endl;
        cout << "7. ��ͥ��ַ" << endl;
        cout << "8. �˳�" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "�������µ�������";
            cin >> changePatient.name;
            break;
        case 2:
            cout << "�������µĳ������ڣ�";
            cin >> changePatient.dateOfBirth;
            break;
        case 3:
            cout << "�������µ����䣺";
            cin >> changePatient.age;
            break;
        case 4:
            cout << "�������µ��Ա�0��ʾ�У�1��ʾŮ����";
            cin >> changePatient.sex;
            break;
        case 5:
            cout << "�������µ����أ�";
            cin >> changePatient.weight;
            break;
        case 6:
            cout << "�������µ���ϵ�绰��";
            cin >> changePatient.phoneNumber;
            break;
        case 7:
            cout << "�������µļ�ͥ��ַ��";
            cin >> changePatient.address;
            break;
        case 8:
            exit = true;  // �˳�ѭ��
            break;
        default:
            cout << "��Чѡ�����������" << endl;
            break;
        }

        if (choice <= 7 && choice >= 1)
            updatePatient(changePatient);
    }
}

bool PatientService::updatePatient(Patient& patient)
{
    try {
        Patient& foundPatient = findPatientById(patient.id);
        foundPatient = patient;
    }
    catch (const exception& e) {
        cout << "�����쳣��" << e.what() << endl;
        return false;
    }

    return true;
}

vector<Patient> PatientService::findPatientsByName(string name)
{
    vector<Patient> findPatients;
    for (auto it = patients.begin(); it != patients.end(); it++) {
        if (it->name == name)
            findPatients.push_back(*it);
    }

    return findPatients;
}

Patient& PatientService::findPatientById(string id)
{
    for (auto it = patients.begin(); it != patients.end(); it++) {
        if (it->id == id)
            return *it;
    }

    throw out_of_range("û���ҵ�");
}

vector<Patient> PatientService::sortById()
{
    vector<Patient> patientsSortById = patients;

    sort(patientsSortById.begin(), patientsSortById.end(), [](const Patient& a, const Patient& b) {
        return a.id < b.id;
        });

    return patientsSortById;
}

bool PatientService::isExist(string id)
{
    for (Patient patient : patients) {
        if (patient.id == id)
            return true;
    }

    return false;
}

void PatientService::showInfo(vector<Patient> v)
{
    for (const auto& patient : v) {
        cout << patient;
        cout << "------------------------" << endl;
    }
}