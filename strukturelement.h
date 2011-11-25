#ifndef STRUKTURELEMENT_H
#define STRUKTURELEMENT_H
#include <QUrl>
#include <QString>
#include <QtGlobal>
#include <QTreeWidgetItem>
#include <QStandardItem>
#include <QStringBuilder>
#include <QClipboard>
#include <QApplication>
#include <QDateTime>

enum MyItemType
{
    semesterItem    = 1000,
    courseItem      = 1001,
    directoryItem   = 1002,
    fileItem        = 1003
};

enum MyItemDataRole
{
    sizeRole    = 32,
    urlRole     = 33,
    dateRole    = 34,
    includeRole = 35
};

class Strukturelement : public QStandardItem
{
public:
    Strukturelement(QString name, QUrl url, MyItemType typeEX);
    qint32 getSize() const;

    int type() const;

    bool operator< (const QStandardItem& other) const;

    void setData(const QVariant &value, int role = Qt::UserRole + 1 );
    QVariant data(int role = Qt::UserRole + 1) const;

protected:
    bool        einschliessen;
    qint32      size;
    QUrl        url;
    QDateTime   zeit;
    MyItemType  typeEX;

};

#endif // STRUKTURELEMENT_H
