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
    char title[25];
    char description[100];
    char priority[10];
    struct Date start;
    struct Date finish;
};

struct List{
    int index;
    struct Activity activities[10];
};

/*Functions prototypes */
int createActivity(struct List *list, struct Activity act);
int updateActivity(struct List *list, struct Activity actUp);
int deleteActivity(struct List *list, struct Activity act);
int findId(struct List *list, struct Activity act);
char* toStringDate(struct Date date);
char* toStringActivity(struct Activity act);
char* toStringList(struct List list);

int main() {

    /*Activities block */
    struct Activity act1 = {.id = 1001, .title = "Activity 1", .description = "Some Description", .priority = "Low",
    .start.day = 06, .start.month = 06, .start.year = 2019,
    .finish.day = 10, .finish.month = 06, .finish.year = 2019,
    };
    struct Activity act2 = {.id = 1002, .title = "Activity 2", .description = "Some Description", .priority = "Medium",
    .start.day = 07, .start.month = 06, .start.year = 2019,
    .finish.day = 11, .finish.month = 06, .finish.year = 2019,
    };
    struct Activity act3 = {.id = 1003, .title = "Activity 3", .description = "Some Description", .priority = "High",
    .start.day = 8, .start.month = 06, .start.year = 2019,
    .finish.day = 12, .finish.month = 06, .finish.year = 2019,
    };
    struct Activity act4 = {.id = 1004, .title = "Activity 4", .description = "Some Description", .priority = "Low",
    .start.day = 16, .start.month = 06, .start.year = 2019,
    .finish.day = 21, .finish.month = 06, .finish.year = 2019,
    };
    struct Activity act5 = {.id = 1005, .title = "Activity 5", .description = "Some Description", .priority = "Medium",
    .start.day = 9, .start.month = 06, .start.year = 2019,
    .finish.day = 15, .finish.month = 06, .finish.year = 2019,
    };
    struct Activity act6 = {.id = 1006, .title = "Activity 6", .description = "Some Description", .priority = "Low",
    .start.day = 21, .start.month = 06, .start.year = 2019,
    .finish.day = 10, .finish.month = 07, .finish.year = 2019,
    };
    struct Activity act7 = {.id = 1007, .title = "Activity 7", .description = "Some Description", .priority = "High",
    .start.day = 7, .start.month = 06, .start.year = 2019,
    .finish.day = 8, .finish.month = 06, .finish.year = 2019,
    };
    struct Activity act8 = {.id = 1008, .title = "Activity 8", .description = "Some Description", .priority = "High",
    .start.day = 14, .start.month = 06, .start.year = 2019,
    .finish.day = 30, .finish.month = 06, .finish.year = 2019,
    };
    struct Activity act9 = {.id = 1009, .title = "Activity 9", .description = "Some Description", .priority = "Medium",
    .start.day = 5, .start.month = 06, .start.year = 2019,
    .finish.day = 10, .finish.month = 06, .finish.year = 2019,
    };
    struct Activity act10 = {.id = 1010, .title = "Activity 10", .description = "Some Description", .priority = "High",
    .start.day = 19, .start.month = 06, .start.year = 2019,
    .finish.day = 20, .finish.month = 06, .finish.year = 2019,
    };
    struct Activity actUp = {.id = 1001, .title = "Activity Up", .description = "Some Description updated", .priority = "Medium",
    .start.day = 16, .start.month = 06, .start.year = 2019,
    .finish.day = 23, .finish.month = 06, .finish.year = 2019,
    };

    /*Initialize list */
    struct List list;
    list.index = 0;

    /*Calling functions */
    createActivity(&list, act1);
    createActivity(&list, act2);
    createActivity(&list, act3);
    createActivity(&list, act4);
    createActivity(&list, act5);
    createActivity(&list, act6);
    createActivity(&list, act7);
    createActivity(&list, act8);
    createActivity(&list, act9);
    createActivity(&list, act10);
    //printf("PRINT");
    printf("%s", toStringList(list));
    updateActivity(&list, actUp);
    printf("%s", toStringList(list));
    deleteActivity(&list, act2);
    printf("%s", toStringList(list));

}

/*Save the activity in the list array */
int createActivity(struct List *list, struct Activity act){
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
int updateActivity(struct List *list, struct Activity actUp){
    printf("\n\nUPDATE ACTIVITY 1001\n");
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
int deleteActivity(struct List *list, struct Activity act){
    printf("\n\nDELETE ACTIVITY 1002\n");
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
int findId(struct List *list, struct Activity act){
    int pos = -1, i;
    for(i=0;i<list->index;i++){
        if(act.id == list->activities[i].id){
            pos = i;
        }
    }
    return pos;
}

/*Returns the print format of a date */
char* toStringDate(struct Date date){
    char output[100];
    char tempInt[10];

    strcpy(output, "");
    sprintf(tempInt, "%d", date.day);
    strcat(output, tempInt);
    strcat(output, "/");
    sprintf(tempInt, "%d", date.month);
    strcat(output, tempInt);
    strcat(output, "/");
    sprintf(tempInt, "%d", date.year);
    strcat(output, tempInt);

    return output;
}

/*Returns the print format of an activity */
char* toStringActivity(struct Activity act){
    char output[1000];
    char tempId[10];
    strcpy(output, "");
    strcpy(output, "\n");
    strcat(output, "Title: ");
    strcat(output, act.title);
    strcat(output, "\n");
    sprintf(tempId, "%d", act.id);
    strcat(output, "ID: ");
    strcat(output, tempId);
    strcat(output, "\n");
    strcat(output, "Description: ");
    strcat(output, act.description);
    strcat(output, "\n");
    strcat(output, "Priority: ");
    strcat(output, act.priority);
    strcat(output, "\n");
    strcat(output, "Start Date: ");
    strcat(output, toStringDate(act.start));
    strcat(output, "\n");
    strcat(output, "Finish Date: ");
    strcat(output, toStringDate(act.finish));
    strcat(output, "\n");

    return output;
}

/*Returns the print format of the list */
char* toStringList(struct List list){
    char output[10000];
    strcpy(output, "");
    int i;
    for(i=0; i<list.index; i++){
        strcat(output, toStringActivity(list.activities[i]));
        }
    return output;
}
