#include "AppointmentService.h"

vector<Appointment> AppointmentService::getAllAppointments()
{
    return this->appointments;
}

bool AppointmentService::addAppointment()
{
    cout << "请输入就诊编号：";
    string id;
    cin >> id;
    if (isExist(id)) {
        cout << "就诊编号已存在，请重新输入！" << endl;
        return false;
    }

    cout << "请输入就诊时间：";
    string visitTime;
    cin >> visitTime;

    cout << "请输入就诊医生工号：";
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
            cout << "发生异常：" << e.what() << endl;
            cout << "请重新输入医生工号！" << endl;
        }
    }

    cout << "请输入就诊费用：";
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
    throw out_of_range("没有找到");
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
        cout << "发生异常：" << e.what() << endl;
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

    //没找到，抛出异常
    throw out_of_range("没有找到");
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