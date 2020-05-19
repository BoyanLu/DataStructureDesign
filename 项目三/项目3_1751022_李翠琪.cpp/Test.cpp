#include<iostream>
#include <vector>
#include "Stack.h"

using namespace std;

void dfs(vector<vector<int>> & map, vector<vector<bool>>& marked,Stack<pair<int,int>>& path, int i, int j, int xhi,int yhi,bool & hasPath)
{
    int M = map.size(), N = map[0].size();
    path.push(make_pair(i, j));
    marked[i][j] = true;
    if(i==xhi && j==yhi)
    {
		hasPath = true;
        Stack<pair<int, int>> reverse;
        while(!path.empty())
        {
            pair<int, int> p = path.top();
            path.pop();
            reverse.push(p);//��ת��stack,�������·��
            map[p.first][p.second] = 2;
        }

        cout<<endl;
        cout << "      ";
        for (int i = 0; i < N; ++i)
        {
            cout << i << "��  ";
        }
        cout<<endl;
        for (int i = 0; i < M; ++i)
        {
            cout << i << "��    ";
            for (int j = 0; j < N; ++j)
            {
                if(map[i][j]==0)
                {
                    cout << "0";
                }
                else if(map[i][j]==2)
                {
                    cout << "X";
                }
                else
                {
                    cout << "#";
                }
                cout << "    ";
            }
            cout<<endl;
        }

        cout<<endl<<"�Թ�·��Ϊ:"<<endl;
        while(!reverse.empty())
        {
            pair<int, int> p = reverse.top();
            reverse.pop();
            if(p.first==xhi && p.second==yhi)
                cout<<"(" << p.first << "," << p.second<<")"<<endl;
            else
                cout << "(" << p.first << "," << p.second << ")->";
        }
    }
    if(i-1>=0 && map[i-1][j]==0 && !marked[i-1][j])
    {
        dfs(map, marked,path, i - 1, j, xhi, yhi, hasPath);
    }
    if(i+1<M && map[i+1][j]==0 && !marked[i+1][j])
    {
        dfs(map, marked,path, i+1, j, xhi, yhi, hasPath);
    }
    if(j+1<N && map[i][j+1]==0 && !marked[i][j+1])
    {
        dfs(map, marked,path, i, j+1, xhi, yhi, hasPath);
    }
    if(j-1>=0 && map[i][j-1]==0 && !marked[i][j-1])
    {
        dfs(map, marked,path, i, j-1, xhi, yhi, hasPath);
    }
    //��·����ʱ,��ջ
    path.pop();
}

bool isValid(vector<vector<int>> & map,int M,int N,int xlo,int ylo,int xhi,int yhi)
{
    if (xlo < 0 || xlo >= M || ylo < 0 || ylo >= N)
    {
        cout << "��ʼ·�������Թ�����";
    }
    else if (map[xlo][ylo] == 1)//����Ϊǽ
    {
        cout << "��ʼ·��Ϊǽ,��������ô��?";
    }
    else if (xhi < 0 || xhi >= M || yhi < 0 || yhi >= N)
    {
        cout << "�յ㲻���Թ�����";
    }
    else if (map[xhi][yhi] == 1)//�յ�Ϊǽ
    {
        cout << "�յ�Ϊǽ,��������ô��?";
    }
    else
    {
        return true;
    }
    return false;
}

int main()
{
    int M,N;
	cout << "����������������,�����Թ���СM*N;������M*N������(0,1�����Թ���·��ǽ):";
	cin >> M >> N;
    vector<vector<int>> map(M, vector<int>(N,1));//Ĭ������ȫΪǽ,��Ȼûʲô��,��Ϊ���û���������
    vector<vector<bool>> marked(M, vector<bool>(N, false));//Ĭ��Ϊû���ʹ���
    Stack<pair<int,int>> path;
    /*
     * 0 0 ·
     * 1 # ǽ
     * 2 x �ߵ�·��
     */
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int mapType;
			cin >> mapType;
            map[i][j] = mapType;
		}
	}
	cout << "������ʼ����ͽ�������(xlo, ylo), (xhi, yhi):";
	int xlo, ylo, xhi, yhi;
	cin >> xlo >> ylo >> xhi >> yhi;

	if(!isValid(map,M,N,xlo,ylo,xhi,yhi))
    {

		cout <<endl<< "���������Ͱ�1: ";
		int gameOver = 0;
		while (true)
		{
			cin >> gameOver;
			if (gameOver == 1)
			{
				break;
			}
		}
	    return 1;
    }

	cout << "�Թ���ͼ:(���Ϊ[" << xlo << "," << ylo << "],�յ�Ϊ[" << xhi << "," << yhi << "])" << endl;

    cout << "      ";
    for (int i = 0; i < N; ++i)
    {
        cout << i << "��  ";
    }
    cout<<endl;
    for (int i = 0; i < M; ++i)
    {
        cout << i << "��    ";
        for (int j = 0; j < N; ++j)
        {
            if(map[i][j]==0)
            {
                cout << "0";
            }
            else
            {
                cout << "#";
            }
            cout << "    ";
        }
        cout<<endl;
    }

	bool hasPath = false;

    //����
    dfs(map,marked,path,xlo,ylo,xhi,yhi, hasPath);
	if (!hasPath)
	{
		cout << "û��·�������[" << xlo << "," << ylo << "]�����յ�[" << xhi << "," << yhi << "])" << endl;
	}

	cout << endl << "���������Ͱ�1: ";
	int gameOver = 0;
	while (true)
	{
		cin >> gameOver;
		if (gameOver == 1)
		{
			break;
		}
	}

    return 0;
}


