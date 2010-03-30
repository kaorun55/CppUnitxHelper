# Makefile

# �v���O�������ƃI�u�W�F�N�g�t�@�C����
-include OBJS
program = UnitTest

# ��`�σ}�N���̍Ē�`
CC = gcc
CFLAGS = -g -Wall
INCLUDE = -Icppunit-x-20020331

# �T�t�B�b�N�X���[���K�p�Ώۂ̊g���q�̒�`
.SUFFIXES: .cpp .o

# �v���C�}���^�[�Q�b�g
$(program): $(objs)
	echo $^
	ruby TestRunnerFactory.rb
	$(CC) -o $(program) libcppunit.a $^

# �T�t�B�b�N�X���[��
.cpp.o:
	echo $<
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

