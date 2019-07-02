/*
Title: CRUD
Author: Alejandro Torre Reyes
Date: 01/07/2019
Functions/Variables named: cammelCase
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

/*Constants */
const int MAX = 100;
const int PEOPLENUM = 3;
#define TRUE 1
#define FALSE 0

/**
*@struct Date struct
*/
struct Date{
    int day;
    int month;
    int year;
};

/**
*@struct Activity struct
*/
struct Activity{
    int id;
    char *title;
    char *description;
    char *priority;
    struct Date start;
    struct Date finish;
};

/**
*@struct List struct
*/
struct List{
    int index;
    struct Node *head;
};

/**
*@struct Node struct
*/
struct Node{
	struct Activity *activity;
	struct Node *next;
};

/**
*@struct Person struct
*/
struct Person{
	struct List *list;
	char *name;
};

/*Functions prototypes */
int createNode(struct List *list, struct Activity *act);
int createNodeSort(struct List *list, struct Activity *act);
int updateActivity(struct List *list, struct Activity *actUp);
int updateActivitySort(struct List *list, struct Activity *actUp);
int deleteActivity(struct List *list, struct Activity *act);
struct Node* findId(struct List *list, struct Activity *act);
char* toStringDate(struct Date *date);
char* toStringActivity(struct Activity *act);
char* toStringList(struct List *list);
void fillData(struct List *list, struct Activity *act);
struct Activity ** dateSort(struct List *list);
int compareTo(struct Activity *act1, struct Activity *act2);
struct Activity ** durationSort(struct List *list);
int getDuration(struct Activity *act);
int getDays(struct Date date);
int getLeapYears(int year);
int isLeapYear(int year);
void copyArray(struct List *list, struct Activity **aux);
void freeNodeByAct(struct List *list, struct Activity *act);
struct Person* createList(struct List *list, struct Person *person);
int updateList(struct Person *person, struct Activity *act);
int deleteList(struct Person *person, struct Activity *act);
void saveInArray(struct Person **array, struct Person *person);
char * toStringPersonList(struct Person *person);
struct Person ** copyDurationArray(struct Person **personArr);
int getTotalDuration(struct Person *person);
void sortDurationArray(struct Person **array);
char* toStringDuration(struct Person **personArr);
struct Person ** shortestActivity(struct Person **personArr);
char* printPersonArray(struct Person **personArr);
int sumDates(struct Date date1, struct Date date2);

