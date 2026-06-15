import QtQuick
import QtQuick.Controls

Window {
    width: 550
    height: 550
    visible: true
    title: "Production Telemetry Hub"

    LogFilterProxyModel {
        id: logProxy
    }
    Column {
        anchors.fill: parent
        anchors.margins: 20
        StatusPieChart {
            id: visualChart
            width: 120
            height: 120
            color: "darkslateblue"
            fillAngle: angleSlider.value
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Slider {
            id: angleSlider
            from: 0
            to: 360
            value: 220
            width: 200
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Row {
            spacing: 10
            width: parent.width

            TextField {
                placeholderText: "Search logs..."
                width: parent.width * 0.65
                onTextChanged: logProxy.setFilterText(text)
            }

            ComboBox {
                model: ["ALL", "INFO", "WARN", "ERROR"]
                width: parent.width * 0.32
                onActivated: logProxy.setFilterLevel(currentText)
            }
        }

        ListView {
            width: parent.width
            height: 230
            clip: true
            model: logProxy
            delegate: ItemDelegate {
                width: parent.width
                contentItem: Row {
                    spacing: 15
                    Text {text: model.timestamp; color: "gray"}
                    Text {
                        text: "[" + model.level + "]"
                        font.bold: true
                        width: 65
                        color: model.level === "ERROR" ? "red" : (model.level === "WARN" ? "orange" : "green")
                    }
                    Text {text: model.message}
                }
            }
        }

        Button {
            text: "Generate Mock Live Error"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: logProxy.generateFakeLog("Core Engine temperature exceeded 95 C threshold", "ERROR")
        }
    }
}
