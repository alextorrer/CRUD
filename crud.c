#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/*Constants */
const int MAX = 100;
#define TRUE 1
#define FALSE 0

/*Structures*/
struct Date{
    int day;
    int month;
    int year;
};

struct Activity{
    int id;
    char *title;
    char *description;
    char *priority;
    struct Date start;
    struct Date finish;
};

struct List{
    int index;
    struct Node *head;
};

struct Node{
	struct Activity *activity;
	struct Node *next;
};

/*Functions prototypes */
int createNode(struct List *list, struct Activity *act);
int updateActivity(struct List *list, struct Activity *actUp);
int deleteActivity(struct List *list, struct Activity *act);
struct Node* findId(struct List *list, struct Activity *act);
char* toStringDate(struct Date *date);
char* toStringActivity(struct Activity *act);
char* toStringList(struct List *list, struct Activity **auxDate);
void fillData(struct List *list, struct Activity *act);
struct Activity ** dateSort(struct List *list);
int compareTo(struct Activity *date1, struct Activity *date2);
int getDays(struct Activity *act);
void copyArray(struct List *list, struct Activity **auxDate);
void freeNodeByAct(struct List *list, struct Activity *act);

int main() {

	//Reserve memory with malloc
	struct Activity *act1 = (struct Activity*)malloc(sizeof(struct Activity));
	struct Activity *act2 = (struct Activity*)malloc(sizeof(struct Activity));
	struct Activity *act3 = (struct Activity*)malloc(sizeof(struct Activity));
	struct Activity *act4 = (struct Activity*)malloc(sizeof(struct Activity));
	struct Activity *act5 = (struct Activity*)malloc(sizeof(struct Activity));
	struct Activity *act6 = (struct Activity*)malloc(sizeof(struct Activity));
	struct Activity *act7 = (struct Activity*)malloc(sizeof(struct Activity));
	struct Activity *act8 = (struct Activity*)malloc(sizeof(struct Activity));
	struct Activity *act9 = (struct Activity*)malloc(sizeof(struct Activity));
	struct Activity *act10 = (struct Activity*)malloc(sizeof(struct Activity));
	struct Activity *actUp = (struct Activity*)malloc(sizeof(struct Activity));
	//Fill data of to-update activity
    actUp->id = 1001; actUp->title = "Activity Updated"; actUp->description = "Some Description updated"; actUp->priority = "Low";
    actUp->start.day = 10; actUp->start.month = 6; actUp->start.year = 2019;
	actUp->finish.day = 11; actUp->finish.month = 6; actUp->finish.year =2019;

    //Initialize variables
    struct List list;
    list.index = 0;
    list.head = NULL;
  	struct Activity **actDate; //New Node-pointer-array for dateSort

    /*Calling functions */
    fillData(&list, act1);
    createNode(&list, act1);
    fillData(&list, act2);
    createNode(&list, act2);
    fillData(&list, act3);
    createNode(&list, act3);
    fillData(&list, act4);
    createNode(&list, act4);
    fillData(&list, act5);
    createNode(&list, act5);
    fillData(&list, act6);
    createNode(&list, act6);
    fillData(&list, act7);
    createNode(&list, act7);
    fillData(&list, act8);
    createNode(&list, act8);
    fillData(&list, act9);
    createNode(&list, act9);
    fillData(&list, act10);
    createNode(&list, act10);

	actDate = dateSort(&list);
    printf("%s", toStringList(&list, actDate));
    free(actDate);

    updateActivity(&list, actUp);
    actDate = dateSort(&list);
    printf("%s", toStringList(&list, actDate));
    free(actDate);

    deleteActivity(&list, act2);
    actDate = dateSort(&list);
    printf("%s", toStringList(&list, actDate));
    free(actDate);

	freeNodeByAct(&list, act1);
	freeNodeByAct(&list, act2);
	freeNodeByAct(&list, act3);
	freeNodeByAct(&list, act4);
	freeNodeByAct(&list, act5);
	freeNodeByAct(&list, act6);
	freeNodeByAct(&list, act7);
	freeNodeByAct(&list, act8);
	freeNodeByAct(&list, act9);
	freeNodeByAct(&list, act10);
	freeNodeByAct(&list, actUp);
}

