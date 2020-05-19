#include <iostream>
#include<string>
#include"Student.h"
#include "LinkedList.h"

using namespace std;

/*
	�ÿ���̨ѡ���ѡ��ʽ������й��ܣ�
	���뿼����Ϣ�����������Ϣ����ѯ������Ϣ����ӿ�����Ϣ���޸Ŀ�����Ϣ��ɾ��������Ϣ��

	��Ŀ����Ҫ��
	����Ŀ��ʵ������ɶԿ�����Ϣ�Ľ��������ң����룬�޸ģ�ɾ���ȹ��ܡ�
	������Ϣ����׼��֤�ţ��������Ա�����ͱ������
	���ݽṹ��������ĳ�Ա�����ͳ�Ա������
	Ȼ��ʵ�ָ���Ա��������ɶ����ݲ�������Ӧ���ܣ�
	����������������֤������Ա�����Ĺ��ܲ��õ����н����
	��������ʵ��
*/

int main()
{
    cout<<"�����뽨��������Ϣϵͳ!"<<endl;
    cout<<"�������뿼��������";
    int N;
    cin>>N;//����ѧ������
    cout<<"���������뿼���Ŀ��ţ��������Ա�����ͱ������:";
    //���Զ���������д洢
    /*
    LinkedList�洢Student�࣬�Լ�ʵ��
    ��������
    Ĭ�ϵ�add���ں������
    */
    LinkedList<Student> studentList;
    for (int i = 0; i < N; i++)
    {
        string id,name,gender,exam_category;
        int age;
        cin>>id>>name>>gender>>age>>exam_category;
        Student student(id,name,gender,age,exam_category);
        studentList.add(student);
    }
    studentList.show();
    cout<<"��ѡ����Ҫ���еĲ���(1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ������)"<<endl;

    bool is_continue=true;
    while(is_continue)
    {
        cout<<"��ѡ����Ҫ���еĲ�����";
        int operate;//����
        int pos;//λ��
        string id,name,gender,exam_category;
        int age;
        string value;//�޸�ʱָ��������
        Student student;
        cin>>operate;
        //1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ������
        switch(operate)
        {
            case 1:
                cout<<"��������Ҫ����Ŀ�����λ�ã�";
                cin>>pos;
                //����һ��������Ϣ
                cout << "����������ÿ�������Ϣ: ";
                cin>>id>>name>>gender>>age>>exam_category;
                student.setId(id);
                student.setName(name);
                student.setGender(gender);
                student.setAge(age);
                student.setExamCategory(exam_category);
                studentList.insert(pos,student);
                break;
            case 2:
                cout<<"������Ҫɾ���Ŀ����Ŀ��ţ�";
                //ע���ǲ������ţ����е���string
                cin>>id;
                studentList.pop(id);
                break;
            case 3:
                cout << "������Ҫ���ҵĿ����Ŀ��ţ�";
                cin >> id;
                studentList.show(id);
                break;
            case 4:
                cout << "������Ҫ�޸ĵĿ����Ŀ��ţ�";
                cin >> id;
                cout << "������Ҫ�޸ĵ�λ�ã�";
                cin >> pos;
                cout << "������Ҫ�޸ĵ�ֵ��";
                cin >> value;
                studentList.change(id,pos,value);
                break;
            case 5:
                studentList.show();
                break;
            case 0:
                is_continue=false;
                break;
            default:
                break;
        }
    }
}