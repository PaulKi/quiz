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

    XMLError eResult = xmlDoc.LoadFile("SavedData.xml");
    XMLNode * pRoot = xmlDoc.FirstChild();

    xmlDoc.InsertFirstChild(pRoot);
    if (pRoot == NULL) return XML_ERROR_FILE_READ_ERROR;

    XMLElement * pElement = pRoot->FirstChildElement("Question");
    if (pElement == NULL) return XML_ERROR_PARSING_ELEMENT;

    int istring;
    eResult = pElement->Query(&istring);
    XMLCheckResult(eResult);



    return 0;
}
