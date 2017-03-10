#ifndef _WMS_H_
#define _WMS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/******************************************************************
���������GNU GPL V2���֤����Ȩ�����������Դ������ȫ�������û������ɻ�ȡ��ʹ�ã��޸ģ��������·���������� 
���Ҹ���GPL���֤�����ݣ��û�������޸İ��Լ�����������һͬ������GPL���֤����Ȩ�������������ν������ɻ���
��Ҫ�������֤��μ��������ӣ� 
GPL V2 ���֤ԭ�ģ�http://www.gnu.org/licenses/old-licenses/gpl-2.0.html 
GPL V2 ���֤���ķ��룺 http://mprc.pku.edu.cn/~ruankunliang/gpl.html
******************************************************************/ 

//Ա���Ա��޶��궨�庯�� 
#define _SEX(sex)	((sex==0 || sex==1)?1:0)
//Ա���Ա�ֵת�����ַ��궨�庯�� 
#define _SEX_CONV(sex)	(sex==0?"��":"Ů")


#define NAMESIZE 20						//Ա�������ַ���С 
#define EMPLOYEES 500					//Employee�ṹ�������С 
#define DATAFILE "employee.dat"			//��ȡ�����ļ��� 

#define CMD_COLOR "color 0a"			//Windows����ϵͳ�ϵĿ���̨�ڵ�������ɫ���� 
#define CMD_PRESSANYKEY "pause && cls"	//Windows����ϵͳ�ϵĿ���̨��ͣ�Լ��������� ������system()������ 
#define CMD_CLEARSCREEN "cls"			//Windows����ϵͳ�ϵĿ���̨�������� ������system()������ 

//������Ϣ�ַ��� 
#define HELPINFO	"��ϵͳ��һ������Windows����ϵͳ CLI��������ʾ���������������ġ������ҿ�Դ�Ĺ��ʹ���ϵͳ������ʹ�����߽�ͨ������ֱ�ӹ���Ա��������Ϣ��������Ϣȫ�����ļ�����ʽ��������������ʮ�ּ򵥣�����������ݿ⡣��ϵͳ�����Ϸ�Ϊ��������ģ�飺\n\n¼��ģ�飺¼���µ�Ա����Ϣ��ϵͳ\n��ѯģ�飺��ѯϵͳ�е�Ա����Ϣ��Ŀǰ֧��ͨ�����Ų�ѯ��\n���ģ�飺���ϵͳ�����е�Ա����Ϣ��Ŀǰ֧���Թ��ʸߵͺ͹�������\n�޸�ģ�飺�޸�ϵͳ�е�Ա����Ϣ\nɾ��ģ�飺ɾ��ϵͳ�е�Ա����Ϣ��Ŀǰ֧��ʹ�ù��Ŷ�λԱ����Ϣ��\nͳ��ģ�飺ͳ��ϵͳ�е�����Ա����Ϣ��Ŀǰ֧���Թ��ʷֲ�ͳ��Ա����Ϣ��\n"


//�����ٽ�ֵ������ͳ�ƹ��ʷֲ� 
#define SPLIT0	0
#define SPLIT1	1000
#define SPLIT2	2000
#define SPLIT3	3000
#define SPLIT4	5000
#define SPLIT5	10000



//��ģ�����ֵö������
typedef enum
{
	OPT_EXIT = '0',	//�˳� 
	OPT_ADD,	//¼����� 
	OPT_QUERY,	//��ѯ���� 
	OPT_EXP,	//������� 
	OPT_MODIFY,	//�޸Ĳ��� 
	OPT_DEL,	//ɾ������ 
	OPT_COUNT,	//ͳ�Ʋ��� 
	OPT_HELP	//ϵͳ���� 
	
}main_module_opt;
 
//��ģ�����ֵö������ 
typedef enum
{
	SUB_EXIT = '0',
	SUB_ENTER
	
}sub_module_opt;


//�Ա�ö������ 
typedef enum
{
	SEX_MAN = '0',	//���� 
	SEX_WOMAN		//Ů�� 
	
}sex;

//�޸�ѡ��ö������ 
typedef enum
{
	MODIFY_EXIT = '0',
	MODIFY_NUM,
	MODIFY_NAME,
	MODIFY_SEX,
	MODIFY_AGE,
	MODIFY_WAGES
	
}modify_option;

//����ʽö������
typedef enum
{
	SORT_DEFAULT = '0',
	SORT_WAGES,
	SORT_NUM
}sort_option;

//EmployeeԱ���ṹ��
typedef struct Employee
{
	int num;				//���� 
	char name[NAMESIZE];	//���� 
	int sex;				//�Ա� 
	int age;				//���� 
	float wages;			//���� 
	
}Employee;



//ȫ�ֵ�Employee�ṹ�����飬EMPLOYEES��Ԫ�� 
Employee *employee;	

//ȫ�ֵ�Employee�ṹ������Ԫ��ָʾ����
int employee_i=0;



//��ģ�����ѡ���� 
int main_module_switch(char opt);

//�ж��Ƿ�����ͬ�Ĺ��ŵĺ��� 
int has_same_num(Employee *p);

//��ģ��˵���ʾ���� 
int display_mainmenu();

//��ģ�����ѡ���� 
int sub_module_switch(char opt);

//¼��ģ�麯�� 
int add_info();

//��ѯģ�麯�� 
int query_info();

//���ģ�麯�� 
int explore_info();

//�޸�ģ�麯�� 
int modify_info();

//ɾ��ģ�麯�� 
int delete_info();

//ͳ��ģ�麯�� 
int count_info();

//����ģ�麯�� 
int help_info();

//Ա����Ϣ�ļ�д�뺯����nΪд��Ԫ�صĸ��� 
void write_employee_array(int n);

//Ա����Ϣ�ļ���ȡ���� ��nmaxΪ����ȡԪ�صĸ��� 
int read_employee_array(int nmax);

//CLI��ɫ��ʼ������ 
int init_color();

//CLI�������� 
int clear_screen();

//Ԫ���ÿպ��� 
int element_set_empty(int i);

//����ͳ����ʾ���� 
int wages_count(); 

//�Թ��ʴ�С����Ա����Ϣ 
int sort_info_by_wages(Employee *p);

//�Թ���˳������Ա����Ϣ
int sort_info_by_num(Employee *p); 



#endif
