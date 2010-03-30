require "TestSuiteFactory.rb"

class TestRunnerFactory
  
  def initialize
    @tests = []
  end
  
  def getTestList
    dir = Dir.open( Dir.pwd )
    reg = /(.*Test)\.h/
    dir.each { |file|
      if reg =~ file then
        @tests.push TestSuiteFactory.new( $1 )
      end
    }
    
    dir.close
  end
  
  def makeRunner
    tester = File.new( "Tester.cpp", "w" )
    tester.puts "#include <cppunit/TestCase.h>"
    tester.puts "#include <cppunit/TestSuite.h>"
    tester.puts "#include <cppunit/TestRunner.h>"
    tester.puts "#include <cppunit/TestCaller.h>"
    tester.puts "USING_NAMESPACE_CPPUNIT"
    tester.puts "using namespace std;"
    tester.puts ""
    
    @tests.each { |aClass|
      aClass.parse
      aClass.makeSuiteMethod( tester )
    }
    
    tester.puts "int main( int argc, char* argv[] )"
    tester.puts "{"
    tester.puts "\tTestRunner runner;"
    
    @tests.each { |aClass|
      tester.puts aClass.makeAddSuite
    }
    
    tester.puts "\treturn runner.run( argc, argv );"
    tester.puts "}"
    tester.close
  end
end
  
factory = TestRunnerFactory.new
factory.getTestList
factory.makeRunner
