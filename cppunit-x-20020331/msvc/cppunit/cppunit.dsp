# Microsoft Developer Studio Project File - Name="cppunit" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** 編集しないでください **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=cppunit - Win32 Debug
!MESSAGE これは有効なﾒｲｸﾌｧｲﾙではありません。 このﾌﾟﾛｼﾞｪｸﾄをﾋﾞﾙﾄﾞするためには NMAKE を使用してください。
!MESSAGE [ﾒｲｸﾌｧｲﾙのｴｸｽﾎﾟｰﾄ] ｺﾏﾝﾄﾞを使用して実行してください
!MESSAGE 
!MESSAGE NMAKE /f "cppunit.mak".
!MESSAGE 
!MESSAGE NMAKE の実行時に構成を指定できます
!MESSAGE ｺﾏﾝﾄﾞ ﾗｲﾝ上でﾏｸﾛの設定を定義します。例:
!MESSAGE 
!MESSAGE NMAKE /f "cppunit.mak" CFG="cppunit - Win32 Debug"
!MESSAGE 
!MESSAGE 選択可能なﾋﾞﾙﾄﾞ ﾓｰﾄﾞ:
!MESSAGE 
!MESSAGE "cppunit - Win32 Release" ("Win32 (x86) Static Library" 用)
!MESSAGE "cppunit - Win32 Debug" ("Win32 (x86) Static Library" 用)
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "cppunit - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x411 /d "NDEBUG"
# ADD RSC /l 0x411 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "cppunit - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0x411 /d "_DEBUG"
# ADD RSC /l 0x411 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../cppunit.lib"

!ENDIF 

# Begin Target

# Name "cppunit - Win32 Release"
# Name "cppunit - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\cppunit\RepeatedTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\SimpleList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\SimpleString.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestCase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestDecorator.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestFailure.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestRegistry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestResult.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestRunner.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestSetup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestSuite.cpp
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestUtility.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\cppunit\cuconfig.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\cudebug.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\custdio.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\RepeatedTest.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\SimpleAutoPtr.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\SimpleList.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\SimpleString.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\Test.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestCaller.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestCase.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestDecorator.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestFailure.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestListener.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestRegistry.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestResult.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestRunner.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestSetup.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestSuite.h
# End Source File
# Begin Source File

SOURCE=..\..\cppunit\TestUtility.h
# End Source File
# End Group
# End Target
# End Project
