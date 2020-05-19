#ifndef _UF_H_
#define _UF_H_

#include <vector>

using namespace std;

class UF
{
public:
	UF(int N)
	{
		for (int i = 0; i < N; ++i)
		{
			id.push_back(i);
			sz.push_back(1);
		}
		count = N;
	}

	int getCount()
	{
		return count;
	}

	bool connected(int p, int q)
	{
		return find(p) == find(q);//����ǲ�����ͬһ������
	}

	int find(int p)
	{
		while (p != id[p])
		{
			p = id[p];
		}
		return p;
	}

	void unionPQ(int p, int q)
	{
		int i = find(p);
		int j = find(q);
		if (i == j)
		{
			return;
		}
		if (sz[i] < sz[j])
		{
			id[i] = j;
			sz[j] += sz[i];
		}
		else
		{
			id[j] = i;
			sz[i] += sz[j];
		}
		count--;
	}



private:
	vector<int> id;//����������
	vector<int> sz;//û�����߶�
	int count;//��ͨ��������
};

#endif //_UF_H_
