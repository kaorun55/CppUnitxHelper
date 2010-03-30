OBJS = Counter.obj Quiz.obj
LIBS = cppunit.lib
INC  = D:\_work\etc\cppunit-x-20020331

test : $(OBJS)
	ruby TestRunnerFactory.rb
	cl -GX -I$(INC) Tester.cpp $(LIBS) $(OBJS)
	Tester.exe
