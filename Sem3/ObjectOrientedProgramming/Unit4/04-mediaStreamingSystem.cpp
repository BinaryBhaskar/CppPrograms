// Set 1: Hierarchy Layouts
// Concepts: Multiple Inheritance, Protected Access Modifiers, Private Inheritance Controls.
// Task: Design a streaming framework that handles underlying media protocols using mixed inheritance permissions.
// Requirements:
// Create a class AudioStream containing a protected string attribute audioCodec (set to "AAC" via a constructor).
// Create a class VideoStream containing a protected string attribute videoCodec (set to "H264" via a constructor).
// Create a class MediaPipeline that inherits from both AudioStream and VideoStream using private inheritance.
// Inside MediaPipeline, use the using keyword (Granting Access) to selectively make the videoCodec variable publicly accessible to outside files again, while keeping audioCodec completely hidden.
// Write a public method inside MediaPipeline called verifyPipeline() that prints both codecs to demonstrate that the derived class still has internal access to its protected base components.
// In main(), instantiate MediaPipeline. Verify you can read the public-granted videoCodec directly from the object instance, but trying to read audioCodec causes a compiler failure.

#include <iostream>
#include <string>

class AudioStream {
protected:
    std::string audioCodec;
public:
    AudioStream() {
        this->audioCodec = "AAC";
    }
};

class VideoStream {
protected:
    std::string videoCodec;
public:
    VideoStream() {
        this->videoCodec = "H264";
    }
};

class MediaPipeline : private AudioStream, private VideoStream {
public:
    using VideoStream::videoCodec;

    void verifyPipeline() {
        std::cout << "Pipeline Info:\n > Audio Codec: " << audioCodec << "\n > Video Codec: " << videoCodec << std::endl;
    }
};

int main() {
    MediaPipeline work;
    work.verifyPipeline();

    // Works as intended
    std::cout << "Video Codec directly from object: " << work.videoCodec << std::endl;

    // Causes compilation error
    // std::cout << "Audio Codec directly from object: " << work.audioCodec << std::endl;

    return 0;
}