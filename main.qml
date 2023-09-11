import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        width: window.width
        height: window.height
        color: "blue"

        Text {
            text: "Game"
            color: "white"
            anchors.centerIn: parent
        }
        Column {
            Text {
                text: "fps: " + fps
                color: "white"
            }
            Text {
                text: "human: " + game.HumanCount
                color: "yellow"
            }
            Text {
                text: "zombi: " + game.ZombiCount
                color: "red"
            }
        }
    }
}
