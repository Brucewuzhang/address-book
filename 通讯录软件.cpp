#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<dos.h>
extern void tongxunlu();
extern void shuomingshu();
extern void printall();
extern void add();
extern void search();
extern void tongxunlu1();
extern void modify();
int a;

typedef struct node{
	char name[25];
	char sex[9];
	char corname[25];
	char home[25];
	char phone[9];
	char mobile[12];
	char workphone[9];
	char email[25];
	char address[25];
}man;
int size(FILE *fp){
	int i;
	man t;
	for(i=0;!feof(fp);i++){
		fread(&t,sizeof(man),1,fp);
	}
	return i-1;
}
void shuomingshu(){
	printf("此软件为傻瓜软件，按提示操作即可！\n按任意键返回！\n");
	getchar();
	system("cls");
	tongxunlu1();
}
void printall(){
	FILE *fp;
	man t;
	int i=0;
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("打开文件失败！\n");
		exit(0);
	}
	else{
		while(fread(&t,sizeof(man),1,fp)==1){
			i++;
			printf("%s,%s,%s,%s,%s,%s,%s,%s,%s\n",t.name,t.sex,t.corname,t.home,t.phone,t.mobile,t.workphone,t.email,t.address);
			if(i%20==0){
				printf("按任意键继续\n");
				getchar();
				system("cls");
			}
		}
	}
	fclose(fp);
	printf("按回车键返回上一级！\n");
	getchar();
	system("cls");
	tongxunlu1();
}
int add1(man *j){
	char ch;
		printf("请选择添加的项目,按回车结束：\n");
		printf("1.姓名\n2.性别\n3.工作单位\n4.住宅\n5.电话\n6.移动电话\n7.办公电话\n8.E-mail\n9.地址\n0.返回上一级\n");
		scanf("%c",&ch);
		getchar();
		system("cls");
		switch(ch){
		case '1':printf("请输入姓名(24个字符以内):\n");gets(j->name);a=1;system("cls");return add1(j);
		case '2':printf("请输入性别(less than8个字符):\n");gets(j->sex);a=1;system("cls");return add1(j);
		case '3':printf("请输入工作单位(less than24个字符):\n");gets(j->corname);a=1;system("cls");return add1(j);
		case '4':printf("请输入住宅(less than 24characters):\n");gets(j->home);a=1;system("cls");return add1(j);
		case '5':printf("请输入电话(less than 8 characters):\n");gets(j->phone);a=1;system("cls");return add1(j);
		case '6':printf("请输入移动电话(less than 11 characters):\n");gets(j->mobile);a=1;system("cls");return add1(j);
		case '7':printf("请输入办公电话(less than 8 characters):\n");gets(j->workphone);a=1;system("cls");return add1(j);
		case '8':printf("请输入E-mail(less than 24 characters):\n");gets(j->email);a=1;system("cls");return add1(j);
		case '9':printf("请输入地址(less than 24 characters):\n");gets(j->address);a=1;system("cls");return add1(j);
		case '0':if(a==1){
			printf("保存输入1，不保存输入0,按回车结束:\n");
			scanf("%c",&ch);
			getchar();
			while(ch!='1'&&ch!='0'){
                   system("cls");
				   printf("输入有误，请重新输入！\n");
				   printf("保存输入1，不保存输入0,按回车结束:\n");
			       scanf("%c",&ch);
			       getchar();
			}
			system("cls");
			if(ch=='1')
				return 1;
			else if(ch=='0')
				return 0;
				  }
			else
             return 0;
		default:printf("输入有误，请重新输入！\n");return add1(j);
		}
}

