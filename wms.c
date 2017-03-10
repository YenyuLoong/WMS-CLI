#include "wms.h"

/*****************************************************************************
本软件是在GNU GPL V2许可证下授权的自由软件，源代码完全公开，用户可自由获取，使用，修改，分享，重新发布本软件， 
并且根据GPL许可证的内容，用户必须把修改版以及衍生版的软件一同继续在GPL许可证下授权成自由软件，所谓软件自由化。
若要查阅许可证请参见以下链接： 
GPL V2 许可证原文：http://www.gnu.org/licenses/old-licenses/gpl-2.0.html 
GPL V2 许可证中文翻译： http://mprc.pku.edu.cn/~ruankunliang/gpl.html
*****************************************************************************/ 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{ 
	//给结构体指针分配内存空间，用于存放员工信息 
	employee = (Employee *)malloc(EMPLOYEES*sizeof(Employee));
	
	//从文件读取所有员工信息，返回信息元素个数 
	employee_i = read_employee_array(EMPLOYEES);
	
	//初始化CLI颜色 
	init_color();
	
	//显示主菜单界面 
	display_mainmenu();
	
	return 0;
}

//主模块菜单显示函数 
int display_mainmenu()
{
	//清屏 
	clear_screen();
	
	//操作值
	char opt; 
	
	//提示信息 
	printf("*********欢迎进入工资管理系统*********\n");
	printf("请选择您的操作：\n【1】信息录入\t【2】信息查询\n【3】信息浏览\t【4】信息修改\n【5】信息删除\t【6】信息统计\n【7】系统帮助\t【0】退出系统\n"); 
	
	//从键盘获取操作值 
	opt=getch();
	
	//判断并根据操作值进入所指定的功能 
	if(main_module_switch(opt)==1)
	{
		//显示主菜单界面 
		display_mainmenu();
	}
	
	return 0;
}

//主模块操作选择函数 
int main_module_switch(char opt)
{
	//对操作值进行筛选，进入指定的功能模块 
	switch(opt)
	{
		case OPT_EXIT:{
			//退出程序 
			exit(0);
			break;
		}
		case OPT_ADD:{
			//录入模块 
			add_info();
			break;
		}
		case OPT_QUERY:{
			//查询模块 
			query_info();
			break;
		}
		case OPT_EXP:{
			//浏览模块 
			explore_info();
			break;
		}
		case OPT_MODIFY:{
			//修改模块 
			modify_info();
			break;
		}
		case OPT_DEL:{
			//删除模块 
			delete_info();
			break;
		}
		case OPT_COUNT:{
			//统计模块 
			count_info();
			break;
		}
		case OPT_HELP:{
			//帮助模块 
			help_info();
			break;
		}
		default:{
			//操作值非法 
			printf("无效操作！\n");
			
			//按任意键继续 
			system(CMD_PRESSANYKEY);
			
			//返回1，使上层代码可判定操作值为错 
			return 1;
			break;
		} 
	}
	return 0;
}

//子模块操作选择函数
int sub_module_switch(char opt)
{
	//对操作值进行筛选，进入指定的功能模块 
	switch(opt)
	{
		case SUB_EXIT:{
			//退出至主菜单界面 
			display_mainmenu();
			break;
		}
		case SUB_ENTER:{
			//继续进入模块 
			break;
		}
		default:{
			//操作值非法 
			printf("\n无效操作\n");
			
			//按任意键继续 
			system(CMD_PRESSANYKEY);
			
			//返回1，使上层代码可判定操作值为错 
			return 1;
			break;
		}
		
	}
	return 0;
}

//录入模块函数 
int add_info()
{
	//清屏 
	clear_screen();
	
	//结构体指针 
	Employee *p=employee;
	
	//操作值 
	char opt;
	
	//循环变量 
	int i=0;
	
	//显示标题信息 
	printf("*********工资管理系统——信息录入模块*********\n【1】进入  【0】退出\n");
	
	//从键盘获得操作值 
	opt=getch();
	
	 //判定操作值 
	if(sub_module_switch(opt)==1)
	{
		add_info();
	} 
	
	//调整指针指向元素的最后位置 
	for(i=0;i<employee_i;i++)
	{
		p++;
	}
	
	
	//循环判定输入工号的相同性 
	do
	{
		if(has_same_num(p)==1)
		{
			printf("系统中已有相同工号！");
		} 
		printf("\n请输入员工工号：");
		scanf("%d",&p->num);
		
	}while(has_same_num(p)==1);
	
	
	//输入姓名 
	printf("\n请输入员工姓名：");
	scanf("%s",p->name);
	
	
	//循环判定输入性别的正确性 
	do
	{
		if(!_SEX(p->sex))
		{
			printf("无效输入！\n");
		}
		printf("\n请输入员工性别，【0】男 【1】女：");
		scanf("%d",&p->sex);
	}
	while(!_SEX(p->sex));
	
	//输入年龄 
	printf("\n请输入员工年龄：");
	scanf("%d",&p->age);
	
	//输入工资 
	printf("\n请输入员工工资：");
	scanf("%f",&p->wages);
	
	//已录入提示信息 
	printf("\n信息已录入！\n");
	
	//元素指示变量+1，即元素个数+1 
	employee_i++;
	
	//指针向后移动一个单位 
	p++;
	
	//写入文件存储 
	write_employee_array(employee_i);
	
	//按任意键继续 
	system(CMD_PRESSANYKEY);
	
	//递归调用函数自身
	add_info();
	
	return 0;
}

