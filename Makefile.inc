mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=

# ここに追加したクラスを追加する
APPL_CXXOBJS += \
    EtRobocon2021.o \
    Measurer.o \
    Pid.o \
    CourseInfo.o \

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIRS += \
    $(mkfile_path)app \
    $(mkfile_path)module \
    $(mkfile_path)module/api \

INCLUDES += \
    -I$(mkfile_path)app \
    -I$(mkfile_path)module \
    -I$(mkfile_path)module/api \

COPTS += -std=gnu++11