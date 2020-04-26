/*
all funcs that not geting input from user
*/


#include "code.h"
#include "linkedList.h"

int fileExist(char *filename)
{
	struct stat   buffer;
	return (stat(filename, &buffer) == 0);
}

int containsName(FrameNode* head, char *name)
{
	int flag = 0;
	FrameNode* current = head;  // Initialize current 
	while (current != NULL && !flag)
	{
		if (strcmp(current->frame->name, name) == 0)//if eqwal
		{
			flag = 1;
		}
		current = current->next;
	}
	return flag;
}

int addNodeBottom(FrameNode *head, char *path, char *name, int duration)
{
	FrameNode *current = head;
	FrameNode *newNode = (FrameNode *)malloc(sizeof(FrameNode));

	newNode->frame->duration = duration;
	newNode->frame->path = path;
	newNode->frame->name = name;
	newNode->next = NULL;

	while (current->next) 
	{
		current = current->next;
	}
	current->next = newNode;
	return 0;
}

/* Given a reference (pointer to pointer) to the head of a list
   and a key, deletes the first occurrence of key in linked list */
int deleteFrame(FrameNode *head_ref, char *name)
{
	// Store head node 
	FrameNode* temp = head_ref->next, *prev = head_ref;

	int flag = 0;
	// If head node itself holds the key to be deleted 
	if (temp != NULL && strcmp(temp->frame->name, name) == 0)
	{
		head_ref = temp->next;   // Changed head 
		free(temp);               // free old head 
		flag = 1;
	}

	if (!flag)
	{
		// Search for the key to be deleted, keep track of the 
		// previous node as we need to change 'prev->next' 
		while (temp != NULL && (strcmp(temp->frame->name, name) != 0))
		{
			prev = temp;
			temp = temp->next;
		}

		// If key was not present in linked list 
		if (temp != NULL)
		{
			flag = 1;
			// Unlink the node from linked list 
			prev->next = temp->next;

			free(temp);  // Free memory
		} 
	}
	return flag;
}

int swichByIndex(FrameNode *head, char *name, int index)
{
	//check if the index is fine
	int i = 1;
	int flag = 1;

	FrameNode* current = head;
	FrameNode* save = NULL;
	while (current->next != NULL) 
	{
		if (strcmp(current->next->frame->name, name) == 0)//if eqwal
		{
			save = current->next;
			current = current->next->next;
		}
		current = current->next;
		i++;
	}

	if (index > i || index < 1)
	{
		flag = 0;
	}

	
	if (flag)
	{
		i = 1;
		FrameNode* current = head->next;  // Initialize current 
		FrameNode* temp = NULL;
		while (current != NULL)
		{
			if (i == index)
			{
				temp = current->next;
				current->next = save;
				save->next = temp;
			}
			current = current->next;
			i++;
		}
	}
	return flag;
}

int changeTimeByName(FrameNode *head, char *name, int time)
{
	FrameNode* current = head;
	while (current != NULL)
	{
		if (strcmp(current->frame->name, name) == 0)//if eqwal
		{
			current->frame->duration = time;
			return 1;
		}
		current = current->next;
	}
}

int changeAllTime(FrameNode *head, int time)
{
	FrameNode* current = head;
	while (current != NULL)
	{
		current->frame->duration = time;
		current = current->next;
	}
}

