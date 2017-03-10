#include "wms.h"

/*****************************************************************************
���������GNU GPL V2���֤����Ȩ�����������Դ������ȫ�������û������ɻ�ȡ��ʹ�ã��޸ģ��������·���������� 
���Ҹ���GPL���֤�����ݣ��û�������޸İ��Լ�����������һͬ������GPL���֤����Ȩ�������������ν������ɻ���
��Ҫ�������֤��μ��������ӣ� 
GPL V2 ���֤ԭ�ģ�http://www.gnu.org/licenses/old-licenses/gpl-2.0.html 
GPL V2 ���֤���ķ��룺 http://mprc.pku.edu.cn/~ruankunliang/gpl.html
*****************************************************************************/ 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{ 
	//���ṹ��ָ������ڴ�ռ䣬���ڴ��Ա����Ϣ 
	employee = (Employee *)malloc(EMPLOYEES*sizeof(Employee));
	
	//���ļ���ȡ����Ա����Ϣ��������ϢԪ�ظ��� 
	employee_i = read_employee_array(EMPLOYEES);
	
	//��ʼ��CLI��ɫ 
	init_color();
	
	//��ʾ���˵����� 
	display_mainmenu();
	
	return 0;
}

//��ģ��˵���ʾ���� 
int display_mainmenu()
{
	//���� 
	clear_screen();
	
	//����ֵ
	char opt; 
	
	//��ʾ��Ϣ 
	printf("*********��ӭ���빤�ʹ���ϵͳ*********\n");
	printf("��ѡ�����Ĳ�����\n��1����Ϣ¼��\t��2����Ϣ��ѯ\n��3����Ϣ���\t��4����Ϣ�޸�\n��5����Ϣɾ��\t��6����Ϣͳ��\n��7��ϵͳ����\t��0���˳�ϵͳ\n"); 
	
	//�Ӽ��̻�ȡ����ֵ 
	opt=getch();
	
	//�жϲ����ݲ���ֵ������ָ���Ĺ��� 
	if(main_module_switch(opt)==1)
	{
		//��ʾ���˵����� 
		display_mainmenu();
	}
	
	return 0;
}

//��ģ�����ѡ���� 
int main_module_switch(char opt)
{
	//�Բ���ֵ����ɸѡ������ָ���Ĺ���ģ�� 
	switch(opt)
	{
		case OPT_EXIT:{
			//�˳����� 
			exit(0);
			break;
		}
		case OPT_ADD:{
			//¼��ģ�� 
			add_info();
			break;
		}
		case OPT_QUERY:{
			//��ѯģ�� 
			query_info();
			break;
		}
		case OPT_EXP:{
			//���ģ�� 
			explore_info();
			break;
		}
		case OPT_MODIFY:{
			//�޸�ģ�� 
			modify_info();
			break;
		}
		case OPT_DEL:{
			//ɾ��ģ�� 
			delete_info();
			break;
		}
		case OPT_COUNT:{
			//ͳ��ģ�� 
			count_info();
			break;
		}
		case OPT_HELP:{
			//����ģ�� 
			help_info();
			break;
		}
		default:{
			//����ֵ�Ƿ� 
			printf("��Ч������\n");
			
			//����������� 
			system(CMD_PRESSANYKEY);
			
			//����1��ʹ�ϲ������ж�����ֵΪ�� 
			return 1;
			break;
		} 
	}
	return 0;
}

//��ģ�����ѡ����
int sub_module_switch(char opt)
{
	//�Բ���ֵ����ɸѡ������ָ���Ĺ���ģ�� 
	switch(opt)
	{
		case SUB_EXIT:{
			//�˳������˵����� 
			display_mainmenu();
			break;
		}
		case SUB_ENTER:{
			//��������ģ�� 
			break;
		}
		default:{
			//����ֵ�Ƿ� 
			printf("\n��Ч����\n");
			
			//����������� 
			system(CMD_PRESSANYKEY);
			
			//����1��ʹ�ϲ������ж�����ֵΪ�� 
			return 1;
			break;
		}
		
	}
	return 0;
}

