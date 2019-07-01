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
char* toStringList(struct List *list, struct Activity **aux);
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
struct Person* createList(struct List *list, struct Person *person, struct Person **personArr);
int updateList(struct Person *person, struct Activity *act);
int deleteList(struct Person *person, struct Activity *act);
void saveInArray(struct Person **array, struct Person *person);
char * toStringPersonList(struct Person *person, struct Activity **aux);

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
	struct Activity **actDur; //New Node-pointer-array for dateSort
	struct Person **personArr;
	personArr = (struct Person**)malloc(PEOPLENUM * sizeof(struct Person*));

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
	person1.list = &list1;
	fillData(&list1, act1);
    createNodeSort(&list1, act1);
    fillData(&list1, act2);
    createNodeSort(&list1, act2);
    fillData(&list1, act3);
    createNodeSort(&list1, act3);

    person2.name = "Jimmy";
	person2.list = &list2;
	fillData(&list2, act4);
    createNodeSort(&list2, act4);
    fillData(&list2, act5);
    createNodeSort(&list2, act5);
    fillData(&list2, act6);
    createNodeSort(&list2, act6);

    person3.name = "Amaury";
	person3.list = &list3;
	fillData(&list3, act7);
    createNodeSort(&list3, act7);
    fillData(&list3, act8);
    createNodeSort(&list3, act8);
    fillData(&list3, act9);
    createNodeSort(&list3, act9);
    fillData(&list3, act10);
    createNodeSort(&list3, act10);

    //Create
    newPerson1 = createList(&list1, newPerson1, personArr);
    actDur = dateSort(newPerson1->list);
    printf("%s", toStringPersonList(newPerson1, actDur));
    free(actDur);

    newPerson2 = createList(&list2, newPerson2, personArr);
    actDur = dateSort(newPerson2->list);
    printf("%s", toStringPersonList(newPerson2, actDur));
    free(actDur);

    newPerson3 = createList(&list3, newPerson3, personArr);
    actDur = dateSort(newPerson3->list);
    printf("%s", toStringPersonList(newPerson3, actDur));
    free(actDur);


    //Update
    updateList(newPerson1, actUp);
    actDur = dateSort(newPerson1->list);
    printf("%s", toStringPersonList(newPerson1, actDur));
    free(actDur);

    updateList(newPerson2, actUp);
    actDur = dateSort(newPerson2->list);
    printf("%s", toStringPersonList(newPerson2, actDur));
    free(actDur);

    updateList(newPerson3, actUp);
    actDur = dateSort(newPerson3->list);
    printf("%s", toStringPersonList(newPerson3, actDur));
    free(actDur);


    //Delete
    deleteList(newPerson1, act2);
    actDur = dateSort(newPerson1->list);
    printf("%s", toStringPersonList(newPerson1, actDur));
    free(actDur);

    deleteList(newPerson2, act5);
    actDur = dateSort(newPerson2->list);
    printf("%s", toStringPersonList(newPerson2, actDur));
    free(actDur);

    deleteList(newPerson3, act9);
    actDur = dateSort(newPerson3->list);
    printf("%s", toStringPersonList(newPerson3, actDur));
    free(actDur);

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
    free(newPerson1);
    free(newPerson2);
    free(newPerson3);

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
	strcat(output, "\n");

    return output;
}

/**
*@brief Returns the print format of the list
*@param list A pointer to a list
*@param aux A pointer to the first element of an activity-pointer array
*@return A string with the entire list information
*/
char* toStringList(struct List *list, struct Activity **aux){
    char output[10000];
    strcpy(output, "");
    int i;
    for(i=0; i<list->index; i++){
        strcat(output, toStringActivity(*(aux + i)));
        }
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
	act->start.day = 30 - (list->index); act->start.month = 6; act->start.year = 2019;
	act->finish.day = 28 - (list->index); act->finish.month = 6; act->finish.year = 2019;
}

/**
*@brief Sort the activities by start date in ascending order
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
*@param personArr The first element in a person-pointer array
*@return A pointer to a person
*/
struct Person* createList(struct List *list, struct Person *person, struct Person **personArr){
	struct Person *newPerson;
	newPerson = (struct Person *)malloc(sizeof(struct Person));
	newPerson->name = person->name;
	newPerson->list = list;

	saveInArray(personArr, newPerson);

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
	char *aux = "updated";
	flag = updateActivitySort(person->list, act);
	strcat(person->name, aux);

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
	while(*(array + i) != NULL){
		i++;
	}
	*(array + i) = person;
}

/**
*@brief Put the person information on a string
*@param person A pointer to a person
*@param aux The first element in an activity-pointer array
*@return A string with the person's information
*/
char * toStringPersonList(struct Person *person, struct Activity **aux){
	char output[100000];
	strcpy(output, "");
	strcat(output, "NAME: ");
	strcat(output, person->name);
	strcat(output, "\n");
	strcat(output, toStringList(person->list, aux));
	return output;
}
