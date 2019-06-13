#
# Makefile component for lwIP shared memory code
#

SOCKSRV_REQ_VARS := \
	ICP_ROOT \
	ICP_BUILD_ROOT
$(call icp_check_vars,$(LW_REQ_VARS))

SOCKSRV_SRC_DIR := $(ICP_ROOT)/src/modules/socket
SOCKSRV_OBJ_DIR := $(ICP_BUILD_ROOT)/obj/modules/socket_server
SOCKSRV_INC_DIR := $(ICP_ROOT)/src/modules
SOCKSRV_LIB_DIR := $(ICP_BUILD_ROOT)/lib

SOCKSRV_SOURCES :=
SOCKSRV_DEPENDS :=
SOCKSRV_LDLIBS  :=

include $(SOCKSRV_SRC_DIR)/module.mk

SOCKSRV_OBJECTS := $(call icp_generate_objects,$(SOCKSRV_SOURCES),$(SOCKSRV_OBJ_DIR))

SOCKSRV_LIBRARY := icpsocket_server
SOCKSRV_TARGET := $(SOCKSRV_LIB_DIR)/lib$(SOCKSRV_LIBRARY).a

ICP_INC_DIRS += $(SOCKSRV_INC_DIR)
ICP_LDLIBS += -Wl,--whole-archive -l$(SOCKSRV_LIBRARY) -Wl,--no-whole-archive $(SOCKSRV_LDLIBS)

# Load external dependencies
-include $(SOCKSRV_OBJECTS:.o=.d)
$(call icp_include_dependencies,$(SOCKSRC_DEPENDS))

###
# Build rules
###
$(eval $(call icp_generate_build_rules,$(SOCKSRV_SOURCES),SOCKSRV_SRC_DIR,SOCKSRV_OBJ_DIR,SOCKSRV_DEPENDS))
$(eval $(call icp_generate_clean_rules,socket_server,SOCKSRV_TARGET,SOCKSRV_OBJECTS))

$(SOCKSRV_TARGET): $(SOCKSRV_OBJECTS)
	$(call icp_link_library,$@,$(SOCKSRV_OBJECTS))

.PHONY: socket_server
socket_server: $(SOCKSRV_TARGET)
