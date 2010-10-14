/******************************************************************************
 * This file is part of dirtsand.                                             *
 *                                                                            *
 * dirtsand is free software: you can redistribute it and/or modify           *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation, either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * dirtsand is distributed in the hope that it will be useful,                *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with dirtsand.  If not, see <http://www.gnu.org/licenses/>.          *
 ******************************************************************************/

#ifndef _DS_SOCKIO_H
#define _DS_SOCKIO_H

#include "streams.h"

namespace DS
{
    typedef void* SocketHandle;

    SocketHandle BindSocket(const char* address, const char* port);
    void ListenSock(SocketHandle sock, int backlog = 10);
    SocketHandle AcceptSock(SocketHandle sock);
    void CloseSock(SocketHandle sock);
    void FreeSock(SocketHandle sock);

    String SockIpAddress(SocketHandle sock);

    void SendBuffer(SocketHandle sock, const void* buffer, size_t size);
    void RecvBuffer(SocketHandle sock, void* buffer, size_t size);

    template <typename tp>
    inline tp RecvValue(SocketHandle sock)
    {
        tp value;
        RecvBuffer(sock, &value, sizeof(value));
        return value;
    }

    Blob* RecvBlob(SocketHandle sock);
}

#endif