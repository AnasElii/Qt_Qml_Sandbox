import QtQuick 2.15
import QtQuick.Controls 2.15
import mathLib

Window {
    id: mainWindow

    property int num: 0
    property int result: 0
    property string type

    color: "#2e2f30"
    height: 650
    title: qsTr("Calculator")
    visible: true
    width: 500

    Rectangle {
        id: inputRec
        color: "#355371"
        height: 55
        radius: 10

        anchors {
            left: parent.left
            leftMargin: 10
            right: parent.right
            rightMargin: 10
            top: parent.top
            topMargin: 10
        }
        TextInput {
            id: numInput
            cursorVisible: false
            leftPadding: 5
            text: "0"

            validator: RegularExpressionValidator {
                regularExpression: /^[0-9./]+$/
            }

            anchors {
                bottom: parent.bottom
                bottomMargin: 10
                left: parent.left
                leftMargin: 10
                right: parent.right
                rightMargin: 10
                top: parent.top
                topMargin: 10
            }
            font {
                bold: true
                pixelSize: 25
            }
        }
    }
    MyButton {
        id: btn1
        myText: "1"

        MouseArea {
            anchors.fill: parent
            hoverEnabled: false

            onClicked: {
                if (num === 0) {
                    num = btn1.myText;
                } else {
                    num = num + btn1.myText;
                    console.log(num);
                }
                numInput.text = num;
                // console.log("Number 1: " + num1)
                // numInput.text = num1
            }
        }
    }
    MyButton {
        id: btn2
        myText: "2"

        anchors {
            left: btn1.left
            leftMargin: 100
        }
        MouseArea {
            anchors.fill: parent
            hoverEnabled: false

            onClicked: {
                if (num === 0) {
                    num = btn2.myText;
                } else {
                    num = num + btn2.myText;
                    console.log(num);
                }
                numInput.text = num;
            }
        }
    }
    MyButton {
        id: btnPlus
        myText: "+"

        anchors {
            left: btn2.left
            leftMargin: 100
        }
        MouseArea {
            anchors.fill: parent
            hoverEnabled: false

            onClicked: {
                type = "Add";
                console.log("Type: " + type);
                btnResult.onClicked;
                num = 0;
                numInput.text = 0;
            }
        }
    }
    MyButton {
        id: btnResult
        myText: "="

        anchors {
            top: btnPlus.bottom
            topMargin: 20
            left: btnPlus.left
        }
        MouseArea {
            anchors.fill: parent
            hoverEnabled: false

            onClicked: {
                if (type === "Add" && num !== 0)
                    result += Number(num);
                numInput.text = result;
                console.log("Result: " + result);
            }
            
        }
    }
    MyButton {
        id: btnClear
        myText: "C"

        anchors {
            top: btnResult.bottom
            topMargin: 20
            left: btnPlus.left
        }
        MouseArea {
            anchors.fill: parent
            hoverEnabled: false

            onClicked: {
                type = null
                num = 0
                result = 0
                numInput.text = 0
            }            
        }
    }
}
