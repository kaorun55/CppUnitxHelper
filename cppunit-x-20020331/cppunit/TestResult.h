/*
 * TestResult.h
 */

#ifndef cppunit_TestResult_h
#define cppunit_TestResult_h

#include "cuconfig.h"

cu_NAMESPACE_BEGIN(cppunit)

class Test;
class TestFailure;
class TestListener;

/**
 * テスト結果を保持するクラス。<br>
 * A TestResult collects the results of executing a test case.
 * It is an instance of the Collecting Parameter pattern.
 *
 * The test framework distinguishes between failures and errors.<br>
 * A failure is anticipated and checked for with assertions.<br>
 * Errors are unanticipated problems signified by exceptions
 * that are not generated by the framework.
 *
 * 保有する TestFailure のライフサイクルを管理する。<br>
 * TestListener のライフサイクルはクライアント側で管理すること。
 *
 * @see Test
 */
class TestResult
{
  public:
	/** 排他セマフォの基底クラス。 */
	class Mutex {
	  public:
		virtual ~Mutex() {}
		virtual void lock();
		virtual void unlock();
	};

  protected:
	/** Mutex 自動ロック。 */
	class AutoMutexLock {
	  public:
		/// ロックを生成する。
		explicit AutoMutexLock(Mutex *mutex)
			: m_mutex(mutex) { m_mutex->lock(); }
		/// ロックを解除する。
		~AutoMutexLock() { m_mutex->unlock(); }

	  private:
		AutoMutexLock(const AutoMutexLock& rhs);
		AutoMutexLock& operator=(const AutoMutexLock& rhs);
		Mutex* m_mutex;
	};

  public:
	/**
	 * コンストラクタ。
	 * @param mutex 0 または <code>new</code> された排他セマフォ。
	 */
	explicit TestResult(Mutex* mutex = 0);

	/** デストラクタ。 */
	~TestResult();

	/**
	 * リスナを追加する。
	 *
	 * ※テスト実行中は使用しないこと。
	 */
	void addListener(TestListener* listener);

	/**
	 * テストを開始する。<br>
	 * Informs the result that a test will be started.
	 */
	void startTest(Test* test);

	/**
	 * テストが終了した。<br>
	 * Informs the result that a test was completed.
	 */
	void endTest(Test* test);

	/**
	 * テストの失敗を追加する。<br>
	 * Adds a failure to the list of failures.
	 * @param failure 失敗したテストの情報。
	 */
	void addFailure(const TestFailure* failure);

	/**
	 * エラーを追加する。<br>
	 * Adds an error to the list of errors.
	 * @param error エラー情報。
	 */
	void addError(const TestFailure* error);

	/**
	 * 実行されたテストの個数を返す。<br>
	 * Gets the number of run tests.
	 */
	int runCount() const;

	/**
	 * 失敗したテストの個数を返す。<br>
	 * Gets the number of detected failures.
	 */
	int failureCount() const;

	/**
	 * エラーになったテストの個数を返す。<br>
	 * Gets the number of detected errors.
	 */
	int errorCount() const;

	/**
	 * 一連のテストが成功したか?<br>
	 * Returns whether the entire test was successful or not.
	 */
	bool wasSuccessful() const;

	/**
	 * テストを中止する必要があるか?<br>
	 * Returns whether testing should be stopped.
	 */
	bool shouldStop() const;

	/**
	 * テストを中止する。<br>
	 * Stop testing.
	 */
	void stop();

	/**
	 * 失敗したテストのリストを返す。<br>
	 * Returns a list of the failures.
	 *
	 * ※テスト実行中は使用しないこと。
	 */
	const cu_List& failures() const { return m_failures; }

	/**
	 * エラーのリストを返す。<br>
	 * Returns a list of the errors.
	 *
	 * ※テスト実行中は使用しないこと。
	 */
	const cu_List& errors() const { return m_errors; }

  private:
	TestResult(const TestResult& rhs);
	TestResult& operator=(const TestResult& rhs);

  private:
	Mutex* m_mutex;
	cu_List m_listeners;	// list<TestListener*>
	cu_List m_failures;		// list<TestFailure*>
	cu_List m_errors;		// list<TestFailure*>
	int  m_runCount;
	bool m_shouldStop;
};

cu_NAMESPACE_END

#endif /* !cppunit_TestResult_h */
