#
# Makefile component for inception framework
#

API_REQ_VARS := \
	ICP_ROOT \
	ICP_BUILD_ROOT
$(call icp_check_vars,$(ICP_REQ_VARS))

API_SRC_DIR := $(ICP_ROOT)/src/modules/api
API_OBJ_DIR := $(ICP_BUILD_ROOT)/obj/modules/api
API_LIB_DIR := $(ICP_BUILD_ROOT)/lib

# We explicitly state our includes, e.g. include module/<header.h>
ICP_INC_DIRS += $(API_INC_DIR)
ICP_LIB_DIRS += $(API_LIB_DIR)

API_SOURCES :=
API_OBJECTS :=
API_DEPENDS :=
API_LDLIBS  :=

include $(API_SRC_DIR)/module.mk

# Generate a list of object files from the API_SOURCES variable
# and translate the path from the SRC to the BUILD directory
API_OBJECTS += $(patsubst %, $(API_OBJ_DIR)/%, \
	$(patsubst %.c, %.o, $(filter %.c, $(API_SOURCES))))

API_OBJECTS += $(patsubst %, $(API_OBJ_DIR)/%, \
	$(patsubst %.cpp, %.o, $(filter %.cpp, $(API_SOURCES))))

API_LIBRARY := icp_api
API_TARGET := $(API_LIB_DIR)/lib$(API_LIBRARY).a

###
# Pull in dependencies, maybe...
# Hopefully, these are generated by the compiler
###
-include $(API_OBJECTS:.o=.d)

# Update library build options before loading dependencies. That way
# archive ordering should be correct.
ICP_LDLIBS += -Wl,--whole-archive -l$(API_LIBRARY) -Wl,--no-whole-archive $(API_LDLIBS)

# Load external dependencies, too
$(foreach DEP, $(API_DEPENDS), $(eval include $(ICP_ROOT)/mk/$(DEP).mk))

###
# Build rules
###
$(API_OBJECTS): | $(API_DEPENDS)

$(API_OBJ_DIR)/%.o: $(API_SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(strip $(ICP_CC) -o $@ -c $(ICP_CPPFLAGS) $(ICP_CFLAGS) $(ICP_COPTS) $(ICP_DEFINES) $<)

$(API_OBJ_DIR)/%.o: $(API_SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(strip $(ICP_CXX) -o $@ -c $(ICP_CPPFLAGS) $(ICP_CXXFLAGS) $(ICP_COPTS) $(ICP_DEFINES) $<)

$(API_TARGET): $(API_OBJECTS)
	@mkdir -p $(dir $@)
	$(strip $(ICP_AR) $(ICP_ARFLAGS) $@ $(API_OBJECTS))

.PHONY: api
api: $(API_TARGET)

.PHONY: clean_api
clean_api:
	@rm -rf $(API_OBJ_DIR) $(API_TARGET)
clean: clean_api