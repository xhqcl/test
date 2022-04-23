#include<stdio.h>
#include<string.h> 
struct Student
{

	int stuId;
	int stuAge;
	char stuName[100];
	struct Student* next;
};
void printStudent(struct Student* curp)
{
	printf("ѧ��: %d, ���� : %d , ����:%s\n", curp->stuId, curp->stuAge, curp->stuName);
}
void printLinkedList(struct Student* headp)
{
	while (headp != NULL)
	{
		printStudent(headp);
		headp = headp->next;
	}
}
int main()
{

	struct Student S1, S2, S3;
	S1.stuId = 2000;
	S1.stuAge = 20;
	strcpy(S1.stuName, "��׿");

	S2.stuId = 2001;
	S2.stuAge = 30;
	strcpy(S2.stuName, "����");

	S3.stuId = 2002;
	S3.stuAge = 12;
	strcpy(S3.stuName, "����");

	struct Student S4 = { 2004,19,"�ŷ�" };

	printf("S1->S2->S3->S4->NULL\n");

	S1.next = &S2;
	S2.next = &S3;
	S3.next = &S4;
	S4.next = NULL;


	struct Student* curp = &S1;
	printLinkedList(curp);
	printf("������Ҫ���ѧ��ѧ��:");
	int id;
	scanf("%d", &id);
	curp = &S1;
	int flag = 0;
	while (curp != NULL)
	{

		if (curp->stuId == id)
		{
			printStudent(curp);
			flag = 1;
			break;

		}
		else
		{
			curp = curp->next;
		}
	}
	if (flag == 0)
	{

		printf("�Ҳ���\n");
	}
	printf("��������ɾ��S2");
	S1.next = &S3;
	S2.next = NULL;

	curp = &S1;
	printLinkedList(curp);
	return 0;
}
