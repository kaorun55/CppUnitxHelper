#include "Quiz.h"

class QuizTest : public TestCase
{
public:

    // いつもきまった書き方のコンストラクタ
    QuizTest( const char* name ) : TestCase( name ) {}

    // 実行したいテストメソッド
    void testQuestion()
    {
        Quiz quiz( "ドラえもんは何型ロボット？", "ねこ", "たぬき" );

        assert( std::string::npos != quiz.getQuestion().find( "ドラえもんは何型ロボット？" ) );
        assert( std::string::npos != quiz.getQuestion().find( "ねこ" ) );
        assert( std::string::npos != quiz.getQuestion().find( "たぬき" ) );
    }

    void testAnswer()
    {
        Quiz quiz( "ドラえもんは何型ロボット？", "ねこ", "たぬき" );

        if ( std::string::npos != quiz.getQuestion().find( "1: ねこ" ) ) {
            assert( quiz.chackAnswer( 1 ) );
        }
        else {
            assert( quiz.chackAnswer( 2 ) );
        }
    }
};
// EOF
