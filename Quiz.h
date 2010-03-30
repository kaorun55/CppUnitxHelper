#ifndef QUIZ_H_INCLUDE
#define QUIZ_H_INCLUDE

#include <string>

class Quiz
{
private:

    std::string     question_;
    int             answer_;

public:

    Quiz( const std::string& aQuestion, const std::string& correctAnswer, const std::string& badAnswer );

    const std::string& getQuestion() const;
    bool chackAnswer( int anAnswer ) const;
};

#endif // #ifndef QUIZ_H_INCLUDE
// EOF