//¼��ģ�麯�� 
int add_info()
{
	//���� 
	clear_screen();
	
	//�ṹ��ָ�� 
	Employee *p=employee;
	
	//����ֵ 
	char opt;
	
	//ѭ������ 
	int i=0;
	
	//��ʾ������Ϣ 
	printf("*********���ʹ���ϵͳ������Ϣ¼��ģ��*********\n��1������  ��0���˳�\n");
	
	//�Ӽ��̻�ò���ֵ 
	opt=getch();
	
	 //�ж�����ֵ 
	if(sub_module_switch(opt)==1)
	{
		add_info();
	} 
	
	//����ָ��ָ��Ԫ�ص����λ�� 
	for(i=0;i<employee_i;i++)
	{
		p++;
	}
	
	
	//ѭ���ж����빤�ŵ���ͬ�� 
	do
	{
		if(has_same_num(p)==1)
		{
			printf("ϵͳ��������ͬ���ţ�");
		} 
		printf("\n������Ա�����ţ�");
		scanf("%d",&p->num);
		
	}while(has_same_num(p)==1);
	
	
	//�������� 
	printf("\n������Ա��������");
	scanf("%s",p->name);
	
	
	//ѭ���ж������Ա����ȷ�� 
	do
	{
		if(!_SEX(p->sex))
		{
			printf("��Ч���룡\n");
		}
		printf("\n������Ա���Ա𣬡�0���� ��1��Ů��");
		scanf("%d",&p->sex);
	}
	while(!_SEX(p->sex));
	
	//�������� 
	printf("\n������Ա�����䣺");
	scanf("%d",&p->age);
	
	//���빤�� 
	printf("\n������Ա�����ʣ�");
	scanf("%f",&p->wages);
	
	//��¼����ʾ��Ϣ 
	printf("\n��Ϣ��¼�룡\n");
	
	//Ԫ��ָʾ����+1����Ԫ�ظ���+1 
	employee_i++;
	
	//ָ������ƶ�һ����λ 
	p++;
	
	//д���ļ��洢 
	write_employee_array(employee_i);
	
	//����������� 
	system(CMD_PRESSANYKEY);
	
	//�ݹ���ú�������
	add_info();
	
	return 0;
}

//��ѯģ�麯��
int query_info()
{
	//���� 
	clear_screen();
	
	//�ṹ��ָ�� 
	Employee *p=employee;
	
	//����ֵ
	char opt;
	
	//ѭ������ 
	int i=0;
	
	//�����ѯ���ŵı��� 
	int input_num;
	
	//��ʾ������Ϣ 
	printf("*********���ʹ���ϵͳ������Ϣ��ѯģ��*********\n��1������  ��0���˳�\n");
	
	//�Ӽ��̻�ò���ֵ 
	opt=getch();
	
	//�ж�����ֵ 
	if(sub_module_switch(opt)==1)
	{
		query_info();
	}
	
	//����Ҫ��ѯ�Ĺ��� 
	printf("\n������Ҫ��ѯԱ���Ĺ��ţ�");
	scanf("%d",&input_num);
	
	//��ʾ��ѯ��� 
	printf("��ѯ������£�\n"); 
	printf("\n����\t����\t�Ա�\t����\t����(Ԫ)\n");
	
	//ѭ���ҳ���Ҫ��ѯ�Ĺ�����ͬ��Ԫ�أ���������е���Ϣ 
	for(i=0;i<employee_i;i++)
	{
		if(p[i].num==input_num)
		{
			printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
		}
	}
	
	//����������� 
	system(CMD_PRESSANYKEY);
	
	//�ݹ���ú�������
	query_info();
	
	return 0;
}