void add(){
	FILE *fp;
    int b;
	int i,m;
	char ch='\n';
	man q[101];	//接收读的变量
	man t={{'\0'},{'\0'},{'\0'},{'\0'},{'\0'},{'\0'},{'\0'},{'\0'},{'\0'}};//初始化
	man *j=&t;
	a=0;

	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL)
	{		printf("打开文件失败\n");
	exit(0);
	}
	else{
		b=add1(j);
		if(b==0)
			tongxunlu1();
		else{
			m=size(fp);
			rewind(fp);
				fread(&q[1],sizeof(man),m,fp);
				q[0]=t;
				i=m;
                while(strcmp(q[i].name,t.name)<0){
					q[i+1]=q[i];
					i--;
				}
				q[i+1]=t;
				fclose(fp);
				fp=fopen("D:\\tongxunlu.dat","wb");
				for(i=1;i<=m+1;i++){
		            fwrite(&q[i],sizeof(man),1,fp);
				}

				fclose(fp);
				tongxunlu1();
		}
	}
}
void search1(){
	FILE *fp;
	man t;
	int i=0;
	char str[25]="\0";
	
	printf("请输入要查找记录的姓名，按回车结束！\n");
	scanf("%s",str);
	getchar();
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("打开文件失败！\n");
		exit(0);
	}
	else{
		while(fread(&t,sizeof(man),1,fp)==1){
			if(strcmp(str,t.name)==0){
				printf("%s,%s,%s,%s,%s,%s,%s,%s,%s\n",t.name,t.sex,t.corname,t.home,t.phone,t.mobile,t.workphone,t.email,t.address);
				i=1;
			}
		}
		fclose(fp);
		if(i==0)
			printf("通讯录中无符合条件的记录！\n");
		printf("按回车返回上一级！\n");
		getchar();
		system("cls");
		search();
	}
}
void search2(){
	FILE *fp;
	man t;
	int i=0;
	char str[25]="\0";
	printf("请输入要查找记录的电话，按回车结束！\n");
	scanf("%s",str);
	getchar();
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("打开文件失败！\n");
		exit(0);
	}
	else{
		while(fread(&t,sizeof(man),1,fp)==1){
			if(strcmp(str,t.phone)==0){
				printf("%s,%s,%s,%s,%s,%s,%s,%s,%s\n",t.name,t.sex,t.corname,t.home,t.phone,t.mobile,t.workphone,t.email,t.address);
				i=1;
			}
		}
		fclose(fp);
		if(i==0)
			printf("通讯录中无符合条件的记录！\n");
		printf("按回车返回上一级！\n");
		getchar();
		system("cls");
		search();
	}
}
void search3(){
	FILE *fp;
	man t;
	int i=0;
	char str[25]="\0";
	printf("请输入要查找记录的性别，按回车结束！\n");
	scanf("%s",str);
	getchar();
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("打开文件失败！\n");
		exit(0);
	}
	else{
		while(fread(&t,sizeof(man),1,fp)==1){
			if(strcmp(str,t.sex)==0){
				printf("%s,%s,%s,%s,%s,%s,%s,%s,%s\n",t.name,t.sex,t.corname,t.home,t.phone,t.mobile,t.workphone,t.email,t.address);
				i=1;
			}
		}
		fclose(fp);
		if(i==0)
			printf("通讯录中无符合条件的记录！\n");
		printf("按回车返回上一级！\n");
		getchar();
		system("cls");
		search();
	}
}
void search4(){
	FILE *fp;
	man t;
	int i=0;
	char str[25]="\0";
	printf("请输入要查找记录的工作单位，按回车结束！\n");
	scanf("%s",str);
	getchar();
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("打开文件失败！\n");
		exit(0);
	}
	else{
		while(fread(&t,sizeof(man),1,fp)==1){
			if(strcmp(str,t.corname)==0){
				printf("%s,%s,%s,%s,%s,%s,%s,%s,%s\n",t.name,t.sex,t.corname,t.home,t.phone,t.mobile,t.workphone,t.email,t.address);
				i=1;
			}
		}
		fclose(fp);
		if(i==0)
			printf("通讯录中无符合条件的记录！\n");
		printf("按回车返回上一级！\n");
		getchar();
		system("cls");
		search();
	}
}
void search5(){
	FILE *fp;
	man t;
	int i=0;
	char str[25]="\0";
	printf("请输入要查找记录的住宅，按回车结束！\n");
	scanf("%s",str);
	getchar();
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("打开文件失败！\n");
		exit(0);
	}
	else{
		while(fread(&t,sizeof(man),1,fp)==1){
			if(strcmp(str,t.home)==0){
				printf("%s,%s,%s,%s,%s,%s,%s,%s,%s\n",t.name,t.sex,t.corname,t.home,t.phone,t.mobile,t.workphone,t.email,t.address);
				i=1;
			}
		}
		fclose(fp);
		if(i==0)
			printf("通讯录中无符合条件的记录！\n");
		printf("按回车返回上一级！\n");
		getchar();
		system("cls");
		search();
	}
}
void search6(){
	FILE *fp;
	man t;
	int i=0;
	char str[25]="\0";
	printf("请输入要查找记录的移动电话，按回车结束！\n");
	scanf("%s",str);
	getchar();
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("打开文件失败！\n");
		exit(0);
	}
	else{
		while(fread(&t,sizeof(man),1,fp)==1){
			if(strcmp(str,t.mobile)==0){
				printf("%s,%s,%s,%s,%s,%s,%s,%s,%s\n",t.name,t.sex,t.corname,t.home,t.phone,t.mobile,t.workphone,t.email,t.address);
				i=1;
			}
		}
		fclose(fp);
		if(i==0)
			printf("通讯录中无符合条件的记录！\n");
		printf("按回车返回上一级！\n");
		getchar();
		system("cls");
		search();
	}
}
void search7(){
	FILE *fp;
	man t;
	int i=0;
	char str[25]="\0";
	printf("请输入要查找记录的办公电话，按回车结束！\n");
	scanf("%s",str);
	getchar();
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("打开文件失败！\n");
		exit(0);
	}
	else{
		while(fread(&t,sizeof(man),1,fp)==1){
			if(strcmp(str,t.workphone)==0){
				printf("%s,%s,%s,%s,%s,%s,%s,%s,%s\n",t.name,t.sex,t.corname,t.home,t.phone,t.mobile,t.workphone,t.email,t.address);
				i=1;
			}
		}
		fclose(fp);
		if(i==0)
			printf("通讯录中无符合条件的记录！\n");
		printf("按回车返回上一级！\n");
		getchar();
		system("cls");
		search();
	}
}
void search8(){
	FILE *fp;
	man t;
	int i=0;
	char str[25]="\0";
	printf("请输入要查找记录的email，按回车结束！\n");
	scanf("%s",str);
	getchar();
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("打开文件失败！\n");
		exit(0);
	}
	else{
		while(fread(&t,sizeof(man),1,fp)==1){
			if(strcmp(str,t.email)==0){
				printf("%s,%s,%s,%s,%s,%s,%s,%s,%s\n",t.name,t.sex,t.corname,t.home,t.phone,t.mobile,t.workphone,t.email,t.address);
				i=1;
			}
		}
		fclose(fp);
		if(i==0)
			printf("通讯录中无符合条件的记录！\n");
		printf("按回车返回上一级！\n");
		getchar();
		system("cls");
		search();
	}
}
void search9(){
	FILE *fp;
	man t;
	int i=0;
	char str[25]="\0";
	printf("请输入要查找记录的住址，按回车结束！\n");
	scanf("%s",str);
	getchar();
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("打开文件失败！\n");
		exit(0);
	}
	else{
		while(fread(&t,sizeof(man),1,fp)==1){
			if(strcmp(str,t.address)==0){
				printf("%s,%s,%s,%s,%s,%s,%s,%s,%s\n",t.name,t.sex,t.corname,t.home,t.phone,t.mobile,t.workphone,t.email,t.address);
				i=1;
			}
		}
		fclose(fp);
		if(i==0)
			printf("通讯录中无符合条件的记录！\n");
		printf("按回车返回上一级！\n");
		getchar();
		system("cls");
		search();
	}
}

