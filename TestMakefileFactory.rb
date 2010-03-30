class TestMakefileFactory

  def initialize
    @files = []
  end

  def getCppList
    dir = Dir.open( Dir.pwd )
    reg = /(.*\.cpp)/
    dir.each { |file|
      if reg =~ file then
        # .cpp を .obj に変換して格納
        @files.push file.sub( ".cpp", ".obj" )
      end
    }

    dir.close
  end

  def makeMakefile
    makefile = File.new( "Makefile", "w" )

    # OBJ ファイル一覧
    makefile.print "OBJS ="
    @files.each { |file|
      makefile.print " " + file
    }
    makefile.puts ""

    makefile.puts "LIBS = cppunit.lib"
    makefile.puts "INC  = D:\\_work\\etc\\cppunit-x-20020331"
    makefile.puts ""
    makefile.puts "test : $(OBJS)"
    makefile.puts "\truby TestRunnerFactory.rb"
    makefile.puts "\tcl -GX -I$(INC) Tester.cpp $(LIBS) $(OBJS)"
    makefile.puts "\tTester.exe"

    makefile.close
  end
end
  
factory = TestMakefileFactory.new
factory.getCppList
factory.makeMakefile