//查询模块函数
int query_info()
{
	//清屏 
	clear_screen();
	
	//结构体指针 
	Employee *p=employee;
	
	//操作值
	char opt;
	
	//循环变量 
	int i=0;
	
	//输入查询工号的变量 
	int input_num;
	
	//显示标题信息 
	printf("*********工资管理系统——信息查询模块*********\n【1】进入  【0】退出\n");
	
	//从键盘获得操作值 
	opt=getch();
	
	//判定操作值 
	if(sub_module_switch(opt)==1)
	{
		query_info();
	}
	
	//输入要查询的工号 
	printf("\n请输入要查询员工的工号：");
	scanf("%d",&input_num);
	
	//显示查询结果 
	printf("查询结果如下：\n"); 
	printf("\n工号\t姓名\t性别\t年龄\t工资(元)\n");
	
	//循环找出与要查询的工号相同的元素，并输出所有的信息 
	for(i=0;i<employee_i;i++)
	{
		if(p[i].num==input_num)
		{
			printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
		}
	}
	
	//按任意键继续 
	system(CMD_PRESSANYKEY);
	
	//递归调用函数自身
	query_info();
	
	return 0;
}

//浏览模块函数 
int explore_info()
{
	//清屏 
	clear_screen();
	
	//结构体指针 
	Employee *p=employee;
	
	//循环变量 
	int i=0;
	
	//操作值 
	char opt;
	
	//显示标题信息 
	printf("*********工资管理系统——信息浏览模块*********\n【1】进入  【0】退出\n");
	
	//从键盘获得操作值 
	opt=getch();
	
	//判定操作值 
	if(sub_module_switch(opt)==1)
	{
		explore_info();
	}
	
	//输出排序方式提示 
	printf("\n按何种方式排序？【1】工资大小 【2】工号 【0】默认\n");
	
	//从键盘获得操作值 
	opt=getch();
	
	printf("浏览全部员工信息：\n"); 
	
	//判定操作值（工资大小，工号，默认）三种排序方式 
	switch(opt)
	{
		case SORT_DEFAULT:{
			
			printf("\n工号\t姓名\t性别\t年龄\t工资(元)\n");
			
			//默认按连续内存空间输出所有元素 
			for(i=0;i<employee_i;i++)
			{
				printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
			}
	
			break;
		}
		case SORT_WAGES:{
			//以工资从高到低排序 
			sort_info_by_wages(p);
			break;
		}
		case SORT_NUM:{
			//以工号由小到大排序 
			sort_info_by_num(p);
			break;
		}
		default:{
			//操作值非法 
			printf("无效输入！\n");
			break;
		}
	}
	
	//按任意键继续 
	system(CMD_PRESSANYKEY);
	
	//递归调用函数自身
	explore_info();
	
	return 0;
}

