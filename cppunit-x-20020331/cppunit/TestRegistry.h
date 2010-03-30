/*
 * TestRegistry.h
 */

#ifndef cppunit_TestRegistry_h
#define cppunit_TestRegistry_h

#include "cuconfig.h"
#include "Test.h"

cu_NAMESPACE_BEGIN(cppunit)

class TestResult;

/**
 * �e�X�g��o�^����N���X�B
 *
 * TestRunner �̎����Ŏg�p�B
 * CppUnit 1.6.x �� TestRegistry �Ƃ͗p�r�������قȂ�B
 * 
 * �ۗL���� Test �̃��C�t�T�C�N�����Ǘ�����B
 */
class TestRegistry
{
  public:
	/** �R���X�g���N�^�B */
	TestRegistry() {}

	/** �f�X�g���N�^�B */
	~TestRegistry();

	/**
	 * �e�X�g��ǉ�����B
	 * @param name �e�X�g���B
	 * @param test �ǉ�����e�X�g�B
	 */
	void addTest(const char* name, Test* test);

	/**
	 * �w�肳�ꂽ���O�̃e�X�g��L���ɂ���B
	 * @param name �e�X�g���B
	 * @return �Y������e�X�g�����邩?
	 */
	bool setAvailable(const char* name, bool value = true);

	/** �S�Ẵe�X�g��L���ɂ���B */
	void setAllAvailable(bool value = true);

	/** �L���ȃe�X�g�����邩? */
	bool hasAvailables() const;

	/** �ǉ����ꂽ�e�X�g�̃��X�g��Ԃ��B */
	const cu_List& entries() const { return m_entries; }

	/**
	 * �e�X�g�����s����B
	 * @param result �e�X�g���ʁB
	 */
	void runTests(TestResult* result);

  private:
	int m_availables;
	cu_List m_entries;	// list<Entry*>

  public:
	/**
	 * �e�X�g�̃G���g���B
	 */
	class Entry {
	  public:
		/**
		 * �R���X�g���N�^�B
		 * @param name      �e�X�g���B
		 * @param test      �e�X�g�B
		 * @param available �e�X�g���L����?
		 */
		Entry(const char* name, Test* test, bool available = false)
			: m_name(name), m_test(test), m_available(available) {}

		/** �f�X�g���N�^�B */
		~Entry() { delete m_test; }

		/** �e�X�g����Ԃ��B */
		const char* getName() const { return m_name.c_str(); }

		/** �e�X�g��Ԃ��B */
		Test* getTest() const { return m_test; }

		/** �e�X�g���L����? */
		bool isAvailable() const { return m_available; }

		/**
		 * �e�X�g���L�����ݒ肷��B
		 * @param value �ݒ肷��l�B
		 */
		void setAvailable(bool value = true) { m_available = value; }

	  private:
		cu_String m_name;
		Test* m_test;
		bool  m_available;
	};
};

cu_NAMESPACE_END

#endif /* !cppunit_TestRegistry_h */