void search(){
	char ch;
	printf("请选择1到3，按回车键结束！\n");
	printf("1.按姓名查询\n2.按电话查询\n3.按性别查询\n4.按工作单位查询\n5.按住宅查询\n6.按移动电话查询\n7.按办公电话查询\n8.按email查询\n9.按住址查询\n0.返回上一级\n");
	scanf("%c",&ch);
	getchar();
	system("cls");
	switch(ch){
	case '1':search1();break;
	case '2':search2();break;
	case '3':search3();break;
	case '4':search4();break;
	case '5':search5();break;
	case '6':search6();break;
	case '7':search7();break;
	case '8':search8();break;
	case '9':search9();break;
	case '0':tongxunlu1();break;
	default:printf("输入有误，请重新输入！\n");search();
}
}
void modify1(man *j){
	char ch;
		printf("请选择要修改的项目,按回车结束：\n");
		printf("1.姓名\n2.性别\n3.工作单位\n4.住宅\n5.电话\n6.移动电话\n7.办公电话\n8.E-mail\n9.地址\n0.修改完成\n");
		scanf("%c",&ch);
		getchar();
		system("cls");
		switch(ch){
		case '1':printf("请输入姓名(24个字符以内):\n");gets(j->name);a=1;system("cls"); modify1(j);break;
		case '2':printf("请输入性别(less than8个字符):\n");gets(j->sex);a=1;system("cls"); modify1(j);break;
		case '3':printf("请输入工作单位(less than24个字符):\n");gets(j->corname);a=1;system("cls"); modify1(j);break;
		case '4':printf("请输入住宅(less than 24characters:\n");gets(j->home);a=1;system("cls"); modify1(j);break;
		case '5':printf("请输入电话(less than 8 characters):\n");gets(j->phone);a=1;system("cls"); modify1(j);break;
		case '6':printf("请输入移动电话(less than 11 characters):\n");gets(j->mobile);a=1;system("cls"); modify1(j);break;
		case '7':printf("请输入办公电话(less than 8 characters):\n");gets(j->workphone);a=1;system("cls"); modify1(j);break;
		case '8':printf("请输入E-mail(less than 24 characters):\n");gets(j->email);a=1;system("cls"); modify1(j);break;
		case '9':printf("请输入地址(less than 24 characters):\n");gets(j->address);a=1;system("cls"); modify1(j);break;
		case '0':printf("修改完成，按回车键返回上一级\n");getchar();system("cls");break;
		default:printf("输入有误，请重新输入！\n"); modify1(j);
		}
}
void modify(){
	char str[25];
	FILE *fp;
	int m,i,j=0;
	man k={{'\0'},{'\0'},{'\0'},{'\0'},{'\0'},{'\0'},{'\0'},{'\0'},{'\0'}};
	man q[101];
	printf("请输入你要修改的记录的姓名,按回车结束：\n");
    gets(str);
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("操作失败！\n");
		exit(0);
	}
	m=size(fp);
	rewind(fp);
	for(i=1;i<=m;i++){
        
	    fread(&q[i],sizeof(man),1,fp);
	}
	for(i=1;i<=m;i++)
		if(strcmp(q[i].name,str)==0){
			j=1;
			break;
		}
		if(j!=1){
			printf("未找到你要修改的记录！\n按任意键返回:\n");
		getchar();
		system("cls");
          tongxunlu1();
		  return ;}
            for(j=i;j<m;j++)
				q[j]=q[j+1];
			fclose(fp);
	fp=fopen("D:\\tongxunlu.dat","wb");
	modify1(&k);
	q[0]=k;
	j=m-1;
	while(strcmp(q[j].name,k.name)<0){
			  q[j+1]=q[j];
		  j--;
	}
	q[j+1]=k;
     fwrite(&q[1],sizeof(man),m,fp);
	 fclose(fp);
	 tongxunlu1();
}
void delete1(){
	char str[25];
	int m,i,j;
	FILE *fp;
	man q[101];
	printf("请输入要删除记录的姓名,按回车键结束！\n");
	gets(str);
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("操作失败！\n");
		exit(0);
	}
	m=size(fp);
	rewind(fp);
	for(i=1;i<=m;i++){
	    fread(&q[i],sizeof(man),1,fp);
	}
	for(i=1;i<=m;i++)
		if(strcmp(q[i].name,str)==0){
			j=1;
			break;
		}
		if(j!=1){
			printf("未找到你要删除的记录！\n按任意键返回:\n");
		getchar();
		system("cls");
          tongxunlu1();
		  return ;}
            for(j=i;j<m;j++)
				q[j]=q[j+1];
			fclose(fp);
			fp=fopen("D:\\tongxunlu.dat","wb");
			fwrite(&q[1],sizeof(man),m-1,fp);
			fclose(fp);
			printf("以删除，按任意键返回！\n");
			getchar();
			system("cls");
				tongxunlu1();
}
void tongxunlu1(){
	char ch;
	printf("请输入0到5选择,按回车键结束\n");
	printf("1.显示全部\n2.添加\n3.查询\n4.修改\n5.删除\n0.退回上一级\n");
	scanf("%c",&ch);
	getchar();
	system("cls");
	switch(ch){
	case '1':printall();break;
	case '2':add();break;
	case '3':search();break;
	case '4':modify();break;
	case '5':delete1();break;
	case '0':tongxunlu();break;
	default :printf("您的输入有误，请重新输入!\n");tongxunlu1();
	}
}
void tongxunlu(){
	char ch;
	printf("输入1到3选择，按回车键结束\n");
	printf("1.使用说明书\n2.通讯录主目录\n3.退出\n");
	scanf("%c",&ch);
	getchar();
	system("cls");
	switch(ch){
	case '1':shuomingshu();break;
	case '2':tongxunlu1();break;
	case '3':printf("感谢您的使用，再见！\n");break;
	default :printf("您的输入有误，请重新输入！\n");tongxunlu();
	}
}

void main(){
		printf("感谢使用我们的通讯录软件！\n");
		tongxunlu();
	}

