#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;

string player_name;
bool pay_half_skip = true;
bool skip = true;
long cash = 0;
long question_price = 100;
int consective = 0;
int right_answer = 0;
int wrong_answer = 0;
int question_no = 1;

void results();
void game_rules();
void ask_random_question();
void check_answer(char answer, char correct_answer);

struct Question
{
        string question;
        string option_a;
        string option_b;
        string option_c;
        string option_d;
        char answer;
        bool availability;
};

Question questions[10];

int main()
{
        system("cls");
        questions[0] = {"Which programming stucture makes a comparion ?", "relaton", "decision", "sequence", "repetition", 'b', true};
        questions[1] = {"A loop within the loop is called :", "nested loop", "complex loop", "infinte loop", "none", 'a', true};
        questions[2] = {"India's Capital is :", "Mumbai", "Nagpur", "Kanpur", "Delhi", 'd', true};
        questions[3] = {"India's Current Prime Minister is :", "Rahul Gandhi", "Manmohan Singh", "Narandra Modi", "Arvind Kejrival", 'c', true};
        questions[4] = {"What is the colour of blood of Octopus :", "Blue", "Read", "Green", "Yellow", 'a', true};
        questions[5] = {"Space-X is owned is :", "Mark Zuckerber", "Mukesh Ambani", "Jack Ma", "Elon Musk", 'd', true};
        questions[6] = {"Who becomes the new President of United States of America :", "Barack Obama", "Joe Biden", "Donald Trump", "Gorge W.Bush ", 'b', true};
        questions[7] = {"Which was the first non-English movie that got the Best Movie Award at Oscars 2k20 :", "Parasite", "Roma", "Bable", "Amour", 'a', true};
        questions[8] = {"Who won the French Open 2019 :", "Novak Djokovic", "Leander Paes", "Rafeal Nadal", "Mahesh Bhupati", 'c', true};
        questions[9] = {"Who won the IPL Edition 13th :", "Mumbai Indians", "Chennai super Kings", "Delih Capitals", "Sunrisers Hydrabad", 'a', true};

        cout << "=========================================================" << endl;
        cout << "======================= WELCOM TO THE ===================" << endl;
        cout << "======================= KBC GAME SHOW ===================" << endl;
        cout << "=========================================================" << endl;

        cout << "Enter your name: " << endl;
        getline(cin , player_name);
        system("cls");
        game_rules();
        while (true)
        {
                if (question_no > 10)
                        break;
                ask_random_question();
        }
        results();
        return 0;
}

void ask_random_question()
{
        srand(time(0));
        while (true)
        {
                system("cls");
                int number = rand() % 10;

                if (questions[number].availability)
                {
                        questions[number].availability = false;
                        cout << "=========================================================" << endl;
                        cout << "======================= KBC GAME SHOW ===================" << endl;
                        cout << endl;
                        cout << "This question no. " << question_no << " is for $" << question_price << "\t\t\tBalance is $" << cash << endl<<endl;
                        cout << "Life Lines: ";
                        if (pay_half_skip)
                                cout << "\th=> PAY HALF SKIP";
                        if (skip)
                                cout << "\tl=> LEAVE QUESTION";
                        cout <<endl<< endl;
                        cout << "=========================================================" << endl;
                        cout << "======================= CHOSE YOUR OPTION ===============" << endl<<endl;
                        cout << questions[number].question << endl<< endl;
                        cout << "a) " << questions[number].option_a << "\t\tb) " << questions[number].option_b << endl
                             << endl;
                        cout << "c) " << questions[number].option_c << "\t\td) " << questions[number].option_d << endl
                             << endl;

                        char answer = _getwche();
                        answer = tolower(answer);
                        cout << endl;
                        question_no++;
                        check_answer(answer, questions[number].answer);
                        break;
                }
        }
}

void check_answer(char answer, char correct_answer)
{
        if (answer == correct_answer)
        {
                cout << "Congratulations... Your answer is correct" << endl;
                cout << "You earned $" << question_price << endl<<endl;
                cout << "Press any key to continue..." << endl;
                _getwch();
                right_answer++;
                consective++;
                cash = cash + question_price;
        }
        else if ((answer == 'h') && (pay_half_skip))
        {
                cout << "You chose the Life Line 'PAY HALH AND SKIP' " << endl;
                cout << "You lose $" << question_price / 4 << endl<<endl;
                cout << "Press any key to continue..." << endl;
                _getwch();
                cash = cash - (question_price / 4);
                pay_half_skip = false;
        }
        else if ((answer == 'l') && (skip))
        {
                cout << "You chose the life line 'LEAVE QUESTION' " << endl;
                cout << "You lose $0" << endl<<endl;
                cout << "Press any key to continue..." << endl;
                _getwch();
                skip = false;
        }
        else
        {
                cout << "Sorry.... Your answer is wrong..." << endl;
                cout << " You lose $" << question_price / 2 << endl<<endl;
                cout << "Press any key to continue..." << endl;
                _getwch();
                wrong_answer++;
                consective = 0;
                cash = cash - (question_price / 2);
        }
        question_price = question_price * 2;

        if (consective == 3)
        {
                pay_half_skip = true;
        }
        if (consective == 5)
        {
                skip = true;
        }
}

void results()
{
        double percentage;
        percentage = right_answer * 10;
        system("cls");
        cout << "=========================================================" << endl;
        cout << "======================= RESULTS =========================" << endl;
        cout << "=========================================================" << endl;
        cout << "Player Name: \t\t\t" << player_name << endl<<endl;
        cout << "Right Answer: \t\t\t" << right_answer << endl<<endl;
        cout << "Wrong Answer: \t\t\t" << wrong_answer << endl<<endl;
        cout << "Average: \t\t\t" << percentage << endl<<endl;

        if (cash >= 0)
                cout << "Winning Amount:\t\t\t " << cash << endl<< endl;
                     
        else
                cout << "Losing Amount:\t\t\t " << cash << endl<< endl;
                     
        cout << "=========================================================" << endl;
        cout << "================ THANKS FOR PLAYING =====================" << endl;
        cout << "=========================================================" << endl;
        cout << "============ PRESS ANY KEY TO CONTINUE ==================" << endl;
        cout << "=========================================================" << endl;
        _getwch();
}

void game_rules()
{
        cout << "=========================================================" << endl;
        cout << "==================== GAME RULES =========================" << endl;
        cout << "=========================================================" << endl;
        cout << "01. There are total 10 questions in the game." << endl << endl;
            
        cout << "02. There are only 2 Life Lines." << endl << endl;
            
        cout << "03. Pay Half & Skip means you have to pay 1/4 of current question." << endl << endl;
            
        cout << "04. Leave Question means you can leave question without any deduction." << endl << endl;
            
        cout << "05. If you attempt 3 consicutive right answers  Pay Half & Skip will rescued." << endl << endl;
            
        cout << "06. If you attempt 5 consicutive right answers Leave Question will rescued." << endl << endl;
            
        cout << "07. After each question, the amount of question will be doubled." << endl << endl;
            
        cout << "08. If the answer is wrong half amount will be deducted from the balance." << endl << endl;
            
        cout << "09. Press 'h' for Half & Skip life line and 'l' for Leave Question help line." << endl << endl;
            
        cout << "10. Press a, b, c or d to answer the question." << endl << endl;
            
        cout << "=========================================================" << endl;
        cout << "============== PLEASE ENTER ANY KEY TO START ============" << endl;
        cout << "=========================================================" << endl;

        _getwch();
} 