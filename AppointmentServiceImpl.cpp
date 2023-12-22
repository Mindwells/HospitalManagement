#include "AppointmentService.h"

vector<Appointment> AppointmentService::getAllAppointments()
{
    return this->appointments;
}

bool AppointmentService::addAppointment()
{
    cout << "����������ţ�";
    string id;
    cin >> id;
    if (isExist(id)) {
        cout << "�������Ѵ��ڣ����������룡" << endl;
        return false;
    }

    cout << "���������ʱ�䣺";
    string visitTime;
    cin >> visitTime;

    cout << "���������ҽ�����ţ�";
    string doctorId;
    Doctor doctor;
    bool exit = false;
    while (!exit) {
        cin >> doctorId;

        try {
            doctor = doctorService.findDoctorById(doctorId);
            exit = true;
        }
        catch (const exception e) {
            cout << "�����쳣��" << e.what() << endl;
            cout << "����������ҽ�����ţ�" << endl;
        }
    }

    cout << "�����������ã�";
    double expense;
    cin >> expense;

    Appointment appointment(id, visitTime, doctor, expense);
    this->appointments.push_back(appointment);

    return true;
}

bool AppointmentService::delAppointment(string id)
{
    for (auto it = appointments.begin(); it != appointments.end(); it++) {
        if (it->id == id) {
            appointments.erase(it);
            return true;
        }
    }
    return false;
}

Appointment& AppointmentService::getAppointment(string id)
{
    for (auto it = appointments.begin(); it != appointments.end(); it++) {
        if (it->id == id) {
            return *it;
        }
    }
    throw out_of_range("û���ҵ�");
}

bool AppointmentService::updateAppointment(Appointment& appointment)
{
    /*for (auto it = appointments.begin(); it != appointments.end(); it++) {
        if (it->id == appointment.id) {
            *it = appointment;
            return true;
        }
    }*/

    try {
        Appointment& foundAppointment = findAppointmentById(appointment.id);
        foundAppointment = appointment;
    }
    catch (const exception e) {
        cout << "�����쳣��" << e.what() << endl;
        return false;
    }

    return true;
}

Appointment& AppointmentService::findAppointmentById(string id)
{
    for (auto it = appointments.begin(); it != appointments.end(); it++) {
        if (it->id == id)
            return *it;
    }

    //û�ҵ����׳��쳣
    throw out_of_range("û���ҵ�");
}

bool AppointmentService::isExist(string id)
{
    for (Appointment appointment : appointments) {
        if (appointment.id == id) {
            return true;
        }
    }
    return false;
}

void AppointmentService::showInfo(vector<Appointment> v)
{
    for (const auto& appointment : v) {
        cout << appointment;
        cout << "------------------------" << endl;
    }
}