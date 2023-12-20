#include "header.h"
#include "entityHeader.h"
#include "serviceHeader.h"

int main()
{
	DoctorService* ds = new DoctorService;
	 
	/*bool exist = false;
	while (exist) {

	}*/
    // 添加一个医生
    ds->addDoctor();

    // 显示所有医生信息
    ds->showInfo(ds->getAllDoctor());

    // 修改医生信息
    ds->changeDoctorInfo("123");

    // 显示所有医生信息
    ds->showInfo(ds->getAllDoctor());

    // 删除医生
    ds->delDoctor("123");

    // 显示所有医生信息
    ds->showInfo(ds->getAllDoctor());

	return 0;
}