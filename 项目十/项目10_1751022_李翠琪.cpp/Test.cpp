#include<iostream>
#include <string>


#include "SortCompare.h"

using namespace std;

int main()
{
    cout << "**            �����㷨�Ƚ�             **"<<endl;
    cout << "========================================"<<endl;
    cout << "**            1---ð������             **"<<endl;
    cout << "**            2---ѡ������             **"<<endl;
    cout << "**            3---ֱ�Ӳ�������          **"<<endl;
    cout << "**            4---ϣ������             **"<<endl;
    cout << "**            5---��������             **"<<endl;
    cout << "**            6---������               **"<<endl;
    cout << "**            7---�鲢����             **"<<endl;
    cout << "**            8---��������             **"<<endl;
    cout << "**            9---�˳�����             **"<<endl;
    cout << "========================================"<<endl;

    cout << "������Ҫ������������ĸ�����";
    int N;
    cin>>N;
    
    int whichSort;
    vector<string> changeIndex={"","ð������","ѡ������","ֱ�Ӳ�������","ϣ������","��������","������","�鲢����","��������"};
    SortCompare sortCompare(N);

    double sortTime=0;
    long long exchangeTime=0;
    
    while(true)
    {
        cout << "��ѡ�������㷨:";
        cin >> whichSort;
        if(whichSort==9)
        {
            break;
        }
        sortCompare.test(whichSort, sortTime, exchangeTime);
        cout<<changeIndex[whichSort]<<"����ʱ��:"<<sortTime<<"s"<<endl;
        //�鲢���򲻽�����������,���Կ��Ƚϴ���
        if(whichSort==7)
            cout<<changeIndex[whichSort]<<"�Ƚϴ�����"<<exchangeTime<<endl;
        else
            cout<<changeIndex[whichSort]<<"����������"<<exchangeTime<<endl;
        //����
        sortTime = 0.0;
        exchangeTime = 0;
    }




    return 0;
}