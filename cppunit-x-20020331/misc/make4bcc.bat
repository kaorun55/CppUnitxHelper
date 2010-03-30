@rem
@rem rem make4bcc.bat
@rem
@echo off
if "%1" == "clean" goto clean

:build
bcc32 -I.. -c cppunit_all.cpp
bcc32 -I.. -c cppunit_tests.cpp
bcc32 -I.. -c -oSampleTest.obj ..\samples\SampleTest.cpp
bcc32 -eAllTests.exe cppunit_tests.obj cppunit_all.obj
bcc32 -eSampleTest.exe SampleTest.obj cppunit_all.obj
goto end

:clean
del *.exe
del *.tds
del *.obj

:end
