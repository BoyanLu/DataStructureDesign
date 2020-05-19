#include<iostream>
#include <string>
#include "Stack.h"
#include <unordered_map>
#include <math.h>

using namespace std;
/*
 ���ʽ�ж�
 1.�����˳���+-* % / ^  ()=,��������������ַ�
 2.()ƥ�䲻ȫ ����()����Ϊ��
 3.���ʽû�н���֮ǰ������=,���߱��ʽ�����=
 4.+-���ǿ�ͷ,����ǰ������(  һĿ�����
 5.�����ǰ�����ߺ������ֻ���(),���Ϊ),�ұ�Ϊ(,����(+)  ��Ŀ�����
 */
bool isValid(const string & expr)
{
    int N = expr.length();
    for (int i = 0; i < N; ++i)
    {
        if(expr[i]!='+'&&expr[i]!='-'&&expr[i]!='*'&&expr[i]!='/'&&expr[i]!='%'&&expr[i]!='^'&&
                expr[i]!='('&&expr[i]!=')'&&expr[i]!='='&& !(expr[i]<='9'&&expr[i]>='0'))
        {
            cout<<"���ʽ���зǷ��ַ�"<<endl;
            return false;
        }
        if(expr[i]=='(')
        {
            if(expr.find(')', i)==-1)
            {
                cout<<"û���㹻��������ƥ��������"<<endl;
                return false;
            }
        }
        if(expr[i]==')')
        {
            int leftCount = 0, rightCount = 0;//()�ĸ���
            for (int j = 0; j <= i; ++j)
            {
                if(expr[j]=='(')
                {
                    ++leftCount;
                }
                else if(expr[j]==')')
                {
                    ++rightCount;
                }
            }
            if(leftCount<rightCount)
            {
                cout<<"û���㹻��������ƥ��������"<<endl;
                return false;
            }
        }
        if(expr[i]=='(' &&i+1<N && expr[i+1]==')')
        {
            cout<<"�����˿�()"<<endl;
            return false;
        }
        if(i==N-1 && expr[i]!='=')
        {
            cout << "����=��β"<<endl;
            return false;
        }
        if(i!=N-1 && expr[i]=='=')
        {
            cout << "���ʽ�г�����="<<endl;
            return false;
        }
        if(expr[i]=='+' || expr[i]=='-')
        {
            if(i==0 || expr[i-1]=='(')//������ĵ� ��Ŀ�����
            {
                if(i+1<N && ((expr[i+1]=='(')||(expr[i+1]<='9'&&expr[i+1]>='0')))//�����˵�
                {
                }
                else
                {
                    cout<<"+-����û�����ֻ���("<<endl;
                    return false;
                }
            }
            //i+1����,���������)��������,�����ұ���(��������
            else if(i+1<N && (expr[i-1]==')' || (expr[i-1]<='9'&&expr[i-1]>='0'))&& ((expr[i+1]=='(')||(expr[i+1]<='9'&&expr[i+1]>='0')))//i-1�϶�>=0,��Ϊ���������
            {

            }
            else
            {
                cout<<"�������+-"<<endl;
                return false;
            }
        }
        if(expr[i]=='^'||expr[i]=='%'||expr[i]=='*'||expr[i]=='/')
        {
            if(i-1>=0 && i+1<N && ((expr[i-1]==')' || (expr[i-1]<='9'&&expr[i-1]>='0'))&& ((expr[i+1]=='(')||(expr[i+1]<='9'&&expr[i+1]>='0'))))
            {
                //�ϸ�
            }
            else
            {
                cout<<"�������*/^%"<<endl;
                return false;
            }
        }
    }
	return true;
}

/*
 * ����˳��
 * ^
 * %
 * �˳�
 * +-
 * ()
 * =
 */

/*
 * ������ֱ�ӷ����׺���ʽ,������,�������ȼ���˳��,������ȼ����ǲ������ӵ�,����ջ����
 * ������ȼ���Ȼ��߸�С,�Ͱ�ջ�еİ������ó���,�����׺���ʽ��
 * �����,�����(),����ѹ��(,����)ʱ��ջ��,(ǰ���ȡ��
 * ���������=-�Ļ�,+���Ե�,-���,����-5  ->  05-
 */
