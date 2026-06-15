import QtQuick
import QtQuick.Controls

Window {
    width: 550
    height: 550
    visible: true
    title: "Production Telemetry Hub"

    // Instantiate our custom C++ Proxy Element
    LogFilterProxyModel {
        id: logProxy
    }

    Column {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 15

        // Module 4: Custom Visual Element bound directly to input sliders
        StatusPieChart {
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

        // Module 6 & 7: Proxy Filtering Input Row Layout Elements
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

        // Module 5: Performance ListView fed safely through the Proxy pipe
        ListView {
            width: parent.width
            height: 230
            clip: true
            model: logProxy

            delegate: ItemDelegate {
                width: parent.width

                contentItem: Row {
                    spacing: 15
                    Text { text: model.timestamp; color: "gray" }
                    Text {
                        text: "[" + model.level + "]"
                        font.bold: true
                        width: 65
                        color: model.level === "ERROR" ? "red" : (model.level === "WARN" ? "orange" : "green")
                    }
                    Text { text: model.message }
                }
            }
        }

        Button {
            text: "Generate Mock Live Error"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: logProxy.generateFakeLog("Core engine temperature exceeded 95°C threshold", "ERROR")
        }
    }
}