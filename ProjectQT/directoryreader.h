#ifndef DIRECTORYREADER_H
#define DIRECTORYREADER_H

#include <QObject>
#include <QStringList>

class DirectoryReader : public QObject {
    Q_OBJECT
public:
    explicit DirectoryReader(QObject *parent = nullptr);

    Q_INVOKABLE QStringList getPhotoList(const QString& path);
};

#endif // DIRECTORYREADER_H
