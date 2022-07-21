
//                                              STUDENT DATABASE PROGRAM
/*
    This is a Program Application which displays the student records based on any one of the input parameters as follows,
    > Student Name
    > Roll number
    >Home Place
    >Residential Status
    >Mobile number
    This program also automatically detects the type of input parameter.
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
#define SIZE 117
/*
    Below is the structure definition for holding all the student data and the variable member names are self - explanatory
*/
struct data
{
    char name[50];
    char rollno[10];
    char homeplace[20];
    char resstatus[20];
    char phoneno[20];
}s[SIZE];

int fundetermine();
void linearsearch();
void binarysearch();
void jumpsearch();
void interpolationsearch();
void exponentialsearch();
void terenarysearch();
void funsort();
void display_search();

int count=0;
int flag=0;

void main()
{
    char input[50];
    int dataflag=0,tempflag,temp,I[SIZE];
    int n=0,searchtype=0,i=0;
    FILE *f1;
    /* All the student details are entered in the below file named "data.txt" and each and every entry of the student
       details are read one by one and are getting stored in the array of structures which is defined above.
    */
    f1=fopen("data.txt","r");
    fscanf(f1,"%s %s %s %s %s\n",s[i].name,s[i].rollno,s[i].homeplace,s[i].resstatus,s[i].phoneno);
    while(strcmpi(s[i].name,"$"))
    {
        i++;
        fscanf(f1,"%s %s %s %s %s\n",s[i].name,s[i].rollno,s[i].homeplace,s[i].resstatus,s[i].phoneno);
    }
    printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DATABASE\n\n\n");
    printf("Search with:\n\n");
    printf("> Name\n> Roll Number\n> City\n> Residential Status(Hosteller/DayScholar)\n> Mobile Number\n\n");
    printf("Enter the search query:");
    /* The input given by the user is stored in the string variable named as input
       This input variable is used throughout the program for input data - type determination and searching.
    */
    gets(input);
    system("cls");
    while(input[0]=='\0')
    {
        printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DATABASE\n\n\n");
        printf("Search with:\n\n");
        printf("> Name\n> Roll Number\n> City\n> Residential Status(Hosteller/DayScholar)\n> Mobile Number\n\n");
        printf("No Data entered\n\nEnter the search query:  ");
        gets(input);
        system("cls");
    }
    dataflag=fundetermine(input);                     // Function call to check which data type input it is.
    /*
          Returning the respective integer value based on the determination of Data done Above..
        '1' stands for Phone number
        '2' stands for Residential Status
        '3' stands for Roll number
        '4' stands for Home Place
        '5' stands for Student's name
        '6' stands for Invalid Data entered
    */
    if(dataflag==1)
        printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DETAIL'S DATABASE\n\n\nYou have entered a Phone number\n");
    else if(dataflag==2)
        printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DETAIL'S DATABASE\n\n\nYou have asked for Residential Status\n");
    else if(dataflag==3)
        printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DETAIL'S DATABASE\n\n\nYou have Entered a Roll no\n");
    else if(dataflag==4)

        printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DETAIL'S DATABASE\n\n\nYou have entered a city\n");
    else if(dataflag==5)
        printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DETAIL'S DATABASE\n\n\nYou have entered a name\n");
    else if(dataflag==6)
        printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DETAIL'S DATABASE\n\n\nYou have entered an invalid input\n");
    for(i=0;i<SIZE;i++)            // Loop to initialize the index array,so it can be used to hold record of different types of sorting.
    {
        I[i]=i;
    }
    if(dataflag==2 || dataflag==4)
    {
        tempflag=3;
        funsort(tempflag,I,s);    // Function call to sort Roll number if Home Place or Residential Status is asked..
    }
    else
        funsort(dataflag,I,s);   // Function call to do the respective data sort based on the data entered by the user..
    switch(dataflag)            // Switch case to call the respective function to perform the search..
    {
        case 5:printf("\nEnter the option of Search\n1 - Linear Search\n2 - Interpolation Search\n3 - Jump Search\n\n");
               scanf("%d",&searchtype);
               switch(searchtype)
               {
                    case 1: system("cls");
                            display_search();
                            printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DATABASE\n\n\n");
                            printf("\nYou have entered a name\n");
                            printf("\n\nYou have selected linear Search\n\n");
                            linearsearch(input,I,dataflag);break;
                    case 2: system("cls");
                            display_search();
                            printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DATABASE\n\n\n");
                            printf("\nYou have entered a name\n");
                            printf("\n\nYou have selected Interpolation Search\n\n");
                            interpolationsearch(input,SIZE,I);break;
                    case 3:system("cls");
                           display_search();
                           printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DATABASE\n\n\n");
                           printf("\nYou have entered a name\n");
                           printf("\n\nYou have selected Jump Search\n\n");
                           jumpsearch(input,SIZE,I);break;
               };break;
        case 3:printf("\nEnter the option of Search\n1 - Linear Search\n2 - Binary Search\n3 - Exponential Search\n\n");
               scanf("%d",&searchtype);    // Search type is asked to use which type of search algorithm
               switch(searchtype)
               {
                    case 1:system("cls");
                           display_search();
                           printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DATABASE\n\n\n");
                           printf("\nYou have Entered a Roll no\n");
                           printf("\n\nYou have selected Linear Search\n\n");
                           linearsearch(input,I,dataflag);break;
                    case 2:system("cls");
                           display_search();
                           printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DATABASE\n\n\n");
                           printf("\nYou have Entered a Roll no\n");
                           printf("\n\nYou have selected Binary Search\n\n");
                           binarysearch(input,0,(SIZE-1),I);break;
                    case 3:system("cls");
                           display_search();
                           printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DATABASE\n\n\n");
                           printf("\nYou have Entered a Roll no\n");
                           printf("\n\nYou have selected Exponential Search\n\n");
                           exponentialsearch(input,SIZE,I);break;
               };break;
       case 4:system("cls");
              display_search();
              printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DATABASE\n\n\n");
              printf("\nYou have entered a city\n");
              linearsearch(input,I,dataflag);break;
       case 2:system("cls");
              display_search();
              printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DATABASE\n\n\n");
              printf("\nYou have asked for Residential Status\n");
              linearsearch(input,I,dataflag);break;
       case 1:printf("\nEnter your Search option\n1 - Linear Search\n2 - Ternary Search\n");
              scanf("%d",&searchtype);
              switch(searchtype)
              {
                    case 1:system("cls");
                           display_search();
                           printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DATABASE\n\n\n");
                           printf("\nYou have entered a Phone number\n");
                           printf("\n\nYou have selected Linear Search\n\n");
                           linearsearch(input,I,dataflag);break;
                    case 2:system("cls");
                           display_search();
                           printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DATABASE\n\n\n");
                           printf("\nYou have entered a Phone number\n");
                           printf("\n\nYou have selected Ternary Search\n\n");
                           terenarysearch(input,0,(SIZE-1),I);break;
              };break;
    }
}
void linearsearch(char input[50],int I[SIZE],int dataflag)
{
     int i;
     if(dataflag==5)                            // Linear search for names
     {
        for(i=0;i<SIZE;i++)
        {
            if(strcmpi(s[I[i]].name,input)==0)
            {
                if(count==0)
                {
                    printf("\n\t\t\tStudentName\t\tRoll No\t\tHomePlace\t\tRes_Status\t\tPhone_Number\n\n");
                    count++;
                }
                printf("\t\t%19s%20s%18s%25s%26s\n",s[I[i]].name,s[I[i]].rollno,s[I[i]].homeplace,s[I[i]].resstatus,s[I[i]].phoneno);
            }
        }
    }
    else if(dataflag==3)                            // Linear Search for Roll number
    {
        for(i=0;i<SIZE;i++)
        {
            if(strcmpi(s[I[i]].rollno,input)==0)
            {
                if(count==0)
                {
                    printf("\n\t\t\tStudentName\t\tRoll No\t\tHomePlace\t\tRes_Status\t\tPhone_Number\n\n");
                    count++;
                }
                printf("\t\t%19s%20s%18s%25s%26s\n",s[I[i]].name,s[I[i]].rollno,s[I[i]].homeplace,s[I[i]].resstatus,s[I[i]].phoneno);
            }
        }
    }
    else if(dataflag==1)                            // Linear Search for phone number
    {
        for(i=0;i<SIZE;i++)
        {
            if(strcmpi(s[I[i]].phoneno,input)==0)
            {
                if(count==0)
                {
                    printf("\n\t\t\tStudentName\t\tRoll No\t\tHomePlace\t\tRes_Status\t\tPhone_Number\n\n");
                    count++;
                }
                printf("\t\t%19s%20s%18s%25s%26s\n",s[I[i]].name,s[I[i]].rollno,s[I[i]].homeplace,s[I[i]].resstatus,s[I[i]].phoneno);
            }
        }
    }
    else if(dataflag==2)                        // Linear Search for Residential Status
    {
        for(i=0;i<SIZE;i++)
        {
            if(strcmpi(s[I[i]].resstatus,input)==0)
            {
                if(count==0)
                {
                    printf("\n\t\t\tStudentName\t\tRoll No\t\tHomePlace\t\tRes_Status\t\tPhone_Number\n\n");
                    count++;
                }
                printf("\t\t%19s%20s%18s%25s%26s\n",s[I[i]].name,s[I[i]].rollno,s[I[i]].homeplace,s[I[i]].resstatus,s[I[i]].phoneno);
            }
        }
    }
    else if(dataflag==4)                        // Linear search for Home place..
    {
         for(i=0;i<SIZE;i++)
         {
             if(strcmpi(s[I[i]].homeplace,input)==0)
             {
                 if(count==0)
                 {
                    printf("\n\t\t\tStudentName\t\tRoll No\t\tHomePlace\t\tRes_Status\t\tPhone_Number\n\n");
                    count++;
                 }
                 printf("\t\t%19s%20s%18s%25s%26s\n",s[I[i]].name,s[I[i]].rollno,s[I[i]].homeplace,s[I[i]].resstatus,s[I[i]].phoneno);
             }
        }
    }
    if(count==0)
        printf("\n\nNo Record Found\n");
}
void binarysearch(char input[50],int m,int n,int I[SIZE])           // Function used to perform Binary Search..
{
    /* Here mid stands for middle of the position
       m stands for the lowest index of the array
       n stands for the highest index of the array
   */
    if(n>=1)
    {
        int mid=m+(n-m)/2;
        int i;
        if(strcmpi(s[I[mid]].rollno,input)==0)
        {
            if(count==0)
            {
                printf("\n\t\t\tStudentName\t\tRoll No\t\tHomePlace\t\tRes_Status\t\tPhone_Number\n\n");
                count++;
            }
            printf("\t\t%19s%20s%18s%25s%26s\n",s[I[mid]].name,s[I[mid]].rollno,s[I[mid]].homeplace,s[I[mid]].resstatus,s[I[mid]].phoneno);
        }
    /* If entered roll number is less than input then the highest index of the array
        is changed to middle index + one(1)
    */
        if(strcmpi(s[I[mid]].rollno,input)==1)
        {
            binarysearch(input,m,mid-1,I);
        }
    /* If entered roll number is greater than input then the lowest  index of the array
    is changed to middle index + one(1)
    */
        if(strcmpi(s[I[mid]].rollno,input)==-1)
        {
            binarysearch(input,mid+1,n,I);
        }
    }
    else
        printf("\n\nNo Record Found\n");
}
void jumpsearch(char input[50],int n,int I[SIZE])           // Function used to perform Jump Search..
{
    int step=sqrt(n),prev=0,min;
    /* In Jump search initial step is calculated and if it is less than size of the array
       and the element located in the index is also less than the entered value then step
       value is incremented by itself.It's previous index s stored in the prev to perform linear search
    */
    while(strcmpi(s[I[((min=step<n?step:n)-1)]].name,input)==-1)
    {
        prev=step;
        step+=sqrt(n);
    }
    /* This loop performs a Linear search from the prev position till it finds the element to be searched
       and in every iteration the prev value is incremented by one.
    */
    while(strcmpi(s[I[prev]].name,input)==-1)
    {
        prev++;
    }
    // Finally the prev value is checked with the given input to verify the result.
    if(strcmpi(s[I[prev]].name,input)==0)
    {
        if(count==0)
        {
            printf("\n\t\t\tStudentName\t\tRoll No\t\tHomePlace\t\tRes_Status\t\tPhone_Number\n\n");
            count++;
        }
        printf("\t\t%19s%20s%18s%25s%26s\n",s[I[prev]].name,s[I[prev]].rollno,s[I[prev]].homeplace,s[I[prev]].resstatus,s[I[prev]].phoneno);
    }
    if(count==0)
        printf("\n\nNo Record Found\n");
}


