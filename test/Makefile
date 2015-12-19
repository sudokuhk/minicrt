CC 			:= $(CC)
CXX			:= $(CXX)
LD			:= $(LD)

TARGET 		:= $(TARGET)
BUILD_DIR 	:= $(BUILD_DIR)
INCLUDE_DIR := $(INC_DIR)

COMPILE_DIR := $(shell pwd)

CFLAG 		:= $(CFLAG)
CXXFLAG 	:= $(CXXFLAG)
LDFLAG 		:= $(LDFLAG)

GET_BEGIN_OBJ=@									\
	objs="";									\
	for obj in $(BEGIN_OBJ);					\
	do											\
		objs=$$objs" "$(BUILD_DIR)/$$obj;		\
	done;										\
	echo $$objs;

GET_END_OBJ=@									\
	objs="";									\
	for obj in $(END_OBJ);						\
	do											\
		objs=$$objs" "$(BUILD_DIR)/$$obj;		\
	done;										\
	echo $$objs;

ENTRY		:= $(ENTRY)
ENTRY_OBJ	:= $(ENTRY_OBJ)
BEGIN_OBJS	:= $(shell $(GET_BEGIN_OBJ))
END_OBJS	:= $(shell $(GET_END_OBJ))

ALL_C_SRC	:= $(wildcard *.c)
ALL_CPP_SRC	:= $(wildcard *.cpp)

BUILD_C= @																		\
	entry_obj=$(BUILD_DIR)/$(ENTRY_OBJ);										\
	targetobj=$(BUILD_DIR)/$(TARGET).a;											\
	c=_c;																		\
	for src in $(ALL_C_SRC); 													\
	do																			\
		clen=`echo $$src | wc -L`;												\
		clen=`expr $$clen - 2`;													\
		tobj=`echo $$src | cut -c1-$$clen`;										\
		tobj=$(BUILD_DIR)/$$tobj;												\
		echo "$(CC) $(CFLAG) -I$(INCLUDE_DIR) $$src -o $$tobj$$c.o";				\
		$(CC) $(CFLAG) -I$(INCLUDE_DIR) $$src -o $$tobj$$c.o;						\
		echo "$(LD) $(LDFLAG) -e $(ENTRY) $$entry_obj $(BEGIN_OBJS) $$tobj$$c.o $$targetobj $(END_OBJS) -o $$tobj$$c";	\
		$(LD) $(LDFLAG) -e $(ENTRY) $$entry_obj $(BEGIN_OBJS) $$tobj$$c.o $$targetobj $(END_OBJS) -o $$tobj$$c;	\
	done

BUILD_CPP= @																		\
	entry_obj=$(BUILD_DIR)/$(ENTRY_OBJ);										\
	targetobj=$(BUILD_DIR)/$(TARGET).a;											\
	c=_cpp;																		\
	for src in $(ALL_CPP_SRC); 													\
	do																			\
		clen=`echo $$src | wc -L`;												\
		clen=`expr $$clen - 4`;													\
		tobj=`echo $$src | cut -c1-$$clen`;										\
		tobj=$(BUILD_DIR)/$$tobj;												\
		echo "$(CXX) $(CXXFLAG) -I$(INCLUDE_DIR) $$src -o $$tobj$$c.o";				\
		$(CXX) $(CXXFLAG) -I$(INCLUDE_DIR) $$src -o $$tobj$$c.o;						\
		echo "$(LD) $(LDFLAG) -e $(ENTRY) $$entry_obj $(BEGIN_OBJS) $$tobj$$c.o $$targetobj $(END_OBJS) -o $$tobj$$c";	\
		$(LD) $(LDFLAG) -e $(ENTRY) $$entry_obj $(BEGIN_OBJS) $$tobj$$c.o $$targetobj $(END_OBJS) -o $$tobj$$c;	\
	done

AR_OBJ=@													\
	objs="";												\
	for obj in $(ALL_AR_OBJ);								\
	do														\
		objs=$$objs" "$(BUILD_DIR)/$$obj;					\
	done;													\
	echo "$(AR) $(ARFLAG) $(BUILD_DIR)/$(TARGET).a $$objs";	\
	$(AR) $(ARFLAG) $(BUILD_DIR)/$(TARGET).a $$objs;		\

all :  
	@echo $(BUILD_DIR)
	@echo "ENTRY_OBJ:"$(ENTRY_OBJ)
	@echo "BEGIN_OBJ:"$(BEGIN_OBJS)
	@echo "END_OBJ:"$(END_OBJS)
	$(BUILD_C)
	$(BUILD_CPP)


.PHONY : clean
clean:
	-rm -f $(TARGET).a
	-rm -f *.o
	-rm -f *.d

