# ========= Set Resources
set(RESOURCE_DIR
    ""
)

# ========= Add qml medule
qt6_add_qml_module(components
    URI "content.components"
    VERSION 1.0
    NO_PLUGIN
    QML_FILES
    MyButton.qml

    RESOURCES
    ${RESOURCE_DIR}
)