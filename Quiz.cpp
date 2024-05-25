#include <iostream>
#include <string>

using namespace std;


struct Question {
    string questionText;
    string options[4]; //ANother alternative is to use vector (I've used array instead)
    char correctOption;
};

//  display a question and get the user's answer
char askQuestion(const Question &q) {
    cout << q.questionText << endl;
    for (int i = 0; i < 4; ++i) {
        cout << char('A' + i) << ": " << q.options[i] << endl;
    }

    char answer;
    cout << "Your answer: ";
    cin >> answer;
    return toupper(answer);
}

//  check if the answer is correct
bool checkAnswer(const Question &q, char answer) {
    return answer == q.correctOption;
}

// display the final score
void displayScore(int score, int totalQuestions) {
    cout << "Your final score is " << score << " out of " << totalQuestions << endl;

    //feedback 
    if (score == totalQuestions) {
        cout << "Excellent! You got all the questions right!" << endl;
    } else if (score >= totalQuestions / 2) {
        cout << "Good job! You scored more than half." << endl;
      else if(score == totalQuestions / 2){
        cout << "You can do better. Keep it up!" << endl;
    } else {
        cout << "Better luck next time. Keep practicing!" << endl;
    }
}

int main() {
    
    Question quiz[10] = {
            {
                "Which of the following elements is the densest at standard temperature and pressure?",
                {"Iron", "Osmium", "Platinum", "Gold"},
                'B'
            },
            {
                "Who was the first woman to fly solo across the Atlantic Ocean?",
                {"Amelia Earhart", "Bessie Coleman", "Amy Johnson", "Jacqueline Cochran"},
                'A'
            },
            {
                "In Greek mythology, who was the goddess of wisdom and warfare?",
                {"Aphrodite", "Hera", "Athena", "Artemis"},
                'C'
            },
            {
                "Which of Shakespeare's plays is the longest?",
                {"Hamlet", "Romeo and Juliet", "Macbeth", "Antony and Cleopatra"},
                'D'
            },
            {
                "What is the chemical symbol for the element silver?",
                {"Si", "Ag", "Au", "Sr"},
                'B'
            },
            {
                "The Great Wall of China is approximately how long?",
                {"5,000 miles", "7,000 miles", "10,000 miles", "13,000 miles"},
                'D'
            },
            {
                "Who wrote the novel \"One Hundred Years of Solitude\"?",
                {"Gabriel Garcia Marquez", "Mario Vargas Llosa", "Jorge Luis Borges", "Isabel Allende"},
                'A'
            },
            {
                "What is the largest planet in our solar system?",
                {"Jupiter", "Saturn", "Uranus", "Neptune"},
                'A'
            },
            {
                "Which planet is known as the \"Red Planet\"?",
                {"Venus", "Mars", "Jupiter", "Saturn"},
                'B'
            },
            {
                "In what year did the Berlin Wall fall?",
                {"1985", "1987", "1989", "1991"},
                'C'
            }
        };

    int score = 0;

    
    for (int i = 0; i < 10; ++i) {
        char answer = askQuestion(quiz[i]);
        if (checkAnswer(quiz[i], answer)) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Incorrect. The correct answer is " << quiz[i].correctOption << "." << endl;
        }
        cout << endl;
    }

    
    displayScore(score, 10); 

    return 0;
}