//���ģ�麯�� 
int explore_info()
{
	//���� 
	clear_screen();
	
	//�ṹ��ָ�� 
	Employee *p=employee;
	
	//ѭ������ 
	int i=0;
	
	//����ֵ 
	char opt;
	
	//��ʾ������Ϣ 
	printf("*********���ʹ���ϵͳ������Ϣ���ģ��*********\n��1������  ��0���˳�\n");
	
	//�Ӽ��̻�ò���ֵ 
	opt=getch();
	
	//�ж�����ֵ 
	if(sub_module_switch(opt)==1)
	{
		explore_info();
	}
	
	//�������ʽ��ʾ 
	printf("\n�����ַ�ʽ���򣿡�1�����ʴ�С ��2������ ��0��Ĭ��\n");
	
	//�Ӽ��̻�ò���ֵ 
	opt=getch();
	
	printf("���ȫ��Ա����Ϣ��\n"); 
	
	//�ж�����ֵ�����ʴ�С�����ţ�Ĭ�ϣ���������ʽ 
	switch(opt)
	{
		case SORT_DEFAULT:{
			
			printf("\n����\t����\t�Ա�\t����\t����(Ԫ)\n");
			
			//Ĭ�ϰ������ڴ�ռ��������Ԫ�� 
			for(i=0;i<employee_i;i++)
			{
				printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
			}
	
			break;
		}
		case SORT_WAGES:{
			//�Թ��ʴӸߵ������� 
			sort_info_by_wages(p);
			break;
		}
		case SORT_NUM:{
			//�Թ�����С�������� 
			sort_info_by_num(p);
			break;
		}
		default:{
			//����ֵ�Ƿ� 
			printf("��Ч���룡\n");
			break;
		}
	}
	
	//����������� 
	system(CMD_PRESSANYKEY);
	
	//�ݹ���ú�������
	explore_info();
	
	return 0;
}

//�޸�ģ�麯�� 
int modify_info()
{
	//���� 
	clear_screen();
	
	//�ṹ��ָ�� 
	Employee *p=employee;
	
	//����ֵ 
	char opt;
	
	//ѭ������ 
	int i=0;
	
	//�����޸Ĺ��ŵı��� 
	int input_num;
	
	//��ʾ������Ϣ 
	printf("*********���ʹ���ϵͳ������Ϣ�޸�ģ��*********\n��1������  ��0���˳�\n");
	
	//�Ӽ��̻�ò���ֵ 
	opt=getch();
	
	//�ж�����ֵ 
	if(sub_module_switch(opt)==1)
	{
		modify_info();
	}
	
	//����Ҫ�޸�Ԫ�صĹ��� 
	printf("\n������Ҫ������Ϣ�޸ĵ�Ա�����ţ�");
	scanf("%d",&input_num);
	
	printf("\n����\t����\t�Ա�\t����\t����(Ԫ)\n");
	
	//ѭ���ҳ���Ҫ��ѯ�Ĺ�����ͬ��Ԫ�أ���������е���Ϣ
	for(i=0;i<employee_i;i++)
	{
		if(p[i].num==input_num)
		{
			
			printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
			do
			{
				//��ʾѡ����ʾ��Ϣ 
				printf("\n��ѡ���޸���Ŀ����1�����š�2��������3���Ա�4�����䡾5�����ʡ�0���˳�\n");
				
				//�Ӽ��̻�ò���ֵ 
				opt=getch();
				
				//�ж�����ֵ���˳������ţ��������Ա����䣬���ʣ����� 
				switch(opt)
				{
					case MODIFY_EXIT:{
						//����ѡ�� 
						modify_info();
						break;
					}
					case MODIFY_NUM:{
						//�����µĹ��� 
						printf("\n������Ա�����ţ�");
						scanf("%d",&p[i].num);
						
						//�ж����ų�ͻ 
						if(has_same_num(p)==1)
						{
							printf("ϵͳ��������ͬ���ţ�");
						}
						
						break;
					}
					case MODIFY_NAME:{
						//�����µ����� 
						printf("������������");
						scanf("%s",p[i].name);
						
						break;
					}
					case MODIFY_SEX:{
						//�Ա���� 
						int sex;
						
						//�����µ��Ա� 
						printf("\n������Ա���Ա𣬡�0���� ��1��Ů��");
						scanf("%d",&sex);
						
						//�ж��Ա���ȷ�ԣ����޸�֮ 
						if(!_SEX(sex))
						{
							printf("��Ч���룡\n");
						}
						else
						{
							p[i].sex=sex;
						}
						
						break;
					}
					case MODIFY_AGE:{
						//�����µ����� 
						printf("������Ա�����䣺");
						scanf("%d",&p[i].age);
						
						break;
					}
					case MODIFY_WAGES:{
						//�����µĹ��� 
						printf("������Ա�����ʣ�");
						scanf("%f",&p[i].wages);
						
						break;
					}
					default:{
						//����ֵ�Ƿ� 
						printf("��Ч���룡\n");
						break;
					}
				}
				
				//д���ļ��洢 
				write_employee_array(employee_i);
				
				//����޸ĺ��Ԫ����Ϣ 
				printf("\n����\t����\t�Ա�\t����\t����(Ԫ)\n");
				printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
				
			}//����ѭ�� 
			while(1); 
		}
	}
	
	//����������� 
	system(CMD_PRESSANYKEY);
	
	//�ݹ���ú������� 
	modify_info();
	
	return 0;
}

