#include "Quiz.h"
#include <cstdlib>
#include <ctime>

Quiz::Quiz( const std::string& aQuestion, const std::string& correctAnswer, const std::string& badAnswer )
{
    srand( ::time( 0 ) );

    question_ = aQuestion + "\n";

    // 問題シャッフル
    if ( (rand() % 2) ) {
        question_ += "1: " + correctAnswer + "\n2: " + badAnswer;
        answer_  = 1;
    }
    else {
        question_ += "1: " + badAnswer + "\n2: " + correctAnswer;
        answer_  = 2;
    }
}

const std::string& Quiz::getQuestion() const
{
    return question_;
}

bool Quiz::chackAnswer( int anAnswer ) const
{
    return answer_ == anAnswer;
}
// EOF