/**
*@brief Main block
*/
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
	struct Activity *actUp2 = (struct Activity*)malloc(sizeof(struct Activity));
	struct Activity *actUp3 = (struct Activity*)malloc(sizeof(struct Activity));

	//Fill data of to-update activity
    actUp->id = 1001; actUp->title = "Activity Updated"; actUp->description = "Some Description updated"; actUp->priority = "Low";
    actUp->start.day = 15; actUp->start.month = 6; actUp->start.year = 2019;
	actUp->finish.day = 21; actUp->finish.month = 6; actUp->finish.year =2019;
	actUp2->id = 1001; actUp2->title = "Activity Updated"; actUp2->description = "Some Description updated"; actUp2->priority = "Low";
    actUp2->start.day = 10; actUp2->start.month = 6; actUp2->start.year = 2019;
	actUp2->finish.day = 14; actUp2->finish.month = 6; actUp2->finish.year =2019;
	actUp3->id = 1001; actUp3->title = "Activity Updated"; actUp3->description = "Some Description updated"; actUp3->priority = "Low";
    actUp3->start.day = 10; actUp3->start.month = 6; actUp3->start.year = 2019;
	actUp3->finish.day = 11; actUp3->finish.month = 6; actUp3->finish.year =2019;

    //Initialize variables
	struct Person **personArr;
	personArr = (struct Person**)malloc(PEOPLENUM * sizeof(struct Person*));
	struct Person **personArrCopy;
	personArrCopy = (struct Person**)malloc(PEOPLENUM * sizeof(struct Person*));
	struct Person **shortArray;
	struct Date date1;
	struct Date date2;
	date1.day = 1; date1.month = 7; date1.year = 2019;
	date2.day = 2; date2.month = 7; date2.year = 2019;


	//Create people
	struct Person *newPerson1;
	struct Person *newPerson2;
	struct Person *newPerson3;

	struct Person person1;
	struct Person person2;
	struct Person person3;
	struct List list1;
	list1.index = 0;
	list1.head = NULL;
	struct List list2;
	list2.index = 0;
	list2.head = NULL;
	struct List list3;
	list3.index = 0;
	list3.head = NULL;

	//Create people's lists
	person1.name = "Alex";
	fillData(&list1, act1);
    createNode(&list1, act1);
    fillData(&list1, act2);
    createNode(&list1, act2);
    fillData(&list1, act3);
    createNode(&list1, act3);
    person1.list = &list1;

    person2.name = "Jimmy";
	fillData(&list2, act4);
    createNode(&list2, act4);
    fillData(&list2, act5);
    createNode(&list2, act5);
    fillData(&list2, act6);
    createNode(&list2, act6);
    person2.list = &list2;

    person3.name = "Amaury";
	fillData(&list3, act7);
    createNode(&list3, act7);
    fillData(&list3, act8);
    createNode(&list3, act8);
    fillData(&list3, act9);
    createNode(&list3, act9);
    fillData(&list3, act10);
    createNode(&list3, act10);
	person3.list = &list3;

    //Create
    newPerson1 = createList(&list1, &person1);
    printf("%s", toStringPersonList(newPerson1));

    newPerson2 = createList(&list2, &person2);
    printf("%s", toStringPersonList(newPerson2));

    newPerson3 = createList(&list3, &person3);
    printf("%s", toStringPersonList(newPerson3));

    //Update
    updateList(newPerson1, actUp);
    printf("%s", toStringPersonList(newPerson1));

    updateList(newPerson2, actUp2);
    printf("%s", toStringPersonList(newPerson2));

    updateList(newPerson3, actUp3);
    printf("%s", toStringPersonList(newPerson3));


    //Delete
    deleteList(newPerson1, act2);
    printf("%s", toStringPersonList(newPerson1));

    deleteList(newPerson2, act5);
    printf("%s", toStringPersonList(newPerson2));

    deleteList(newPerson3, act9);
    printf("%s", toStringPersonList(newPerson3));


    //Save in array
    //saveInArray(personArr, newPerson1);
    //saveInArray(personArr, newPerson2);
    //saveInArray(personArr, newPerson3);
    *(personArr + 0) = newPerson1;
    *(personArr + 1) = newPerson2;
    *(personArr + 2) = newPerson3;
    printf("%s", toStringDuration(personArr));

    //Sort by duration
    personArrCopy = copyDurationArray(personArr);
    sortDurationArray(personArrCopy);
    printf("ORDERED\n");
    printf("%s", toStringDuration(personArrCopy));

    //Print the shortest (duration)
    shortArray = shortestActivity(personArr);
    printf("%s", printPersonArray(shortArray));

    //Sum dates
    printf("The sum of the dates is: %d days", sumDates(date1, date2));

    //Free
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
    free(actUp2);
    free(actUp3);
    free(newPerson1);
    free(newPerson2);
    free(newPerson3);
    free(personArr);
    free(personArrCopy);
    free(shortArray);

}

/**
*@brief Save the activity at the end of the linked list
*@param list A pointer to a list
*@param act A pointer to an activity
*@return A flag (True/False)
*/
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

