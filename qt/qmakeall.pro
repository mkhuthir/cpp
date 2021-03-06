TEMPLATE = subdirs

SUBDIRS = \
    button \
    button2 \
    camera \
    oglbufobj \
    oglcolorcube \
    oglcube \
    ogldice \
    ogltexture \
    oglvert \
    oglwin \
    qimage \
    rasterwin \
    slider \
    win

message("----------------------------------------------------")
message(Qt version: $$[QT_VERSION])
message(Qt is installed in $$[QT_INSTALL_PREFIX])
message(Qt resources can be found in the following locations:)
message(Documentation: $$[QT_INSTALL_DOCS])
message(Header files: $$[QT_INSTALL_HEADERS])
message(Libraries: $$[QT_INSTALL_LIBS])
message(Binary files (executables): $$[QT_INSTALL_BINS])
message(Plugins: $$[QT_INSTALL_PLUGINS])
message(Data files: $$[QT_INSTALL_DATA])
message(Translation files: $$[QT_INSTALL_TRANSLATIONS])
message(Settings: $$[QT_INSTALL_CONFIGURATION])
message(Examples: $$[QT_INSTALL_EXAMPLES])
message("----------------------------------------------------")

