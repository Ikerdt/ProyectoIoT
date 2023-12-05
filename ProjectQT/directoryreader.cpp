#include "directoryreader.h"
#include <QDir>

DirectoryReader::DirectoryReader(QObject *parent) : QObject(parent) {}

QStringList DirectoryReader::getPhotoList(const QString &path) {
    QDir dir(path);
    QStringList filters;
    filters << "*.jpg"; // Change the filter as needed for your image types
    QStringList photos = dir.entryList(filters, QDir::Files);
    for (int i = 0; i < photos.size(); ++i) {
        photos[i] = path + "/" + photos[i];
    }
    return photos;
}
