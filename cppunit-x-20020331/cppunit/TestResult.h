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
 * �e�X�g���ʂ�ێ�����N���X�B<br>
 * A TestResult collects the results of executing a test case.
 * It is an instance of the Collecting Parameter pattern.
 *
 * The test framework distinguishes between failures and errors.<br>
 * A failure is anticipated and checked for with assertions.<br>
 * Errors are unanticipated problems signified by exceptions
 * that are not generated by the framework.
 *
 * �ۗL���� TestFailure �̃��C�t�T�C�N�����Ǘ�����B<br>
 * TestListener �̃��C�t�T�C�N���̓N���C�A���g���ŊǗ����邱�ƁB
 *
 * @see Test
 */
class TestResult
{
  public:
	/** �r���Z�}�t�H�̊��N���X�B */
	class Mutex {
	  public:
		virtual ~Mutex() {}
		virtual void lock();
		virtual void unlock();
	};

  protected:
	/** Mutex �������b�N�B */
	class AutoMutexLock {
	  public:
		/// ���b�N�𐶐�����B
		explicit AutoMutexLock(Mutex *mutex)
			: m_mutex(mutex) { m_mutex->lock(); }
		/// ���b�N����������B
		~AutoMutexLock() { m_mutex->unlock(); }

	  private:
		AutoMutexLock(const AutoMutexLock& rhs);
		AutoMutexLock& operator=(const AutoMutexLock& rhs);
		Mutex* m_mutex;
	};

  public:
	/**
	 * �R���X�g���N�^�B
	 * @param mutex 0 �܂��� <code>new</code> ���ꂽ�r���Z�}�t�H�B
	 */
	explicit TestResult(Mutex* mutex = 0);

	/** �f�X�g���N�^�B */
	~TestResult();

	/**
	 * ���X�i��ǉ�����B
	 *
	 * ���e�X�g���s���͎g�p���Ȃ����ƁB
	 */
	void addListener(TestListener* listener);

	/**
	 * �e�X�g���J�n����B<br>
	 * Informs the result that a test will be started.
	 */
	void startTest(Test* test);

	/**
	 * �e�X�g���I�������B<br>
	 * Informs the result that a test was completed.
	 */
	void endTest(Test* test);

	/**
	 * �e�X�g�̎��s��ǉ�����B<br>
	 * Adds a failure to the list of failures.
	 * @param failure ���s�����e�X�g�̏��B
	 */
	void addFailure(const TestFailure* failure);

	/**
	 * �G���[��ǉ�����B<br>
	 * Adds an error to the list of errors.
	 * @param error �G���[���B
	 */
	void addError(const TestFailure* error);

	/**
	 * ���s���ꂽ�e�X�g�̌���Ԃ��B<br>
	 * Gets the number of run tests.
	 */
	int runCount() const;

	/**
	 * ���s�����e�X�g�̌���Ԃ��B<br>
	 * Gets the number of detected failures.
	 */
	int failureCount() const;

	/**
	 * �G���[�ɂȂ����e�X�g�̌���Ԃ��B<br>
	 * Gets the number of detected errors.
	 */
	int errorCount() const;

	/**
	 * ��A�̃e�X�g������������?<br>
	 * Returns whether the entire test was successful or not.
	 */
	bool wasSuccessful() const;

	/**
	 * �e�X�g�𒆎~����K�v�����邩?<br>
	 * Returns whether testing should be stopped.
	 */
	bool shouldStop() const;

	/**
	 * �e�X�g�𒆎~����B<br>
	 * Stop testing.
	 */
	void stop();

	/**
	 * ���s�����e�X�g�̃��X�g��Ԃ��B<br>
	 * Returns a list of the failures.
	 *
	 * ���e�X�g���s���͎g�p���Ȃ����ƁB
	 */
	const cu_List& failures() const { return m_failures; }

	/**
	 * �G���[�̃��X�g��Ԃ��B<br>
	 * Returns a list of the errors.
	 *
	 * ���e�X�g���s���͎g�p���Ȃ����ƁB
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