string toPostOrder(const string & expr)
{
    unordered_map<char,int> priority;//�洢����������ȼ�
    priority['='] = 1;
    priority['('] = 2;
    priority[')'] = 2;
    priority['+'] = 3;
    priority['-'] = 3;
    priority['*'] = 4;
    priority['/'] = 4;
    priority['%'] = 5;
    priority['^'] = 6;
    string postOrderedExpr;
    Stack<char> ops;//�洢�������
    for (int i = 0; i < expr.length(); ++i)
    {
        //����һĿ�����
        if((expr[i]=='+' || expr[i]=='-')&&(i == 0 || expr[i - 1] == '('))//����������ʹ��ʱ
        {
            if(expr[i]=='+')
            {
                //������
            }
            else
            {
                postOrderedExpr += "0 ";
                ++i;//��-����Ķ���
                postOrderedExpr += expr[i];
                postOrderedExpr += " - ";
            }

        }
        else if(expr[i]<='9'&&expr[i]>='0')//������Ҫ������,��������������0-9������Ҳ����ȷ����
        {
			int hi = i+1;
			while (true)
			{
				if (hi < expr.length() && expr[hi] <= '9'&&expr[hi] >= '0')
				{
					++hi;
				}
				else
				{
					break;
				}

			}
			//hiָ��������ֺ���ĵ�һ���������ַ�
			//expr.substr(i, hi - i); �õ������ֵ��ַ���
            postOrderedExpr += expr.substr(i, hi - i);
            postOrderedExpr += " ";//�������10+5->105+������
			i = hi - 1;
        }
        else if(expr[i]=='(')
        {
            ops.push(expr[i]);
        }
        else if(expr[i]!=')')//��)����������ѹ��
        {
            if(ops.empty())//ջΪ��,��ѹ�뼴��
            {
                ops.push(expr[i]);
            }
            else
            {
                //��Ҫ��ջ��������Ƚ����ȼ�
                int topStackPriority = priority[ops.top()];
                if(priority[expr[i]]>topStackPriority)
                {
                    ops.push(expr[i]);
                }
                else
                {
                    //���ȼ���ͬ,�ؽ�����֮ǰ���д��ڵ��������ȼ��������,�ټ�����������
                    while(!ops.empty() && priority[expr[i]]<=topStackPriority)
                    {
                        postOrderedExpr += ops.top();
                        postOrderedExpr += " ";
                        ops.pop();
                        if(!ops.empty())
                        {
                            topStackPriority = priority[ops.top()];
                        }
                    }

                    ops.push(expr[i]);
                }
            }
        }
        else if(expr[i]==')')
        {
            //���ʽ�����,һ����ȷ,���Կ���ֱ��������
            while(ops.top()!='(')
            {
                postOrderedExpr += ops.top();
                postOrderedExpr += " ";//�������10+5->105+������
                ops.pop();
            }
            ops.pop();//��(����ȥ
        }
    }
    //ʣ�µ������һ�����
    while(!ops.empty())
    {
        if(ops.top()!='=')//��Ҫ=
        {
            postOrderedExpr += ops.top();
			postOrderedExpr += " ";
        }
        ops.pop();
    }
    return postOrderedExpr;
}

int caculatePostOrder(const string & postOrderedExpr)
{
    Stack<int> nums;
    for (int i = 0; i < postOrderedExpr.length(); ++i)
    {
        if(postOrderedExpr[i]<='9'&&postOrderedExpr[i]>='0')
        {
			//��Ҫ���Ǵ������10������

			int hi = i + 1;
			while (true)
			{
				if (hi < postOrderedExpr.length() && postOrderedExpr[hi] <= '9'&&postOrderedExpr[hi] >= '0')
				{
					++hi;
				}
				else
				{
					break;
				}

			}
			//hiָ��������ֺ���ĵ�һ���������ַ�
			//postOrderedExpr.substr(i, hi - i); �õ������ֵ��ַ���
			

            nums.push(atoi(postOrderedExpr.substr(i, hi - i).c_str()));

			i = hi - 1;
        }
        else if(postOrderedExpr[i]=='^')
        {
            //num1Ϊ��,num2Ϊ��
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();
            nums.push(pow(num1, num2));
        }
        else if(postOrderedExpr[i]=='%')
        {
            //num1Ϊ��,num2Ϊ��
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();
            nums.push(num1%num2);
        }
        else if(postOrderedExpr[i]=='/')
        {
            //num1Ϊ��,num2Ϊ��
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();
            nums.push(num1/num2);
        }
        else if(postOrderedExpr[i]=='*')
        {
            //num1Ϊ��,num2Ϊ��
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();
            nums.push(num1*num2);
        }
        else if(postOrderedExpr[i]=='-')
        {
            //num1Ϊ��,num2Ϊ��
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();
            nums.push(num1-num2);
        }
        else if(postOrderedExpr[i]=='+')
        {
            //num1Ϊ��,num2Ϊ��
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();
            nums.push(num1+num2);
        }

    }
    return nums.top();
}

int main()
{
    while(true)
    {
        string expr,isContinue;
        cout << "������ʽ��" << endl;
        getline(cin,expr);
        if(isValid(expr))
        {
            string postOrderedExpr=toPostOrder(expr);
            cout <<"������ʽΪ:"<<  postOrderedExpr<<endl;
            int result = caculatePostOrder(postOrderedExpr);
            cout<<result<<endl;
        }
        cout<<"���������,n�˳���";
        getline(cin,isContinue);
        if(isContinue=="n")
        {
            break;
        }
    }
    return 0;
}