CC=gcc
CXX=g++
AR=ar
LD=ld

TARGET = minicrt

ENTRY = mini_crt_entry
ENTRY_OBJ = entry.o
INIT_ARRAY_BEGIN = crt1.o 
INIT_ARRAY_END = crtn.o
CRT_BEGIN = crtbegin.o
CRT_END = crtend.o
AR_IGNORE_OBJ = $(ENTRY_OBJ) $(INIT_ARRAY_BEGIN) $(INIT_ARRAY_END) $(CRT_BEGIN) $(CRT_END)

COMPILE_DIR = $(shell pwd)
SUB_DIRS = src test
DEST_DIR = $(COMPILE_DIR)/build
INC_DIR = $(COMPILE_DIR)/inc

CFLAG = -m32 -c -ggdb -fno-builtin -nostdlib -fno-stack-protector
CXXFLAG = -m32 -c -ggdb -nostdinc++ -fno-rtti -fno-exceptions -fno-builtin -nostdlib -fno-stack-protector
ARFLAG = -rs
LDFLAG = -m elf_i386 -static -ggdb

RECURSIVE_MAKE= @ 														\
	for subdir in $(SUB_DIRS);  										\
	do 																	\
        echo "making in $$subdir"; 										\
        (cd $$subdir && $(MAKE) all -f Makefile -e TARGET='${TARGET}' 	\
			CC='${CC}' CXX='${CXX}' CFLAG='${CFLAG}' 					\
			CXXFLAG='${CXXFLAG}' ARFLAG='${ARFLAG}' 					\
			INC_DIR='$(INC_DIR)'										\
			IGNORE_OBJ='$(AR_IGNORE_OBJ)' BUILD_DIR='$(DEST_DIR)' 		\
			LDFLAG='$(LDFLAG)' LD='$(LD)' ENTRY='$(ENTRY)'				\
			ENTRY_OBJ='$(ENTRY_OBJ)' 									\
			BEGIN_OBJ='$(INIT_ARRAY_BEGIN) $(CRT_BEGIN)'				\
			END_OBJ='$(INIT_ARRAY_END) $(CRT_END)')						\
			|| exit 1;													\
	done;  

RECURSIVE_CLEAN= @ 														\
	for subdir in $(SUB_DIRS); 											\
	do 																	\
	   	echo "cleaning in $$subdir"; 									\
	   	(cd $$subdir && $(MAKE) clean -f Makefile) || exit 1; 			\
	done;  

all: 
	mkdir -p $(DEST_DIR)
	$(RECURSIVE_MAKE)
	echo $(COMPILE_DIR)
	echo $(DEST_DIR)

cleandirs:
	$(RECURSIVE_CLEAN)
	

.PHONY : clean
clean: cleandirs
	-rm -r $(DEST_DIR)
	-rm -f $(TARGET).a
	-rm -f *.o
	-rm -f *.d

