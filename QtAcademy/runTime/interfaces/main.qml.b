import QtQuick
import QtQuick.Controls.Basic
import mainLib 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML and Cpp integration")

    LumberSawController {
        id: sawController
    }

    Column {
        id: root
        anchors.centerIn: parent
        spacing: 10

        Text {
            text: "Lumber mill control center"
            anchors.horizontalCenter: parent.horizontalCenter

            font.pointSize: 18
        }

        Text {
            text: "Saw 1"
            anchors.horizontalCenter: parent.horizontalCenter

            font.pointSize: 14
        }

        Row {
            AnimatedImage {
                id: sawImage
                width: 200
                height: 200

                playing: sawController.isWorking
                source: "qrc:/mainLib/resources/icons/circular-saw.gif"
                speed: sawController.sawSpeed

                Text {
                    anchors.top: parent.top
                    anchors.left: parent.left
                    text: "C++ | Speed: " + sawController.sawSpeed

                    font {
                        pointSize: 14
                        styleName: "bold"
                    }
                }
            }

            AnimatedImage {
                id: sawImage2
                width: 200
                height: 200

                playing: false
                source: "qrc:/mainLib/resources/icons/circular-saw.gif"
                speed: slider.value

                Text {
                    anchors.top: parent.top
                    anchors.left: parent.left
                    text: "Qml | Speed: " + sawController.sawSpeed

                    font {
                        pointSize: 14
                        styleName: "bold"
                    }
                }
            }
        }
        Column {
            anchors.horizontalCenter: parent.horizontalCenter
            Row {
                spacing: 10

                Button {
                    text: "Start"

                    onClicked: {
                        sawController.start();
                        sawImage2.playing = true;
                    }
                }

                Button {
                    text: "Stop"

                    onClicked: {
                        sawController.stop();
                        sawImage2.playing = false;
                    }
                }
            }

            Slider {
                id: slider

                anchors.horizontalCenter: parent.horizontalCenter
                width: 200

                from: 0
                to: 5

                value: sawController.sawSpeed

                onValueChanged: {
                    sawController.sawSpeed = value;
                }
            }
        }
    }

    Image {
        width: 100
        height: 24

        anchors {
            right: parent.right
            bottom: parent.bottom
            margins: 10
        }

        source: "qrc:/mainLib/resources/icons/built-with-qt-badge.png"
    }
}
