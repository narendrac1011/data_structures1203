/*Hash Tables using Open Addressing*/

/*I have used Linear Probing method to do the operations in the Hash Table.
Particularly, I have used Linear Probing for Insertion, Searching and Deletion.

The Index is given by the Hash Function (Dot Product Hash Family).

Linear Probing is a technique used for avoiding collisions in hash tables.
If 2 Elements in the Hash Table get the same indexes 'i',
then the first element to be inserted in the Hash Table, would get the index 'i'.
However, the next element to be inserted in the Hash Table, would check for an empty index after index 'i'.
This is done by incrementing the index by 1 and checking if that index is empty or not!
Repeat this until you get a empty index.
If you get a empty index, insert! Else, if there is no empty index, we won't be able to insert!

This makes the Linear probing technique good for collisions!
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdint.h>


//Set he maximum Character length to 256
#define maxlen 256

//Set the Table size as 25
#define tablesize 25


//Node with Name, Age, Gender, Batch and Major
struct node{
    char name[maxlen];
    int age;
    char gender[maxlen];
    char batch[maxlen];
    char major[maxlen];
};

typedef struct node Person;


//Define Deleted Node
//Any Deleted Node in the Hash Table will be seen as this random node.
//This would make the insertion and Search Easier at the Deleted Index.
#define Deleted (Person *)(0xABCDEF)


//Create a Hash Table with the size 25
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

        //If the Index was previously Deleted
        else if(HashTable[i] == Deleted){
            printf("\t%i\t-<Deleted>-\n", i);   
        }

        //If the Index of the Hash Table is not Empty, we show the data
        else{
            printf("\t%i\t%s\n", i, HashTable[i]->name);
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

        //We check for the next empty Index in the Hash Table for the Insertion
        //In case, if the Index in the Hash Table is already taken, then there would be a collision!
        //So we insert the Person in the next following empty index
        int next = (index + i) % tablesize;

        //If the Inserting data is already in the Hash Table, we do not insert it again!
        if(HashTable[next] != NULL && strncmp(HashTable[next]->name, x->name, tablesize) == 0){
            return false;
        }

        //If the Index is empty, then we insert the Person at the Index.
        if(HashTable[next] == NULL || HashTable[next] == Deleted){
            HashTable[next] = x;
            return true;
        }
    }

    //If the Hash Table is full, i.e. there is no Space for the person, we print False!
    return false;
}

//#======================================================================================#

//Search a Person's name in the Hash Table
Person *SearchHashTable(char *name){

    //Index of the Person
    int index = hashfunction(name);

    //We check for each Index in the Hash Table
    for(int i = 0; i < tablesize; i++){

        int next = (i + index) % tablesize;

        //If the Hash Table has the index of the person as NULL, we return NULL
        if(HashTable[next] == NULL){
            return NULL;
        }

        //If the Hash Table has the Index of the Person as Deleted, we continue to check for other indexes
        if(HashTable[next] == Deleted){
            continue;
        }

        //If the Index name and the name matches, we return the index!
        if(strncmp(HashTable[next]->name, name, tablesize) == 0){
            return HashTable[next];
        }
    }

    //If we complete checking the entire Hash Table and found no match, then we return NULL!
    return NULL;
}

//#======================================================================================#

//Delete a Person's name in the Hash Table
Person *DeleteHashTable(char *name){

    //Index of the Person
    int index = hashfunction(name);

    //We go through each index in the Hash Table
    for(int i = 0; i < tablesize; i++){

        int next = (i + index) % tablesize;

        //If the index in the Hash table is NULL, then we return NULL, since we wouldn't be able to delete Anything
        if(HashTable[next] == NULL){
            return NULL;
        }

        //If the index in the Hash Table is Deleted, then we continue to check for other indexes in the Hash Table
        if(HashTable[next] == Deleted){
            continue;
        }

        //If the Index name and the name matches, we remove the person/element by converting it to NULL.
        //After Deleting the person's index, we print the Index as Deleted!
        if(HashTable[next] != NULL && strncmp(HashTable[next]->name, name, tablesize) == 0){
            Person *Temp = HashTable[next];
            HashTable[next] = Deleted;
            return Temp;
        }
    }

    //If we check the entire Hash Table and didn't found any match, then we return NULL!
    //In other words, the Person is not there in the Hash Table
    return NULL;
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
    DeleteHashTable("Nageshwar");

    //Deletion 3
    DeleteHashTable("Narendra");

    //Print the Hash Table
    printf("#========================================================#\n");
    printf("Deleting Siddartha, Nageshwar, Narendra from the Hash Table.\n");
    printf("Hash Table after Deletion: \n\n");
    PrintHashTable();

//#======================================================================================#

    return 0;
}