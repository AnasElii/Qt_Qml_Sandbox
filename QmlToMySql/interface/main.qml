import QtQuick 6.0
import QtQuick.Controls.Material 6.0
import TableModel 1.0

Window {
    width: 800
    height: 560

    visible: true
    title: "QtMySql_pj01"

    // QML code
    Connections {
        target: qmlController
        function onNewProductContoller(nom, description, qteStock) {
            // Handle the signal here
            console.log("Product added: " + nom + " | " + description + " | " + qteStock);
        }
    }

    Rectangle {
        id: rectangle

        anchors.fill: parent

        // color: Constants.backgroundColor
        Text {
            id: titleText

            width: 108
            height: 35
            anchors.top: parent.top
            anchors.topMargin: 20

            text: qsTr("Produit")
            font.pixelSize: 24
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.styleName: "Bold"
        }

        // Header Input
        Grid {
            id: gridInput

            anchors {
                horizontalCenter: rectangle.horizontalCenter
                top: titleText.bottom
                topMargin: 20
                left: parent.left
                leftMargin: 20
            }

            spacing: 20
            columns: 2

            Text {
                text: qsTr("ID")
            }

            TextField {
                id: idInput

                // enabled: false
                text: qmlController.id
                placeholderText: qsTr("Enter id...")
                font.pixelSize: 12
            }

            Text {
                text: qsTr("Name")
            }

            TextField {
                id: nameInput

                placeholderText: qsTr("Enter name...")
                font.pixelSize: 12
            }

            Text {
                text: qsTr("Description")
            }

            TextField {
                id: descInput

                placeholderText: qsTr("Enter Descript...")
                font.pixelSize: 12
            }
            Text {
                text: qsTr("Quantity")
            }

            TextField {
                id: qteInput

                placeholderText: qsTr("Enter Quant...")
                font.pixelSize: 12
            }
        }

        Text {
            id: miniTitleText

            width: 108
            height: 35

            anchors {
                top: gridInput.bottom
                topMargin: 20
                left: parent.left
                leftMargin: 20
            }

            text: qsTr("Produit List")
            font.pixelSize: 24
            font.styleName: "Bold"
        }

        // Search Input
        TextField {
            id: searchInput

            anchors {
                bottom: tableDisplay.top
                bottomMargin: 10
                right: tableDisplay.right
            }

            placeholderText: qsTr("Search...")
            font.pixelSize: 12
        }

        // Table View
        Rectangle {
            id: tableDisplay
            width: parent.width / 1.4

            color: "red"
            anchors {
                top: miniTitleText.bottom
                topMargin: 10
                left: parent.left
                leftMargin: 20
                bottom: infoLable.top
            }

            TableView {
                anchors.fill: parent
                columnSpacing: 1
                rowSpacing: 1
                clip: true

                model: TableModel {
                }

                delegate: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 50
                    Text {
                        text: display
                    }
                }
            }
        }

        // Add Update and Delete Buttons
        Rectangle {

            color: "blue"
            anchors {
                left: tableDisplay.right
                leftMargin: 20
                top: tableDisplay.top
                right: parent.rights
                rightMargin: 20
            }
            Column {
                spacing: 20

                Button {
                    id: addBtn

                    text: "Add"
                    onClicked: {
                        console.log("addProduct Clicked!");
                        qmlController.name = nameInput.text;
                        qmlController.description = descInput.text;
                        qmlController.qteStock = parseInt(qteInput.text);
                        qmlController.setNewProduct();
                    }
                }
                Button {
                    id: updateBtn

                    text: "Update"

                    onClicked: {
                        qmlController.id = parseInt(idInput.text);
                        qmlController.name = nameInput.text;
                        qmlController.description = descInput.text;
                        qmlController.qteStock = parseInt(qteInput.text);
                        qmlController.UpdateProduct();
                    }
                }
                Button {
                    id: deleteBtn
                    text: "Delete"
                    onClicked: {
                        qmlController.id = parseInt(idInput.text);
                        qmlController.DeleteProduct();
                    }
                }
            }
        }

        // Lable Info
        Label {
            id: infoLable

            visible: false
            anchors {
                left: parent.left
                leftMargin: 20
                bottom: parent.bottom
                bottomMargin: 20
            }

            text: ""
            font.pixelSize: 22
            font.italic: true
        }
    }
}
