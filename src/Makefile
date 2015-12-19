CC 			:= $(CC)
CXX			:= $(CXX)
AR			:= $(AR)

TARGET 		:= $(TARGET)
BUILD_DIR 	:= $(BUILD_DIR)
INCLUDE_DIR := $(INC_DIR)

COMPILE_DIR := $(shell pwd)

CFLAG 		:= $(CFLAG)
CXXFLAG 	:= $(CXXFLAG)
ARFLAG 		:= $(ARFLAG)
IGNORE_OBJ	:= $(IGNORE_OBJ)

FILTER_IGNORE_OBJ= @								\
	allarobj="";									\
	for arobj in $(ALL_OBJECTS);					\
	do												\
		ignore=0;									\
		for ignoreobj in $(IGNORE_OBJ); 			\
		do											\
			if [ $$arobj = $$ignoreobj ]; then		\
				ignore=1;							\
			fi;										\
		done;										\
		if [ $$ignore -eq 0 ]; then					\
			allarobj=$$allarobj" "$$arobj;			\
		fi;											\
	done;											\
	echo $$allarobj;

ALL_OBJECTS := $(patsubst %.c, %.o, $(wildcard *.c))
ALL_OBJECTS += $(patsubst %.cpp, %.o, $(wildcard *.cpp))
ALL_C_SRC	:= $(wildcard *.c)
ALL_CPP_SRC	:= $(wildcard *.cpp)
ALL_AR_OBJ  := $(shell $(FILTER_IGNORE_OBJ))

BUILD_C_OBJ= @																	\
	for src in $(ALL_C_SRC); 													\
	do																			\
		clen=`echo $$src | wc -L`;												\
		clen=`expr $$clen - 2`;													\
		tobj=`echo $$src | cut -c1-$$clen`;										\
		tobj=$$tobj.o;															\
		echo "$(CC) $(CFLAG) -I$(INCLUDE_DIR) $$src -o $(BUILD_DIR)/$$tobj";	\
		$(CC) $(CFLAG) -I$(INCLUDE_DIR) $$src -o $(BUILD_DIR)/$$tobj;			\
	done

BUILD_CPP_OBJ= @																\
	for src in $(ALL_CPP_SRC); 													\
	do																			\
		clen=`echo $$src | wc -L`;												\
		clen=`expr $$clen - 4`;													\
		tobj=`echo $$src | cut -c1-$$clen`;										\
		tobj=$$tobj.o;															\
		echo "$(CXX) $(CXXFLAG) -I$(INCLUDE_DIR) $$src -o $(BUILD_DIR)/$$tobj";	\
		$(CXX) $(CXXFLAG) -I$(INCLUDE_DIR) $$src -o $(BUILD_DIR)/$$tobj;		\
	done;

AR_OBJ=@													\
	objs="";												\
	for obj in $(ALL_AR_OBJ);								\
	do														\
		objs=$$objs" "$(BUILD_DIR)/$$obj;					\
	done;													\
	echo "$(AR) $(ARFLAG) $(BUILD_DIR)/$(TARGET).a $$objs";	\
	$(AR) $(ARFLAG) $(BUILD_DIR)/$(TARGET).a $$objs;		\

all :  
	@echo "sub src"
	@echo $(TARGET)
	@echo $(CC)
	@echo $(CXX)
	@echo $(CFLAG)
	@echo $(CXXFLAG)
	@echo $(ARFLAG)
	@echo $(ALL_OBJECTS)
	@echo $(ALL_C_SRC)
	@echo $(ALL_CPP_SRC)
	@echo $(IGNORE_OBJ)
	@echo $(BUILD_DIR)
	@echo $(INCLUDE_DIR)
	@echo "ALLAR_OBJ:"$(ALL_AR_OBJ)
	$(BUILD_C_OBJ)
	$(BUILD_CPP_OBJ)
	$(AR_OBJ)



$(TARGET_C_TEST) : $(C_TEST_SOURCE) $(TARGET)
	$(CC) $(C_FLAGS) $< -o $@.o
	$(LD) $(LD_FLAGS) -e $(C_ENTRY) $(ENTRY_OBJ) $(INIT_ARRAY_BEGIN) $@.o $(TARGET).a $(INIT_ARRAY_END) -o $@
	
$(TARGET_CPP_TEST) : $(CPP_TEST_SOURCE) $(TARGET)
	$(CXX) $(CXX_FLAGS) $< -o $@.o
	$(LD) $(LD_FLAGS) -e $(C_ENTRY) $(ENTRY_OBJ) $(INIT_ARRAY_BEGIN) $@.o $(TARGET).a $(INIT_ARRAY_END) -o $@

$(TARGET) : c_obj cpp_obj $(STRING_CXX) lib_obj

.PHONY : clean
clean:
	-rm -f $(TARGET).a
	-rm -f *.o
	-rm -f *.d

