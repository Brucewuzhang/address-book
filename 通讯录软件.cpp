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
	printf("�����Ϊɵ�����������ʾ�������ɣ�\n����������أ�\n");
	getchar();
	system("cls");
	tongxunlu1();
}
void printall(){
	FILE *fp;
	man t;
	int i=0;
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("���ļ�ʧ�ܣ�\n");
		exit(0);
	}
	else{
		while(fread(&t,sizeof(man),1,fp)==1){
			i++;
			printf("%s,%s,%s,%s,%s,%s,%s,%s,%s\n",t.name,t.sex,t.corname,t.home,t.phone,t.mobile,t.workphone,t.email,t.address);
			if(i%20==0){
				printf("�����������\n");
				getchar();
				system("cls");
			}
		}
	}
	fclose(fp);
	printf("���س���������һ����\n");
	getchar();
	system("cls");
	tongxunlu1();
}
int add1(man *j){
	char ch;
		printf("��ѡ����ӵ���Ŀ,���س�������\n");
		printf("1.����\n2.�Ա�\n3.������λ\n4.סլ\n5.�绰\n6.�ƶ��绰\n7.�칫�绰\n8.E-mail\n9.��ַ\n0.������һ��\n");
		scanf("%c",&ch);
		getchar();
		system("cls");
		switch(ch){
		case '1':printf("����������(24���ַ�����):\n");gets(j->name);a=1;system("cls");return add1(j);
		case '2':printf("�������Ա�(less than8���ַ�):\n");gets(j->sex);a=1;system("cls");return add1(j);
		case '3':printf("�����빤����λ(less than24���ַ�):\n");gets(j->corname);a=1;system("cls");return add1(j);
		case '4':printf("������סլ(less than 24characters):\n");gets(j->home);a=1;system("cls");return add1(j);
		case '5':printf("������绰(less than 8 characters):\n");gets(j->phone);a=1;system("cls");return add1(j);
		case '6':printf("�������ƶ��绰(less than 11 characters):\n");gets(j->mobile);a=1;system("cls");return add1(j);
		case '7':printf("������칫�绰(less than 8 characters):\n");gets(j->workphone);a=1;system("cls");return add1(j);
		case '8':printf("������E-mail(less than 24 characters):\n");gets(j->email);a=1;system("cls");return add1(j);
		case '9':printf("�������ַ(less than 24 characters):\n");gets(j->address);a=1;system("cls");return add1(j);
		case '0':if(a==1){
			printf("��������1������������0,���س�����:\n");
			scanf("%c",&ch);
			getchar();
			while(ch!='1'&&ch!='0'){
                   system("cls");
				   printf("�����������������룡\n");
				   printf("��������1������������0,���س�����:\n");
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
		default:printf("�����������������룡\n");return add1(j);
		}
}

void add(){
	FILE *fp;
    int b;
	int i,m;
	char ch='\n';
	man q[101];	//���ն��ı���
	man t={{'\0'},{'\0'},{'\0'},{'\0'},{'\0'},{'\0'},{'\0'},{'\0'},{'\0'}};//��ʼ��
	man *j=&t;
	a=0;

	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL)
	{		printf("���ļ�ʧ��\n");
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
	
	printf("������Ҫ���Ҽ�¼�����������س�������\n");
	scanf("%s",str);
	getchar();
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("���ļ�ʧ�ܣ�\n");
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
			printf("ͨѶ¼���޷��������ļ�¼��\n");
		printf("���س�������һ����\n");
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
	printf("������Ҫ���Ҽ�¼�ĵ绰�����س�������\n");
	scanf("%s",str);
	getchar();
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("���ļ�ʧ�ܣ�\n");
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
			printf("ͨѶ¼���޷��������ļ�¼��\n");
		printf("���س�������һ����\n");
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
	printf("������Ҫ���Ҽ�¼���Ա𣬰��س�������\n");
	scanf("%s",str);
	getchar();
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("���ļ�ʧ�ܣ�\n");
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
			printf("ͨѶ¼���޷��������ļ�¼��\n");
		printf("���س�������һ����\n");
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
	printf("������Ҫ���Ҽ�¼�Ĺ�����λ�����س�������\n");
	scanf("%s",str);
	getchar();
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("���ļ�ʧ�ܣ�\n");
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
			printf("ͨѶ¼���޷��������ļ�¼��\n");
		printf("���س�������һ����\n");
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
	printf("������Ҫ���Ҽ�¼��סլ�����س�������\n");
	scanf("%s",str);
	getchar();
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("���ļ�ʧ�ܣ�\n");
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
			printf("ͨѶ¼���޷��������ļ�¼��\n");
		printf("���س�������һ����\n");
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
	printf("������Ҫ���Ҽ�¼���ƶ��绰�����س�������\n");
	scanf("%s",str);
	getchar();
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("���ļ�ʧ�ܣ�\n");
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
			printf("ͨѶ¼���޷��������ļ�¼��\n");
		printf("���س�������һ����\n");
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
	printf("������Ҫ���Ҽ�¼�İ칫�绰�����س�������\n");
	scanf("%s",str);
	getchar();
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("���ļ�ʧ�ܣ�\n");
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
			printf("ͨѶ¼���޷��������ļ�¼��\n");
		printf("���س�������һ����\n");
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
	printf("������Ҫ���Ҽ�¼��email�����س�������\n");
	scanf("%s",str);
	getchar();
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("���ļ�ʧ�ܣ�\n");
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
			printf("ͨѶ¼���޷��������ļ�¼��\n");
		printf("���س�������һ����\n");
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
	printf("������Ҫ���Ҽ�¼��סַ�����س�������\n");
	scanf("%s",str);
	getchar();
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("���ļ�ʧ�ܣ�\n");
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
			printf("ͨѶ¼���޷��������ļ�¼��\n");
		printf("���س�������һ����\n");
		getchar();
		system("cls");
		search();
	}
}

void search(){
	char ch;
	printf("��ѡ��1��3�����س���������\n");
	printf("1.��������ѯ\n2.���绰��ѯ\n3.���Ա��ѯ\n4.��������λ��ѯ\n5.��סլ��ѯ\n6.���ƶ��绰��ѯ\n7.���칫�绰��ѯ\n8.��email��ѯ\n9.��סַ��ѯ\n0.������һ��\n");
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
	default:printf("�����������������룡\n");search();
}
}
void modify1(man *j){
	char ch;
		printf("��ѡ��Ҫ�޸ĵ���Ŀ,���س�������\n");
		printf("1.����\n2.�Ա�\n3.������λ\n4.סլ\n5.�绰\n6.�ƶ��绰\n7.�칫�绰\n8.E-mail\n9.��ַ\n0.�޸����\n");
		scanf("%c",&ch);
		getchar();
		system("cls");
		switch(ch){
		case '1':printf("����������(24���ַ�����):\n");gets(j->name);a=1;system("cls"); modify1(j);break;
		case '2':printf("�������Ա�(less than8���ַ�):\n");gets(j->sex);a=1;system("cls"); modify1(j);break;
		case '3':printf("�����빤����λ(less than24���ַ�):\n");gets(j->corname);a=1;system("cls"); modify1(j);break;
		case '4':printf("������סլ(less than 24characters:\n");gets(j->home);a=1;system("cls"); modify1(j);break;
		case '5':printf("������绰(less than 8 characters):\n");gets(j->phone);a=1;system("cls"); modify1(j);break;
		case '6':printf("�������ƶ��绰(less than 11 characters):\n");gets(j->mobile);a=1;system("cls"); modify1(j);break;
		case '7':printf("������칫�绰(less than 8 characters):\n");gets(j->workphone);a=1;system("cls"); modify1(j);break;
		case '8':printf("������E-mail(less than 24 characters):\n");gets(j->email);a=1;system("cls"); modify1(j);break;
		case '9':printf("�������ַ(less than 24 characters):\n");gets(j->address);a=1;system("cls"); modify1(j);break;
		case '0':printf("�޸���ɣ����س���������һ��\n");getchar();system("cls");break;
		default:printf("�����������������룡\n"); modify1(j);
		}
}
void modify(){
	char str[25];
	FILE *fp;
	int m,i,j=0;
	man k={{'\0'},{'\0'},{'\0'},{'\0'},{'\0'},{'\0'},{'\0'},{'\0'},{'\0'}};
	man q[101];
	printf("��������Ҫ�޸ĵļ�¼������,���س�������\n");
    gets(str);
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("����ʧ�ܣ�\n");
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
			printf("δ�ҵ���Ҫ�޸ĵļ�¼��\n�����������:\n");
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
	printf("������Ҫɾ����¼������,���س���������\n");
	gets(str);
	if((fp=fopen("D:\\tongxunlu.dat","rb"))==NULL){
		printf("����ʧ�ܣ�\n");
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
			printf("δ�ҵ���Ҫɾ���ļ�¼��\n�����������:\n");
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
			printf("��ɾ��������������أ�\n");
			getchar();
			system("cls");
				tongxunlu1();
}
void tongxunlu1(){
	char ch;
	printf("������0��5ѡ��,���س�������\n");
	printf("1.��ʾȫ��\n2.���\n3.��ѯ\n4.�޸�\n5.ɾ��\n0.�˻���һ��\n");
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
	default :printf("����������������������!\n");tongxunlu1();
	}
}
void tongxunlu(){
	char ch;
	printf("����1��3ѡ�񣬰��س�������\n");
	printf("1.ʹ��˵����\n2.ͨѶ¼��Ŀ¼\n3.�˳�\n");
	scanf("%c",&ch);
	getchar();
	system("cls");
	switch(ch){
	case '1':shuomingshu();break;
	case '2':tongxunlu1();break;
	case '3':printf("��л����ʹ�ã��ټ���\n");break;
	default :printf("���������������������룡\n");tongxunlu();
	}
}

void main(){
		printf("��лʹ�����ǵ�ͨѶ¼�����\n");
		tongxunlu();
	}

