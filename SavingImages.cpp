#include <opencv2/opencv.hpp>
#include <ctime>

using namespace cv;

int main() {
    VideoCapture cap(0); // Use the default camera, change the argument if needed

    if (!cap.isOpened()) {
        std::cout << "Error: Could not open the camera." << std::endl;
        return -1;
    }

    Mat frame;
    int photoNumber = 1;
    time_t start = time(0);
    const int interval = 10; // Interval in seconds (1 minute)

    while (true) {
        cap >> frame; // Capture frame from the camera

        if (frame.empty()) {
            std::cout << "Error: Blank frame grabbed" << std::endl;
            break;
        }

        time_t now = time(0);
        double secondsPassed = difftime(now, start);

        if (secondsPassed >= interval) {
            // Save the photo with a timestamp
            std::string filename = "IMages/new_photo.jpg" ;
            imwrite(filename, frame);
            std::cout << "Photo captured: " << filename << std::endl;

            // Update for next capture
            start = time(0);
            photoNumber++;
        }

        // Delay to control capture rate
        waitKey(100); // Adjust the delay time if necessary
    }

    cap.release();
    return 0;
}