/*Save the activity at the end of the linked list */
int createNode(struct List *list, struct Activity *act){
    int flag = FALSE;
    struct Node *newNode;
    struct Node *node;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if((list->index == 0)&&(newNode!= NULL)){ //if the linked list its empty
    	newNode->activity = act;
    	newNode->next = NULL;
    	list->head = newNode;
    	list->index++;
    	flag = TRUE;
	}else if((list->index > 0)&&(newNode!=NULL)){
		for(node = list->head; node!= NULL; node=node->next){
			if(node->next == NULL){
				node->next = newNode;
				break;
			}
		}
		newNode->activity = act;
		newNode->next = NULL;
		list->index++;
		flag = TRUE;
	}
    return flag;
}
/*Update an activity
Activity to update -> act1, ID= 1001*/
int updateActivity(struct List *list, struct Activity *actUp){
    printf("\n\n-----UPDATE ACTIVITY 1001-----\n");
    int flag = FALSE;
    struct Node *nodeUp;
    nodeUp = findId(list, actUp);
    if(nodeUp != NULL){
       nodeUp->activity = actUp;
       flag = TRUE;
    }
    return flag;
}

/*Delete an activity
Delete act2, ID= 1002 */
int deleteActivity(struct List *list, struct Activity *act){
    printf("\n\n-----DELETE ACTIVITY 1002-----\n");
    int flag = FALSE;
    struct Node *nodeDel;
    struct Node *ind;
    struct Node *last;
    nodeDel = findId(list, act);
    if(nodeDel != NULL){
      	for(ind = list->head; ind!= NULL; ind=ind->next){ //bucle to search in the LinkedList
      		if(ind->next==nodeDel){ //find the last node before the node to delete
      			last = ind;
      			break;
			  }
		  }
		if(nodeDel == list->head){ //If the node to delete its the head of the LinkedList
			list->head = nodeDel->next;
			list->index--;
		}else{
			last->next = nodeDel->next;
			list->index--;
		}
		free(nodeDel);
        flag = TRUE;
	}
    return flag;
}

/*Searchs an activity's ID and return the node where its located */
struct Node* findId(struct List *list, struct Activity *act){
    struct Node *node;
	struct Node *nodeFound = NULL;
    for(node = list->head; node!= NULL; node=node->next){ //bucle to search in the LinkedList
        if(act->id == node->activity->id){
            nodeFound = node;
            break;
        }
    }
    return nodeFound;
}

/*Returns the print format of a date */
char* toStringDate(struct Date *date){
    char output[100];
    char tempInt[10];

    strcpy(output, "");
    sprintf(tempInt, "%d", date->day);
    strcat(output, tempInt);
    strcat(output, "/");
    sprintf(tempInt, "%d", date->month);
    strcat(output, tempInt);
    strcat(output, "/");
    sprintf(tempInt, "%d", date->year);
    strcat(output, tempInt);

    return output;
}

/*Returns the print format of an activity */
char* toStringActivity(struct Activity *act){
    char output[1000];
    char tempId[10];
    strcpy(output, "");
    strcpy(output, "\n");
    strcat(output, "Title: ");
    strcat(output, act->title);
    strcat(output, "\n");
    sprintf(tempId, "%d", act->id);
    strcat(output, "ID: ");
    strcat(output, tempId);
    strcat(output, "\n");
    strcat(output, "Description: ");
    strcat(output, act->description);
    strcat(output, "\n");
    strcat(output, "Priority: ");
    strcat(output, act->priority);
    strcat(output, "\n");
    strcat(output, "Start Date: ");
    strcat(output, toStringDate(&(act->start)));
    strcat(output, "\n");
    strcat(output, "Finish Date: ");
    strcat(output, toStringDate(&(act->finish)));
    strcat(output, "\n");

    return output;
}

