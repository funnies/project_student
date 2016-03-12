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

		cout << "请依次输入学生学号，姓名，地址，高数，英语，C++：" << endl;
		cin >> pr[c].code >> pr[c].name >> pr[c].address >> pr[c].math >> pr[c].english >> pr[c].C;
		cout << pr[c].code << "    " << pr[c].name << "    " << pr[c].address << "    "
			<< pr[c].math << "    " << pr[c].english << "    " << pr[c].C << "    " << endl;
		cout << "是否继续输入？<y/n>"; cin >> i;
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
	cout << "请输入你要删除的学号：";
	cin >> m;
	l = select_ele(m);
	if (m != -1)
	{
		pr[l].name == 0; pr[l].code = 0; pr[l].address == 0;
		pr[l].math = 0; pr[l].english = 0; pr[l].C = 0;
	}
	else
		cout << "该学号不存在" << endl;
}
int save()
{
	ofstream one("学生成绩.txt", ios::out);
	if (!one)
	{
		cerr << "Write Error" << endl;
		return 0;
	}
	one << "                                               学生成绩                                                 " << endl;
	one << "学号" << "  " << "姓名" << "  " << "地址" << "  " << "高数成绩" << "  " << "英语成绩" << "  " << "C++成绩" << "  " << endl;
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
	cout << "1.输入添加学生资料" << endl;
	cout << "2.显示学生资料" << endl;
	cout << "3.按学号查找" << endl;
	cout << "4.删除记录" << endl;
	cout << "5.保存" << endl;
	cout << "6.退出" << endl;
	cout << "请选择操作（1—6）" << endl;
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
		cout << "序号" << "  " << "学号" << "  " << "姓名" << "  " << "地址" << "  " << "高数"
			<< "  " << "英语" << "  " << "C++" << "  " << "总分" << "  " << endl;
		for (int e = 0; e <= c; e++)
		{
			in_storage(pr[e]);
		}
		goto loop;
		break;
	}
	case 3:
	{
		cout << "输入你要查询的学生的学号：";
		cin >> stu_num;
		tem = select_ele(stu_num);
		if (tem != -1)
		{
			cout << "学号   姓名   地址   高数   英语   C++" << endl;
			cout << pr[tem].code << "   " << pr[tem].name << "   " << pr[tem].address << "   "
				<< pr[tem].math << "   " << pr[tem].english << "   " << pr[tem].C << endl;
		}
		else
			cout << "对不起，该学号不存在。" << endl;
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
		cout << "成绩已存储" << endl;
		goto loop;
		break;
	}
	}
	system("pause");
	return 0;
};