#include<iostream>
#include<fstream>
using namespace std;
static int c;
struct student
{
	char name[20];
	long code;
	char address[20];
	long math;
	long english;
	long C;


};
student pr[100] = { 0, 0, 0, 0, 0 };
void first_face()
{
	char i;
	for (c; c < 100; c++)
	{

		cout << "����������ѧ��ѧ�ţ���������ַ��������Ӣ�C++��" << endl;
		cin >> pr[c].code >> pr[c].name >> pr[c].address >> pr[c].math >> pr[c].english >> pr[c].C;
		cout << pr[c].code << "    " << pr[c].name << "    " << pr[c].address << "    "
			<< pr[c].math << "    " << pr[c].english << "    " << pr[c].C << "    " << endl;
		cout << "�Ƿ�������룿<y/n>"; cin >> i;
		if (i == 'n')
			break;
	}
}
void  in_storage(student pt)
{
	int p = pt.math + pt.english + pt.C;
	if (pt.code != 0)
	{
		cout << pt.code << "  " << pt.name << "  " << pt.address << "  " << pt.math
			<< "  " << pt.english << "  " << pt.C << "  " << p << "  " << endl;
	}
}
int select_ele(long f)
{
	for (int g = 0; g < 100; g++)
	{
		if (f == pr[g].code)
			return g;
	}
	return -1;
}
void out_storage()
{
	int l, m;
	cout << "��������Ҫɾ����ѧ�ţ�";
	cin >> m;
	l = select_ele(m);
	if (m != -1)
	{
		pr[l].name == 0; pr[l].code = 0; pr[l].address == 0;
		pr[l].math = 0; pr[l].english = 0; pr[l].C = 0;
	}
	else
		cout << "��ѧ�Ų�����" << endl;
}
int save()
{
	ofstream one("ѧ���ɼ�.txt", ios::out);
	if (!one)
	{
		cerr << "Write Error" << endl;
		return 0;
	}
	one << "                                               ѧ���ɼ�                                                 " << endl;
	one << "ѧ��" << "  " << "����" << "  " << "��ַ" << "  " << "�����ɼ�" << "  " << "Ӣ��ɼ�" << "  " << "C++�ɼ�" << "  " << endl;
	for (int o = 0; o < c + 1; o++)
	{
		if (pr[o].code != 0)
		{
			one << pr[o].code << "  " << pr[o].name << "  " << pr[o].address << "  " << pr[o].math << "  " << pr[o].english << "  " << pr[o].C << endl;
		}
	}
	printf("\n");
	one.close();
	return 0;
}
int main()
{
loop:
	cout << "............................................\n";
	cout << "1.�������ѧ������" << endl;
	cout << "2.��ʾѧ������" << endl;
	cout << "3.��ѧ�Ų���" << endl;
	cout << "4.ɾ����¼" << endl;
	cout << "5.����" << endl;
	cout << "6.�˳�" << endl;
	cout << "��ѡ�������1��6��" << endl;
	cout << "............................................\n";
	int a = 0;
	long stu_num;
	int tem;
	cin >> a;


	switch (a)
	{
	case 1:
	{
		first_face();
		goto loop;
		break;
	}
	case 2:
	{
		cout << "���" << "  " << "ѧ��" << "  " << "����" << "  " << "��ַ" << "  " << "����"
			<< "  " << "Ӣ��" << "  " << "C++" << "  " << "�ܷ�" << "  " << endl;
		for (int e = 0; e <= c; e++)
		{
			in_storage(pr[e]);
		}
		goto loop;
		break;
	}
	case 3:
	{
		cout << "������Ҫ��ѯ��ѧ����ѧ�ţ�";
		cin >> stu_num;
		tem = select_ele(stu_num);
		if (tem != -1)
		{
			cout << "ѧ��   ����   ��ַ   ����   Ӣ��   C++" << endl;
			cout << pr[tem].code << "   " << pr[tem].name << "   " << pr[tem].address << "   "
				<< pr[tem].math << "   " << pr[tem].english << "   " << pr[tem].C << endl;
		}
		else
			cout << "�Բ��𣬸�ѧ�Ų����ڡ�" << endl;
		goto loop;
		break;
	}
	case 4:
	{
		out_storage();
		goto loop;
		break;
	}
	case 5:
	{
		save();
		cout << "�ɼ��Ѵ洢" << endl;
		goto loop;
		break;
	}
	}
	system("pause");
	return 0;
};