void interpolationsearch(char input[50],int n,int I[SIZE])           // Function used to perform Interpolation Search..
{
    // Here n stands for the highest index of the array
    int lo=0,hi=(n-1);
    while(lo<=hi&&(strcmpi(s[I[lo]].name,input)==-1||strcmpi(s[I[lo]].name,input)==0)&&(strcmpi(s[I[hi]].name,input)==1||strcmpi(s[I[hi]].name,input)==0))
    {
    // Below is the Probe Position Formula to find out the index of the element
        int pos= lo+(( (hi-lo) * (input[0]-s[I[lo]].name[0]) ) / (s[I[hi]].name[0]-s[I[lo]].name[0]) );
    // The Below condition is used to check whether the element located at pos is the required element
        if(strcmpi(s[I[pos]].name,input)==0)
        {
             if(count==0)
             {
                    printf("\n\t\t\tStudentName\t\tRoll No\t\tHomePlace\t\tRes_Status\t\tPhone_Number\n\n");
                    count++;
             }
             printf("\t\t%19s%20s%18s%25s%26s\n",s[I[pos]].name,s[I[pos]].rollno,s[I[pos]].homeplace,s[I[pos]].resstatus,s[I[pos]].phoneno);
        }
    // The Below condition checks the alphabetical letters of the two given name and the searched name and alters the range.
        if(s[I[pos]].name[0]<input[0])
        {
            lo=pos+1;
        }
        else
        {
            hi=pos-1;
        }
    }
    if(count==0)
        printf("\n\nNo Record Found\n");
}
void exponentialsearch(char input[50],int n,int I[SIZE])            // Function used to perform Exponential Search..
{
    /* Here n  stands for the size of the array
       Initially, the first element in the array is checked and if it is not equal
       Then it moves to next set of code.
    */
    if(strcmpi(s[0].rollno,input)==0)
    {
        if(count==0)
        {
            printf("\n\t\t\tStudentName\t\tRoll No\t\tHomePlace\t\tRes_Status\t\tPhone_Number\n\n");
            count++;
        }
        printf("\t\t%19s%20s%18s%25s%26s\n",s[0].name,s[0].rollno,s[0].homeplace,s[0].resstatus,s[0].phoneno);
    }
    /* The below loop runs until the index calculated contains an element greater than the element given for the search
       At each unsuccessful check the higher index i is multiplied by two.
    */
    else
    {
        int i=1;
        while(i<n&&(strcmpi(s[I[i]].rollno,input)==0||strcmpi(s[I[i]].rollno,input)==-1))
        {
            i*=2;
        }
    // Finally  a Binary search is made in the new found range of the array.
        binarysearch(input,i/2,i<n?i:n,I);
    }
}
void terenarysearch(char input[50],int m,int n,int I[SIZE])     // Function used to perform Ternary search..
{
    /* Here m stands for the lowest index if the array
            n stands for the highest index of the array
            mid1 is for finding the index of first middle position
            mid2 id for finding the index of the second middle position
            flag is used to break the search loop whenever the mid1 value equals the mid 2 value
    */
    if(flag>0)
    {
        if(count==0)
        {
            printf("\n\nNo Record Found\n\n");
            count++;
        }
        exit(0);
    }
    if(n==m)
    {
        flag++;
    }
    int mid1=m+(n-m)/3;
    int mid2=mid1+(n-m)/3;
  //  if(strcmpi(s[I[0]].phoneno,input)<0)
    //    flag=1;
    if(strcmpi(s[I[mid1]].phoneno,input)==0)           //If the Phone number matches the mid1 value it prints it.
    {
        if(count==0)
        {
            printf("\n\t\t\tStudentName\t\tRoll No\t\tHomePlace\t\tRes_Status\t\tPhone_Number\n\n");
            count++;
        }
        printf("\t\t%19s%20s%18s%25s%26s\n",s[I[mid1]].name,s[I[mid1]].rollno,s[I[mid1]].homeplace,s[I[mid1]].resstatus,s[I[mid1]].phoneno);
        exit(0);
    }
    else if(strcmpi(s[I[mid2]].phoneno,input)==0)      //If the Phone number matches the mid2 value it prints it.
    {
        if(count==0)
        {
            printf("\n\t\t\tStudentName\t\tRoll No\t\tHomePlace\t\tRes_Status\t\tPhone_Number\n\n");
        }
        printf("\t\t%19s%20s%18s%25s%26s\n",s[I[mid2]].name,s[I[mid2]].rollno,s[I[mid2]].homeplace,s[I[mid2]].resstatus,s[I[mid2]].phoneno);
        exit(0);
    }
        /* Below are the Recursive calls made to the function
           Based on the updated range until it finds the element
        */
    else if(strcmpi(s[I[mid1]].phoneno,input)==-1 && strcmpi(s[I[mid2]].phoneno,input)==1)
    {
        terenarysearch(input,mid1+1,mid2-1,I);
    }
    else if(strcmpi(s[I[mid1]].phoneno,input)==1)
    {
        terenarysearch(input,m,mid1-1,I);
    }
    else if(strcmpi(s[I[mid2]].phoneno,input)==-1)
    {
        terenarysearch(input,mid2+1,n,I);
    }
}
void funsort(int dataflag,int I[SIZE])
{
    int i,j,swap;
    /*
        This function is used to sort different types of data based on the below dataflag
        '1' stands for Mobile number
        '2' stands for Residential Status
        '3' stands for Roll number
        '4' stands for Home Place
        '5' stands for Student's name
        '6' stands for Invalid Data entered
    */
    if(dataflag==1)                           //Used to sort Phone numbers..
    {
        for(i=0;i<SIZE;i++)
        {
            for(j=i+1;j<SIZE;j++)
            {
                if(strcmpi(s[I[i]].phoneno,s[I[j]].phoneno)>0)
                {
                    swap=I[i];
                    I[i]=I[j];
                    I[j]=swap;
                }
            }
        }
    }
    else if(dataflag==2)                              //Used to sort residential status
    {
        for(i=0;i<SIZE;i++)
        {
            for(j=i+1;j<SIZE;j++)
            {
                if(strcmpi(s[I[i]].resstatus,s[I[j]].resstatus)>0)
                {
                    swap=I[i];
                    I[i]=I[j];
                    I[j]=swap;
                }
            }
        }
    }
    else if(dataflag==3)                            //Used to sort Roll numbers..
    {
        for(i=0;i<SIZE;i++)
        {
            for(j=i+1;j<SIZE;j++)
            {
                if(strcmpi(s[I[i]].rollno,s[I[j]].rollno)>0)
                {
                    swap=I[i];
                    I[i]=I[j];
                    I[j]=swap;
                }
            }
        }
    }
    else if(dataflag==4)                           // Used to sort Home Place..
    {
        for(i=0;i<SIZE;i++)
        {
            for(j=i+1;j<SIZE;j++)
            {
                if(strcmpi(s[I[i]].homeplace,s[I[j]].homeplace)>0)
                {
                    swap=I[i];
                    I[i]=I[j];
                    I[j]=swap;
                }
            }
        }
    }
    else if(dataflag==5)                           // Used to sort names..
    {
        for(i=0;i<SIZE;i++)
        {
            for(j=i+1;j<SIZE;j++)
            {
                if(strcmpi(s[I[i]].name,s[I[j]].name)>0)
                {
                    swap=I[i];
                    I[i]=I[j];
                    I[j]=swap;
                }
            }
        }
    }
}
int fundetermine(char input[20])               // Function used to determine the Data entered by the user..
{
    FILE *file1;
    file1=fopen("cities.txt","r");
    int count=0,numchk=0,flag=0;
    char city[20];
    while(input[count]!='\0')               //To check whether all the characters are digits
    {
        if(input[count]<48 || input[count]>57)
        {
            numchk=1;
            break;
        }
        count++;
    }
    count=0;
    while(input[count]!='\0')               // Searching whether the name contains any unwanted characters starts here
    {
        if(input[count]<65 || ((input[count]>90 && input[count]<95) && (input[count]>95 && input[count]<97)) || input[count]>122)
        {
            flag=2;
            break;
        }
        count++;
    }                                   // Searching whether the name contains any unwanted characters ends
    if(numchk==1 || flag!=2)              // Searching for the cities starts here
    {
        fscanf(file1,"%s\n",city);
        while(strcmpi(city,"$")!=0)
        {
            if(strcmpi(input,city)==0)
            {
                flag=1;
                break;
            }
            fscanf(file1,"%s\n",city);
        }
    }                                      // Searching for the cities ends here
    /*
        Returning the respective integer value based on the determination of Data done Above..
        '1' stands for Phone number
        '2' stands for Residential Status
        '3' stands for Roll number
        '4' stands for Home Place
        '5' stands for Student's name
        '6' stands for Invalid Data entered
    */
    if(strlen(input)==10 && numchk==0)
            return(1);
    else if((strcmpi(input,"Hosteller")==0) || (strcmpi(input,"Dayscholar")==0))
            return(2);
    if (strcmpi(input,"Day scholar")==0)
    {
        strcpy(input,"Dayscholar");
        return(2);
    }
    else if((strlen(input)==6) && (input[2]=='P' || input[2]=='p') && (input[0]>=48 && input[0]<=57) && (input[1]>=48 && input[1]<=57 && (input[4]>=48 && input[4]<=57) && (input[5]>=48 && input[5]<=57)))
            return(3);
    else if(flag==1)
            return(4);
    else if(flag==2 || strlen(input)<=3)
            return(6);
    else
            return(5);
}
void display_search()
{
    system("cls");
    printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DATABASE\n\n\n");
    printf("Searching.");
    Sleep(150);
    system("cls");
    printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DATABASE\n\n\n");
    printf("Searching..");
    Sleep(150);
    system("cls");
    printf("\t\t\t\t\t\t\t\tWELCOME TO STUDENT DATABASE\n\n\n");
    printf("Searching...");
    Sleep(150);
    system("cls");
}


