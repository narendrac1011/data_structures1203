/*HASH TABLES with CHAINING*/

/*I have used the closed addressing method to do the operations in the Hash Table.
Particularly, I have used Chaining in order to Insert, Delete and Search in the Hash Table.

The Index is given by the Hash Function (Dot Product Hash Function).

Chaining is a technique used for avoiding collisions in hash tables.
If 2 Elements in the Hash Table get the same indexes, then we treat each index as a Linked List.
The First element with index 'i' to be inserted in the Hash Table, would be the head in the Linked List at Index 'i'.
The Next element with index 'i' to be inserted in the Hash Table, would be the next element in the Linked List at index 'i'.
Thus, we create a Linked List with Elements of similiar index.

Therefore, Chaining is a good technique for Collisions.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdint.h>


//Set he maximum Character length to 256
#define maxlen 256

//Set the Table size as 16
#define tablesize 16


//Node with Name, Age, Gender, Batch, Major and a next pointer
//Each Index in the Hash Table is a Linked List
struct node{
    char name[maxlen];
    int age;
    char gender[maxlen];
    char batch[maxlen];
    char major[maxlen];
    struct node *next;
};

typedef struct node Person;


//Create a Hash Table with the size 16
Person * HashTable[tablesize];

//#======================================================================================#

//Random Hash Function which would assign each person to a number/index in the Hash Table.
unsigned int hashfunction(char *name){
    int length = strnlen(name, maxlen);
    unsigned int index = 0;

    //Hash Function
    for(int i = 0; i < length; i++){

        //The Dot-Product Hash Family Method
        index = index + name[i];
        index = (index * name[i]) % tablesize;

    }//We get the range of Indexes as {0, 1, 2, 3, 4, 5, .... , tablesize - 1}.

    return index;
}

//#======================================================================================#

//Print the Hash Table
void PrintHashTable(){
    
    printf("Hash Table Start: \n");

    //Go through each index in the HashTable
    for(int i = 0; i < tablesize; i++){

        //If the Index of the Hash Table is Empty
        if(HashTable[i] == NULL){
            printf("\t%i\t---\n", i);
        }

        //If the Index of the Hash Table is not Empty
        else{
            printf("\t%i\t", i);

            Person *temp = HashTable[i];


            //Print all the People in Each Index, i.e. a Linked List.
            while(temp != NULL){
                printf("%s\t\t", temp->name);
                temp = temp->next;
            }

            printf("\n");
        }
    }

    printf("Hash Table End! \n");
    printf("#========================================================#\n");
}

//#======================================================================================#

//Initialize the Hash Table
void initHashTable(){

    //The Hash Table is initially set to be Empty
    for(int i = 0; i < tablesize; i++){
        HashTable[i] == NULL;
    }
}//This would Create an Empty Hash Table

//#======================================================================================#

//Insertion in a Hash Table
//Boolean: True if we successfully insert the person, else False!
bool InsertHashTable(Person *x){

    //If the Person is a Null Pointer, we return false!
    if (x == NULL){
        return false;
    }

    //Index of the Person
    int index = hashfunction(x->name);

    for(int i = 0; i < tablesize; i++){

        //If the Inserting data is already in the Hash Table, we do not insert it again!
        if(HashTable[index] != NULL && strncmp(HashTable[index]->name, x->name, tablesize) == 0){
            return false;
        }
    }

    //We Add the Person x in front of the Linked List
    //We return True since we were successful in Inserting the Person to the Hash Table
    x->next = HashTable[index];
    HashTable[index] = x;
    return true;
}

//#======================================================================================#

//Search a Person's name in the Hash Table
Person *SearchHashTable(char *name){

    //Index of the Person
    int index = hashfunction(name);

    //We create a Temporary Element with the same Index of the Person to be Searched! 
    Person *temp = HashTable[index];

    //While the Temporary element is not null &
    //If the Temporary element's name and the Searched name match, then this loop will terminate.
    //And Temporary Element would be the Searched Name/Person
    while(temp != NULL && strncmp(temp->name, name, maxlen) != 0){
        temp = temp->next;
    }

    //If we found out the Searched element in the Linked List, then we return temp, which would be our Searched Person
    //Else if we do not find the Searched Element in the Entire Linked List, then the temp would be NULL!
    return temp;
}

//#======================================================================================#

//Delete a Person's name in the Hash Table
Person *DeleteHashTable(char *name){

    //Index of the Person
    int index = hashfunction(name);

    //We create a Temporary Element with the same Index of the Person to be Deleted! 
    Person *temp = HashTable[index];

    //We also create a Temporary Element prev, which is assigned as NULL.
    Person *prev = NULL;

    //While the Temporary element is not null &
    //If the Temporary element's name and the name to be Deleted match, then this loop will terminate.
    while(temp != NULL && strncmp(temp->name, name, maxlen) != 0){

        //When a Match is found, we assign Prev as the Person, and temp as the person next to them.
        prev = temp;
        temp = temp->next;
    }

    //If temp is NULL, i.e. the Person next to the Person to be Deleted is NULL, then we return NULL;
    //In other words, the Person to be Deleted is the last person in the Linked List
    if(temp == NULL){
        return NULL;
    }


    //Stabilizing the Linked List after deleting the Element
    if(prev == NULL){
        HashTable[index] = temp->next;
    }

    //So after deleting temp, you set prev->next to temp->next, since temp is no longer there in the Linked list
    else{
        prev->next = temp->next;
    }

    return temp;
}

//#======================================================================================#

//Get all data of a given Person in the Hash Table
void GetData(Person *name){
    printf("\tName: %s \n", name);
    printf("\tAge: %d \n", name->age);
    printf("\tGender: %s \n", name->gender);
    printf("\tBatch: %s \n", name->batch);
    printf("\tMajor: %s \n", name->major);
    printf("\n");
}

//#======================================================================================#

//Final Search Operation of the Hash Table
Person *Search(char *name){

    Person *check = SearchHashTable(name);

    //If the Output of the SearchHashTable function was NULL, then we print Person not found!
    if(check == NULL){
        printf("\tPerson not Found!\n\n");
    }

    //Else if the Output of the function is not NULL, then we print Person Found and also Print the Entire Data of that person
    else{
        printf("\tPerson Found!\n");
        Person *x = check;
        GetData(x);
    }
}


//#======================================================================================#
//Main Function
int main(){

    //Initialize the Hash Table &,
    //Print the Empty Hash Table
    initHashTable();
    printf("Hash Table Initially: \n\n");
    PrintHashTable();


//#======================================================================================#
//Data of People:

    Person Siddhartha = {.name = "Siddhartha", .age = 23, .gender = "Male", .batch = "UG23", .major = "Political Science"};
    Person Mahesh = {.name = "Mahesh", .age = 21, .gender = "Male", .batch = "UG23", .major = "Political Science"};
    Person Narendra = {.name = "Narendra", .age = 18, .gender = "Male", .batch = "UG24", .major = "Computer Science"};
    Person Ramzan = {.name = "Ramzan", .age = 22, .gender = "Male", .batch = "UG23", .major = "Mathematics"};
    Person Sharon = {.name = "Sharon", .age = 19, .gender = "Female", .batch = "UG23", .major = "Sociology"};
    Person Abhay = {.name = "Abhay", .age = 20, .gender = "Male", .batch = "UG23", .major = "Biology"};
    Person Santosh = {.name = "Santosh", .age = 22, .gender = "Male", .batch = "UG24", .major = "Computer Science"};
    Person Gautam = {.name = "Gautam", .age = 21, .gender = "Male", .batch = "UG24", .major = "Computer Science"};
    Person Arvind = {.name = "Arvind", .age = 23, .gender = "Male", .batch = "UG23", .major = "Economics"};
    Person Nita = {.name = "Nita", .age = 21, .gender = "Female", .batch = "UG23", .major = "Psychology"};
    Person Asha = {.name = "Asha", .age = 20, .gender = "Female", .batch = "UG23", .major = "Pschology"};
    Person Padmaja = {.name = "Padmaja", .age = 20, .gender = "Female", .batch = "UG23", .major = "Pschology"};
    Person Shiva = {.name = "Shiva", .age = 23, .gender = "Male", .batch = "UG23", .major = "Economics"};
    Person Nageshwar = {.name = "Nageshwar", .age = 23, .gender = "Male", .batch = "UG23", .major = "Biology"};
    Person Gaurav = {.name = "Gaurav", .age = 22, .gender = "Male", .batch = "UG23", .major = "Economics"};
    Person Anand = {.name = "Anand", .age = 21, .gender = "Male", .batch = "UG23", .major = "Computer Science"};
    Person Abhisek = {.name = "Abhisek", .age = 20, .gender = "Male", .batch = "UG24", .major = "Computer Science"};

//#======================================================================================#

    //The Scanf function doesn't work in my Laptop, so I have manually inputted People's data and Inserted them in to the Hash Table.

    //Insert Person in the Hash Table
    InsertHashTable(&Siddhartha);
    InsertHashTable(&Mahesh);
    InsertHashTable(&Narendra);
    InsertHashTable(&Ramzan);
    InsertHashTable(&Sharon);
    InsertHashTable(&Abhay);
    InsertHashTable(&Santosh);
    InsertHashTable(&Gautam);
    InsertHashTable(&Arvind);
    InsertHashTable(&Nita);
    InsertHashTable(&Asha);
    InsertHashTable(&Padmaja);
    InsertHashTable(&Shiva);
    InsertHashTable(&Nageshwar);
    InsertHashTable(&Gaurav);
    InsertHashTable(&Anand);
    InsertHashTable(&Abhisek);


    //Print the Hash Table
    printf("Hash Table after Insertions: \n\n");
    PrintHashTable();

//#======================================================================================#
    //Search for any Person

    printf("Searching in the Hash Table: \n\n");
    //Search a person present in the Hash Table

    //Searching 1
    printf("Searching for Siddhartha: ");
    Search("Siddhartha");

    //Searching 2
    printf("Searching for Mahesh: ");
    Search("Mahesh");

    //Searching 3
    printf("Searching for Narendra: ");
    Search("Narendra");

    //Searching 4
    printf("Searching for Abhay: ");
    Search("Abhay");

    //Searching 5
    printf("Searching for Niranjan: ");
    Search("Niranjan");

    //Searching 6
    printf("Searching for Sharon: ");
    Search("Sharon");

    //Searching 7
    printf("Searching for Padmaja: ");
    Search("Padmaja");

    //Searching 8
    printf("Searching for Mayank: ");
    Search("Mayank");

//#======================================================================================#
    //Delete a Person's Name and Print the Hash Table
    
    //Deletion 1
    DeleteHashTable("Siddhartha");

    //Deletion 2
    DeleteHashTable("Abhisek");

    //Deletion 3
    DeleteHashTable("Narendra");

    //Print the Hash Table
    printf("#========================================================#\n");
    printf("Deleting Siddartha, Abhisek, Narendra from the Hash Table.\n");
    printf("Hash Table after Deletion: \n\n");
    PrintHashTable(); 

//#======================================================================================#


    return 0;
}