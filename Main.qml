import QtQuick
import QtQuick.Controls

Window {
    width: 400
    height: 300
    visible: true
    title: "Simplified Interview Test"

    // Only instantiating the non-visual processing item
    DataEncryptor {
        id: encryptor
    }

    Column {
        anchors.centerIn: parent
        spacing: 20

        Text {
            text: "C++ Integration Test"
            font.pointSize: 16
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // Standard QML Button — zero custom rendering required
        Button {
            text: "Run C++ Encryptor"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                var result = encryptor.encryptData("Hello")
                console.log("C++ Output: " + result)
            }
        }
    }
}