/**
*@brief Save the activity in the linked list sorting it by start date
*@param list A pointer to a list
*@param act A pointer to an activity
*@return a flag (True/False)
*/
int createNodeSort(struct List *list, struct Activity *act){
	int flag = FALSE;
    struct Node *newNode;
    struct Node *node;
    struct Node *temp;
    int greater = 0, auxGreater = 0;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if((list->index == 0)&&(newNode!= NULL)){ //if the linked list its empty
    	newNode->activity = act;
    	newNode->next = NULL;
    	list->head = newNode;
    	list->index++;
    	flag = TRUE;

	}else if((list->index > 0)&&(newNode!=NULL)){
		newNode->activity = act;
		for(node = list->head; node!=NULL; node = node->next){
			greater = compareTo(node->activity, act);

			if(greater == 1){ //Add at the beginning
				newNode->next = node;
				list->index++;
    			flag = TRUE;
				break;
			}

			if((greater != 1)&&(node->next != NULL)){ //Add between 2 nodes
				auxGreater = compareTo(node->next->activity, act);
				if(auxGreater == 1){
					temp = node->next;
					node->next = newNode;
					newNode->next = temp;
					list->index++;
    				flag = TRUE;
					break;
			}

			if((greater != 1)&&(node->next == NULL)){ //Add at the end
				node->next = newNode;
				newNode->next = NULL;
				list->index++;
    			flag = TRUE;
				break;
			}

			}

		}
	}
	return flag;
}

/**
*@brief Update an activity
*@param list A pointer to a list
*@param actUp A pointer to an activity to update
*@return A flag (True/False)
*/
//Activity to update -> act1, ID= 1001
int updateActivity(struct List *list, struct Activity *actUp){
    printf("\n\n-----UPDATE ACTIVITY-----\n");
    int flag = FALSE;
    struct Node *nodeUp;
    nodeUp = findId(list, actUp);
    if(nodeUp != NULL){
       nodeUp->activity = actUp;
       flag = TRUE;
    }
    return flag;
}

/**
*@brief Update an activity using the date sorting
*@param list A pointer to a list
*@param actUp A pointer to an activity to update
*@return A flag (True/False)
*/
int updateActivitySort(struct List *list, struct Activity *actUp){
	printf("\n\n-----UPDATE ACTIVITY 1001 (Sorting)-----\n");
    int flag = FALSE;
    struct Node *nodeUp;
    nodeUp = findId(list, actUp);
    flag = deleteActivity(list,nodeUp->activity);
    flag = createNodeSort(list, actUp);

    return flag;
}

/**
*@brief Delete an activity
*@param list A pointer to a list
*@param act A pointer to an activity to delete
*@return A flag (True/False)
*/
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

/**
*@brief Searchs an activity's ID and return the node where its located
*@param list A pointer to a list
*@param act A pointer to a activity to find
*@return A pointer to a node where the activity its located
*/
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

/**
*@brief Returns the print format of a date
*@param date A pointer to a date struct
*@return A string with the date
*/
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

/**
*@brief Returns the print format of an activity
*@param act A pointer to an activity
*@return A string with the activity information
*/
char* toStringActivity(struct Activity *act){
    char output[1000];
    char tempId[10];
    char tempDur[20];
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
    strcat(output, "Duration (days): ");
    sprintf(tempDur, "%d", getDuration(act));
    strcat(output, tempDur);
	strcat(output, "\n\n");

    return output;
}

/**
*@brief Returns the print format of the list
*@param list A pointer to a list
*@return A string with the entire list information
*/
char* toStringList(struct List *list){
    char output[10000];
    int i = 0;
    strcpy(output, "");
    struct Node *node;
    for(node=list->head; node!=NULL; node = node->next){
        strcat(output, toStringActivity(node->activity));
        }
        i++;

    return output;
}

/**
*@brief Fill the activitie's information
*@param list A pointer to a list
*@param act A pointer to an activity
*/
void fillData(struct List *list, struct Activity *act) {
	char temp_index[3];
	strcpy(temp_index, "");
	act->id = 1001 +(list->index);
	sprintf(temp_index, "%d", list->index);
	act->title = "Activity X";
	act->description = "Some Description";
	act->priority = "High";
	act->start.day = 26 - (list->index); act->start.month = 6; act->start.year = 2019;
	act->finish.day = 30 - (list->index); act->finish.month = 6; act->finish.year = 2019;
}

/**
*@brief Sort the activities by start date in ascending order
*@param list A pointer to a list
*@return pointer to activity-pointer-array
*/
struct Activity ** dateSort(struct List *list){
	int i, j, greater = 0;
	struct Activity *temp;
	struct Activity **auxDate;
	auxDate = (struct Activity **)malloc(list->index * sizeof(struct Activity *));

