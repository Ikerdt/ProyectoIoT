import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Plant viewer"

    Image {
        id: displayImage
        anchors.centerIn: parent
        width: 400
        height: 300
        source: "file:////home/root/IMages/new_photo.jpg"
        fillMode: Image.PreserveAspectFit

        Timer {
            interval: 10000 // 10,000 ms = 10 seconds
            running: true
            repeat: true
            onTriggered: {
                displayImage.source = "file:////home/root/IMages/new_photo.jpg"
            }
        }
    }
    Rectangle {
        width: parent.width
        height: 20
        color: "#DDDDDD" // Background color

        Rectangle {
            width: parent.width * (percentage / 100)
            height: parent.height
            color: "green" // Bar color
        }
    }

    Image {
        id: displayImageplant
        x: 0
        y: 300
        width: 200
        height: 350
        source: "qrc:images/plant2.png"
        fillMode: Image.PreserveAspectFit
    }
    Image {
        id: displayImageplant2
        x: 620
        y: 40
        width: 180
        height: 300
        source: "qrc:images/plant.jpg"
        fillMode: Image.PreserveAspectFit
    }
    Text{
             id: myText
             text: qsTr("Moisture percentage")
             x:250
             y:25
             font.pixelSize: 30
         }
    Text{
             id: myTextplant
             text: qsTr("Plant view")
             x:300
             y:500
             font.pixelSize: 40
         }
    Slider {
        anchors {
            left: parent.left
            right: parent.right
            top: parent.bottom
            topMargin: 10
        }
        from: 0
        to: 100
        value: percentage
        onValueChanged: {
            percentage = value
        }
    }

    Text {
        anchors {
            left: parent.left
            right: parent.right
            top: parent.bottom
            topMargin: 40
        }
        text: "Percentage: " + percentage.toFixed(0) + "%"
        horizontalAlignment: Text.AlignHCenter
    }

    property int percentage: 70 // Change this value to set the initial percentage
}
