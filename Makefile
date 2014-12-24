SILENCE = @

COMPONENT_NAME = FocosBox

PROJECT_HOME_DIR = .
PROJECT_TEST_DIR = tests
UNITY_HOME = unity.framework
CPP_PLATFORM = Gcc
UNITY_BUILD_HOME = unity.framework/extras/fixture/build

UNITY_CFLAGS += -DUNITY_OUTPUT_CHAR=UnityOutputCharSpy_OutputChar
UNITY_WARNINGFLAGS = -Wall -Werror -Wswitch-default

SRC_DIRS = \
	$(PROJECT_HOME_DIR)/src/Focos\

TEST_SRC_DIRS = \
        $(PROJECT_TEST_DIR)\
	$(PROJECT_TEST_DIR)/Focos\
	$(UNITY_HOME)/src\
	$(UNITY_HOME)/extras/fixture/src\
	$(UNITY_HOME)/extras/fixture/test\

INCLUDE_DIRS =\
	.\
	$(UNITY_HOME)/src\
	$(UNITY_HOME)/extras/fixture/src\
	$(UNITY_HOME)/extras/fixture/test\
	$(PROJECT_HOME_DIR)/include/Focos/\

include $(UNITY_BUILD_HOME)/MakefileWorker.mk
