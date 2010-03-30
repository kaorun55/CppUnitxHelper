/*
 * TestSetup.h
 */

#ifndef cppunit_TestSetup_h
#define cppunit_TestSetup_h

#include "cuconfig.h"
#include "TestCase.h"
#include "TestDecorator.h"

cu_NAMESPACE_BEGIN(cppunit)

/**
 * テストの初期化、後片付けを追加するデコレータ。<br>
 * Decorator to set up and tear down additional fixture state.
 *
 * 保有する Test のライフサイクルを管理する。
 */
class TestSetup : public TestDecorator
{
  public:
	/**
	 * コンストラクタ。
	 * @param test 元になるテスト。
	 */
	explicit TestSetup(Test* test);

	virtual void run(TestResult* result);

  protected:
	/** テストを初期化する。 */
	virtual void setUp() {}

	/** テストの後片付けをする。 */
	virtual void tearDown() {}

	/** 実際にテストを実行する。 */
	void runBare();

//	#define TEST_ERROR(msg)
	/**
	 * エラーを追加する。
	 * @param msg  メッセージ。
	 * @param file 発生したファイル名。
	 * @param line 発生した行番号。
	 * @see TEST_ERROR
	 */
	void addError(const cu_String& msg, const char* file, long line);

  private:
	TestSetup(const TestSetup& rhs);
	TestSetup& operator=(const TestSetup& rhs);

  private:
	bool m_hasError;
	TestResult* m_result;	// 実行中だけセットされる。
};

cu_NAMESPACE_END

#endif /* !cppunit_TestSetup_h */
