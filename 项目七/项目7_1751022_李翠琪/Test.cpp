#include<iostream>
#include <vector>
#include "MinPQ.h"

using namespace std;

//�ȼ�����n��Ԫ�ع���һ��������,n��Ԫ����������ײ�
// ����ʹ�ó���root��,�����ڵ������С

/*
 * ������˼��,���ÿ�ζ԰�ֵ�ʱ��,�������С
 * ��ô,��ֻ����Ƭ��ʱ��,ÿһ�ζ��ó���С����������ƴ��
 * ���Ƕ԰�ֵ��������
 * ����ֻ��Ҫ��һ��ÿ�ζ���ȡ����СԪ�ص����ȶ��м���
 */
int main()
{
    cout << "����������N(�ֳ�N��,N<1024),��N��������(ÿ�鳤��):";
    int N;
    cin >> N;
    int sum = 0;
    MinPQ minPQ(N);
    for (int i = 0; i < N; ++i)
    {
        int len;
        cin >> len;
		minPQ.push(len);
    }
    while(minPQ.size()>=2)
    {
        int min1=minPQ.delMin();
        int min2=minPQ.delMin();
        sum += min1 + min2;
        minPQ.push(min1 + min2);
    }
    cout << sum;
	cout <<endl<< "�Ƿ�Ҫ�˳�?��1�˳�"<<endl;
	cin >> N;
	while (N!=1)
	{

	}

    return 0;
}