	copyArray(list,auxDate);

	for(i=0;i<(list->index)-1;i++){
		for(j=0;j<(list->index)-i-1;j++){
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

/**
*@brief Function to compare dates
*@param act1 A pointer to an activity
*@param act2 A pointer to an activity
*@return A flag with the biggest date
 */
int compareTo(struct Activity *act1, struct Activity *act2){
	int flag = -1;
	if(act1->start.year > act2->start.year){
		flag = 1;
	}else if(act2->start.year > act1->start.year){
		flag = 2;
	}else{
		if(act1->start.month > act2->start.month){
			flag = 1;
		}else if(act2->start.month > act1->start.month){
			flag = 2;
		}else{
			if(act1->start.day > act2->start.day){
				flag = 1;
			}else if(act2->start.day > act1->start.day){
				flag = 2;
			}
		}
	}
	return flag;
}

/**
*@brief Sort the linked list by the activitie's duration
*@param list A pointer to a list
*@return The first element in an activity-pointer array
*/
struct Activity ** durationSort(struct List *list){
	struct Activity **auxDur;
	int duration1 = 0, duration2 = 0, i, j;
	struct Activity *temp;
	auxDur = (struct Activity**)malloc(list->index * sizeof(struct Activity *));
	copyArray(list,auxDur);

	for(i=0;i<(list->index)-1;i++){
		for(j=0;j<(list->index)-i-1;j++){
			duration1 = getDuration(*(auxDur + j));
			duration2 = getDuration(*(auxDur + j + 1));
			if(duration1 >= duration2){
				temp = *(auxDur + j);
				*(auxDur + j) = *(auxDur + j +1);
				*(auxDur + j + 1) = temp;
			}
		}
	}
	return auxDur;
}

/**
*@brief Get the duration of an activity
*@param act A pointer to an activity
*@return The duration in days of an activity
*/
int getDuration(struct Activity *act){
	int duration;
	int startDays = 0, finishDays = 0;
	startDays = getDays(act->start);
	finishDays = getDays(act->finish);
	duration = finishDays - startDays;
	return duration;
}

/**
*@brief Get the number of days contained in the start date
*@param date A date struct
*@return The number of days in the date
*/
int getDays(struct Date date){
	int days = getLeapYears(date.year); //The variable "days" initialize with the extra days, including the actual year if its a leap year
	int actualLeapYear = isLeapYear(date.year);

	switch(date.month){
		case 1:
			days = (((date.year)-1) * (365)) + (date.day) - actualLeapYear;
			break;
		case 2:
			days = (((date.year)-1) * (365)) + 31 + (date.day) - actualLeapYear;
			break;
		case 3:
			days = (((date.year)-1) * (365)) + 31 + 28 + (date.day);
			break;
		case 4:
			days = (((date.year)-1) * (365)) + 31 + 28 + 31 + (date.day);
			break;
		case 5:
			days = (((date.year)-1) * (365)) + 31 + 28 + 31 + 30 + (date.day);
			break;
		case 6:
			days = (((date.year)-1) * (365)) + 31 + 28 + 31 + 30 + 31 + (date.day);
			break;
		case 7:
			days = (((date.year)-1) * (365)) + 31 + 28 + 31 + 30 + 31 + 30 + (date.day);
			break;
		case 8:
			days = (((date.year)-1) * (365)) + 31 + 28 + 31 + 30 + 31 + 30 + 31 + (date.day);
			break;
		case 9:
			days = (((date.year)-1) * (365)) + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + (date.day);
			break;
		case 10:
			days = (((date.year)-1) * (365)) + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + (date.day);
			break;
		case 11:
			days = (((date.year)-1) * (365)) + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + (date.day);
			break;
		case 12:
			days = (((date.year)-1) * (365)) + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + (date.day);
			break;
	}
	return days;
}

/**
*@brief Get the leap years (extra days) between year 0 and the activity start year
*@param year A year from a date struct
*@return The number of leap years between year 0 and the entered year
*/
int getLeapYears(int year){
	int leapYears = 0;
	int dif = 0, i;

	for(i=0;i<year;i=i+100){
		if((i%100 == 0)&&(i%400 != 0)){
			dif++;
		}
	}
	leapYears = floor(year/4) - dif;
	return leapYears;
}

/**
*@brief Function to know if the activity start year is a leap year
*@param year A year from a date struct
*@return A flag (True/False) if the actual year is a leap year
*/
int isLeapYear(int year){
	int flag = FALSE;
	if((year%4==0)&&((year%400 == 0)||(!(year%100 == 0)))){
		flag = TRUE;
	}
	return flag;
}

/**
*@brief Copy the linked list to a new Activity-pointer-array
*@param list A pointer to a list
*@param aux The first element of an activity-pointer array
*/
void copyArray(struct List *list, struct Activity **aux){
	int i = 0;
	struct Node *node;
	for(node = list->head; node!= NULL; node=node->next){
		*(aux + i) = node->activity;
		i++;
	}
}

/**
*@brief Free a node by sending its activity
*@param list A pointer to a list
*@param act A pointer to an activity
*/
void freeNodeByAct(struct List *list,struct Activity *act){
	struct Node *node;
	for(node = list->head; node!= NULL; node=node->next){
		if(node->activity == act){
			free(node);
			break;
		}
	}
}

/**
@brief Creates a person and his activity list
*@param list A pointer to a list
*@param person A pointer to a person
*@return A pointer to a person
*/
struct Person* createList(struct List *list, struct Person *person){
	struct Person *newPerson;
	newPerson = (struct Person *)malloc(sizeof(struct Person));
	newPerson->name = person->name;
	newPerson->list = list;

	return newPerson;
}

/**
*@brief Updates a person list and name
*@param person A pointer to a person
*@param act A pointer to an activity
*@return A flag (True/False)
*/
int updateList(struct Person *person, struct Activity *act){
	int flag = FALSE;
	char aux[15];
	strcpy(aux,"");
	char auxName[50];
	strcpy(auxName,"");
	strcpy(aux," updated");
	strcpy(auxName, person->name);
	strcat(auxName, aux);
	flag = updateActivity(person->list, act);

	return flag;
}

/**
*@brief Delete an activity from a person list
*@param person A pointer to a person
*@param act A pointer to an activity
*@return A flag (True/False)
*/
int deleteList(struct Person *person, struct Activity *act){
	int flag = FALSE;
	flag = deleteActivity(person->list, act);
	return flag;
}

/**
*@brief Function to save a person in a person-pointer-array
*@param array The first element in a person-pointer array
*@param person A pointer to a person
*/
void saveInArray(struct Person **array, struct Person *person){
	int i = 0;
	while(*(array+i)!=NULL){
		i++;
	}
	*(array+i) = person;
}

/**
*@brief Put the person information on a string
*@param person A pointer to a person
*@return A string with the person's information
*/
char * toStringPersonList(struct Person *person){
	char output[100000];
	strcpy(output, "");
	strcat(output, "NAME: ");
	strcat(output, person->name);
	strcat(output, "\n");
	strcat(output, toStringList(person->list));
	return output;
}

/**
*@brief Copies a struct person-pointer array to another
*@param personArr A struct person-pointer array
*@return The copy of the array
*/
struct Person ** copyDurationArray(struct Person **personArr){
	struct Person **copiedArr = (struct Person**)malloc(PEOPLENUM * sizeof(struct Person*));
	int i;
	for(i=0;i<PEOPLENUM;i++){
		*(copiedArr + i) = *(personArr + i);
	}
	return copiedArr;
}

/**
*@brief Gets the total duration of a list
*@param list A list
*@return The total duration of the activities in the list
*/
int getTotalDuration(struct Person *person){
	int totalDuration = 0;
	int actDuration = 0;
	struct Node *node;
	for(node=person->list->head; node!=NULL; node=node->next){
		actDuration = getDuration(node->activity);
		totalDuration = totalDuration + actDuration;
	}
	return totalDuration;
}

/**
*@brief Bubble sort the copied struct person-pointer array by duration
*@param array The copy of a struct person-pointer array
*/
void sortDurationArray(struct Person **array){
	int i,j;
	struct Person *temp;
	struct Person *element1;
	struct Person *element2;
	for(i=0;i<PEOPLENUM-1; i++){
		for(j=0; j<PEOPLENUM-i-1; j++){
			element1 = *(array + j);
			element2 = *(array + j + 1);
			if(getTotalDuration(element1) > getTotalDuration(element2)){
				temp = *(array + j);
				*(array + j) = *(array + j + 1);
				*(array + j + 1) = temp;
			}
		}
	}
}

/**
*@brief Creates a string with the list duration information
*@param personArr A struct person-pointer array
*@return A string with the duration information
*/
char* toStringDuration(struct Person **personArr){
	char output[10000];
	strcpy(output, "");
	char tempDur[3];
	strcpy(tempDur, "");
	int i;
	int listDuration = 0;
	struct Person *element;

	for(i=0;i<PEOPLENUM;i++){
		element = *(personArr + i);
		listDuration = getTotalDuration(element);
		sprintf(tempDur, "%d", listDuration);
		strcat(output, "Name: ");
		strcat(output, (element->name));
		strcat(output, "\n" );
		strcat(output, "Total Duration: ");
		strcat(output, tempDur);
		strcat(output, "\n");
	}

	return output;
}

/**
*@brief Finds the activity with the less duration time
*@param personArr A pointer to the first element of a person-pointer-array
*@return An array of people with the less duration time activitie's
*/
struct Person ** shortestActivity(struct Person **personArr){
	int i,j;
	struct Node *node;
	struct Person *actualPerson;
	struct Activity *shortAct;
	struct Person *aux;
	struct Person **shortArray;
	shortArray = (struct Person**)malloc(PEOPLENUM * sizeof(struct Person *));
	aux = *(personArr+0);
	shortAct = aux->list->head->activity; //The shortest activity begin with the first activity of the first person
	*(shortArray+0) = *(personArr+0);

	for(i=0;i<PEOPLENUM;i++){ //Searching the shortest activities and save it in an array
		actualPerson = *(personArr + i);
		j=0;
		for(node= actualPerson->list->head; node!=NULL; node = node->next){
			if(getDuration(node->activity) < getDuration(shortAct)){ //If the duration of the activity in the actual list in the actual person is SMALLER than the shortest Activity
				*(shortArray+0) = actualPerson; //Save it in the first position
				shortAct = node->activity;
				while(j < PEOPLENUM-1){ //Make NULL everything after the first element (the shortest)
					j++;
					*(shortArray+j) = NULL;
					break;
				}

			}else if(getDuration(node->activity) == getDuration(shortAct)){ //If the duration of the activity in the actual list in the actual person is EQUAL to the shortest Activity
				for(j=0;j<PEOPLENUM;j++){
					if(actualPerson == *(shortArray + j)){ //If the person its already in the array
						break;
					}else{
						if(*(shortArray+j)==NULL){ //If the position its empty
							*(shortArray+j) = actualPerson;
							break;
						}
					}
				}
			}
		}
	}
	return shortArray;
}

/**
*@brief Generates the string of the shortest activity information
*@param personArr A person pointer array
*@return A string with the shortest activity information
*/
char* printPersonArray(struct Person **personArr){
	int i;
	char output[10000];
	struct Person *actualPerson;
	strcpy(output, "");
	for(i=0;i<PEOPLENUM;i++){
		actualPerson = *(personArr+i);
    	if(actualPerson!=NULL){
    		strcat(output, "Person with the shortest activity: ");
    		strcat(output, actualPerson->name);
    		strcat(output, "\n");
		}else{
			break;
		}
	}
	return output;
}

/**
*@brief Convert two dates in days and sum them
*@param date1 A date struct
*@param date2 A date struct
*@return The sum of the two dates
*/
int sumDates(struct Date date1, struct Date date2){
	int totalDays;
	totalDays = getDays(date1) + getDays(date2);
	return totalDays;
}
