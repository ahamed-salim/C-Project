#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct patient
{
    int id;
    char patientName[50];
    char patientAddress[100];
    char disease[50];
    char bloodgroup[10];
    char gender[10];
    char date[12];
    struct patient *next;
};

struct doctor
{
    int id;
    char name[50];
    char shifttime[50];
    char specialize[50];
    char date[12];
    struct doctor *next;
};

struct patient *patientHead = NULL;
struct doctor *doctorHead = NULL;

void main_display();
void admitPatient();
void patientList();
void dischargePatient();
void addDoctor();
void doctorList();
void deleteDoctor();

int main()
{
        long long int id,pass;
        system("cls");
        printf("\n\n\t\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n");
        printf("\n\t\t\3                      WELCOME TO                         \3\n");
        printf("\n\t\t\3           <== Hospital Management System ==>            \3\n");
        printf("\n\t\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n\n");

        printf("\n\n\t\tEnter Your Id To Access: ");
        scanf("%lld",&id);
        printf("\n\n\t\tEnter Correct Password: ");
        scanf("%lld",&pass);

        if(id==12345 && pass==123)
            main_display();
        else
        {
            printf("\n\n\t\t\tIncorrect Id or Password.....\a");
            printf("\n\n\t\t\t\t\t\tEnter Correct Id And Password To Access\2");
            getch();
            main();
        }
    }
void main_display()
{

    int ch;

    while(1)
    {
        system("cls");
        printf("\n\n\t\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n");
        printf("\n\t\t\3                      WELCOME TO                         \3\n");
        printf("\n\t\t\3           <== Hospital Management System ==>            \3\n");
        printf("\n\t\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n\n");

        printf("\n\n\t\t1. Admit Patient\n\n");
        printf("\t\t2. Patient List\n\n");
        printf("\t\t3. Discharge Patient\n\n");
        printf("\t\t4. Add Doctor\n\n");
        printf("\t\t5. Doctors List\n\n");
        printf("\t\t6. Delete Doctor's Record\n\n");
        printf("\t\t0. Exit\n");
        printf("\t\t----------------------------------------------------------\n\n");
        printf("\t\tEnter Your Choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
        case 0:
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\1 \2 \1 Thank You for Visiting Our Site \1 \2 \1\n\n\n\n\n\n\n\n\n\n\n");
            exit(0);
        case 1:
            admitPatient();
            break;
        case 2:
            patientList();
            break;
        case 3:
            dischargePatient();
            break;
        case 4:
            addDoctor();
            break;
        case 5:
            doctorList();
            break;
        case 6:
            deleteDoctor();
            break;

        default:
            system("cls");
            printf("\n\n\n\n\t\t\t\tInvalid Choice......\a\n\n\n");
        }
        printf("\n\n\n\n\n-------------------------------------------------------------------------");
        printf("\n\nPress Any Key To Continue...");
        getch();

}
}
void admitPatient()
{
    system("cls");
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);

    struct patient *newPatient = (struct patient*)malloc(sizeof(struct patient));
    strcpy(newPatient->date, myDate);
    printf("\n\n\t\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n");
    printf("\n\t\t\3                <== Admit  A   Patient ==>               \3\n");
    printf("\n\t\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n\n");
    printf("\n\n\t\tEnter Patient id: ");
    scanf("%d", &newPatient->id);

    printf("\n\t\tEnter Patient name: ");
    fflush(stdin);
    gets(newPatient->patientName);

    printf("\n\t\tEnter Gender(F or M): ");
    fflush(stdin);
    gets(newPatient->gender);

    printf("\n\t\tEnter Patient Blood Group: ");
    fflush(stdin);
    gets(newPatient->bloodgroup);

    printf("\n\t\tEnter Patient Address: ");
    fflush(stdin);
    gets(newPatient->patientAddress);

    printf("\n\t\tEnter Patient Disease: ");
    fflush(stdin);
    gets(newPatient->disease);

    newPatient->next = patientHead;
    patientHead = newPatient;

    printf("\n\n\n\t\t\t\t<== Patient Added Successfully ==>\n");
}

