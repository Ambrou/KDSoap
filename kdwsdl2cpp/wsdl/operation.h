/****************************************************************************
** Copyright (C) 2010-2010 Klaralvdalens Datakonsult AB.  All rights reserved.
**
** This file is part of the KD SOAP library.
**
** Licensees holding valid commercial KD Soap licenses may use this file in
** accordance with the KD Soap Commercial License Agreement provided with
** the Software.
**
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 and version 3 as published by the
** Free Software Foundation and appearing in the file LICENSE.GPL included.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** Contact info@kdab.com if any conditions of this licensing are not
** clear to you.
**
**********************************************************************/

/*
    This file is part of KDE.

    Copyright (c) 2005 Tobias Koenig <tokoe@kde.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef KWSDL_OPERATION_H
#define KWSDL_OPERATION_H

#include <QDomElement>
#include <QList>

#include <wsdl/element.h>
#include <wsdl/fault.h>
#include <wsdl/param.h>

#include <kode_export.h>

class ParserContext;

namespace KWSDL {

/**
 * <operation> as defined inside <portType>.
 * Contains input message, output message, and faults.
 */
class KWSDL_EXPORT Operation : public Element
{
  public:
    typedef QList<Operation> List;

    enum OperationType
    {
      OneWayOperation,
      RequestResponseOperation,
      SolicitResponseOperation,
      NotificationOperation
    };

    Operation();
    Operation( const QString &nameSpace );
    ~Operation();

    void setOperationType( OperationType type );
    OperationType operationType() const;

    void setName( const QString &name );
    QString name() const;

    void setInput( const Param &input );
    Param input() const;

    void setOutput( const Param &output );
    Param output() const;

    void setFaults( const Fault::List &faults );
    Fault::List faults() const;

    void loadXML( ParserContext *context, const QDomElement &element );
    void saveXML( ParserContext *context, QDomDocument &document, QDomElement &parent ) const;

  private:
    OperationType mType;

    Param mInput;
    Param mOutput;
    Fault::List mFaults;

    QString mName;
};

}

#endif // KWSDL_OPERATION_H
