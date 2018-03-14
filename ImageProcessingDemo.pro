TEMPLATE = subdirs

SUBDIRS = app image-processing cpputils cpp-template-utils qtutils

cpputils.depends = cpp-template-utils
image-processing.depends = cpputils
app.depends = image-processing qtutils cpputils
