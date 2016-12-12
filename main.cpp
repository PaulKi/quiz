#include <iostream>
#include <string>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

/**
*Base class
*/
class User
{
    private:
        string name;                     /**<string containing user name*/
        int id;                          /**<integer containing user id number*/

    public:
        string getName() {return name;} /**<Access function to retrieve name*/
        int getID()     {return id;}    /**<Access function to retrieve name*/
        void login(string);             /**<function to login*/
        void answer(int);               /**<function to send an answer*/
};

/**
*Student class inherited from User class
*/
class Student: public User
{
    public:
        void viewStudent(int id);       /**<function to retrieve and display student profile*/
        void restartQuiz();             /**<function to restart quiz*/

};

/**
*Admin class inherited from User class
*/
class Admin: public User
{
    public:
        void view(int id,string name);    /**<function to retrieve and display student profile*/
        void remove();                    /**<function to remove a question from question databank*/
        void add();                       /**<function to add a question from question databank*/

};

/**
*Quiz class
*/
class Quiz
{
    public:
        string question[];                            /**<String array to store 10 question quiz*/
        int answers[];                                /**<int array to store 10 correct answers from quiz*/

        void read();
        void makeQs(string *question, int *answer);  /**<Function to fetch 10 random questions from database*/
        void sendQ(string *question);                /**<Print question to screen and request answer from user*/
        bool verifyQs(char answer);                  /**<check user entered answer versus correct answer*/
        void report(int id,string profile_type);     /**<generate and print report*/
        void save();                                 /**<save quiz result & report*/
};


int main()
{
    XMLDocument xmlDoc;

    XMLNode * pRoot = xmlDoc.NewElement("Root");
    xmlDoc.InsertFirstChild(pRoot);
    XMLElement * pElement = xmlDoc.NewElement("Questions document");
    pRoot->InsertEndChild(pElement);

    pElement = xmlDoc.NewElement("List");
    pElement->SetAttribute("description", "list of questions");
    pRoot->InsertEndChild(pElement);


    for (int i=0; i<10; i++)
    {
        XMLElement * pListElement = xmlDoc.NewElement("Question");
        pListElement->SetAttribute("answer", i);
        pListElement->SetText("question 1 blah blah (1 (2 (3");
        pElement->InsertEndChild(pListElement);
    }

    xmlDoc.SaveFile("SavedData.xml");



    return 0;
}
