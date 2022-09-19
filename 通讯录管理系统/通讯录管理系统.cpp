// 通讯录管理系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//这是一个c++写的通讯录程序
//
#include <iostream>
#define Max 1000
#include<string>
using namespace std;
// 联系人结构体
struct LianXiRen
{
	string name;
	int sex;//1--boy,2--girl
	int age;
	string tel;
	string address;
};
//通讯录结构体，一个通讯录结构体里有很多联系人结构体，而且还有一个记录通信录中记录数的number
struct TongXunLu
{
	int number;//当前记录的人数
	struct LianXiRen lianxiren[Max];//保存联系人结构体
};


//显示菜单
void showMenu()
{
	cout << "*********************" << endl;
	cout << "通讯录管理系统  " << endl;
	cout << "****************************" << endl;
	cout << "*****1-添加联系人    *******" << endl;
	cout << "*****2-查找所有联系人*******" << endl;
	cout << "*****3-删除联系人    *******" << endl;
	cout << "*****4-查找联系人    *******" << endl;
	cout << "*****5-修改联系人    *******" << endl;
	cout << "*****6-清空联系人    *******" << endl;
	cout << "*****7-退出系统      *******" << endl;
	cout << "****************************" << endl;

}
//添加联系人
void addPersion(TongXunLu* tongxunlu)
{
	//判断通讯录是否已满
	if (tongxunlu->number == Max)
	{
		cout << "-->通讯录已满，无法添加联系人" << endl;
		return;
	}
	else
	{//输入信息
		cout << "请输入姓名" << endl;
		string name;
		cin >> name;
		tongxunlu->lianxiren[tongxunlu->number].name = name;
		cout << "请输入性别：1--男 2--女" << endl;
		int sex = 0;

		while (true)//如果输入的是1，2则输入正确，如果输入的是其他非1，2数则从新输入，直到输入正确为止
		{
			cin >> sex;

			if (sex == 1 || sex == 2)
			{
				tongxunlu->lianxiren[tongxunlu->number].sex = sex;
				break;
			}
			else
			{
				cout << "-->输入错误！参照：1--男，2--女" << endl;
			}
		}
		cout << "请输入年龄" << endl;
		int age = 0;
		while (true)//如果输入的是0<=age<<150则输入正确，如果输入的是其他非0<=age<<150数则从新输入，直到输入正确为止
		{
			cin >> age;

			if (age >= 0 || age <= 150)
			{
				tongxunlu->lianxiren[tongxunlu->number].age = age;
				break;
			}
			else
			{
				cout << "-->输入错误！参照：0<=age<<150" << endl;
			}
		}
		cout << "请输入电话号码" << endl;
		string tel;
		cin >> tel;
		tongxunlu->lianxiren[tongxunlu->number].tel = tel;
		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		tongxunlu->lianxiren[tongxunlu->number].address = address;
		//更新通讯录中的人数
		tongxunlu->number++;
		cout << "-->添加成功" << endl;
		system("pause");
		//清屏
		system("cls");
	}
}
//查找所有的联系人
void findAlls(TongXunLu tongxunlu)
{
	if (tongxunlu.number == 0)
	{
		cout << "-->没有数据" << endl;
	}
	else
	{
		cout << "总共是" << tongxunlu.number << "条数据；分别是：" << endl;

		for (int i = 0; i < tongxunlu.number; i++)
		{
			cout << "姓名：" << tongxunlu.lianxiren[i].name << "\t";
			cout << "性别：" << (tongxunlu.lianxiren[i].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << tongxunlu.lianxiren[i].age << "\t";
			cout << "电话：" << tongxunlu.lianxiren[i].tel << "\t";
			cout << "地址：" << tongxunlu.lianxiren[i].address << endl;
		}
	};
	cout << "-->查找完成" << endl;
	system("pause");
	system("cls");
}
//按名字删除一个联系人
void deletePersion(TongXunLu* tongxunlu)
{
	cout << "请输入要删除的姓名" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < tongxunlu->number; i++)
	{
		if (tongxunlu->lianxiren[i].name == name)
		{
			for (int j = i; j < tongxunlu->number; j++)
			{
				tongxunlu->lianxiren[j] = tongxunlu->lianxiren[j + 1];
			}
			tongxunlu->number--;
			cout << "-->删除成功" << endl;
			return;
		}
	}
	cout << "-->没有找到该联系人" << endl;
}
//通过姓名查找联系人
void findByName(TongXunLu tongxunlu)
{
	cout << "请输入要查找的姓名" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < tongxunlu.number; i++)
	{
		if (tongxunlu.lianxiren[i].name == name)
		{
			cout << "姓名：" << tongxunlu.lianxiren[i].name << endl;
			cout << "性别：" << tongxunlu.lianxiren[i].sex << endl;
			cout << "年龄：" << tongxunlu.lianxiren[i].age << endl;
			cout << "电话：" << tongxunlu.lianxiren[i].tel << endl;
			cout << "地址：" << tongxunlu.lianxiren[i].address << endl;
		}
		cout << "-->查找完成" << endl;
	}
	system("pause");
	system("cls");
}
//更新（修改）联系人
void updata(TongXunLu* tongxunlu)
{
	cout << "请输入要修改的姓名" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < tongxunlu->number; i++)
	{
		if (tongxunlu->lianxiren[i].name == name)
		{
			cout << "请输入姓名" << endl;
			string name;
			cin >> name;
			tongxunlu->lianxiren[i].name = name;
			cout << "请输入性别：1--男 2--女" << endl;
			int sex;
			cin >> sex;
			tongxunlu->lianxiren[i].sex = sex;
			cout << "请输入年龄：" << endl;
			int age;
			cin >> age;
			tongxunlu->lianxiren[i].age = age;
			cout << "请输入电话号码" << endl;
			string tel;
			cin >> tel;
			tongxunlu->lianxiren[i].tel = tel;
			cout << "请输入地址" << endl;
			string address;
			cin >> address;
			tongxunlu->lianxiren[i].address = address;
			cout << "-->修改成功" << endl;
			return;
		}
	}

}
//清除所有联系人 逻辑清空而非物理清空
void cleanAlls(TongXunLu* tongxunlu)
{
	int input;
	cout << "是否确认清除所有联系人？1--是，2--否" << endl;
	cin >> input;
	if (input == 1 || tongxunlu->number != 0)
	{
		tongxunlu->number = 0;//逻辑清空
		cout << "通讯录已经被清空" << endl;
	}
	else
		cout << "--您没有清除任何信息！" << endl;
	return;

}

int main()
{
	int select;
	TongXunLu tongxunlu;
	tongxunlu.number = 0;
	//菜单调用
	while (true)//一直显示菜单，直到退出
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://1-添加联系人
			addPersion(&tongxunlu);//利用地址传递可以修改实参
			break;
		case 2://2-查找所有联系人
			findAlls(tongxunlu);
			break;
		case 3://3-删除联系人
			deletePersion(&tongxunlu);
			break;
		case 4://4-查找联系人 
			findByName(tongxunlu);
			break;
		case 5://5-修改联系人
			updata(&tongxunlu);
			break;
		case 6://6-清空联系人
			cleanAlls(&tongxunlu);
			break;
		case 7://7-退出系统
			cout << "欢迎下次使用" << endl;
			return 0;
			break;

		default:
			break;

		}

	}
	system("pause");
	return 0;
}