void patientList()
{
    system("cls");
    printf("\n\n\t\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n");
    printf("\n\t\t\3                <== Patient List ==>                     \3\n");
    printf("\n\t\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n\n");
    printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "Id", "Patient Name", "Address", "Disease", "Gender","Blood Group","Date");
    printf("----------------------------------------------------------------------------------------------------------\n");

    struct patient *temp = patientHead;
    while(temp != NULL)
    {
        printf("%-15d %-15s %-15s %-15s %-15s %-15s %-15s\n", temp->id, temp->patientName, temp->patientAddress, temp->disease,temp->gender,temp->bloodgroup,temp->date);
        temp = temp->next;
    }
}

void dischargePatient()
{
    int id;
    system("cls");
    printf("\n\n\t\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n");
    printf("\n\t\t\3                <== Discharge A   Patient ==>            \3\n");
    printf("\n\t\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n\n");
    printf("\n\n\t\tEnter Patient id to discharge: ");
    scanf("%d", &id);

    struct patient *current = patientHead;
    struct patient *prev = NULL;

    while(current != NULL)
    {
        if(current->id == id)
        {
            if(prev == NULL)
            {
                patientHead = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            printf("\n\n\n\t\t\t\tPatient Discharged Successfully...");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("\n\n\n\t\t\t\tRecord Not Found!!!\a\n\n");
}

void addDoctor()
{
    system("cls");
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);

    struct doctor *newDoctor = (struct doctor*)malloc(sizeof(struct doctor));
    strcpy(newDoctor->date, myDate);
    printf("\n\n\t\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n");
    printf("\n\t\t\3                <== Add Doctor ==>                       \3\n");
    printf("\n\t\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n\n");
    printf("\n\n\t\tEnter Doctor's id: ");
    scanf("%d", &newDoctor->id);

    printf("\n\t\tEnter Doctor Name: ");
    fflush(stdin);
    gets(newDoctor->name);

    printf("\n\t\tEnter Doctor Shift Time: ");
    fflush(stdin);
    gets(newDoctor->shifttime);

    printf("\n\t\tDoctor Specialize in: ");
    fflush(stdin);
    gets(newDoctor->specialize);

    newDoctor->next = doctorHead;
    doctorHead = newDoctor;

    printf("\n\n\t\t\tDoctor Added Successfully!!!\n\n");
}

void doctorList()
{
    system("cls");
        printf("\n\n\t\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n");
    printf("\n\t\t\3               <== Doctors List ==>                      \3\n");
    printf("\n\t\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n\n");
    printf("%-10s %-30s %-30s %-30s %s\n", "id", "Name", "Shift-Time", "Specialize","Date");
    printf("-------------------------------------------------------------------------------------------------------------------\n");

    struct doctor *temp = doctorHead;
    while(temp != NULL)
    {
        printf("%-10d %-30s %-30s %-30s %s\n", temp->id, temp->name, temp->shifttime, temp->specialize, temp->date);
        temp = temp->next;
    }

}    void deleteDoctor()
    {
        int id;
        system("cls");
       printf("\n\n\t\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n");
    printf("\n\t\t\3                <== Delete Doctor's Record ==>           \3\n");
    printf("\n\t\t\3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3 \3\n\n");
        printf("\n\t\tEnter Doctor ID to delete: ");
        scanf("%d", &id);

        struct doctor *current = doctorHead;
        struct doctor *prev = NULL;

        while(current != NULL)
        {
            if(current->id == id)
            {
                if(prev == NULL)
                {
                    doctorHead = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                free(current);
                printf("\n\n\t\t\tDoctor Deleted Successfully.");
                return;
            }
            prev = current;
            current = current->next;
        }

        printf("\n\n\t\t\tDoctor with ID %d not found!\a", id);
    }