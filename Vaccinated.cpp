#include <stdio.h>
#include <stdlib.h>

typedef struct sqInfo{
    char date[9]; // yy/mm/dd
    char personalID[32];
    char name[16];
    char phone[11];
    char gender[7];
    int age;
} sqInfo;

sqInfo* newSqInfo(size_t);
void inputSqInfo(sqInfo*, int);
void displayRow(sqInfo*, int);
void displaySqInfo(sqInfo*, int);

int main(){
    int size;
    sqInfo *sqinfo;

    printf("Please input the no. of people vaccinated: ");
    scanf("%i", &size);

    if(size<0){
        fprintf(stderr, "Invalid no. of people vaccinated");
        exit(EXIT_FAILURE);
    }

    sqinfo = newSqInfo(size);

    printf("\n...............................Please input the information of Vaccinated people: ...............................\n");
    for(int i=0;i<size;++i){
        inputSqInfo(sqinfo, i);
    }

    printf("\n----------------------------------------------------------------------------------------------------------------\n");
    displaySqInfo(sqinfo, size);

    //free heap allocated memory
    free(sqinfo);
    return 0;
}


sqInfo* newSqInfo(size_t size){
    sqInfo* info = (sqInfo*) malloc(sizeof(sqInfo) * size);
    return info;
}

void inputSqInfo(sqInfo* s, int i){
        printf("\nEnter Vaccinated Date (yy/mm/dd) : ");
        scanf(" %s", (s+i)->date);

        printf("Enter PersonalID: ");
        scanf(" %s", (s+i)->personalID);

        printf("Enter Name: ");
        scanf(" %[^\n]s", (s+i)->name);

        printf("Enter Phone No.: ");
        scanf(" %s", (s+i)->phone);

        printf("Enter Gender: ");
        scanf(" %s", (s+i)->gender);

        printf("Enter Age: ");
        scanf("%d", &(s+i)->age);
}
void displayRow(sqInfo* s, int i){
    printf("\n");
    printf("%s", (s+i)->date);
    printf("%20s", (s+i)->personalID);
    printf("%20s", (s+i)->name);
    printf("%20s", (s+i)->phone);
    printf("%20s", (s+i)->gender);
    printf("%20d", (s+i)->age);
}

void printSpace(int n){
    for(int i=0;i<n;++i) printf(" ");
}

void displaySqInfo(sqInfo* s, int size){
    printf("Date\t\t PersonalID\t\t Name\t\t Phone No.\t\t Gender\t\t Age");
    for(int i=0;i<size;++i){
        displayRow(s, i);
    }
}
