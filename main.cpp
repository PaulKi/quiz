#include <iostream>
#include <string>
#include <vector>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

/**
*Base class
*/
class User
{
    public:
        string name;                     /**<string containing user name*/
        int id;                          /**<integer containing user id number*/
        int score;                      /**<stores the current quiz score of user*/

        string getName() {return name;} /**<Access function to retrieve name*/
        int getID()     {return id;}    /**<Access function to retrieve name*/
        void login(string);             /**<function to login*/
        void answer(char ans);          /**<function to send an answer*/

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
        std::vector<string> qQuestions;            /**<a vector used to store 10 questions as text*/
        std::vector<string> qAnswers;              /**<a vector to store the 10 correct answers tot he questions stored in qQuestions*/

        void read();
        void makeQs(string *question, int *answer);  /**<Function to fetch 10 random questions from database*/
        void sendQ(string *question);                /**<Print question to screen and request answer from user*/
        bool verifyQs(char answer);                  /**<check user entered answer versus correct answer*/
        void report(int id,string profile_type);     /**<generate and print report*/
        void save();                                 /**<save quiz result & report*/
};


int main()
{
    string name;
    cout << "enter name" << endl;
    cin >> name;

    if(name == "student" || name == "admin")
    {
        XMLDocument xmlDoc;
        std::vector<int> vecList;
        const char * questionText = NULL;
        const char * answerText = NULL;
        string input;

        Quiz quiz1;
        Student student;

        student.score =0;

        xmlDoc.LoadFile("SavedData.xml");
        XMLNode * pRoot = xmlDoc.FirstChild();
        XMLElement *pElement = pRoot->FirstChildElement("List");
        XMLElement * pListElement = pElement->FirstChildElement("Item");

        while(pListElement != NULL)
        {
            int iOutListValue;
            pListElement->QueryIntText(&iOutListValue);
            questionText = pListElement->Attribute("question");
            answerText = pListElement->Attribute("answer");

            quiz1.qQuestions.push_back(questionText);
            quiz1.qAnswers.push_back(answerText);

            vecList.push_back(iOutListValue);
            pListElement = pListElement->NextSiblingElement("Item");

        }

        for(int i=0; i<10; i++)
        {
            cout << "Question " << i+1 << endl;
            cout << quiz1.qQuestions[i] << endl << endl;
            cin >> input;

            if(input == quiz1.qAnswers[i])
                student.score += 10;
            system("CLS");
        }

        cout << "Your score is " << student.score << "%" << endl << endl;
    }

    else
        cout << "user not recognised" << endl;

    return 0;
}
