COMPONENT_NAME=food

include $(UNITTEST_MAKEFILES_DIR)/MakefileShared.mk

SRC_FILES += \
  $(PROJECT_SRC_DIR)/food.cpp

TEST_SRC_FILES = \
  $(UNITTEST_SRC_DIR)/test_food.cpp

include $(CPPUTEST_MAKFILE_INFRA)