//ɾ��ģ�麯�� 
int delete_info()
{
	//���� 
	clear_screen();
	
	//�ṹ��ָ�� 
	Employee *p=employee;
	
	//����ֵ 
	char opt;
	
	//ѭ������ 
	int i=0;
	
	//�����Ա������ 
	int input_num;
	
	
	//��ʾ������Ϣ 
	printf("*********���ʹ���ϵͳ������Ϣɾ��ģ��*********\n��1������  ��0���˳�\n");
	
	//�Ӽ��̻�ò���ֵ 
	opt=getch();
	
	//�ж�����ֵ 
	if(sub_module_switch(opt)==1)
	{
		delete_info();
	}
	
	//����Ҫɾ����Ա����Ϣ�Ĺ��� 
	printf("\n������Ҫɾ����Ա�����ţ�");
	scanf("%d",&input_num);
	
	printf("\n����\t����\t�Ա�\t����\t����(Ԫ)\n");
	
	//ѭ������ָ�����ŵ�Ԫ�� 
	for(i=0;i<employee_i;i++)
	{
		if(p[i].num==input_num)
		{
			int j;
			printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
			printf("ȷ��ɾ������Ա����Ϣ�𣿡�1��ȷ�� ��0��ȡ��\n");
			
			//�Ӽ��̻�ò���ֵ 
			opt=getch();
			
			//�ж�����ֵ��ȷ��ɾ���� 
			if(opt=='1')
			{
				//ѭ������ 
				int c;
				
				//ѭ������һԪ�ص�ֵһһ��ֵ����ǰԪ�� 
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
				
				//�����һλԪ���ÿ� 
				element_set_empty(employee_i);
				
				//ָʾ����-1����Ԫ�ظ���-1 
				employee_i--;
				
				//д���ļ��洢 
				write_employee_array(employee_i);
				
				//��ʾ�ɹ���Ϣ 
				printf("\n����Ա����Ϣ�ѳɹ�ɾ��\n");
				
			}
			else if(opt=='0')
			{
				//�˳� 
				break;
			}
			else
			{
				//����ֵ�Ƿ� 
				printf("��Ч������\n");
				
				break;
			}	
		}
		
	}
	
	//����������� 
	system(CMD_PRESSANYKEY);
	
	//�ݹ���ú������� 
	delete_info();
	
	return 0;
}

//ͳ��ģ�麯�� 
int count_info()
{
	//���� 
	clear_screen();
	
	//����ֵ 
	char opt;
	
	//��ʾ������Ϣ 
	printf("*********���ʹ���ϵͳ������Ϣͳ��ģ��*********\n��1������  ��0���˳�\n");
	
	//�Ӽ��̻�ò���ֵ 
	opt=getch();
	
	//�ж�����ֵ 
	if(sub_module_switch(opt)==1)
	{
		count_info();
	}
	
	//������Ϣͳ�ƺ����������ʷֲ�ͳ�� 
	wages_count();
	
	//�ݹ���ú������� 
	count_info();
	
	return 0;
}

//����ģ�麯�� 
int help_info()
{
	//���� 
	clear_screen();
	
	//��ʾһ��Ѱ�����Ϣ 
	printf("*********���ʹ���ϵͳ����ϵͳ����*********\n\n");
	printf(HELPINFO);
	
	//����������� 
	system(CMD_PRESSANYKEY);
	
	//�ݹ���ú���
	display_mainmenu();
	
	return 0;
}

