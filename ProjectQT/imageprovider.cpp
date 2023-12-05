// imageprovider.cpp
#include "imageprovider.h"

ImageProvider::ImageProvider() : QQuickImageProvider(QQuickImageProvider::Pixmap) {}

QPixmap ImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) {
    QPixmap pixmap("file:///path/to/your/image.jpg");
    if (size) {
        *size = pixmap.size();
    }
    return pixmap;
}

void ImageProvider::loadImage() {
    // Load your image here or do any required initialization
}
