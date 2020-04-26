#pragma once

#include <sys/stat.h>


int fileExist(char *filename);
int containsName(struct FrameNode* head, char *name);
int deleteFrame(struct FrameNode *head_ref, char *name);;
int swichByIndex(struct FrameNode *head, char *name, int index);
int changeTimeByName(struct FrameNode *head, char *name, int time);
int changeAllTime(struct FrameNode *head, int time);


