#include "header.h"
#include "entityHeader.h"
#include "serviceHeader.h"

int main()
{
	DoctorService* ds = new DoctorService;
	 
	/*bool exist = false;
	while (exist) {

	}*/
    // ���һ��ҽ��
    ds->addDoctor();

    // ��ʾ����ҽ����Ϣ
    ds->showInfo(ds->getAllDoctor());

    // �޸�ҽ����Ϣ
    ds->changeDoctorInfo("123");

    // ��ʾ����ҽ����Ϣ
    ds->showInfo(ds->getAllDoctor());

    // ɾ��ҽ��
    ds->delDoctor("123");

    // ��ʾ����ҽ����Ϣ
    ds->showInfo(ds->getAllDoctor());

	return 0;
}