/**
 * @file   device_notif_impl.h
 * @date   31 Aug 2013
 * @author lukasz.forynski@gmail.com
 * @brief  TODO
 *
 * ___________________________
 * 
 * The MIT License (MIT)
 * 
 * Copyright (c) 2013 Lukasz Forynski
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION 
 */

#ifndef DEVICE_NOTIF_IMPL_H_
#define DEVICE_NOTIF_IMPL_H_

#include <device_notification.h>
#include <string.h>


#ifndef POSIX
#ifndef ANSI
#define ANSI
#endif /*!ANSI*/
#ifndef WIN32_LEAN_AND_MEAN
#define AWIN32_LEAN_AND_MEANNSI
#endif /*!WIN32_LEAN_AND_MEAN*/
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif /*!_WIN32_WINNT*/

#include <windows.h>
#include <winuser.h>
#include <Dbt.h>
#include <guiddef.h>

extern "C"
{
    #include<SetupAPI.h>
}

class DeviceNotification;

class DeviceNotificationImpl
{
public:
    DeviceNotificationImpl(DeviceNotification* the_parent);
    ~DeviceNotificationImpl();
    void init(GUID interface_guid);
    void run_from_thread_never_returns();

private:
    void create_msg_window();
    void destroy_msg_window();
    static LRESULT _message_handler(HWND__* hwnd, UINT message, WPARAM wparam, LPARAM lparam);

private:
    HWND hwnd;
    HDEVNOTIFY dev_notif;
    GUID guid;
    const char* class_name;
    DeviceNotification* parent;
};


#else

class DeviceNotificationImpl
{
public:
    DeviceNotificationImpl(DeviceNotification* the_parent);
    void init(int interface_guid);
    ~DeviceNotificationImpl();
    void run_from_thread_never_returns();

private:
    DeviceNotification* parent;
};
#endif


#endif /* DEVICE_NOTIF_IMPL_H_ */