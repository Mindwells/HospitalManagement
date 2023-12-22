#include  "PatientService.h"

vector<Patient> PatientService::getAllPatients()
{
    return this->patients;
}

bool PatientService::addPatient()
{
    cout << "请输入患者ID：";
    string id = "";
    while (true) {
        cin >> id;
        if (isExist(id)) {
            cout << "患者ID已存在，请重新输入！" << endl;
        }
        else {
            break;
        }
    }

    cout << "请输入患者姓名：";
    string name = "";
    cin >> name;

    cout << "请输入患者出生日期：";
    string dateOfBirth = "";
    cin >> dateOfBirth;

    cout << "请输入患者年龄：";
    int age = 0;
    cin >> age;

    cout << "请输入患者性别：" << endl;
    cout << "0-男" << endl;
    cout << "1-女" << endl;
    int sex = 0;
    while (true) {
        cin >> sex;
        if (sex != 0 && sex != 1) {
            cout << "输入有误，请按提示输入！" << endl;
        }
        else {
            break;
        }
    }

    cout << "请输入患者体重：";
    double weight = 0.0;
    cin >> weight;

    cout << "请输入患者联系电话：";
    string phoneNumber = "";
    cin >> phoneNumber;

    cout << "请输入患者家庭地址：";
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

    // 没找到
    return false;
}

void PatientService::changePatientInfo(string id)
{
    Patient& changePatient = findPatientById(id);

    bool exit = false;
    while (!exit) {
        cout << "请选择要修改的信息：" << endl;
        cout << "1. 姓名" << endl;
        cout << "2. 出生日期" << endl;
        cout << "3. 年龄" << endl;
        cout << "4. 性别" << endl;
        cout << "5. 体重" << endl;
        cout << "6. 联系电话" << endl;
        cout << "7. 家庭地址" << endl;
        cout << "8. 退出" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "请输入新的姓名：";
            cin >> changePatient.name;
            break;
        case 2:
            cout << "请输入新的出生日期：";
            cin >> changePatient.dateOfBirth;
            break;
        case 3:
            cout << "请输入新的年龄：";
            cin >> changePatient.age;
            break;
        case 4:
            cout << "请输入新的性别（0表示男，1表示女）：";
            cin >> changePatient.sex;
            break;
        case 5:
            cout << "请输入新的体重：";
            cin >> changePatient.weight;
            break;
        case 6:
            cout << "请输入新的联系电话：";
            cin >> changePatient.phoneNumber;
            break;
        case 7:
            cout << "请输入新的家庭地址：";
            cin >> changePatient.address;
            break;
        case 8:
            exit = true;  // 退出循环
            break;
        default:
            cout << "无效选项，请重新输入" << endl;
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
        cout << "发生异常：" << e.what() << endl;
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

    throw out_of_range("没有找到");
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