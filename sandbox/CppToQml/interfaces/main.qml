import QtQuick
import QtQuick.Controls
import CppBackEnd 1.0

Window {
    id: mainWindow

    title: "C++ Qml Signals and Slots"
    width: 650
    height: 500
    visible: true

    default property int count: cppBackEnd.counter

    CppBackEnd {
        id: cppBackEnd

        onCounterChanged: {
            console.log("Property is notified. Update value is: " + count);
        }
    }

    CppBackEnd {
        id: cppBackEnd2

        onCounterChanged: {
            console.log("Property is notified. Update value is: " + cppBackEnd2.counter);
        }
    }

    Connections {
        target: cppBackEnd
        function onSendToQml() {
            // count = cppBackEnd.counter;
            labelCount.text = "Fetched value is :" + count;
        }
    }

    Row {
        anchors.centerIn: parent
        spacing: 20
        Text {
            id: labelCount
            text: "Fetched value is: " + count
        }

        Button {
            id: btn
            text: qsTr("Fetch")
            width: 100
            height: 20
            onClicked: {
                cppBackEnd2.counter = cppBackEnd2.counter++;
            }
        }
    }
}
