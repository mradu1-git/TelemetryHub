import QtQuick
import QtQuick.Controls

Window {
    width: 400
    height: 300
    visible: true
    title: "Interview Project Test"

    // NO IMPORT NEEDED HERE! Because DeviceController has QML_ELEMENT
    // and is in the same CMake target, it is available automatically.
    DeviceController {
        id: backendDevice
    }

    Column {
        anchors.centerIn: parent
        spacing: 20

        Text {
            text: "Current Temperature: " + backendDevice.temperature + "°C"
            font.pixelSize: 18
        }

        Text {
            text: "Status: " + backendDevice.connectionStatus
            font.pixelSize: 16
            color: "blue"
        }

        Button {
            text: "Reset System Metrics"
            onClicked: backendDevice.resetDevice()
        }
    }
}