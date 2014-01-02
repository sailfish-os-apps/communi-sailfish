/*
* Copyright (C) 2013-2014 J-P Nurmi <jpnurmi@gmail.com>
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*/

#ifndef MESSAGESTORAGE_H
#define MESSAGESTORAGE_H

#include <QObject>
#include <QHash>

class IrcBuffer;
class IrcMessage;
class MessageModel;

class MessageStorage : public QObject
{
    Q_OBJECT

public:
    static MessageStorage* instance();

    Q_INVOKABLE QObject* get(IrcBuffer* buffer) const;

public slots:
    void add(IrcBuffer* buffer);
    void remove(IrcBuffer* buffer);

signals:
    void highlighted(IrcBuffer* buffer, IrcMessage* message);
    void messageCountChanged(QString bufferDisplayName);

private slots:
    void onHighlighted(IrcMessage* message);
    void onCountChanged();

private:
    MessageStorage(QObject* parent = 0);

    QHash<IrcBuffer*, MessageModel*> m_models;
};

#endif // MESSAGESTORAGE_H
