mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=

# moduleディレクトリ中に追加したクラスを検索する
APPL_CXXOBJS += $(shell echo \
                    `ls ${HOME}/etrobo/workspace/etrobocon2021/module/*.cpp | \
                     sed -r 's/(\/.*)*\/(.*\.)cpp/\2o/g'`)

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

