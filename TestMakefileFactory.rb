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
        @files.push file.sub( ".cpp", ".o" )
      end
    }

    dir.close
  end

  def makeMakefile
    makefile = File.new( "OBJS", "w" )

    # OBJ ファイル一覧
    makefile.print "objs ="
    @files.each { |file|
      makefile.print " " + file
    }

    makefile.close
  end
end
  
factory = TestMakefileFactory.new
factory.getCppList
factory.makeMakefile