//修改模块函数 
int modify_info()
{
	//清屏 
	clear_screen();
	
	//结构体指针 
	Employee *p=employee;
	
	//操作值 
	char opt;
	
	//循环变量 
	int i=0;
	
	//输入修改工号的变量 
	int input_num;
	
	//显示标题信息 
	printf("*********工资管理系统——信息修改模块*********\n【1】进入  【0】退出\n");
	
	//从键盘获得操作值 
	opt=getch();
	
	//判定操作值 
	if(sub_module_switch(opt)==1)
	{
		modify_info();
	}
	
	//输入要修改元素的工号 
	printf("\n请输入要进行信息修改的员工工号：");
	scanf("%d",&input_num);
	
	printf("\n工号\t姓名\t性别\t年龄\t工资(元)\n");
	
	//循环找出与要查询的工号相同的元素，并输出所有的信息
	for(i=0;i<employee_i;i++)
	{
		if(p[i].num==input_num)
		{
			
			printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
			do
			{
				//显示选项提示信息 
				printf("\n请选择修改项目：【1】工号【2】姓名【3】性别【4】年龄【5】工资【0】退出\n");
				
				//从键盘获得操作值 
				opt=getch();
				
				//判定操作值（退出，工号，姓名，性别，年龄，工资）六种 
				switch(opt)
				{
					case MODIFY_EXIT:{
						//返回选项 
						modify_info();
						break;
					}
					case MODIFY_NUM:{
						//输入新的工号 
						printf("\n请输入员工工号：");
						scanf("%d",&p[i].num);
						
						//判定工号冲突 
						if(has_same_num(p)==1)
						{
							printf("系统中已有相同工号！");
						}
						
						break;
					}
					case MODIFY_NAME:{
						//输入新的姓名 
						printf("请输入姓名：");
						scanf("%s",p[i].name);
						
						break;
					}
					case MODIFY_SEX:{
						//性别变量 
						int sex;
						
						//输入新的性别 
						printf("\n请输入员工性别，【0】男 【1】女：");
						scanf("%d",&sex);
						
						//判定性别正确性，并修改之 
						if(!_SEX(sex))
						{
							printf("无效输入！\n");
						}
						else
						{
							p[i].sex=sex;
						}
						
						break;
					}
					case MODIFY_AGE:{
						//输入新的年龄 
						printf("请输入员工年龄：");
						scanf("%d",&p[i].age);
						
						break;
					}
					case MODIFY_WAGES:{
						//输入新的工资 
						printf("请输入员工工资：");
						scanf("%f",&p[i].wages);
						
						break;
					}
					default:{
						//操作值非法 
						printf("无效输入！\n");
						break;
					}
				}
				
				//写入文件存储 
				write_employee_array(employee_i);
				
				//输出修改后的元素信息 
				printf("\n工号\t姓名\t性别\t年龄\t工资(元)\n");
				printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
				
			}//永真循环 
			while(1); 
		}
	}
	
	//按任意键继续 
	system(CMD_PRESSANYKEY);
	
	//递归调用函数自身 
	modify_info();
	
	return 0;
}

//删除模块函数 
int delete_info()
{
	//清屏 
	clear_screen();
	
	//结构体指针 
	Employee *p=employee;
	
	//操作值 
	char opt;
	
	//循环变量 
	int i=0;
	
	//输入的员工工号 
	int input_num;
	
	
	//显示标题信息 
	printf("*********工资管理系统——信息删除模块*********\n【1】进入  【0】退出\n");
	
	//从键盘获得操作值 
	opt=getch();
	
	//判定操作值 
	if(sub_module_switch(opt)==1)
	{
		delete_info();
	}
	
	//输入要删除的员工信息的工号 
	printf("\n请输入要删除的员工工号：");
	scanf("%d",&input_num);
	
	printf("\n工号\t姓名\t性别\t年龄\t工资(元)\n");
	
	//循环查找指定工号的元素 
	for(i=0;i<employee_i;i++)
	{
		if(p[i].num==input_num)
		{
			int j;
			printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
			printf("确定删除这条员工信息吗？【1】确定 【0】取消\n");
			
			//从键盘获得操作值 
			opt=getch();
			
			//判定操作值（确认删除） 
			if(opt=='1')
			{
				//循环变量 
				int c;
				
				//循环将下一元素的值一一赋值给当前元素 
				for(j=i;j<employee_i;j++)
				{
					p[j].num=p[j+1].num;
					for(c=0;c<NAMESIZE;c++)
					{
						p[j].name[c]=p[j+1].name[c];
					}
					p[j].sex=p[j+1].sex;
					p[j].age=p[j+1].age;
					p[j].wages=p[j+1].wages;
				}
				
				//将最后一位元素置空 
				element_set_empty(employee_i);
				
				//指示变量-1，即元素个数-1 
				employee_i--;
				
				//写入文件存储 
				write_employee_array(employee_i);
				
				//显示成功信息 
				printf("\n该条员工信息已成功删除\n");
				
			}
			else if(opt=='0')
			{
				//退出 
				break;
			}
			else
			{
				//操作值非法 
				printf("无效操作！\n");
				
				break;
			}	
		}
		
	}
	
	//按任意键继续 
	system(CMD_PRESSANYKEY);
	
	//递归调用函数自身 
	delete_info();
	
	return 0;
}

