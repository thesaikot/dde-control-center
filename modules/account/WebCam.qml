import QtQuick 2.1
import QtMultimedia 5.0
import "../widgets"

Item {
    id: root
    property bool running: false
    property int verticalPadding: 8

    onRunningChanged: {
        if (running) {
            camera.start()
        } else {
            camera.stop()
        }
    }

    Component.onCompleted: {
        if (running) {
            camera.start()
        } else {
            camera.stop()
        }
    }

    Camera {
        id: camera

        property url imageSavedPath: ""

        imageCapture {

            onImageCaptured: {
                avatar_preview.source = preview
                avatar_preview.visible = true
            }

            onImageSaved: {
                imageSavedPath = path
            }
        }

        function snapshot() {
            imageCapture.capture()
        }
    }

    Rectangle {
        id: video_output_box

        width: 120
        height: 120
        clip: true

        VideoOutput {
            id: video_output
            width: 120
            height: 120

            source: camera

            fillMode: VideoOutput.PreserveAspectCrop
            anchors.centerIn: parent
        }

        Image {
            id: avatar_preview
            width: 120
            height: 120

            scale: video_output.scale
            
            visible: false
            fillMode: Image.PreserveAspectCrop
            anchors.centerIn: parent
        }

        anchors.fill: mask
    }


    Image {
        id: mask
        source: "images/mask.png"

        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
    }

    SliderWithButtons {
        id: slider

        onPercentageChanged: {
            video_output.scale = percentage + 1
        }

        anchors.top: mask.bottom
        anchors.topMargin: root.verticalPadding
        anchors.horizontalCenter: parent.horizontalCenter
    }

    DTextButton {
        id: snapshot_button
        /* text: dsTr("Snapshot") */
        text: "Snapshot"
        property bool textIsSnapshotFlag: true

        anchors.top: slider.bottom
        anchors.topMargin: root.verticalPadding * 2
        anchors.right: confirm_button.left
        anchors.rightMargin: root.verticalPadding

        onClicked: {
            if (textIsSnapshotFlag) {
                camera.snapshot()
                text = "Resnapshot"
                textIsSnapshotFlag = false
            } else {
                avatar_preview.visible = false
                text = "Snapthot"
                textIsSnapshotFlag = true
            }
        }
    }

    DTextButton {
        id: confirm_button
        /* text: dsTr("Confirm") */
        text: "Confirm"

        anchors.right: parent.right
        anchors.rightMargin: root.verticalPadding
        anchors.verticalCenter: snapshot_button.verticalCenter

        onClicked: {
            root.confirm(radio_button.currentIndex == 1)
        }
    }
}
