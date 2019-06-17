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
    struct Activity *activities[10]; //Make a pointer-array
};

/*Functions prototypes */
int createActivity(struct List *list, struct Activity *act);
int updateActivity(struct List *list, struct Activity *actUp);
int deleteActivity(struct List *list, struct Activity *act);
int findId(struct List *list, struct Activity *act);
char* toStringDate(struct Date *date);
char* toStringActivity(struct Activity *act);
char* toStringList(struct List *list, struct Activity *actDate[]);
void fillData(struct List *list, struct Activity *act);
void dateSort(struct Activity *actDate[], struct List *list);
int getDays(struct Activity *act);
void copyArray(struct List *list, struct Activity *actDate[]);

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
	actUp->finish.day = 9; actUp->finish.month = 6; actUp->finish.year =2019;

    /*Initialize variables */
    struct List list;
    list.index = 0;
    struct Activity *actDate[10]; //New activity-pointer-array for dateSort

    /*Calling functions */
    fillData(&list, act1);
    createActivity(&list, act1);
    fillData(&list, act2);
    createActivity(&list, act2);
    fillData(&list, act3);
    createActivity(&list, act3);
    fillData(&list, act4);
    createActivity(&list, act4);
    fillData(&list, act5);
    createActivity(&list, act5);
    fillData(&list, act6);
    createActivity(&list, act6);
    fillData(&list, act7);
    createActivity(&list, act7);
    fillData(&list, act8);
    createActivity(&list, act8);
    fillData(&list, act9);
    createActivity(&list, act9);
    fillData(&list, act10);
    createActivity(&list, act10);

	copyArray(&list,actDate);
	dateSort(actDate, &list);
    printf("%s", toStringList(&list, actDate));

    updateActivity(&list, actUp);
    copyArray(&list,actDate);
    dateSort(actDate, &list);
    printf("%s", toStringList(&list, actDate));

    deleteActivity(&list, act2);
    copyArray(&list,actDate);
    dateSort(actDate, &list);
    printf("%s", toStringList(&list, actDate));

    free(act1);
    free(act2);
    free(act3);
    free(act4);
    free(act5);
    free(act6);
    free(act7);
    free(act8);
    free(act9);
    free(act10);
    free(actUp);

}

/*Save the activity in the list array */
int createActivity(struct List *list, struct Activity *act){
    int flag = FALSE;
    if(list -> index < MAX){
        list -> activities[list->index] = act;
        flag = TRUE;
        list -> index++;
    }
    return flag;
}
/*Update an activity
Activity to update -> act1, ID= 1001*/
int updateActivity(struct List *list, struct Activity *actUp){
    printf("\n\n-----UPDATE ACTIVITY 1001-----\n");
    int flag = FALSE;
    int position;
    position = findId(list, actUp);
    if(position != -1){
       list -> activities[position] = actUp;
       flag = TRUE;
    }
    return flag;
}

/*Delete an activity
Delete act2, ID= 1002 */
int deleteActivity(struct List *list, struct Activity *act){
    printf("\n\n-----DELETE ACTIVITY 1002-----\n");
    int flag = FALSE;
    int i, position;
    position = findId(list, act);
    if(position != -1){
      for(i=position; i<list->index; i++){
        list->activities[i] = list->activities[i+1];
        }
        list -> index--;
        flag = TRUE;
    }
    return flag;
}

/*Searchs an activity's ID and return its position */
int findId(struct List *list, struct Activity *act){
    int pos = -1, i;
    for(i=0;i<list->index;i++){
        if(act->id == list->activities[i]->id){
            pos = i;
        }
    }
    return pos;
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
char* toStringList(struct List *list, struct Activity *actDate[]){
    char output[10000];
    strcpy(output, "");
    int i;
    for(i=0; i<list->index; i++){
        strcat(output, toStringActivity(actDate[i]));
        }
    return output;
}

//Fill the activitie's information
void fillData(struct List *list, struct Activity *act) {
	char temp_index[3];
	strcpy(temp_index, "");
	act->id = 1001 +(list->index);
	sprintf(temp_index, "%d", list->index);
	act->title = "Activity X";
	act->description = "Some Description";
	act->priority = "High";
	act->start.day = 15 + (list->index); act->start.month = 6; act->start.year = 2019;
	act->finish.day = 17 + (list->index); act->finish.month = 6; act->finish.year = 2019;
}

/*Sort the activities by start date in ascending order*/
void dateSort(struct Activity *actDate[], struct List *list){
	int i, j , days_x, days_y;
	struct Activity *temp;

	for(i=0;i<(list->index)-1;i++){
		for(j=0;j<(list->index)-1;j++){
			days_x = 0;
			days_y = 0;
			days_x = getDays((actDate[j]));
			days_y = getDays((actDate[j+1]));
			if( days_x >= days_y ){
				temp = (actDate[j]);
				(actDate[j]) = (actDate[j+1]);
				(actDate[j+1]) = temp;
			}
		}
	}
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
//Copy the list structure activity-pointer-array to a new activity-pointer-array
void copyArray(struct List *list, struct Activity *actDate[]){
	int i;
	for(i=0; i<(list->index); i++){
		actDate[i] =(list->activities[i]);
	}
}
