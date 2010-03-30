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
 * テストを登録するクラス。
 *
 * TestRunner の実装で使用。
 * CppUnit 1.6.x の TestRegistry とは用途が多少異なる。
 * 
 * 保有する Test のライフサイクルを管理する。
 */
class TestRegistry
{
  public:
	/** コンストラクタ。 */
	TestRegistry() {}

	/** デストラクタ。 */
	~TestRegistry();

	/**
	 * テストを追加する。
	 * @param name テスト名。
	 * @param test 追加するテスト。
	 */
	void addTest(const char* name, Test* test);

	/**
	 * 指定された名前のテストを有効にする。
	 * @param name テスト名。
	 * @return 該当するテストがあるか?
	 */
	bool setAvailable(const char* name, bool value = true);

	/** 全てのテストを有効にする。 */
	void setAllAvailable(bool value = true);

	/** 有効なテストがあるか? */
	bool hasAvailables() const;

	/** 追加されたテストのリストを返す。 */
	const cu_List& entries() const { return m_entries; }

	/**
	 * テストを実行する。
	 * @param result テスト結果。
	 */
	void runTests(TestResult* result);

  private:
	int m_availables;
	cu_List m_entries;	// list<Entry*>

  public:
	/**
	 * テストのエントリ。
	 */
	class Entry {
	  public:
		/**
		 * コンストラクタ。
		 * @param name      テスト名。
		 * @param test      テスト。
		 * @param available テストが有効か?
		 */
		Entry(const char* name, Test* test, bool available = false)
			: m_name(name), m_test(test), m_available(available) {}

		/** デストラクタ。 */
		~Entry() { delete m_test; }

		/** テスト名を返す。 */
		const char* getName() const { return m_name.c_str(); }

		/** テストを返す。 */
		Test* getTest() const { return m_test; }

		/** テストが有効か? */
		bool isAvailable() const { return m_available; }

		/**
		 * テストが有効か設定する。
		 * @param value 設定する値。
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