/*Returns the print format of the list */
char* toStringList(struct List *list, struct Activity **auxDate){
    char output[10000];
    strcpy(output, "");
    int i;
    for(i=0; i<list->index; i++){
        strcat(output, toStringActivity(*(auxDate + i)));
        }
    return output;
}

/*Fill the activitie's information*/
void fillData(struct List *list, struct Activity *act) {
	char temp_index[3];
	strcpy(temp_index, "");
	act->id = 1001 +(list->index);
	sprintf(temp_index, "%d", list->index);
	act->title = "Activity X";
	act->description = "Some Description";
	act->priority = "High";
	act->start.day = 30 - (list->index); act->start.month = 6; act->start.year = 2019;
	act->finish.day = 28 - (list->index); act->finish.month = 6; act->finish.year = 2019;
}

/*Sort the activities by start date in ascending order*/
struct Activity ** dateSort(struct List *list){
	int i, j, greater = 0;
	struct Activity *temp;
	struct Activity **auxDate;
	auxDate = (struct Activity **)malloc(list->index * sizeof(struct Activity *));

	copyArray(list,auxDate);

	for(i=0;i<(list->index)-1;i++){
		for(j=0;j<(list->index)-1;j++){
			greater = compareTo((*(auxDate + j)), (*(auxDate + j + 1)));
			if(greater == 1){
				temp = *(auxDate + j);
				*(auxDate + j) = *(auxDate + j +1);
				*(auxDate + j + 1) = temp;
			}
		}
	}
	return auxDate;
}

/* Function to compare dates
	@return 1 if date1 is bigger
	@return 2 if date2 is bigger
	@return -1 if date1 == date2
 */
int compareTo(struct Activity *date1, struct Activity *date2){
	int flag = -1;
	if(date1->start.year > date2->start.year){
		flag = 1;
	}else if(date2->start.year > date1->start.year){
		flag = 2;
	}else{
		if(date1->start.month > date2->start.month){
			flag = 1;
		}else if(date2->start.month > date1->start.month){
			flag = 2;
		}else{
			if(date1->start.day > date2->start.day){
				flag = 1;
			}else if(date2->start.day > date1->start.day){
				flag = 2;
			}
		}
	}
	return flag;
}

/* Get the number of days contained in the start date */
int getDays(struct Activity *act){
	int days;
	if(((act->start.month)%2==0) && ((act->start.month) < 9)){ //if its February, April, June or August
		days = (((act->start.year)-1) * (365)) + (((act->start.month)-1) * (31)) + (act->start.day);

	}else if(((act->start.month)%2==0) && ((act->start.month) > 9)){ //if its October or December
		days = (((act->start.year)-1) * (365)) + (((act->start.month)-1) * (30)) + (act->start.day);

	}else if(((act->start.month)%2!=0) && ((act->start.month) == 1)){ // if its January
		days = (((act->start.year)-1) * (365)) + (act->start.day);

	}else if(((act->start.month)%2!=0) && ((act->start.month) == 3)){ // if its March
		days = (((act->start.year)-1) * (365)) + (((act->start.month)-1) * (28)) + (act->start.day);

	}else if(((act->start.month)%2!=0) && ((act->start.month) < 8)){ //if its May or July
		days = (((act->start.year)-1) * (365)) + (((act->start.month)-1) * (30)) + (act->start.day);

	}else if(((act->start.month)%2!=0) && ((act->start.month) > 8)){ //if its September or November
		days = (((act->start.year)-1) * (365)) + (((act->start.month)-1) * (31)) + (act->start.day);
	}

	return days;

}
/*Copy the linked list to a new Activity-pointer-array*/
void copyArray(struct List *list, struct Activity **auxDate){
	int i = 0;
	struct Node *node;
	for(node = list->head; node!= NULL; node=node->next){
		*(auxDate + i) = node->activity;
		i++;
	}

}

/* Free a node by sending its activity */
void freeNodeByAct(struct List *list,struct Activity *act){
	struct Node *node;
	for(node = list->head; node!= NULL; node=node->next){
		if(node->activity == act){
			free(node);
			break;
		}
	}
}
