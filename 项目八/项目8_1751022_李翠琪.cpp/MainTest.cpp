#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Edge.h"
#include "EdgeWeightedGraph.h"
#include "KruskalMST.h"

using namespace std;

int main()
{

	cout << "**             �����������ģ��ϵͳ             **" << endl;
	cout << "================================================" << endl;
	cout << "**                A---������������             **" << endl;
	cout << "**                B---��ӵ����ı�             **" << endl;
	cout << "**                C---������С������           **" << endl;
	cout << "**                D---��ʾ��С������           **" << endl;
	cout << "**                E---�˳�����                **" << endl;
	cout << "================================================" << endl;

	unordered_map<string, int> names;//�ڵ�������ڵ������໥��Ӧ
	EdgeWeightedGraph * G = nullptr;
	KruskalMST * kruskal = nullptr;

	while (true)
	{
		cout << "��ѡ�����:";
		char operation;
		cin >> operation;
		if (operation == 'A')
		{
			cout << "������ڵ�����:";
			int N;//�ڵ�����
			cin >> N;
			cout << "����������ڵ�����:";
			for (int i = 0; i < N; ++i)
			{
				string node;
				cin >> node;
				names[node] = i;
			}
			G = new EdgeWeightedGraph(N);//����һ��û�бߵ�ͼ
		}
		else if (operation == 'B')
		{
			while (true)
			{
				cout << "�������������㼰�ߣ�(����0 0 0 ����)";
				string node1, node2;
				double nodeValue;
				cin >> node1 >> node2 >> nodeValue;
				if (node1 == "0" && node2 == "0" && nodeValue == 0)
				{
					break;
				}
				if (nodeValue <= 0)
				{
					cout << "�������,����������·�Ļ��Ѳ���С�ڵ���0";
				}
				int v = 0, w = 0;
				auto iter = names.find(node1);
				if (iter != names.end())
				{
					v = iter->second;
				}
				auto iter2 = names.find(node2);
				if (iter2 != names.end())
				{
					w = iter2->second;
				}
				if (v == -1 || w == -1)
				{
					cout << "�������,����Ķ��㲻��ͼ��!";
				}
				else
				{
					Edge edge(v, w, nodeValue);
					G->addEdge(edge);
				}
			}
		}
		else if (operation == 'C')
		{
			cout << "��С�����������ɹ�!";
			kruskal = new KruskalMST(*G);
		}
		else if (operation == 'D')
		{
			cout << "��С�������Ķ���ͱ�Ϊ:" << endl;
			Queue<Edge> queue = kruskal->getMST();
			while (!queue.empty())
			{
				Edge e = queue.dequeue();
				int v = e.either();
				int w = e.other(v);
				string name1, name2;

				int count = 0;
				for (auto iter = names.begin(); iter != names.end(); ++iter)
				{
					if (iter->second == v)
					{
						name1 = iter->first;
						++count;
					}
					if (iter->second == w)
					{
						name2 = iter->first;
						++count;
					}
					if (count == 2)
					{
						break;
					}//�ҵ��������˳�
				}
				cout << "[" << name1 << "---" << name2 << " cost: " << e.getWeight() << "]" << endl;
			}
			// kruskal->printAll(); ��Ҫ�ַ���ʾ
		}
		else if (operation == 'E')
		{
			cout << "�ڴ������´�ʹ��!";
			return 0;
		}
	}
}

