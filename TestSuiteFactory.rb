class TestSuiteFactory
  
    def initialize( classname )
      @classname = classname
      @testMethods = []
    end
    
    def makeAddSuite
      "\trunner.addTest( \"" + @classname + "\", tmp" + @classname + "::suite() );\n";
    end
    
    def makeSuiteMethod( file )
      file.puts "#include \"" + @classname + ".h\""
      file.puts "class tmp" + @classname + " : public " + @classname
      file.puts "{"
      file.puts "public:"
      file.puts "\ttmp" + @classname + "( const char* name ) : " + @classname + "( name ) {}\n"
      file.puts "\tstatic Test* suite()"
      file.puts "\t{"
      file.puts "\t\tTestSuite* suite = new TestSuite( \"" + @classname + "\");\n"
      @testMethods.each{ |method|
        file.puts "\t\tsuite->addTest( new TEST_CALLER( " + @classname + ", " + method + "));"
      }
      file.puts "\t\treturn suite;"
      file.puts "\t}"
      file.puts "};"
      file.puts ""
    end
    
    def parse
      lex = /.void (test.*)\(\).*/
      File.readlines( @classname + ".h" ).each do |f|
        if lex =~ f then
          @testMethods.push( $1 )
        end
      end
    end
  end
