DATE_NAME ?= devices/date

override CXXFLAGS := -I$(LVGL_DIR) $(CXXFLAGS)

CXXSRCS += $(wildcard $(LVGL_DIR)/$(DATE_NAME)/*.cpp)
