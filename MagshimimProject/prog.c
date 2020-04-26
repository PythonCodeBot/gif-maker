/*********************************
* Class: MAGSHIMIM C2			 *
* Week:                			 *
* Name:                          *
* Credits:                       *
**********************************/
#pragma warning(disable : 4996)

#include <stdlib.h>
#include "LinkedList.h"
#include "view.h"
#include "code.h"
#include <string.h>
#include <stdio.h>

#define MAX 60

void switchFrames(FrameNode *list);
void addFrame(FrameNode *list);
int printName(struct FrameNode* head, char *name);
void removeFrame(FrameNode *list);
void changeTime(FrameNode *list);
void changeAllTheTime(FrameNode *list);
int showAllNotes(FrameNode *head);


int main(void)
{
	FrameNode * list = NULL;
	list = (FrameNode *)malloc(sizeof(FrameNode));
	list->next = NULL;
	list->frame = NULL;

	int choose = 0, time = 0;

	while (1)
	{
		printf("0 for exit\n1 for add frame\n2 for remove frame\n3 for swich frames\n4 for change time\n5 for show all frames\n6 for play gif\n");
		printf("enter a number: ");
		scanf("%d", &choose);

		switch (choose)
		{
		case 0:
			printf("bye");
			getchar();
			return 0;
			break;
		case 1:
			addFrame(list->next);
			break;
		case 2:
			removeFrame(list);
			break;
		case 3:
			switchFrames(list);
			break;
		case 4:
			changeTime(list->next);
			break;
		case 5:
			changeAllTheTime(list->next);
			break;
		case 6:
			showAllNotes(list->next);
			break;
		case 7:
			play(list);
			break;
		default:
			break;
		}
	}
}

int printName(struct FrameNode* head, char *name)
{
	int flag = containsName(head, name);
	if (flag)
	{
		printf("the list have this name !, enter a new one!\n");
	}
	return flag;
}

void addFrame(FrameNode *list)
{
	char enterName[MAX] = { 0 };
	char enterPath[MAX] = { 0 };
	int time = 0;

	printf("enter path of the pic: ");
	fgets(enterPath, MAX, stdin);
	strtok(enterPath, "\n");

	if (fileExist(enterPath)) //if file exist
	{
		do
		{
			printf("enter name for the pic: ");
			fgets(enterName, MAX, stdin);
			strtok(enterName, "\n");
		} while (printName(list, enterName));

		printf("enter a time: ");
		scanf("%d", &time);
		addNodeBottom(list, enterPath, enterName, time);
	}
	else
	{
		printf("cant find path!\n");
	}
}

void removeFrame(FrameNode *list)
{
	char enterName[MAX] = { 0 };
	printf("enter name of the frame: ");
	fgets(enterName, MAX, stdin);
	strtok(enterName, "\n");
	if (deleteFrame(list, enterName))
	{
		printf("Succeeded\n");
	}
	else
	{
		printf("dont find!\n");
	}
}

void switchFrames(FrameNode *list)
{
	int flag = 0;

	char enterName[MAX] = { 0 };
	printf("enter name of the frame: ");
	fgets(enterName, MAX, stdin);
	strtok(enterName, "\n");

	if (!containsName(list, enterName))
	{
		printf("cant find name!\n");
		flag = 1;
	}

	if (!flag)
	{
		int index = 0;
		printf("enter index: ");
		scanf("%d", &index);

		if (!swichByIndex(list, enterName, index))
		{
			printf("index is worng...\n");
		}
		else
		{
			printf("Succeeded");
		}
	}
}

void changeTime(FrameNode *list)
{
	int flag = 0;
	int time = 0;
	char enterName[MAX] = { 0 };
	printf("enter name of the frame: ");
	fgets(enterName, MAX, stdin);
	strtok(enterName, "\n");

	if (!containsName(list, enterName))
	{
		printf("cant find name!\n");
		flag = 1;
	}

	printf("enter time: ");
	scanf("%d", &time);
	if (!flag)
	{
		changeTimeByName(list, enterName, time);
	}
}

void changeAllTheTime(FrameNode *list)
{
	int time = 0;
	printf("enter time: ");
	scanf("%d", &time);
	
	
	changeAllTime(list, time);
	
}

int showAllNotes(FrameNode *head)
{
	FrameNode* current = head;
	while (current != NULL)
	{
		printf("time: %d ", current->frame->duration);
		printf("name: %s ", current->frame->name);
		printf("path: %s \n", current->frame->path);
		current = current->next;
	}
}