//Ա����Ϣ�ļ�д�뺯�������ļ�д�� n ��Ա����Ϣ 
void write_employee_array(int n)
{
	//�ļ���� 
    FILE *fd; 
    
	//ѭ������ 
	int i;
    
    //�ṹ��ָ�� 
    Employee *p=employee; 
    
    //С�ڻ����0���򷵻� 
    if(n<=0)
        return;
    
    //��DATAFILE��ָ���������ļ�����ʼ����� 
    if((fd=fopen(DATAFILE,"w"))==NULL)
	{
		//��ʧ�ܣ�������ֹ 
        perror("fopen");
        printf("\n�����ļ�%s��ʧ����������ֹ\n",DATAFILE);
        system(CMD_PRESSANYKEY);
        exit(1);
    }
    
    //ѭ��д��ÿ��Ԫ�ص������ļ��� 
    for (i=0;i<n;i++)
	{
        fprintf(fd,"%d %s %d %d %f\n", p[i].num, p[i].name, p[i].sex, p[i].age, p[i].wages);
    }
    
    //�ر��ļ���� 
    fclose(fd);
}

//Ա����Ϣ�ļ���ȡ�����������ļ��ж�ȡ nmax ��Ա����Ϣ����������ʵ�ʶ�ȡ�ļ�¼������
int read_employee_array(int nmax)
{
	//�ļ����
    FILE *fd;  
    
    //ѭ������ 
    int i=0;
    
    //�ṹ��ָ�� 
   	Employee *p=employee;
   	
   	//��DATAFILE��ָ���������ļ�����ʼ����� 
    if((fd=fopen(DATAFILE,"r"))==NULL)
	{
		//��ʧ�ܣ�������ֹ
        perror("fopen");
        printf("\n�����ļ�%s��ʧ����������ֹ\n",DATAFILE);
        system(CMD_PRESSANYKEY);
        exit(1);
    }
    
    //ѭ����ȡÿһ��Ԫ�ص��ṹ�������� 
    while(fscanf(fd,"%d %s %d %d %f", &p[i].num, p[i].name, &p[i].sex, &p[i].age, &p[i].wages)!=EOF)
	{
		// �Ѿ����������
        if(++i==nmax) break;
    }
    
    //�ر��ļ���� 
    fclose(fd);
    
    //����ʵ�ʶ�ȡ��Ԫ�ظ��� 
    return i;
}

//CLI��ɫ��ʼ������
int init_color()
{
	//����DOS��ɫ���� 
	system(CMD_COLOR);
	
	return 0;
}

//CLI�������� 
int clear_screen()
{
	//����DOS�������� 
	system(CMD_CLEARSCREEN);
	
	return 0;
}

//�ж��Ƿ�����ͬ�Ĺ��ŵĺ��� 
int has_same_num(Employee *p)
{
	//�ṹ��ָ�� 
	Employee *e = employee;
	
	//ѭ������ 
	int i;
	
	//ѭ���ж�Ԫ�����Ƿ��й�����ͬ 
	for(i=0;i<employee_i;i++)
	{
		if(e->num==p->num)
		{
			//������������ 
			if(e!=p)
			{
				return 1;
			}
			
		}
		e++;
	}
	return 0;
}

