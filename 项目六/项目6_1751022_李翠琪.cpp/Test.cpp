#include<iostream>
#include "LinkedList.h"
#include <string>

using namespace std;

//�ù����
int main()
{
    cout << "**            ���׹���ϵͳ             **"<<endl;
    cout << "========================================"<<endl;
    cout << "**         ��ѡ��Ҫִ�еĲ���           **"<<endl;
    cout << "**            A---���Ƽ���             **"<<endl;
    cout << "**            B---��Ӽ�ͥ��Ա         **"<<endl;
    cout << "**            C---��ɢ�ֲ���ͥ         **"<<endl;
    cout << "**            D---���ļ�ͥ��Ա����     **"<<endl;
    cout << "**            E---��ѯ����            **"<<endl;
    cout << "**            F---�˳�����            **"<<endl;
    cout << "========================================"<<endl;

    LinkedList<string> families;
    string familyRoot;
    cout << "���Ƚ���һ������!"<<endl;
    cout << "���������ȵ�������"<<endl;
    cin >> familyRoot;
    families.add(familyRoot);
    cout << "�˼��׵������ǣ�" << familyRoot << endl;

    cout<<"��ѡ��Ҫִ�еĲ���:"<<endl;
    string ops;
    cin >> ops;
    while(true)
    {
        if(ops=="A")
        {
            string fatherName;
            int childCount;
            cout<<"������Ҫ������ͥ���˵�����:";
            cin >> fatherName;
			if (families.findFromTree(fatherName))//����˴����˲ż�������������Ů
			{
				cout << "������" << fatherName << "�Ķ�Ů������";
				cin >> childCount;
				cout << "����������" << fatherName << "�Ķ�Ů������";
				string childName;
				for (int i = 0; i < childCount; ++i)
				{
					cin >> childName;
					families.add(fatherName, childName);
				}
				cout << fatherName << "�ĵ�һ�������ǣ�";
				families.show(fatherName);
			}
			else
			{
				cout << "���˲�����!";
			}      
        }
        else if(ops=="B")
        {
            cout << "������Ҫ��Ӷ��ӣ���Ů�������˵�����:";
            string fatherName;
            cin >> fatherName;
			if (families.findFromTree(fatherName))
			{
				cout << " ������" << fatherName << "����ӵĶ��ӣ���Ů������������";
				string childName;
				cin >> childName;
				families.add(fatherName, childName);
				cout << fatherName << "�ĵ�һ�������ǣ�";
				families.show(fatherName);
			}
			else
			{
				cout << "���˲�����!";
			}
        }
        else if(ops=="C")
        {
            cout << "������Ҫ��ɢ��ͥ���˵�������";
            string fatherName;
            cin >> fatherName;
            //ɾ������
            cout << "Ҫ��ɢ��ͥ������"<< fatherName<<endl;
			if (families.findFromTree(fatherName))
			{
				cout << fatherName << "�ĵ�һ��������:";
				families.show(fatherName);
				families.deleteFromTree(fatherName);
			}
			else
			{
				cout << "���˲�����!";
			}
		
        }
        else if(ops=="D")
        {
            cout << "����������������˵�Ŀǰ����";
            string fatherName;
            cin >> fatherName;
			if (families.findFromTree(fatherName))
			{
				cout << "��������ĺ������";
				string updateName;
				cin >> updateName;
				cout << fatherName << "�Ѹ���Ϊ" << updateName;//���ɹ��ĸ���Ҳ���������ʾ,���ǲ���Ū��
				families.update(fatherName, updateName);
			}
			else
			{
				cout << "���˲�����!";
			}
        }
        else if(ops=="E")
        {
            string fatherName;
            cout << " ������Ҫ��ѯ�˵�������";
            cin >> fatherName;
            if(families.findFromTree(fatherName))
            {
                cout <<fatherName<< "�ĵ�һ�������ǣ�";
                families.show(fatherName);
            }
            else
            {
                cout << "���˲�����!";
            }
        }
        else if(ops=="F")
        {
            break;
        }
        cout<<endl<<"��ѡ��Ҫִ�еĲ���:"<<endl;
        cin>>ops;
    }

    return 0;
}
