# Makefile

# プログラム名とオブジェクトファイル名
-include OBJS
program = UnitTest

# 定義済マクロの再定義
CC = gcc
CFLAGS = -g -Wall
INCLUDE = -Icppunit-x-20020331

# サフィックスルール適用対象の拡張子の定義
.SUFFIXES: .cpp .o

# プライマリターゲット
$(program): $(objs)
	echo $^
	ruby TestRunnerFactory.rb
	$(CC) -o $(program) libcppunit.a $^

# サフィックスルール
.cpp.o:
	echo $<
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