//Ԫ���ÿպ���
int element_set_empty(int i)
{
	//�ṹ��ָ�� 
	Employee *p=employee;
	
	//ѭ������ 
	int c;
	
	//Ԫ��һһ��Ϊ'\0'������ֵ 
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

//����ͳ����ʾ���� 
int wages_count()
{
	//�ṹ��ָ�� 
	Employee *p=employee;
	
	//ѭ������ 
	int i;	
	
	//0-SPLIT1
	printf("\nͳ�ƹ�����%d ~ %d��Ա����\n",SPLIT0,SPLIT1);
	printf("����\t����\t�Ա�\t����\t����(Ԫ)\n");
	for(i=0;i<employee_i;i++)
	{
		// 
		if(p[i].wages>=SPLIT0 && p[i].wages<SPLIT1)	 
		{
			printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
			
		}
	}
	
	//SPLIT1-SPLIT2
	printf("\nͳ�ƹ�����%d ~ %d��Ա����\n",SPLIT1,SPLIT2);
	printf("����\t����\t�Ա�\t����\t����(Ԫ)\n");
	for(i=0;i<employee_i;i++)
	{
		if(p[i].wages>=SPLIT1 && p[i].wages<SPLIT2)
		{
			printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
			
		}
	}
	
	//SPLIT2-SPLIT3
	printf("\nͳ�ƹ�����%d ~ %d��Ա����\n",SPLIT2,SPLIT3);
	printf("����\t����\t�Ա�\t����\t����(Ԫ)\n");
	for(i=0;i<employee_i;i++)
	{
		if(p[i].wages>=SPLIT2 && p[i].wages<SPLIT3)
		{
			printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
			
		}
	}
	
	//SPLIT3-SPLIT4
	printf("\nͳ�ƹ�����%d ~ %d��Ա����\n",SPLIT3,SPLIT4);
	printf("����\t����\t�Ա�\t����\t����(Ԫ)\n");
	for(i=0;i<employee_i;i++)
	{
		if(p[i].wages>=SPLIT3 && p[i].wages<SPLIT4)
		{
			printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
			
		}
	}
	
	//SPLIT4-SPLIT5
	printf("\nͳ�ƹ�����%d ~ %d��Ա����\n",SPLIT4,SPLIT5);
	printf("����\t����\t�Ա�\t����\t����(Ԫ)\n");
	for(i=0;i<employee_i;i++)
	{
		if(p[i].wages>=SPLIT4 && p[i].wages<SPLIT5)
		{
			printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
			
		}
	}
	
	//���� SPLIT5
	printf("\nͳ�ƹ�����%d�����ϵ�Ա����\n",SPLIT5);
	printf("����\t����\t�Ա�\t����\t����(Ԫ)\n");
	for(i=0;i<employee_i;i++)
	{
		if(p[i].wages>=SPLIT5)
		{
			printf("%d\t%s\t%s\t%d\t%.2f\n", p[i].num, p[i].name, _SEX_CONV(p[i].sex), p[i].age, p[i].wages);
			
		}
	}
	
	//����������� 
	system(CMD_PRESSANYKEY);
	
	return 0;
}

//�Թ��ʴ�С����Ա����Ϣ 
int sort_info_by_wages(Employee *p)
{
	//ѭ������ 
	int i; 
	int j;
	
	//���ֵ�����ڱȽϣ��ɴ�С�� 
	float max=0;
	
	//��eָ������ڴ�ռ� 
	Employee *e = (Employee *)malloc(EMPLOYEES*sizeof(Employee));
	
	//����pָ����ָ���ڴ�����eָ����ڴ����򣬴����¶��󣬿�������Ա����Ϣ 
	memcpy(e,p,EMPLOYEES*sizeof(Employee));
	
	//�Ƚ�-���ѭ�� 
	for(i=0;i<employee_i;i++)
	{
		for(j=0;j<employee_i;j++)
		{
			//�������ֵ 
			if(e[j].wages>=max)
			{
				max=e[j].wages;
			}
		}
		
		for(j=0;j<employee_i;j++)
		{
			//������ֵ 
			if(e[j].wages==max)
			{
				printf("%d\t%s\t%s\t%d\t%.2f\n", e[j].num, e[j].name, _SEX_CONV(e[j].sex), e[j].age, e[j].wages);
				
				//�������޶��ϴε����ֵ 
				e[j].wages=-1;
				max=0;
			}
		}
	}
	
	//�ͷ�pָ��
	free(e);
	
	return 0;
	
}

//�Թ���˳������Ա����Ϣ
int sort_info_by_num(Employee *p)
{
	//ѭ������ 
	int i;
	int j;
	
	//��Сֵ�����ڱȽϣ���С���� 
	int min=2147483647;
	
	//��eָ������ڴ�ռ� 
	Employee *e = (Employee *)malloc(EMPLOYEES*sizeof(Employee));
	//����pָ����ָ���ڴ�����eָ����ڴ����򣬴����¶��󣬿�������Ա����Ϣ 
	memcpy(e,p,EMPLOYEES*sizeof(Employee));
	
	//�Ƚ�-���ѭ�� 
	for(i=0;i<employee_i;i++)
	{
		for(j=0;j<employee_i;j++)
		{
			//������Сֵ 
			if(e[j].num<=min)
			{
				min=e[j].num;
			}
		}
		
		for(j=0;j<employee_i;j++)
		{
			//�����Сֵ 
			if(e[j].num==min)
			{
				printf("%d\t%s\t%s\t%d\t%.2f\n", e[j].num, e[j].name, _SEX_CONV(e[j].sex), e[j].age, e[j].wages);
				
				//�������޶��ϴε���Сֵ 
				e[j].num=2147483647;
				min=2147483646;
			}
		}
	}
	
	//�ͷ�pָ�� 
	free(e);
	
	return 0;
}

