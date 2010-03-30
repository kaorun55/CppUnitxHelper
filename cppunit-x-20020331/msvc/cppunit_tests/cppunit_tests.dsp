# Microsoft Developer Studio Project File - Name="cppunit_tests" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** 編集しないでください **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=cppunit_tests - Win32 Debug
!MESSAGE これは有効なﾒｲｸﾌｧｲﾙではありません。 このﾌﾟﾛｼﾞｪｸﾄをﾋﾞﾙﾄﾞするためには NMAKE を使用してください。
!MESSAGE [ﾒｲｸﾌｧｲﾙのｴｸｽﾎﾟｰﾄ] ｺﾏﾝﾄﾞを使用して実行してください
!MESSAGE 
!MESSAGE NMAKE /f "cppunit_tests.mak".
!MESSAGE 
!MESSAGE NMAKE の実行時に構成を指定できます
!MESSAGE ｺﾏﾝﾄﾞ ﾗｲﾝ上でﾏｸﾛの設定を定義します。例:
!MESSAGE 
!MESSAGE NMAKE /f "cppunit_tests.mak" CFG="cppunit_tests - Win32 Debug"
!MESSAGE 
!MESSAGE 選択可能なﾋﾞﾙﾄﾞ ﾓｰﾄﾞ:
!MESSAGE 
!MESSAGE "cppunit_tests - Win32 Release" ("Win32 (x86) Console Application" 用)
!MESSAGE "cppunit_tests - Win32 Debug" ("Win32 (x86) Console Application" 用)
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "cppunit_tests - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /I../.. /c
# ADD BASE RSC /l 0x411 /d "NDEBUG"
# ADD RSC /l 0x411 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "cppunit_tests - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /I../.. /c
# ADD BASE RSC /l 0x411 /d "_DEBUG"
# ADD RSC /l 0x411 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "cppunit_tests - Win32 Release"
# Name "cppunit_tests - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\cppunit\tests\AllTests.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\CppUnitTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\RepeatedTestTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\SimpleAutoPtrTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\SimpleListTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\SimpleStringTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\TestCallerTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\TestCaseTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\TestDecoratorTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\TestRegistryTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\TestResultTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\TestSetupTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\TestSuiteTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\TestUtilityTest.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\cppunit\tests\CppUnitTest.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\RepeatedTestTest.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\SimpleAutoPtrTest.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\SimpleListTest.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\SimpleStringTest.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\TestCallerTest.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\TestCaseTest.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\TestDecoratorTest.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\TestRegistryTest.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\TestResultTest.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\TestSetupTest.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\TestSuiteTest.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\tests\TestUtilityTest.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