//统计模块函数 
int count_info()
{
	//清屏 
	clear_screen();
	
	//操作值 
	char opt;
	
	//显示标题信息 
	printf("*********工资管理系统——信息统计模块*********\n【1】进入  【0】退出\n");
	
	//从键盘获得操作值 
	opt=getch();
	
	//判定操作值 
	if(sub_module_switch(opt)==1)
	{
		count_info();
	}
	
	//调用信息统计函数，按工资分布统计 
	wages_count();
	
	//递归调用函数自身 
	count_info();
	
	return 0;
}

//帮助模块函数 
int help_info()
{
	//清屏 
	clear_screen();
	
	//显示一大堆帮助信息 
	printf("*********工资管理系统——系统帮助*********\n\n");
	printf(HELPINFO);
	
	//按任意键继续 
	system(CMD_PRESSANYKEY);
	
	//递归调用函数
	display_mainmenu();
	
	return 0;
}

//员工信息文件写入函数，向文件写入 n 条员工信息 
void write_employee_array(int n)
{
	//文件句柄 
    FILE *fd; 
    
	//循环变量 
	int i;
    
    //结构体指针 
    Employee *p=employee; 
    
    //小于或等于0条则返回 
    if(n<=0)
        return;
    
    //打开DATAFILE宏指定的数据文件，初始化句柄 
    if((fd=fopen(DATAFILE,"w"))==NULL)
	{
		//打开失败，程序终止 
        perror("fopen");
        printf("\n数据文件%s丢失！程序已终止\n",DATAFILE);
        system(CMD_PRESSANYKEY);
        exit(1);
    }
    
    //循环写入每个元素到数据文件中 
    for (i=0;i<n;i++)
	{
        fprintf(fd,"%d %s %d %d %f\n", p[i].num, p[i].name, p[i].sex, p[i].age, p[i].wages);
    }
    
    //关闭文件句柄 
    fclose(fd);
}

//员工信息文件读取函数，最多从文件中读取 nmax 条员工信息，函数返回实际读取的记录的条数
int read_employee_array(int nmax)
{
	//文件句柄
    FILE *fd;  
    
    //循环变量 
    int i=0;
    
    //结构体指针 
   	Employee *p=employee;
   	
   	//打开DATAFILE宏指定的数据文件，初始化句柄 
    if((fd=fopen(DATAFILE,"r"))==NULL)
	{
		//打开失败，程序终止
        perror("fopen");
        printf("\n数据文件%s丢失！程序已终止\n",DATAFILE);
        system(CMD_PRESSANYKEY);
        exit(1);
    }
    
    //循环读取每一个元素到结构体数组中 
    while(fscanf(fd,"%d %s %d %d %f", &p[i].num, p[i].name, &p[i].sex, &p[i].age, &p[i].wages)!=EOF)
	{
		// 已经将表格填满
        if(++i==nmax) break;
    }
    
    //关闭文件句柄 
    fclose(fd);
    
    //返回实际读取的元素个数 
    return i;
}

//CLI颜色初始化函数
int init_color()
{
	//调用DOS颜色命令 
	system(CMD_COLOR);
	
	return 0;
}

//CLI清屏函数 
int clear_screen()
{
	//调用DOS清屏命令 
	system(CMD_CLEARSCREEN);
	
	return 0;
}

//判断是否有相同的工号的函数 
int has_same_num(Employee *p)
{
	//结构体指针 
	Employee *e = employee;
	
	//循环变量 
	int i;
	
	//循环判定元素中是否有工号相同 
	for(i=0;i<employee_i;i++)
	{
		if(e->num==p->num)
		{
			//不包含自身工号 
			if(e!=p)
			{
				return 1;
			}
			
		}
		e++;
	}
	return 0;
}

//元素置空函数
int element_set_empty(int i)
{
	//结构体指针 
	Employee *p=employee;
	
	//循环变量 
	int c;
	
	//元素一一置为'\0'，即空值 
	p[i].num='\0';
	for(c=0;c<NAMESIZE;c++)
	{
		p[i].name[c]='\0';
	}
	p[i].sex='\0';
	p[i].age='\0';
	p[i].wages='\0';
	
	return 0;
}

