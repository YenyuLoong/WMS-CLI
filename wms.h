#ifndef _WMS_H_
#define _WMS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/******************************************************************
本软件是在GNU GPL V2许可证下授权的自由软件，源代码完全公开，用户可自由获取，使用，修改，分享，重新发布本软件， 
并且根据GPL许可证的内容，用户必须把修改版以及衍生版的软件一同继续在GPL许可证下授权成自由软件，所谓软件自由化。
若要查阅许可证请参见以下链接： 
GPL V2 许可证原文：http://www.gnu.org/licenses/old-licenses/gpl-2.0.html 
GPL V2 许可证中文翻译： http://mprc.pku.edu.cn/~ruankunliang/gpl.html
******************************************************************/ 

//员工性别限定宏定义函数 
#define _SEX(sex)	((sex==0 || sex==1)?1:0)
//员工性别值转中文字符宏定义函数 
#define _SEX_CONV(sex)	(sex==0?"男":"女")


#define NAMESIZE 20						//员工名字字符大小 
#define EMPLOYEES 500					//Employee结构体数组大小 
#define DATAFILE "employee.dat"			//存取数据文件名 

#define CMD_COLOR "color 0a"			//Windows操作系统上的控制台黑底绿字颜色命令 
#define CMD_PRESSANYKEY "pause && cls"	//Windows操作系统上的控制台暂停以及清屏命令 （用于system()函数） 
#define CMD_CLEARSCREEN "cls"			//Windows操作系统上的控制台清屏命令 （用于system()函数） 

//帮助信息字符串 
#define HELPINFO	"本系统是一个基于Windows操作系统 CLI（命令提示符），超轻量级的、自由且开源的工资管理系统，可以使管理者仅通过键盘直接管理员工工资信息。所有信息全部以文件的形式保存下来，构造十分简单，无需操作数据库。本系统大体上分为六个功能模块：\n\n录入模块：录入新的员工信息到系统\n查询模块：查询系统中的员工信息（目前支持通过工号查询）\n浏览模块：浏览系统中所有的员工信息（目前支持以工资高低和工号排序）\n修改模块：修改系统中的员工信息\n删除模块：删除系统中的员工信息（目前支持使用工号定位员工信息）\n统计模块：统计系统中的所有员工信息（目前支持以工资分布统计员工信息）\n"


//工资临界值，用于统计工资分布 
#define SPLIT0	0
#define SPLIT1	1000
#define SPLIT2	2000
#define SPLIT3	3000
#define SPLIT4	5000
#define SPLIT5	10000



//主模块操作值枚举类型
typedef enum
{
	OPT_EXIT = '0',	//退出 
	OPT_ADD,	//录入操作 
	OPT_QUERY,	//查询操作 
	OPT_EXP,	//浏览操作 
	OPT_MODIFY,	//修改操作 
	OPT_DEL,	//删除操作 
	OPT_COUNT,	//统计操作 
	OPT_HELP	//系统帮助 
	
}main_module_opt;
 
//子模块操作值枚举类型 
typedef enum
{
	SUB_EXIT = '0',
	SUB_ENTER
	
}sub_module_opt;


//性别枚举类型 
typedef enum
{
	SEX_MAN = '0',	//男性 
	SEX_WOMAN		//女性 
	
}sex;

//修改选项枚举类型 
typedef enum
{
	MODIFY_EXIT = '0',
	MODIFY_NUM,
	MODIFY_NAME,
	MODIFY_SEX,
	MODIFY_AGE,
	MODIFY_WAGES
	
}modify_option;

//排序方式枚举类型
typedef enum
{
	SORT_DEFAULT = '0',
	SORT_WAGES,
	SORT_NUM
}sort_option;

//Employee员工结构体
typedef struct Employee
{
	int num;				//工号 
	char name[NAMESIZE];	//姓名 
	int sex;				//性别 
	int age;				//年龄 
	float wages;			//工资 
	
}Employee;



//全局的Employee结构体数组，EMPLOYEES个元素 
Employee *employee;	

//全局的Employee结构体数组元素指示变量
int employee_i=0;



//主模块操作选择函数 
int main_module_switch(char opt);

//判断是否有相同的工号的函数 
int has_same_num(Employee *p);

//主模块菜单显示函数 
int display_mainmenu();

//子模块操作选择函数 
int sub_module_switch(char opt);

//录入模块函数 
int add_info();

//查询模块函数 
int query_info();

//浏览模块函数 
int explore_info();

//修改模块函数 
int modify_info();

//删除模块函数 
int delete_info();

//统计模块函数 
int count_info();

//帮助模块函数 
int help_info();

//员工信息文件写入函数，n为写入元素的个数 
void write_employee_array(int n);

//员工信息文件读取函数 ，nmax为最多读取元素的个数 
int read_employee_array(int nmax);

//CLI颜色初始化函数 
int init_color();

//CLI清屏函数 
int clear_screen();

//元素置空函数 
int element_set_empty(int i);

//工资统计显示函数 
int wages_count(); 

//以工资大小排序员工信息 
int sort_info_by_wages(Employee *p);

//以工号顺序排序员工信息
int sort_info_by_num(Employee *p); 



#endif
