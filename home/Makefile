app_home_src = $(addprefix apps/home/,\
  bg.cpp \
  app.cpp \
  app_cell.cpp \
  apps_layout.py \
  controller.cpp \
  selectable_table_view_with_background.cpp \
)

apps_src += $(app_home_src)

i18n_files += $(call i18n_without_universal_for,home/base)

# Apps layout file generation

# The header is referred to as <apps/home/apps_layout.h> so make sure it's
# findable this way
SFLAGS += -I$(BUILD_DIR)

apps_layout = apps/home/apps_layout.csv

$(eval $(call rule_for, \
  APPS_LAYOUT, \
  apps/home/apps_layout.cpp, \
  , \
  $$(PYTHON) apps/home/apps_layout.py --layouts $(apps_layout) --header $$(subst .cpp,.h,$$@) --implementation $$@ --apps $$(EPSILON_APPS), \
  global \
))

$(BUILD_DIR)/apps/home/apps_layout.h: $(BUILD_DIR)/apps/home/apps_layout.cpp