//工资统计显示函数 
int wages_count()
{
	//结构体指针 
	Employee *p=employee;
	
	//循环变量 
	int i;	
	
	//0-SPLIT1
	printf("\n统计工资在%d ~ %d的员工：\n",SPLIT0,SPLIT1);
	printf("工号\t姓名\t性别\t年龄\t工资(元)\n");
	for(i=0;i<employee_i;i++)
	{
		// 
		if(p[i].wages>=SPLIT0 && p[i].wages<SPLIT1)	 
		{
			printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
			
		}
	}
	
	//SPLIT1-SPLIT2
	printf("\n统计工资在%d ~ %d的员工：\n",SPLIT1,SPLIT2);
	printf("工号\t姓名\t性别\t年龄\t工资(元)\n");
	for(i=0;i<employee_i;i++)
	{
		if(p[i].wages>=SPLIT1 && p[i].wages<SPLIT2)
		{
			printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
			
		}
	}
	
	//SPLIT2-SPLIT3
	printf("\n统计工资在%d ~ %d的员工：\n",SPLIT2,SPLIT3);
	printf("工号\t姓名\t性别\t年龄\t工资(元)\n");
	for(i=0;i<employee_i;i++)
	{
		if(p[i].wages>=SPLIT2 && p[i].wages<SPLIT3)
		{
			printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
			
		}
	}
	
	//SPLIT3-SPLIT4
	printf("\n统计工资在%d ~ %d的员工：\n",SPLIT3,SPLIT4);
	printf("工号\t姓名\t性别\t年龄\t工资(元)\n");
	for(i=0;i<employee_i;i++)
	{
		if(p[i].wages>=SPLIT3 && p[i].wages<SPLIT4)
		{
			printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
			
		}
	}
	
	//SPLIT4-SPLIT5
	printf("\n统计工资在%d ~ %d的员工：\n",SPLIT4,SPLIT5);
	printf("工号\t姓名\t性别\t年龄\t工资(元)\n");
	for(i=0;i<employee_i;i++)
	{
		if(p[i].wages>=SPLIT4 && p[i].wages<SPLIT5)
		{
			printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
			
		}
	}
	
	//超过 SPLIT5
	printf("\n统计工资在%d及以上的员工：\n",SPLIT5);
	printf("工号\t姓名\t性别\t年龄\t工资(元)\n");
	for(i=0;i<employee_i;i++)
	{
		if(p[i].wages>=SPLIT5)
		{
			printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
			
		}
	}
	
	//按任意键继续 
	system(CMD_PRESSANYKEY);
	
	return 0;
}

//以工资大小排序员工信息 
int sort_info_by_wages(Employee *p)
{
	//循环变量 
	int i; 
	int j;
	
	//最大值，用于比较（由大到小） 
	float max=0;
	
	//给e指针分配内存空间 
	Employee *e = (Employee *)malloc(EMPLOYEES*sizeof(Employee));
	
	//复制p指针所指的内存区域到e指针的内存区域，创建新对象，拷贝所有员工信息 
	memcpy(e,p,EMPLOYEES*sizeof(Employee));
	
	//比较-输出循环 
	for(i=0;i<employee_i;i++)
	{
		for(j=0;j<employee_i;j++)
		{
			//生成最大值 
			if(e[j].wages>=max)
			{
				max=e[j].wages;
			}
		}
		
		for(j=0;j<employee_i;j++)
		{
			//输出最大值 
			if(e[j].wages==max)
			{
				printf("%d\t%s\t%s\t%d\t%.2f\n", e[j].num, e[j].name, _SEX_CONV(e[j].sex), e[j].age, e[j].wages);
				
				//笨方法限定上次的最大值 
				e[j].wages=-1;
				max=0;
			}
		}
	}
	
	//释放p指针
	free(e);
	
	return 0;
	
}

//以工号顺序排序员工信息
int sort_info_by_num(Employee *p)
{
	//循环变量 
	int i;
	int j;
	
	//最小值，用于比较（由小到大） 
	int min=2147483647;
	
	//给e指针分配内存空间 
	Employee *e = (Employee *)malloc(EMPLOYEES*sizeof(Employee));
	//复制p指针所指的内存区域到e指针的内存区域，创建新对象，拷贝所有员工信息 
	memcpy(e,p,EMPLOYEES*sizeof(Employee));
	
	//比较-输出循环 
	for(i=0;i<employee_i;i++)
	{
		for(j=0;j<employee_i;j++)
		{
			//生成最小值 
			if(e[j].num<=min)
			{
				min=e[j].num;
			}
		}
		
		for(j=0;j<employee_i;j++)
		{
			//输出最小值 
			if(e[j].num==min)
			{
				printf("%d\t%s\t%s\t%d\t%.2f\n", e[j].num, e[j].name, _SEX_CONV(e[j].sex), e[j].age, e[j].wages);
				
				//笨方法限定上次的最小值 
				e[j].num=2147483647;
				min=2147483646;
			}
		}
	}
	
	//释放p指针 
	free(e);
	
	return 0;
}

